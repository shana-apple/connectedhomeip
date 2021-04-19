/*
 *
 *    Copyright (c) 2020-2021 Project CHIP Authors
 *    Copyright (c) 2019 Google LLC.
 *    Copyright (c) 2016-2017 Nest Labs, Inc.
 *    All rights reserved.
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

/**
 *    @file
 *      This file contains definitions of test certificates used by various unit tests.
 *
 */

#pragma once

#include <asn1/ASN1OID.h>
#include <core/CHIPConfig.h>
#include <support/BitFlags.h>
#include <support/CodeUtils.h>

namespace chip {
namespace TestCerts {

using namespace chip::Credentials;
using namespace chip::ASN1;

enum TestCert
{
    kNone      = 0,
    kRoot01    = 1,
    kRoot02    = 2,
    kICA01     = 3,
    kICA02     = 4,
    kICA01_1   = 5,
    kFWSign01  = 6,
    kNode01_01 = 7,
    kNode01_02 = 8,
    kNode02_01 = 9,
    kNode02_02 = 10,
    kNode02_03 = 11,
    kNode02_04 = 12,
};

// Special flags to alter how certificates are fetched/loaded.
enum class TestCertLoadFlags : uint8_t
{
    kDERForm               = 0x01,
    kSuppressIsCA          = 0x02,
    kSuppressKeyUsage      = 0x04,
    kSuppressKeyCertSign   = 0x08,
    kSetPathLenConstZero   = 0x10,
    kSetAppDefinedCertType = 0x20,
};

extern CHIP_ERROR GetTestCert(uint8_t certType, BitFlags<TestCertLoadFlags> certLoadFlags, const uint8_t *& certData,
                              uint32_t & certDataLen);
extern const char * GetTestCertName(uint8_t certType);
extern CHIP_ERROR LoadTestCert(ChipCertificateSet & certSet, uint8_t certType, BitFlags<TestCertLoadFlags> certLoadFlags,
                               BitFlags<CertDecodeFlags> decodeFlags);

extern const uint8_t gTestCerts[];
extern const size_t gNumTestCerts;

// ------------------------------ DECLARATIONS ----------------------------------------

extern const uint8_t sTestCert_Root01_Chip[];
extern const uint32_t sTestCert_Root01_Chip_Len;
extern const uint8_t sTestCert_Root01_DER[];
extern const uint32_t sTestCert_Root01_DER_Len;
extern const uint8_t sTestCert_Root01_PublicKey[];
extern const uint8_t sTestCert_Root01_PublicKey_Len;
extern const uint8_t sTestCert_Root01_PrivateKey[];
extern const uint8_t sTestCert_Root01_PrivateKey_Len;
extern const uint8_t sTestCert_Root01_SubjectKeyId[];
extern const uint8_t sTestCert_Root01_SubjectKeyId_Len;

extern const uint8_t sTestCert_Root02_Chip[];
extern const uint32_t sTestCert_Root02_Chip_Len;
extern const uint8_t sTestCert_Root02_DER[];
extern const uint32_t sTestCert_Root02_DER_Len;
extern const uint8_t sTestCert_Root02_PublicKey[];
extern const uint8_t sTestCert_Root02_PublicKey_Len;
extern const uint8_t sTestCert_Root02_PrivateKey[];
extern const uint8_t sTestCert_Root02_PrivateKey_Len;
extern const uint8_t sTestCert_Root02_SubjectKeyId[];
extern const uint8_t sTestCert_Root02_SubjectKeyId_Len;

extern const uint8_t sTestCert_ICA01_Chip[];
extern const uint32_t sTestCert_ICA01_Chip_Len;
extern const uint8_t sTestCert_ICA01_DER[];
extern const uint32_t sTestCert_ICA01_DER_Len;
extern const uint8_t sTestCert_ICA01_PublicKey[];
extern const uint8_t sTestCert_ICA01_PublicKey_Len;
extern const uint8_t sTestCert_ICA01_PrivateKey[];
extern const uint8_t sTestCert_ICA01_PrivateKey_Len;
extern const uint8_t sTestCert_ICA01_SubjectKeyId[];
extern const uint8_t sTestCert_ICA01_SubjectKeyId_Len;

extern const uint8_t sTestCert_ICA02_Chip[];
extern const uint32_t sTestCert_ICA02_Chip_Len;
extern const uint8_t sTestCert_ICA02_DER[];
extern const uint32_t sTestCert_ICA02_DER_Len;
extern const uint8_t sTestCert_ICA02_PublicKey[];
extern const uint8_t sTestCert_ICA02_PublicKey_Len;
extern const uint8_t sTestCert_ICA02_PrivateKey[];
extern const uint8_t sTestCert_ICA02_PrivateKey_Len;
extern const uint8_t sTestCert_ICA02_SubjectKeyId[];
extern const uint8_t sTestCert_ICA02_SubjectKeyId_Len;

extern const uint8_t sTestCert_ICA01_1_Chip[];
extern const uint32_t sTestCert_ICA01_1_Chip_Len;
extern const uint8_t sTestCert_ICA01_1_DER[];
extern const uint32_t sTestCert_ICA01_1_DER_Len;
extern const uint8_t sTestCert_ICA01_1_PublicKey[];
extern const uint8_t sTestCert_ICA01_1_PublicKey_Len;
extern const uint8_t sTestCert_ICA01_1_PrivateKey[];
extern const uint8_t sTestCert_ICA01_1_PrivateKey_Len;
extern const uint8_t sTestCert_ICA01_1_SubjectKeyId[];
extern const uint8_t sTestCert_ICA01_1_SubjectKeyId_Len;

extern const uint8_t sTestCert_FWSign01_Chip[];
extern const uint32_t sTestCert_FWSign01_Chip_Len;
extern const uint8_t sTestCert_FWSign01_DER[];
extern const uint32_t sTestCert_FWSign01_DER_Len;
extern const uint8_t sTestCert_FWSign01_PublicKey[];
extern const uint8_t sTestCert_FWSign01_PublicKey_Len;
extern const uint8_t sTestCert_FWSign01_PrivateKey[];
extern const uint8_t sTestCert_FWSign01_PrivateKey_Len;
extern const uint8_t sTestCert_FWSign01_SubjectKeyId[];
extern const uint8_t sTestCert_FWSign01_SubjectKeyId_Len;

extern const uint8_t sTestCert_Node01_01_Chip[];
extern const uint32_t sTestCert_Node01_01_Chip_Len;
extern const uint8_t sTestCert_Node01_01_DER[];
extern const uint32_t sTestCert_Node01_01_DER_Len;
extern const uint8_t sTestCert_Node01_01_PublicKey[];
extern const uint8_t sTestCert_Node01_01_PublicKey_Len;
extern const uint8_t sTestCert_Node01_01_PrivateKey[];
extern const uint8_t sTestCert_Node01_01_PrivateKey_Len;
extern const uint8_t sTestCert_Node01_01_SubjectKeyId[];
extern const uint8_t sTestCert_Node01_01_SubjectKeyId_Len;

extern const uint8_t sTestCert_Node01_02_Chip[];
extern const uint32_t sTestCert_Node01_02_Chip_Len;
extern const uint8_t sTestCert_Node01_02_DER[];
extern const uint32_t sTestCert_Node01_02_DER_Len;
extern const uint8_t sTestCert_Node01_02_PublicKey[];
extern const uint8_t sTestCert_Node01_02_PublicKey_Len;
extern const uint8_t sTestCert_Node01_02_PrivateKey[];
extern const uint8_t sTestCert_Node01_02_PrivateKey_Len;
extern const uint8_t sTestCert_Node01_02_SubjectKeyId[];
extern const uint8_t sTestCert_Node01_02_SubjectKeyId_Len;

extern const uint8_t sTestCert_Node02_01_Chip[];
extern const uint32_t sTestCert_Node02_01_Chip_Len;
extern const uint8_t sTestCert_Node02_01_DER[];
extern const uint32_t sTestCert_Node02_01_DER_Len;
extern const uint8_t sTestCert_Node02_01_PublicKey[];
extern const uint8_t sTestCert_Node02_01_PublicKey_Len;
extern const uint8_t sTestCert_Node02_01_PrivateKey[];
extern const uint8_t sTestCert_Node02_01_PrivateKey_Len;
extern const uint8_t sTestCert_Node02_01_SubjectKeyId[];
extern const uint8_t sTestCert_Node02_01_SubjectKeyId_Len;

extern const uint8_t sTestCert_Node02_02_Chip[];
extern const uint32_t sTestCert_Node02_02_Chip_Len;
extern const uint8_t sTestCert_Node02_02_DER[];
extern const uint32_t sTestCert_Node02_02_DER_Len;
extern const uint8_t sTestCert_Node02_02_PublicKey[];
extern const uint8_t sTestCert_Node02_02_PublicKey_Len;
extern const uint8_t sTestCert_Node02_02_PrivateKey[];
extern const uint8_t sTestCert_Node02_02_PrivateKey_Len;
extern const uint8_t sTestCert_Node02_02_SubjectKeyId[];
extern const uint8_t sTestCert_Node02_02_SubjectKeyId_Len;

extern const uint8_t sTestCert_Node02_03_Chip[];
extern const uint32_t sTestCert_Node02_03_Chip_Len;
extern const uint8_t sTestCert_Node02_03_DER[];
extern const uint32_t sTestCert_Node02_03_DER_Len;
extern const uint8_t sTestCert_Node02_03_PublicKey[];
extern const uint8_t sTestCert_Node02_03_PublicKey_Len;
extern const uint8_t sTestCert_Node02_03_PrivateKey[];
extern const uint8_t sTestCert_Node02_03_PrivateKey_Len;
extern const uint8_t sTestCert_Node02_03_SubjectKeyId[];
extern const uint8_t sTestCert_Node02_03_SubjectKeyId_Len;

extern const uint8_t sTestCert_Node02_04_Chip[];
extern const uint32_t sTestCert_Node02_04_Chip_Len;
extern const uint8_t sTestCert_Node02_04_DER[];
extern const uint32_t sTestCert_Node02_04_DER_Len;
extern const uint8_t sTestCert_Node02_04_PublicKey[];
extern const uint8_t sTestCert_Node02_04_PublicKey_Len;
extern const uint8_t sTestCert_Node02_04_PrivateKey[];
extern const uint8_t sTestCert_Node02_04_PrivateKey_Len;
extern const uint8_t sTestCert_Node02_04_SubjectKeyId[];
extern const uint8_t sTestCert_Node02_04_SubjectKeyId_Len;

} // namespace TestCerts
} // namespace chip
