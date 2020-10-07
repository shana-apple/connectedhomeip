/**
 *
 *    Copyright (c) 2020 Project CHIP Authors
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
 *
 *    Copyright (c) 2020 Silicon Labs
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
// This file is generated by Simplicity Studio.  Please do not edit manually.
//
//

// Enclosing macro to prevent multiple inclusion
#ifndef SILABS_ZNET_CONFIG
#define SILABS_ZNET_CONFIG

#include "debug-printing-test.h"

/**** Included Header Section ****/

// Networks
#define EM_AF_GENERATED_NETWORK_TYPES                                                                                              \
    {                                                                                                                              \
        EM_AF_NETWORK_TYPE_ZIGBEE_PRO, /* Primary */                                                                               \
    }
#define EM_AF_GENERATED_ZIGBEE_PRO_NETWORKS                                                                                        \
    {                                                                                                                              \
        {                                                                                                                          \
            /* Primary */                                                                                                          \
            ZA_ROUTER,                                                                                                             \
            EMBER_AF_SECURITY_PROFILE_Z3,                                                                                          \
        },                                                                                                                         \
    }
#define EM_AF_GENERATED_NETWORK_STRINGS "Primary (pro)", /**** ZCL Section ****/
#define ZA_PROMPT "CHIPv1Clusters"
#define ZCL_USING_BASIC_CLUSTER_CLIENT
#define ZCL_USING_BASIC_CLUSTER_SERVER
#define ZCL_USING_TEMP_MEASUREMENT_CLUSTER_CLIENT
#define ZCL_USING_TEMP_MEASUREMENT_CLUSTER_SERVER
#define EMBER_AF_MANUFACTURER_CODE 0x1002
#define EMBER_AF_DEFAULT_RESPONSE_POLICY_ALWAYS

/**** Cluster endpoint counts ****/
#define EMBER_AF_BASIC_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_BASIC_CLUSTER_SERVER_ENDPOINT_COUNT (1)
#define EMBER_AF_TEMP_MEASUREMENT_CLUSTER_CLIENT_ENDPOINT_COUNT (1)
#define EMBER_AF_TEMP_MEASUREMENT_CLUSTER_SERVER_ENDPOINT_COUNT (1)

/**** Cluster Endpoint Summaries ****/
#define EMBER_AF_MAX_SERVER_CLUSTER_COUNT (2)
#define EMBER_AF_MAX_CLIENT_CLUSTER_COUNT (2)
#define EMBER_AF_MAX_TOTAL_CLUSTER_COUNT (4)

/**** CLI Section ****/
#define EMBER_AF_GENERATE_CLI

/**** Security Section ****/
#define EMBER_AF_HAS_SECURITY_PROFILE_Z3

/**** Network Section ****/
#define EMBER_SUPPORTED_NETWORKS (1)
#define EMBER_AF_ZC_AND_ZR_DEVICE_COUNT (1)
#define EMBER_AF_NETWORK_INDEX_PRIMARY (0)
#define EMBER_AF_DEFAULT_NETWORK_INDEX EMBER_AF_NETWORK_INDEX_PRIMARY
#define EMBER_AF_HAS_ROUTER_NETWORK
#define EMBER_AF_HAS_RX_ON_WHEN_IDLE_NETWORK
#define EMBER_AF_TX_POWER_MODE EMBER_TX_POWER_MODE_USE_TOKEN

/**** Callback Section ****/
#define EMBER_CALLBACK_STACK_STATUS
#define EMBER_CALLBACK_TEMPERATURE_READING_COMPLETE
#define EMBER_CALLBACK_BASIC_CLUSTER_RESET_TO_FACTORY_DEFAULTS
/**** Debug printing section ****/

// Global switch
#define EMBER_AF_PRINT_ENABLE
// Individual areas

// Generated plugin macros

// Use this macro to check if Antenna Stub plugin is included
#define EMBER_AF_PLUGIN_ANTENNA_STUB

// Use this macro to check if Basic Server Cluster plugin is included
#define EMBER_AF_PLUGIN_BASIC

// Use this macro to check if Binding Table Library plugin is included
#define EMBER_AF_PLUGIN_BINDING_TABLE_LIBRARY
// User options for plugin Binding Table Library
#define EMBER_BINDING_TABLE_SIZE 10

// Use this macro to check if CCM* Encryption plugin is included
#define EMBER_AF_PLUGIN_CCM_ENCRYPTION
// User options for plugin CCM* Encryption
#define EMBER_AF_PLUGIN_CCM_ENCRYPTION_SOFTWARE_CCM
#define USE_SOFTWARE_CCM

// Use this macro to check if Radio Coexistence Stub plugin is included
#define EMBER_AF_PLUGIN_COEXISTENCE_STUB

// Use this macro to check if Ember Minimal Printf plugin is included
#define EMBER_AF_PLUGIN_EMBER_MINIMAL_PRINTF

// Use this macro to check if HAL Library plugin is included
#define EMBER_AF_PLUGIN_HAL_LIBRARY

