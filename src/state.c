#include "state.h"

#include <errno.h>
#include "rrdp/db/db_rrdp.h"
#include "log.h"
#include "thread_var.h"

/**
 * The current state of the validation cycle.
 *
 * It is one of the core objects in this project. Every time a trust anchor
 * triggers a validation cycle, the validator creates one of these objects and
 * uses it to traverse the tree and keep track of validated data.
 */
struct validation {
	struct tal *tal;

	struct x509_data {
		/** https://www.openssl.org/docs/man1.1.1/man3/X509_STORE_load_locations.html */
		X509_STORE *store;
		X509_VERIFY_PARAM *params;
	} x509_data;

	struct cert_stack *certstack;

	struct uri_list *rsync_visited_uris;

	/* Local RRDP workspace path */
	char const *rrdp_workspace;

	/* Shallow copy of RRDP URIs and its corresponding visited uris */
	struct db_rrdp_uri *rrdp_uris;

	/* Did the TAL's public key match the root certificate's public key? */
	enum pubkey_state pubkey_state;

	/**
	 * Two buffers calling code will store stringified IP addresses in,
	 * to prevent proliferation of similar buffers on the stack.
	 *
	 * They are meant to be large enough to contain both IPv4 and IPv6
	 * addresses.
	 */
	char addr_buffer1[INET6_ADDRSTRLEN];
	char addr_buffer2[INET6_ADDRSTRLEN];

	struct validation_handler validation_handler;
};

/*
 * It appears that this function is called by LibreSSL whenever it finds an
 * error while validating.
 * It is expected to return "okay" status: Nonzero if the error should be
 * ignored, zero if the error is grounds to abort the validation.
 *
 * Note to myself: During my tests, this function was called in
 * X509_verify_cert(ctx) -> check_chain_extensions(0, ctx),
 * and then twice again in
 * X509_verify_cert(ctx) -> internal_verify(1, ctx).
 *
 * Regarding the ok argument: I'm not 100% sure that I get it; I don't
 * understand why this function would be called with ok = 1.
 * http://openssl.cs.utah.edu/docs/crypto/X509_STORE_CTX_set_verify_cb.html
 * The logic I implemented is the same as the second example: Always ignore the
 * error that's troubling the library, otherwise try to be as unintrusive as
 * possible.
 */
static int
cb(int ok, X509_STORE_CTX *ctx)
{
	int error;

	/*
	 * We need to handle two new critical extensions (IP Resources and ASN
	 * Resources), so unknown critical extensions are fine as far as
	 * LibreSSL is concerned.
	 * Unfortunately, LibreSSL has no way of telling us *which* is the
	 * unknown critical extension, but since RPKI defines its own set of
	 * valid extensions, we'll have to figure it out later anyway.
	 */
	error = X509_STORE_CTX_get_error(ctx);
	return (error == X509_V_ERR_UNHANDLED_CRITICAL_EXTENSION) ? 1 : ok;
}

/**
 * Creates a struct validation, puts it in thread local, and (incidentally)
 * returns it.
 */
int
validation_prepare(struct validation **out, struct tal *tal,
    struct validation_handler *validation_handler)
{
	struct validation *result;
	X509_VERIFY_PARAM *params;
	int error;

	result = malloc(sizeof(struct validation));
	if (!result)
		return pr_enomem();

	error = state_store(result);
	if (error)
		goto abort1;

	result->tal = tal;

	result->x509_data.store = X509_STORE_new();
	if (!result->x509_data.store) {
		error = val_crypto_err("X509_STORE_new() returned NULL");
		goto abort1;
	}

	params = X509_VERIFY_PARAM_new();
	if (params == NULL) {
		error = pr_enomem();
		goto abort2;
	}

	X509_VERIFY_PARAM_set_flags(params, X509_V_FLAG_CRL_CHECK);
	X509_STORE_set1_param(result->x509_data.store, params);
	X509_STORE_set_verify_cb(result->x509_data.store, cb);

	error = certstack_create(&result->certstack);
	if (error)
		goto abort3;

	error = rsync_create(&result->rsync_visited_uris);
	if (error)
		goto abort4;

	result->rrdp_uris = db_rrdp_get_uris(tal_get_file_name(tal));
	result->rrdp_workspace = db_rrdp_get_workspace(tal_get_file_name(tal));

	result->pubkey_state = PKS_UNTESTED;
	result->validation_handler = *validation_handler;
	result->x509_data.params = params; /* Ownership transfered */

	*out = result;
	return 0;
abort4:
	certstack_destroy(result->certstack);
abort3:
	X509_VERIFY_PARAM_free(params);
abort2:
	X509_STORE_free(result->x509_data.store);
abort1:
	free(result);
	return error;
}

void
validation_destroy(struct validation *state)
{
	X509_VERIFY_PARAM_free(state->x509_data.params);
	X509_STORE_free(state->x509_data.store);
	certstack_destroy(state->certstack);
	rsync_destroy(state->rsync_visited_uris);
	free(state);
}

struct tal *
validation_tal(struct validation *state)
{
	return state->tal;
}

X509_STORE *
validation_store(struct validation *state)
{
	return state->x509_data.store;
}

struct cert_stack *
validation_certstack(struct validation *state)
{
	return state->certstack;
}

struct uri_list *
validation_rsync_visited_uris(struct validation *state)
{
	return state->rsync_visited_uris;
}

void
validation_pubkey_valid(struct validation *state)
{
	state->pubkey_state = PKS_VALID;
}

void
validation_pubkey_invalid(struct validation *state)
{
	state->pubkey_state = PKS_INVALID;
}

enum pubkey_state
validation_pubkey_state(struct validation *state)
{
	return state->pubkey_state;
}

char *
validation_get_ip_buffer1(struct validation *state)
{
	return state->addr_buffer1;
}

char *
validation_get_ip_buffer2(struct validation *state)
{
	return state->addr_buffer2;
}

struct validation_handler const *
validation_get_validation_handler(struct validation *state)
{
	return &state->validation_handler;
}

struct db_rrdp_uri *
validation_get_rrdp_uris(struct validation *state)
{
	return state->rrdp_uris;
}

char const *
validation_get_rrdp_workspace(struct validation *state)
{
	return state->rrdp_workspace;
}
