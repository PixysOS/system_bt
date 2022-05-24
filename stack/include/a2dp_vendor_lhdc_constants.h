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
#ifndef A2DP_VENDOR_LHDC_CONSTANTS_H
#define A2DP_VENDOR_LHDC_CONSTANTS_H

//
// A2DP constants for LHDC codecs
//

// Length of the LHDC Media Payload header
#define A2DP_LHDC_MPL_HDR_LEN 2
#define A2DP_LHDC_HDR_NUM_SHIFT 2

// LHDC codec specific settings
#define A2DP_LHDCV5_CODEC_LEN 13
// [Octet 0-3] Vendor ID
#define A2DP_LHDC_VENDOR_ID (0x0000053A)
// [Octet 4-5] Vendor Specific Codec ID
#define A2DP_LHDCV5_CODEC_ID (0x4C35)

// LHDC Audio Quality mode Mask
#define A2DP_LHDC_VENDOR_CMD_MASK     (0xC000)
#define A2DP_LHDC_QUALITY_MAGIC_NUM   (0x8000)

/* index for A2DP codec configs */
#define A2DP_LHDC_TO_A2DP_CODEC_CONFIG_         (0x1ULL)   //codec_config_
#define A2DP_LHDC_TO_A2DP_CODEC_CAP_            (0x2ULL)   //codec_capability_
#define A2DP_LHDC_TO_A2DP_CODEC_LOCAL_CAP_      (0x4ULL)   //codec_local_capability_
#define A2DP_LHDC_TO_A2DP_CODEC_SELECT_CAP_     (0x8ULL)   //codec_selectable_capability_
#define A2DP_LHDC_TO_A2DP_CODEC_USER_           (0x10ULL)  //codec_user_config_
#define A2DP_LHDC_TO_A2DP_CODEC_AUDIO_          (0x20ULL)  //codec_audio_config_

// index of codec config specifics:
#define LHDC_FEATURE_ON_A2DP_SPECIFIC_1    (0x00)
#define LHDC_FEATURE_ON_A2DP_SPECIFIC_2    (0x40)
#define LHDC_FEATURE_ON_A2DP_SPECIFIC_3    (0x80)
#define LHDC_FEATURE_ON_A2DP_SPECIFIC_4    (0xC0)

#define LHDC_SETUP_A2DP_SPEC(cfg, spec, has, value)  do{   \
  if( spec == LHDC_FEATURE_ON_A2DP_SPECIFIC_1 ) \
    (has) ? (cfg->codec_specific_1 |= value) : (cfg->codec_specific_1 &= ~value);   \
  if( spec == LHDC_FEATURE_ON_A2DP_SPECIFIC_2 ) \
    (has) ? (cfg->codec_specific_2 |= value) : (cfg->codec_specific_2 &= ~value);   \
  if( spec == LHDC_FEATURE_ON_A2DP_SPECIFIC_3 ) \
    (has) ? (cfg->codec_specific_3 |= value) : (cfg->codec_specific_3 &= ~value);   \
  if( spec == LHDC_FEATURE_ON_A2DP_SPECIFIC_4 ) \
    (has) ? (cfg->codec_specific_4 |= value) : (cfg->codec_specific_4 &= ~value);   \
} while(0)

#define LHDC_CHECK_IN_A2DP_SPEC(cfg, spec, value)  ({ \
  bool marco_ret = false; \
  do{   \
    if( spec == LHDC_FEATURE_ON_A2DP_SPECIFIC_1 ) \
      marco_ret = (cfg->codec_specific_1 & value);   \
    if( spec == LHDC_FEATURE_ON_A2DP_SPECIFIC_2 ) \
      marco_ret = (cfg->codec_specific_2 & value);   \
    if( spec == LHDC_FEATURE_ON_A2DP_SPECIFIC_3 ) \
      marco_ret = (cfg->codec_specific_3 & value);   \
    if( spec == LHDC_FEATURE_ON_A2DP_SPECIFIC_4 ) \
      marco_ret = (cfg->codec_specific_4 & value);   \
    } while(0);  \
  marco_ret;   \
})

#endif  // A2DP_VENDOR_LHDC_CONSTANTS_H
