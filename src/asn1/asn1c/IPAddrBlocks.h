/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "IPAddrAndASCertExtn"
 * 	found in "rfc3779.asn1"
 * 	`asn1c -Werror -fcompound-names -fwide-types -D asn1/asn1c -no-gen-PER -no-gen-example`
 */

#ifndef	_IPAddrBlocks_H_
#define	_IPAddrBlocks_H_


#include "asn1/asn1c/asn_application.h"

/* Including external dependencies */
#include "asn1/asn1c/asn_SEQUENCE_OF.h"
#include "asn1/asn1c/constr_SEQUENCE_OF.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct IPAddressFamily;

/* IPAddrBlocks */
typedef struct IPAddrBlocks {
	A_SEQUENCE_OF(struct IPAddressFamily) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} IPAddrBlocks_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_IPAddrBlocks;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "IPAddressFamily.h"

#endif	/* _IPAddrBlocks_H_ */
#include "asn1/asn1c/asn_internal.h"
