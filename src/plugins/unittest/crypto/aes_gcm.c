/*
 * Copyright (c) 2019 Cisco and/or its affiliates.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* Test vectors published in GCM Specification */

#include <vppinfra/clib.h>
#include <vnet/crypto/crypto.h>
#include <unittest/crypto/crypto.h>

static u8 tc6_iv[] = {
  0x93, 0x13, 0x22, 0x5d, 0xf8, 0x84, 0x06, 0xe5,
  0x55, 0x90, 0x9c, 0x5a, 0xff, 0x52, 0x69, 0xaa,
  0x6a, 0x7a, 0x95, 0x38, 0x53, 0x4f, 0x7d, 0xa1,
  0xe4, 0xc3, 0x03, 0xd2, 0xa3, 0x18, 0xa7, 0x28,
  0xc3, 0xc0, 0xc9, 0x51, 0x56, 0x80, 0x95, 0x39,
  0xfc, 0xf0, 0xe2, 0x42, 0x9a, 0x6b, 0x52, 0x54,
  0x16, 0xae, 0xdb, 0xf5, 0xa0, 0xde, 0x6a, 0x57,
  0xa6, 0x37, 0xb3, 0x9b
};

static u8 tc6_plaintext[] = {
  0xd9, 0x31, 0x32, 0x25, 0xf8, 0x84, 0x06, 0xe5,
  0xa5, 0x59, 0x09, 0xc5, 0xaf, 0xf5, 0x26, 0x9a,
  0x86, 0xa7, 0xa9, 0x53, 0x15, 0x34, 0xf7, 0xda,
  0x2e, 0x4c, 0x30, 0x3d, 0x8a, 0x31, 0x8a, 0x72,
  0x1c, 0x3c, 0x0c, 0x95, 0x95, 0x68, 0x09, 0x53,
  0x2f, 0xcf, 0x0e, 0x24, 0x49, 0xa6, 0xb5, 0x25,
  0xb1, 0x6a, 0xed, 0xf5, 0xaa, 0x0d, 0xe6, 0x57,
  0xba, 0x63, 0x7b, 0x39,
};

static u8 tc6_key[] = {
  0xfe, 0xff, 0xe9, 0x92, 0x86, 0x65, 0x73, 0x1c,
  0x6d, 0x6a, 0x8f, 0x94, 0x67, 0x30, 0x83, 0x08
};

static u8 tc6_aad[] = {
  0xfe, 0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef,
  0xfe, 0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef,
  0xab, 0xad, 0xda, 0xd2
};

static u8 tc6_ciphertext[] = {
  0x8c, 0xe2, 0x49, 0x98, 0x62, 0x56, 0x15, 0xb6,
  0x03, 0xa0, 0x33, 0xac, 0xa1, 0x3f, 0xb8, 0x94,
  0xbe, 0x91, 0x12, 0xa5, 0xc3, 0xa2, 0x11, 0xa8,
  0xba, 0x26, 0x2a, 0x3c, 0xca, 0x7e, 0x2c, 0xa7,
  0x01, 0xe4, 0xa9, 0xa4, 0xfb, 0xa4, 0x3c, 0x90,
  0xcc, 0xdc, 0xb2, 0x81, 0xd4, 0x8c, 0x7c, 0x6f,
  0xd6, 0x28, 0x75, 0xd2, 0xac, 0xa4, 0x17, 0x03,
  0x4c, 0x34, 0xae, 0xe5
};

static u8 tc6_tag[] = {
  0x61, 0x9c, 0xc5, 0xae, 0xff, 0xfe, 0x0b, 0xfa,
  0x46, 0x2a, 0xf4, 0x3c, 0x16, 0x99, 0xd0, 0x50,
};

/* *INDENT-OFF* */
UNITTEST_REGISTER_CRYPTO_TEST (aes_gcm_tc6) = {
  .name = "128-GCM Spec. TC6",
  .alg = VNET_CRYPTO_ALG_AES_128_GCM,
  .iv = TEST_DATA (tc6_iv),
  .key = TEST_DATA (tc6_key),
  .plaintext = TEST_DATA (tc6_plaintext),
  .ciphertext = TEST_DATA (tc6_ciphertext),
  .tag = TEST_DATA (tc6_tag),
  .aad = TEST_DATA (tc6_aad),
};

/* *INDENT-ON* */

static u8 tc5_iv[] = {
  0xca, 0xfe, 0xba, 0xbe, 0xfa, 0xce, 0xdb, 0xad
};

