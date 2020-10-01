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
#ifndef SILABS_AF_ENDPOINT_CONFIG
#define SILABS_AF_ENDPOINT_CONFIG

// Fixed number of defined endpoints
#define FIXED_ENDPOINT_COUNT (1)

// Generated attributes
#define GENERATED_ATTRIBUTES                                                                                                       \
    {                                                                                                                              \
        {                                                                                                                          \
            0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT | ATTRIBUTE_MASK_SINGLETON), { (uint8_t *) 0x0001 }       \
        }, /* 0 / Basic / cluster revision*/                                                                                       \
            {                                                                                                                      \
                0x0000, ZCL_INT8U_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_SINGLETON), { (uint8_t *) 0x03 }                              \
            }, /* 1 / Basic / ZCL version*/                                                                                        \
            {                                                                                                                      \
                0x0007, ZCL_ENUM8_ATTRIBUTE_TYPE, 1, (ATTRIBUTE_MASK_SINGLETON), { (uint8_t *) 0x00 }                              \
            }, /* 2 / Basic / power source*/                                                                                       \
            {                                                                                                                      \
                0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_SINGLETON), { (uint8_t *) 0x0001 }                           \
            }, /* 3 / Basic / cluster revision*/                                                                                   \
            {                                                                                                                      \
                0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (ATTRIBUTE_MASK_CLIENT), { (uint8_t *) 0x0001 }                              \
            }, /* 4 / Temperature Measurement / cluster revision*/                                                                 \
            {                                                                                                                      \
                0x0000, ZCL_INT16S_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t *) 0x0000 }                                               \
            }, /* 5 / Temperature Measurement / measured value*/                                                                   \
            {                                                                                                                      \
                0x0001, ZCL_INT16S_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t *) 0x0000L }                                              \
            }, /* 6 / Temperature Measurement / min measured value*/                                                               \
            {                                                                                                                      \
                0x0002, ZCL_INT16S_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t *) 0x0000L }                                              \
            }, /* 7 / Temperature Measurement / max measured value*/                                                               \
            {                                                                                                                      \
                0xFFFD, ZCL_INT16U_ATTRIBUTE_TYPE, 2, (0x00), { (uint8_t *) 0x0001 }                                               \
            }, /* 8 / Temperature Measurement / cluster revision*/                                                                 \
    }

// Cluster function static arrays
#define GENERATED_FUNCTION_ARRAYS

// Clusters definitions
#define GENERATED_CLUSTERS                                                                                                         \
    {                                                                                                                              \
        {                                                                                                                          \
            0x0000, (EmberAfAttributeMetadata *) &(generatedAttributes[0]), 1, 0, (CLUSTER_MASK_CLIENT), NULL,                     \
        },                                                                                                                         \
            {                                                                                                                      \
                0x0000, (EmberAfAttributeMetadata *) &(generatedAttributes[1]), 3, 0, (CLUSTER_MASK_SERVER), NULL,                 \
            },                                                                                                                     \
            {                                                                                                                      \
                0x0402, (EmberAfAttributeMetadata *) &(generatedAttributes[4]), 1, 2, (CLUSTER_MASK_CLIENT), NULL,                 \
            },                                                                                                                     \
            {                                                                                                                      \
                0x0402, (EmberAfAttributeMetadata *) &(generatedAttributes[5]), 4, 8, (CLUSTER_MASK_SERVER), NULL,                 \
            },                                                                                                                     \
    }

// Endpoint types
#define GENERATED_ENDPOINT_TYPES                                                                                                   \
    {                                                                                                                              \
        { (EmberAfCluster *) &(generatedClusters[0]), 4, 10 },                                                                     \
    }

// Cluster manufacturer codes
#define GENERATED_CLUSTER_MANUFACTURER_CODES                                                                                       \
    {                                                                                                                              \
        {                                                                                                                          \
            0x00, 0x00                                                                                                             \
        }                                                                                                                          \
    }
#define GENERATED_CLUSTER_MANUFACTURER_CODE_COUNT (0)

// Attribute manufacturer codes
#define GENERATED_ATTRIBUTE_MANUFACTURER_CODES                                                                                     \
    {                                                                                                                              \
        {                                                                                                                          \
            0x00, 0x00                                                                                                             \
        }                                                                                                                          \
    }
#define GENERATED_ATTRIBUTE_MANUFACTURER_CODE_COUNT (0)

// Largest attribute size is needed for various buffers
#define ATTRIBUTE_LARGEST (2)
// Total size of singleton attributes
#define ATTRIBUTE_SINGLETONS_SIZE (6)

// Total size of attribute storage
#define ATTRIBUTE_MAX_SIZE 10

// Array of endpoints that are supported
#define FIXED_ENDPOINT_ARRAY                                                                                                       \
    {                                                                                                                              \
        1                                                                                                                          \
    }

// Array of profile ids
#define FIXED_PROFILE_IDS                                                                                                          \
    {                                                                                                                              \
        65535                                                                                                                      \
    }

// Array of device ids
#define FIXED_DEVICE_IDS                                                                                                           \
    {                                                                                                                              \
        65535                                                                                                                      \
    }

// Array of device versions
#define FIXED_DEVICE_VERSIONS                                                                                                      \
    {                                                                                                                              \
        1                                                                                                                          \
    }

// Array of endpoint types supported on each endpoint
#define FIXED_ENDPOINT_TYPES                                                                                                       \
    {                                                                                                                              \
        0                                                                                                                          \
    }

// Array of networks supported on each endpoint
#define FIXED_NETWORKS                                                                                                             \
    {                                                                                                                              \
        0                                                                                                                          \
    }

#define EMBER_AF_GENERATED_PLUGIN_INIT_FUNCTION_DECLARATIONS void emberAfPluginTemperatureMeasurementServerInitCallback(void);

#define EMBER_AF_GENERATED_PLUGIN_INIT_FUNCTION_CALLS emberAfPluginTemperatureMeasurementServerInitCallback();

#define EMBER_AF_GENERATED_PLUGIN_STACK_STATUS_FUNCTION_DECLARATIONS                                                               \
    void emberAfPluginTemperatureMeasurementServerStackStatusCallback(EmberStatus status);

#define EMBER_AF_GENERATED_PLUGIN_STACK_STATUS_FUNCTION_CALLS emberAfPluginTemperatureMeasurementServerStackStatusCallback(status);

// Generated reporting configuration defaults
#define EMBER_AF_GENERATED_REPORTING_CONFIG_DEFAULTS                                                                               \
    {                                                                                                                              \
        { EMBER_ZCL_REPORTING_DIRECTION_REPORTED, 1, 0x0402, 0x0000, CLUSTER_MASK_SERVER, 0x0000, 1, 65534, 0 },                   \
    }
#define EMBER_AF_GENERATED_REPORTING_CONFIG_DEFAULTS_TABLE_SIZE (1)
#endif // SILABS_AF_ENDPOINT_CONFIG
