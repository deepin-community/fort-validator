/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CryptographicMessageSyntax2004"
 * 	found in "rfc5652-12.1.asn1"
 * 	`asn1c -Werror -fcompound-names -fwide-types -D asn1/asn1c -no-gen-PER -no-gen-example`
 */

#include "SignedDataPKCS7.h"

static asn_TYPE_member_t asn_MBR_SignedDataPKCS7_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct SignedDataPKCS7, version),
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_CMSVersion,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"version"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct SignedDataPKCS7, digestAlgorithms),
		(ASN_TAG_CLASS_UNIVERSAL | (17 << 2)),
		0,
		&asn_DEF_DigestAlgorithmIdentifiers,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"digestAlgorithms"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct SignedDataPKCS7, encapContentInfo),
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_EncapsulatedContentInfoPKCS7,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"encapContentInfo"
		},
	{ ATF_POINTER, 2, offsetof(struct SignedDataPKCS7, certificates),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CertificateSet,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"certificates"
		},
	{ ATF_POINTER, 1, offsetof(struct SignedDataPKCS7, crls),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RevocationInfoChoices,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"crls"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct SignedDataPKCS7, signerInfos),
		(ASN_TAG_CLASS_UNIVERSAL | (17 << 2)),
		0,
		&asn_DEF_SignerInfos,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"signerInfos"
		},
};
static const int asn_MAP_SignedDataPKCS7_oms_1[] = { 3, 4 };
static const ber_tlv_tag_t asn_DEF_SignedDataPKCS7_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_SignedDataPKCS7_tag2el_1[] = {
    { (ASN_TAG_CLASS_UNIVERSAL | (2 << 2)), 0, 0, 0 }, /* version */
    { (ASN_TAG_CLASS_UNIVERSAL | (16 << 2)), 2, 0, 0 }, /* encapContentInfo */
    { (ASN_TAG_CLASS_UNIVERSAL | (17 << 2)), 1, 0, 1 }, /* digestAlgorithms */
    { (ASN_TAG_CLASS_UNIVERSAL | (17 << 2)), 5, -1, 0 }, /* signerInfos */
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 3, 0, 0 }, /* certificates */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 4, 0, 0 } /* crls */
};
static asn_SEQUENCE_specifics_t asn_SPC_SignedDataPKCS7_specs_1 = {
	sizeof(struct SignedDataPKCS7),
	offsetof(struct SignedDataPKCS7, _asn_ctx),
	asn_MAP_SignedDataPKCS7_tag2el_1,
	6,	/* Count of tags in the map */
	asn_MAP_SignedDataPKCS7_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_SignedDataPKCS7 = {
	"SignedDataPKCS7",
	"SignedDataPKCS7",
	&asn_OP_SEQUENCE,
	asn_DEF_SignedDataPKCS7_tags_1,
	sizeof(asn_DEF_SignedDataPKCS7_tags_1)
		/sizeof(asn_DEF_SignedDataPKCS7_tags_1[0]), /* 1 */
	asn_DEF_SignedDataPKCS7_tags_1,	/* Same as above */
	sizeof(asn_DEF_SignedDataPKCS7_tags_1)
		/sizeof(asn_DEF_SignedDataPKCS7_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_SignedDataPKCS7_1,
	6,	/* Elements count */
	&asn_SPC_SignedDataPKCS7_specs_1	/* Additional specs */
};
