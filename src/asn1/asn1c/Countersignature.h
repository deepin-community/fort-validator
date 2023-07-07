/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "CryptographicMessageSyntax2004"
 * 	found in "rfc5652-12.1.asn1"
 * 	`asn1c -Werror -fcompound-names -fwide-types -D asn1/asn1c -no-gen-PER -no-gen-example`
 */

#ifndef	_Countersignature_H_
#define	_Countersignature_H_


#include "asn1/asn1c/asn_application.h"

/* Including external dependencies */
#include "SignerInfo.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Countersignature */
typedef SignerInfo_t	 Countersignature_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_Countersignature;
asn_struct_free_f Countersignature_free;
asn_struct_print_f Countersignature_print;
asn_constr_check_f Countersignature_constraint;
ber_type_decoder_f Countersignature_decode_ber;
der_type_encoder_f Countersignature_encode_der;
xer_type_decoder_f Countersignature_decode_xer;
xer_type_encoder_f Countersignature_encode_xer;
oer_type_decoder_f Countersignature_decode_oer;
oer_type_encoder_f Countersignature_encode_oer;

#ifdef __cplusplus
}
#endif

#endif	/* _Countersignature_H_ */
#include "asn1/asn1c/asn_internal.h"