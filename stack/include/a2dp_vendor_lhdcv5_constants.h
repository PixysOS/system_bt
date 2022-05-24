/*
 * Copyright (C) 2016 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//
// A2DP constants for LHDC codec
//

#ifndef A2DP_VENDOR_LHDCV5_CONSTANTS_H
#define A2DP_VENDOR_LHDCV5_CONSTANTS_H

////////////////////////////////////////////////////////////////////
// LHDCV5 codec info format:
// Total Length: A2DP_LHDCV5_CODEC_LEN + 1(losc)
//  ----------------------------------------------------------------
//  H0   |    H1     |    H2     |  P0-P3   | P4-P5   | P6[5:0]  |
//  losc | mediaType | codecType | vendorId | codecId | SampRate |
//  ----------------------------------------------------------------
//  P7[2:0]   | P7[5:4]    | P7[7:6]       | P8[3:0] | P8[4]       |
//  bit depth | MaxBitRate | MinBitRate    | Version | FrameLen5ms |
//  ----------------------------------------------------------------
//  P9[0:5]   | P9[6]         | P9[7]    | P10[0:7] |
//  Reserved  | LowLatenyMode | Reserved | Reserved |
//  ----------------------------------------------------------------

// P0-P3 Vendor ID: (0x0000053a)
// P4-P5 Vendor Specific Codec ID: (0x4C35)
// P6[5:0] Sampling Frequency
#define A2DP_LHDCV5_SAMPLING_FREQ_MASK    (0x35)
#define A2DP_LHDCV5_SAMPLING_FREQ_44100   (0x20)
#define A2DP_LHDCV5_SAMPLING_FREQ_48000   (0x10)
#define A2DP_LHDCV5_SAMPLING_FREQ_96000   (0x04)
#define A2DP_LHDCV5_SAMPLING_FREQ_192000  (0x01)
#define A2DP_LHDCV5_SAMPLING_FREQ_NS      (0x00)

// P7[2:0] Bit depth
#define A2DP_LHDCV5_BIT_FMT_MASK  (0x07)
#define A2DP_LHDCV5_BIT_FMT_16    (0x04)
#define A2DP_LHDCV5_BIT_FMT_24    (0x02)
#define A2DP_LHDCV5_BIT_FMT_32    (0x01)
#define A2DP_LHDCV5_BIT_FMT_NS    (0x00)

// P7[5:4] Max Bit Rate Type
#define A2DP_LHDCV5_MAX_BIT_RATE_MASK   (0x30)
#define A2DP_LHDCV5_MAX_BIT_RATE_900K   (0x30)
#define A2DP_LHDCV5_MAX_BIT_RATE_500K   (0x20)
#define A2DP_LHDCV5_MAX_BIT_RATE_400K   (0x10)
#define A2DP_LHDCV5_MAX_BIT_RATE_1000K  (0x00)

// P7[7:6] Min Bit Rate Type
#define A2DP_LHDCV5_MIN_BIT_RATE_MASK   (0xC0)
#define A2DP_LHDCV5_MIN_BIT_RATE_400K   (0xC0)
#define A2DP_LHDCV5_MIN_BIT_RATE_256K   (0x80)
#define A2DP_LHDCV5_MIN_BIT_RATE_128K   (0x40)
#define A2DP_LHDCV5_MIN_BIT_RATE_64K    (0x00)

// P8[3:0] Codec SubVersion (bitmap)
#define A2DP_LHDCV5_VERSION_MASK    (0x0F)
#define A2DP_LHDCV5_VER_1           (0x01)
#define A2DP_LHDCV5_VER_NS          (0x00)

// P8[5:4] Frame Length Type
#define A2DP_LHDCV5_FRAME_LEN_MASK  (0x10)
#define A2DP_LHDCV5_FRAME_LEN_5MS   (0x10)
#define A2DP_LHDCV5_FRAME_LEN_NS    (0x00)

// P9[6] HasLowLatency
#define A2DP_LHDCV5_FEATURE_MASK      (0xC7)
#define A2DP_LHDCV5_FEATURE_LL        (0x40)

////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
//  attributes which not in codec info format
//    channel mode
//    channel separation mode
////////////////////////////////////////////////////////////////////
// channel mode:
#define A2DP_LHDCV5_CHANNEL_MODE_MASK   (0x07)
#define A2DP_LHDCV5_CHANNEL_MODE_MONO   (0x04)
#define A2DP_LHDCV5_CHANNEL_MODE_DUAL   (0x02)
#define A2DP_LHDCV5_CHANNEL_MODE_STEREO (0x01)
#define A2DP_LHDCV5_CHANNEL_MODE_NS     (0x00)

// LHDC Quality Mode Index
#define A2DP_LHDCV5_QUALITY_MASK   (0x0F)
#define A2DP_LHDCV5_QUALITY_ABR    (0x09)  // Adaptive Bit Rate
#define A2DP_LHDCV5_QUALITY_HIGH1  (0x08)  // 1000kbps
#define A2DP_LHDCV5_QUALITY_HIGH   (0x07)  // 900kbps
#define A2DP_LHDCV5_QUALITY_MID    (0x06)  // 500kbps
#define A2DP_LHDCV5_QUALITY_LOW    (0x05)  // 400kbps
#define A2DP_LHDCV5_QUALITY_LOW4   (0x04)  // 320kbps
#define A2DP_LHDCV5_QUALITY_LOW3   (0x03)  // 256kbps
#define A2DP_LHDCV5_QUALITY_LOW2   (0x02)  // 192kbps
#define A2DP_LHDCV5_QUALITY_LOW1   (0x01)  // 128kbps
#define A2DP_LHDCV5_QUALITY_LOW0   (0x00)  // 64kbps
////////////////////////////////////////////////////////////////////

/************************************************
 * LHDC Feature Capabilities on A2DP specifics:
   * feature id:                          (1 byte)
   * target specific index:               (2 bits)
   * target bit index on a specific:      (decimal: 0~63)
************************************************/
// feature code:
#define LHDCV5_FEATURE_CODE_MASK     (0xFF)
#define LHDCV5_FEATURE_CODE_NA       (0x00)
#define LHDCV5_FEATURE_CODE_LL       (0x08)

// target bit index on the specific:
//  specific@1
#define LHDCV5_FEATURE_QM_SPEC_BIT_POS        (0x00)
//  specific@2
#define LHDCV5_FEATURE_LL_SPEC_BIT_POS        (0x00)
#define LHDCV5_FEATURE_MAX_SPEC_BIT_POS       (0x19)

#endif  // A2DP_VENDOR_LHDCV5_CONSTANTS_H