static u8 tc5_ciphertext[] = {
  0x61, 0x35, 0x3b, 0x4c, 0x28, 0x06, 0x93, 0x4a,
  0x77, 0x7f, 0xf5, 0x1f, 0xa2, 0x2a, 0x47, 0x55,
  0x69, 0x9b, 0x2a, 0x71, 0x4f, 0xcd, 0xc6, 0xf8,
  0x37, 0x66, 0xe5, 0xf9, 0x7b, 0x6c, 0x74, 0x23,
  0x73, 0x80, 0x69, 0x00, 0xe4, 0x9f, 0x24, 0xb2,
  0x2b, 0x09, 0x75, 0x44, 0xd4, 0x89, 0x6b, 0x42,
  0x49, 0x89, 0xb5, 0xe1, 0xeb, 0xac, 0x0f, 0x07,
  0xc2, 0x3f, 0x45, 0x98
};

static u8 tc5_tag[] = {
  0x36, 0x12, 0xd2, 0xe7, 0x9e, 0x3b, 0x07, 0x85,
  0x56, 0x1b, 0xe1, 0x4a, 0xac, 0xa2, 0xfc, 0xcb
};

/* *INDENT-OFF* */
UNITTEST_REGISTER_CRYPTO_TEST (aes_gcm_tc5) = {
  .name = "128-GCM Spec. TC5",
  .alg = VNET_CRYPTO_ALG_AES_128_GCM,
  .iv = TEST_DATA (tc5_iv),
  .key = TEST_DATA (tc6_key),
  .plaintext = TEST_DATA (tc6_plaintext),
  .ciphertext = TEST_DATA (tc5_ciphertext),
  .tag = TEST_DATA (tc5_tag),
  .aad = TEST_DATA (tc6_aad),
};
/* *INDENT-ON* */

static u8 tc4_iv[] = {
  0xca, 0xfe, 0xba, 0xbe, 0xfa, 0xce, 0xdb, 0xad,
  0xde, 0xca, 0xf8, 0x88
};

static u8 tc4_ciphertext[] = {
  0x42, 0x83, 0x1e, 0xc2, 0x21, 0x77, 0x74, 0x24,
  0x4b, 0x72, 0x21, 0xb7, 0x84, 0xd0, 0xd4, 0x9c,
  0xe3, 0xaa, 0x21, 0x2f, 0x2c, 0x02, 0xa4, 0xe0,
  0x35, 0xc1, 0x7e, 0x23, 0x29, 0xac, 0xa1, 0x2e,
  0x21, 0xd5, 0x14, 0xb2, 0x54, 0x66, 0x93, 0x1c,
  0x7d, 0x8f, 0x6a, 0x5a, 0xac, 0x84, 0xaa, 0x05,
  0x1b, 0xa3, 0x0b, 0x39, 0x6a, 0x0a, 0xac, 0x97,
  0x3d, 0x58, 0xe0, 0x91
};

static u8 tc4_tag[] = {
  0x5b, 0xc9, 0x4f, 0xbc, 0x32, 0x21, 0xa5, 0xdb,
  0x94, 0xfa, 0xe9, 0x5a, 0xe7, 0x12, 0x1a, 0x47
};

/* *INDENT-OFF* */
UNITTEST_REGISTER_CRYPTO_TEST (aes_gcm_tc4) = {
  .name = "128-GCM Spec. TC4",
  .alg = VNET_CRYPTO_ALG_AES_128_GCM,
  .iv = TEST_DATA (tc4_iv),
  .key = TEST_DATA (tc6_key),
  .plaintext = TEST_DATA (tc6_plaintext),
  .ciphertext = TEST_DATA (tc4_ciphertext),
  .tag = TEST_DATA (tc4_tag),
  .aad = TEST_DATA (tc6_aad),
};
/* *INDENT-ON* */

static u8 tc3_plaintext[] = {
  0xd9, 0x31, 0x32, 0x25, 0xf8, 0x84, 0x06, 0xe5,
  0xa5, 0x59, 0x09, 0xc5, 0xaf, 0xf5, 0x26, 0x9a,
  0x86, 0xa7, 0xa9, 0x53, 0x15, 0x34, 0xf7, 0xda,
  0x2e, 0x4c, 0x30, 0x3d, 0x8a, 0x31, 0x8a, 0x72,
  0x1c, 0x3c, 0x0c, 0x95, 0x95, 0x68, 0x09, 0x53,
  0x2f, 0xcf, 0x0e, 0x24, 0x49, 0xa6, 0xb5, 0x25,
  0xb1, 0x6a, 0xed, 0xf5, 0xaa, 0x0d, 0xe6, 0x57,
  0xba, 0x63, 0x7b, 0x39, 0x1a, 0xaf, 0xd2, 0x55
};

