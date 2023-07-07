/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "RPKI-ROA"
 * 	found in "rfc6482.asn1"
 * 	`asn1c -Werror -fcompound-names -fwide-types -D asn1/asn1c -no-gen-PER -no-gen-example`
 */

#include "RouteOriginAttestation.h"

static int
memb_ipAddrBlocks_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size >= 1)) {
		/* Perform validation of the inner elements */
		return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_type_ipAddrBlocks_constr_4 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..MAX)) */};
static asn_oer_constraints_t asn_OER_memb_ipAddrBlocks_constr_4 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(1..MAX)) */};
static int asn_DFL_2_cmp_0(const void *sptr) {
	const INTEGER_t *st = sptr;
	
	if(!st) {
		return -1; /* No value is not a default value */
	}
	
	/* Test default value 0 */
	long value;
	if(asn_INTEGER2long(st, &value))
		return -1;
	return (value != 0);
}
static int asn_DFL_2_set_0(void **sptr) {
	INTEGER_t *st = *sptr;
	
	if(!st) {
		st = (*sptr = CALLOC(1, sizeof(*st)));
		if(!st) return -1;
	}
	
	/* Install default value 0 */
	return asn_long2INTEGER(st, 0);
}
static asn_TYPE_member_t asn_MBR_ipAddrBlocks_4[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_ROAIPAddressFamily,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_ipAddrBlocks_tags_4[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_ipAddrBlocks_specs_4 = {
	sizeof(struct RouteOriginAttestation__ipAddrBlocks),
	offsetof(struct RouteOriginAttestation__ipAddrBlocks, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ipAddrBlocks_4 = {
	"ipAddrBlocks",
	"ipAddrBlocks",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_ipAddrBlocks_tags_4,
	sizeof(asn_DEF_ipAddrBlocks_tags_4)
		/sizeof(asn_DEF_ipAddrBlocks_tags_4[0]), /* 1 */
	asn_DEF_ipAddrBlocks_tags_4,	/* Same as above */
	sizeof(asn_DEF_ipAddrBlocks_tags_4)
		/sizeof(asn_DEF_ipAddrBlocks_tags_4[0]), /* 1 */
	{ &asn_OER_type_ipAddrBlocks_constr_4, 0, SEQUENCE_OF_constraint },
	asn_MBR_ipAddrBlocks_4,
	1,	/* Single element */
	&asn_SPC_ipAddrBlocks_specs_4	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_RouteOriginAttestation_1[] = {
	{ ATF_POINTER, 1, offsetof(struct RouteOriginAttestation, version),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_INTEGER,
		0,
		{ 0, 0, 0 },
		&asn_DFL_2_cmp_0,	/* Compare DEFAULT 0 */
		&asn_DFL_2_set_0,	/* Set DEFAULT 0 */
		"version"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RouteOriginAttestation, asID),
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_ASID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"asID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RouteOriginAttestation, ipAddrBlocks),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_ipAddrBlocks_4,
		0,
		{ &asn_OER_memb_ipAddrBlocks_constr_4, 0,  memb_ipAddrBlocks_constraint_1 },
		0, 0, /* No default value */
		"ipAddrBlocks"
		},
};
static const int asn_MAP_RouteOriginAttestation_oms_1[] = { 0 };
static const ber_tlv_tag_t asn_DEF_RouteOriginAttestation_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_RouteOriginAttestation_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 1, 0, 0 }, /* asID */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 2, 0, 0 }, /* ipAddrBlocks */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* version */
};
static asn_SEQUENCE_specifics_t asn_SPC_RouteOriginAttestation_specs_1 = {
	sizeof(struct RouteOriginAttestation),
	offsetof(struct RouteOriginAttestation, _asn_ctx),
	asn_MAP_RouteOriginAttestation_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_RouteOriginAttestation_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_RouteOriginAttestation = {
	"RouteOriginAttestation",
	"RouteOriginAttestation",
	&asn_OP_SEQUENCE,
	asn_DEF_RouteOriginAttestation_tags_1,
	sizeof(asn_DEF_RouteOriginAttestation_tags_1)
		/sizeof(asn_DEF_RouteOriginAttestation_tags_1[0]), /* 1 */
	asn_DEF_RouteOriginAttestation_tags_1,	/* Same as above */
	sizeof(asn_DEF_RouteOriginAttestation_tags_1)
		/sizeof(asn_DEF_RouteOriginAttestation_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_RouteOriginAttestation_1,
	3,	/* Elements count */
	&asn_SPC_RouteOriginAttestation_specs_1	/* Additional specs */
};