// Use this macro to check if mbed TLS plugin is included
#define EMBER_AF_PLUGIN_MBEDTLS
// User options for plugin mbed TLS
#define EMBER_AF_PLUGIN_MBEDTLS_CONF_DEVICE_ACCELERATION
#define EMBER_AF_PLUGIN_MBEDTLS_CONF_DEVICE_ACCELERATION_APP

// Use this macro to check if Strong Random plugin is included
#define EMBER_AF_PLUGIN_STRONG_RANDOM
// User options for plugin Strong Random
#define EMBER_AF_PLUGIN_STRONG_RANDOM_RADIO_PRNG
#define USE_RADIO_API_FOR_TRNG

// Use this macro to check if Temperature Measurement Server Cluster plugin is included
#define EMBER_AF_PLUGIN_TEMPERATURE_MEASUREMENT_SERVER
// User options for plugin Temperature Measurement Server Cluster
#define EMBER_AF_PLUGIN_TEMPERATURE_MEASUREMENT_SERVER_MAX_MEASUREMENT_FREQUENCY_S 300
#define EMBER_AF_PLUGIN_TEMPERATURE_MEASUREMENT_SERVER_DEFAULT_REPORTABLE_TEMPERATURE_CHANGE_M_C 500
#define EMBER_AF_PLUGIN_TEMPERATURE_MEASUREMENT_SERVER_OVER_TEMPERATURE
#define EMBER_AF_PLUGIN_TEMPERATURE_MEASUREMENT_SERVER_OVER_TEMPERATURE_ASSERT_WARNING_THRESHOLD 55
#define EMBER_AF_PLUGIN_TEMPERATURE_MEASUREMENT_SERVER_OVER_TEMPERATURE_DEASSERT_WARNING_THRESHOLD 50
#define EMBER_AF_PLUGIN_TEMPERATURE_MEASUREMENT_SERVER_OVER_TEMPERATURE_ASSERT_CRITICAL_THRESHOLD 60
#define EMBER_AF_PLUGIN_TEMPERATURE_MEASUREMENT_SERVER_OVER_TEMPERATURE_DEASSERT_CRITICAL_THRESHOLD 55

// Use this macro to check if Temperature Si7053 Stub plugin is included
#define EMBER_AF_PLUGIN_TEMPERATURE_SI7053_STUB

// Use this macro to check if ZCL Framework Core plugin is included
#define EMBER_AF_PLUGIN_ZCL_FRAMEWORK_CORE
// User options for plugin ZCL Framework Core
#define EMBER_AF_PLUGIN_ZCL_FRAMEWORK_CORE_CLI_ENABLED
#define ZA_CLI_FULL

// Use this macro to check if ZigBee PRO Stack Library plugin is included
#define EMBER_AF_PLUGIN_ZIGBEE_PRO_LIBRARY
// User options for plugin ZigBee PRO Stack Library
#define EMBER_MAX_END_DEVICE_CHILDREN 6
#define EMBER_PACKET_BUFFER_COUNT 75
#define EMBER_END_DEVICE_KEEP_ALIVE_SUPPORT_MODE EMBER_KEEP_ALIVE_SUPPORT_ALL
#define EMBER_END_DEVICE_POLL_TIMEOUT MINUTES_256
#define EMBER_END_DEVICE_POLL_TIMEOUT_SHIFT 6
#define EMBER_LINK_POWER_DELTA_INTERVAL 300
#define EMBER_APS_UNICAST_MESSAGE_COUNT 10
#define EMBER_BROADCAST_TABLE_SIZE 15
#define EMBER_NEIGHBOR_TABLE_SIZE 16

// Generated API headers

// API antenna from Antenna Stub plugin
#define EMBER_AF_API_ANTENNA                                                                                                       \
    "../../../../../Applications/Simplicity "                                                                                      \
    "Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.0/platform/base/hal/plugin/antenna/antenna.h"

// API coexistence from Radio Coexistence Stub plugin
#define EMBER_AF_API_COEXISTENCE                                                                                                   \
    "../../../../../Applications/Simplicity "                                                                                      \
    "Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.0/platform/radio/rail_lib/plugin/coexistence/protocol/"         \
    "ieee802154/coexistence-802154.h"

// API temperature from Temperature Si7053 Stub plugin
#define EMBER_AF_API_TEMPERATURE                                                                                                   \
    "../../../../../Applications/Simplicity "                                                                                      \
    "Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.0/platform/base/hal/plugin/temperature/temperature.h"

// API command-interpreter2 from ZCL Framework Core plugin
#define EMBER_AF_API_COMMAND_INTERPRETER2                                                                                          \
    "../../../../../Applications/Simplicity "                                                                                      \
    "Studio.app/Contents/Eclipse/developer/sdks/gecko_sdk_suite/v3.0/protocol/zigbee/app/util/serial/command-interpreter2.h"

// Custom macros
#ifdef TRANSITION_TIME_DS
#undef TRANSITION_TIME_DS
#endif
#define TRANSITION_TIME_DS 20

#ifdef FINDING_AND_BINDING_DELAY_MS
#undef FINDING_AND_BINDING_DELAY_MS
#endif
#define FINDING_AND_BINDING_DELAY_MS 3000

#endif // SILABS_ZNET_CONFIG