static u8 tc3_ciphertext[] = {
  0x42, 0x83, 0x1e, 0xc2, 0x21, 0x77, 0x74, 0x24,
  0x4b, 0x72, 0x21, 0xb7, 0x84, 0xd0, 0xd4, 0x9c,
  0xe3, 0xaa, 0x21, 0x2f, 0x2c, 0x02, 0xa4, 0xe0,
  0x35, 0xc1, 0x7e, 0x23, 0x29, 0xac, 0xa1, 0x2e,
  0x21, 0xd5, 0x14, 0xb2, 0x54, 0x66, 0x93, 0x1c,
  0x7d, 0x8f, 0x6a, 0x5a, 0xac, 0x84, 0xaa, 0x05,
  0x1b, 0xa3, 0x0b, 0x39, 0x6a, 0x0a, 0xac, 0x97,
  0x3d, 0x58, 0xe0, 0x91, 0x47, 0x3f, 0x59, 0x85
};

static u8 tc3_tag[] = {
  0x4d, 0x5c, 0x2a, 0xf3, 0x27, 0xcd, 0x64, 0xa6,
  0x2c, 0xf3, 0x5a, 0xbd, 0x2b, 0xa6, 0xfa, 0xb4
};

/* *INDENT-OFF* */
UNITTEST_REGISTER_CRYPTO_TEST (aes_gcm_tc3) = {
  .name = "128-GCM Spec. TC3",
  .alg = VNET_CRYPTO_ALG_AES_128_GCM,
  .iv = TEST_DATA (tc4_iv),
  .key = TEST_DATA (tc6_key),
  .plaintext = TEST_DATA (tc3_plaintext),
  .ciphertext = TEST_DATA (tc3_ciphertext),
  .tag = TEST_DATA (tc3_tag),
};
/* *INDENT-ON* */

static u8 tc2_key[16] = { 0, };
static u8 tc2_iv[12] = { 0, };
static u8 tc2_plaintext[16] = { 0, };

static u8 tc2_tag[] = {
  0xab, 0x6e, 0x47, 0xd4, 0x2c, 0xec, 0x13, 0xbd,
  0xf5, 0x3a, 0x67, 0xb2, 0x12, 0x57, 0xbd, 0xdf
};

static u8 tc2_ciphertext[] = {
  0x03, 0x88, 0xda, 0xce, 0x60, 0xb6, 0xa3, 0x92,
  0xf3, 0x28, 0xc2, 0xb9, 0x71, 0xb2, 0xfe, 0x78
};

/* *INDENT-OFF* */
UNITTEST_REGISTER_CRYPTO_TEST (aes_gcm_tc2) = {
  .name = "128-GCM Spec. TC2",
  .alg = VNET_CRYPTO_ALG_AES_128_GCM,
  .iv = TEST_DATA (tc2_iv),
  .key = TEST_DATA (tc2_key),
  .plaintext = TEST_DATA (tc2_plaintext),
  .ciphertext = TEST_DATA (tc2_ciphertext),
  .tag = TEST_DATA (tc2_tag),
};
/* *INDENT-ON* */

static u8 tc1_tag[] = {
  0x58, 0xe2, 0xfc, 0xce, 0xfa, 0x7e, 0x30, 0x61,
  0x36, 0x7f, 0x1d, 0x57, 0xa4, 0xe7, 0x45, 0x5a
};

/* *INDENT-OFF* */
UNITTEST_REGISTER_CRYPTO_TEST (aes_gcm_tc1) = {
  .name = "128-GCM Spec. TC1",
  .alg = VNET_CRYPTO_ALG_AES_128_GCM,
  .iv = TEST_DATA (tc2_iv),
  .key = TEST_DATA (tc2_key),
  .tag = TEST_DATA (tc1_tag),
};
/* *INDENT-ON* */

static u8 tc1_256_key[32] = { 0, };

static u8 tc1_256_tag[] = {
  0x53, 0x0f, 0x8a, 0xfb, 0xc7, 0x45, 0x36, 0xb9,
  0xa9, 0x63, 0xb4, 0xf1, 0xc4, 0xcb, 0x73, 0x8b,
};

/* *INDENT-OFF* */
UNITTEST_REGISTER_CRYPTO_TEST (aes_gcm256_tc1) = {
  .name = "256-GCM Spec. TC1",
  .alg = VNET_CRYPTO_ALG_AES_256_GCM,
  .key = TEST_DATA (tc1_256_key),
  .iv = TEST_DATA (tc2_iv),
  .tag = TEST_DATA (tc1_256_tag),
};
/* *INDENT-ON* */

static u8 tc2_256_ciphertext[] = {
  0xce, 0xa7, 0x40, 0x3d, 0x4d, 0x60, 0x6b, 0x6e,
  0x07, 0x4e, 0xc5, 0xd3, 0xba, 0xf3, 0x9d, 0x18
};

static u8 tc2_256_tag[] = {
  0xd0, 0xd1, 0xc8, 0xa7, 0x99, 0x99, 0x6b, 0xf0,
  0x26, 0x5b, 0x98, 0xb5, 0xd4, 0x8a, 0xb9, 0x19
};

/* *INDENT-OFF* */
UNITTEST_REGISTER_CRYPTO_TEST (aes_gcm256_tc2) = {
  .name = "256-GCM Spec. TC2",
  .alg = VNET_CRYPTO_ALG_AES_256_GCM,
  .key = TEST_DATA (tc1_256_key),
  .iv = TEST_DATA (tc2_iv),
  .plaintext = TEST_DATA(tc2_plaintext),
  .ciphertext = TEST_DATA(tc2_256_ciphertext),
  .tag = TEST_DATA (tc2_256_tag),
};
/* *INDENT-ON* */

static u8 tc3_256_key[] = {
  0xfe, 0xff, 0xe9, 0x92, 0x86, 0x65, 0x73, 0x1c,
  0x6d, 0x6a, 0x8f, 0x94, 0x67, 0x30, 0x83, 0x08,
  0xfe, 0xff, 0xe9, 0x92, 0x86, 0x65, 0x73, 0x1c,
  0x6d, 0x6a, 0x8f, 0x94, 0x67, 0x30, 0x83, 0x08
};

static u8 tc3_256_ciphertext[] = {
  0x52, 0x2d, 0xc1, 0xf0, 0x99, 0x56, 0x7d, 0x07,
  0xf4, 0x7f, 0x37, 0xa3, 0x2a, 0x84, 0x42, 0x7d,
  0x64, 0x3a, 0x8c, 0xdc, 0xbf, 0xe5, 0xc0, 0xc9,
  0x75, 0x98, 0xa2, 0xbd, 0x25, 0x55, 0xd1, 0xaa,
  0x8c, 0xb0, 0x8e, 0x48, 0x59, 0x0d, 0xbb, 0x3d,
  0xa7, 0xb0, 0x8b, 0x10, 0x56, 0x82, 0x88, 0x38,
  0xc5, 0xf6, 0x1e, 0x63, 0x93, 0xba, 0x7a, 0x0a,
  0xbc, 0xc9, 0xf6, 0x62, 0x89, 0x80, 0x15, 0xad
};

static u8 tc3_256_tag[] = {
  0xb0, 0x94, 0xda, 0xc5, 0xd9, 0x34, 0x71, 0xbd,
  0xec, 0x1a, 0x50, 0x22, 0x70, 0xe3, 0xcc, 0x6c
};

/* *INDENT-OFF* */
UNITTEST_REGISTER_CRYPTO_TEST (aes_gcm256_tc3) = {
  .name = "256-GCM Spec. TC3",
  .alg = VNET_CRYPTO_ALG_AES_256_GCM,
  .key = TEST_DATA (tc3_256_key),
  .iv = TEST_DATA (tc4_iv),
  .plaintext = TEST_DATA(tc3_plaintext),
  .ciphertext = TEST_DATA(tc3_256_ciphertext),
  .tag = TEST_DATA (tc3_256_tag),
};
/* *INDENT-ON* */

static u8 tc4_256_ciphertext[] = {
  0x52, 0x2d, 0xc1, 0xf0, 0x99, 0x56, 0x7d, 0x07,
  0xf4, 0x7f, 0x37, 0xa3, 0x2a, 0x84, 0x42, 0x7d,
  0x64, 0x3a, 0x8c, 0xdc, 0xbf, 0xe5, 0xc0, 0xc9,
  0x75, 0x98, 0xa2, 0xbd, 0x25, 0x55, 0xd1, 0xaa,
  0x8c, 0xb0, 0x8e, 0x48, 0x59, 0x0d, 0xbb, 0x3d,
  0xa7, 0xb0, 0x8b, 0x10, 0x56, 0x82, 0x88, 0x38,
  0xc5, 0xf6, 0x1e, 0x63, 0x93, 0xba, 0x7a, 0x0a,
  0xbc, 0xc9, 0xf6, 0x62
};

static u8 tc4_256_tag[] = {
  0x76, 0xfc, 0x6e, 0xce, 0x0f, 0x4e, 0x17, 0x68,
  0xcd, 0xdf, 0x88, 0x53, 0xbb, 0x2d, 0x55, 0x1b
};

/* *INDENT-OFF* */
UNITTEST_REGISTER_CRYPTO_TEST (aes_gcm256_tc4) = {
  .name = "256-GCM Spec. TC4",
  .alg = VNET_CRYPTO_ALG_AES_256_GCM,
  .key = TEST_DATA (tc3_256_key),
  .iv = TEST_DATA (tc4_iv),
  .plaintext = TEST_DATA(tc6_plaintext),
  .ciphertext = TEST_DATA(tc4_256_ciphertext),
  .aad = TEST_DATA(tc6_aad),
  .tag = TEST_DATA (tc4_256_tag),
};
/* *INDENT-ON* */

static u8 tc5_256_ciphertext[] = {
  0xc3, 0x76, 0x2d, 0xf1, 0xca, 0x78, 0x7d, 0x32,
  0xae, 0x47, 0xc1, 0x3b, 0xf1, 0x98, 0x44, 0xcb,
  0xaf, 0x1a, 0xe1, 0x4d, 0x0b, 0x97, 0x6a, 0xfa,
  0xc5, 0x2f, 0xf7, 0xd7, 0x9b, 0xba, 0x9d, 0xe0,
  0xfe, 0xb5, 0x82, 0xd3, 0x39, 0x34, 0xa4, 0xf0,
  0x95, 0x4c, 0xc2, 0x36, 0x3b, 0xc7, 0x3f, 0x78,
  0x62, 0xac, 0x43, 0x0e, 0x64, 0xab, 0xe4, 0x99,
  0xf4, 0x7c, 0x9b, 0x1f
};

static u8 tc5_256_tag[] = {
  0x3a, 0x33, 0x7d, 0xbf, 0x46, 0xa7, 0x92, 0xc4,
  0x5e, 0x45, 0x49, 0x13, 0xfe, 0x2e, 0xa8, 0xf2
};

/* *INDENT-OFF* */
UNITTEST_REGISTER_CRYPTO_TEST (aes_gcm256_tc5) = {
  .name = "256-GCM Spec. TC5",
  .alg = VNET_CRYPTO_ALG_AES_256_GCM,
  .key = TEST_DATA (tc3_256_key),
  .iv = TEST_DATA (tc5_iv),
  .plaintext = TEST_DATA(tc6_plaintext),
  .ciphertext = TEST_DATA(tc5_256_ciphertext),
  .aad = TEST_DATA(tc6_aad),
  .tag = TEST_DATA (tc5_256_tag),
};
/* *INDENT-ON* */

static u8 tc6_256_ciphertext[] = {
  0x5a, 0x8d, 0xef, 0x2f, 0x0c, 0x9e, 0x53, 0xf1,
  0xf7, 0x5d, 0x78, 0x53, 0x65, 0x9e, 0x2a, 0x20,
  0xee, 0xb2, 0xb2, 0x2a, 0xaf, 0xde, 0x64, 0x19,
  0xa0, 0x58, 0xab, 0x4f, 0x6f, 0x74, 0x6b, 0xf4,
  0x0f, 0xc0, 0xc3, 0xb7, 0x80, 0xf2, 0x44, 0x45,
  0x2d, 0xa3, 0xeb, 0xf1, 0xc5, 0xd8, 0x2c, 0xde,
  0xa2, 0x41, 0x89, 0x97, 0x20, 0x0e, 0xf8, 0x2e,
  0x44, 0xae, 0x7e, 0x3f
};

static u8 tc6_256_tag[] = {
  0xa4, 0x4a, 0x82, 0x66, 0xee, 0x1c, 0x8e, 0xb0,
  0xc8, 0xb5, 0xd4, 0xcf, 0x5a, 0xe9, 0xf1, 0x9a
};

/* *INDENT-OFF* */
UNITTEST_REGISTER_CRYPTO_TEST (aes_gcm256_tc6) = {
  .name = "256-GCM Spec. TC6",
  .alg = VNET_CRYPTO_ALG_AES_256_GCM,
  .key = TEST_DATA (tc3_256_key),
  .iv = TEST_DATA (tc6_iv),
  .plaintext = TEST_DATA(tc6_plaintext),
  .ciphertext = TEST_DATA(tc6_256_ciphertext),
  .aad = TEST_DATA(tc6_aad),
  .tag = TEST_DATA (tc6_256_tag),
};
/* *INDENT-ON* */

/*
 * fd.io coding-style-patch-verification: ON
 *
 * Local Variables:
 * eval: (c-set-style "gnu")
 * End:
 */
