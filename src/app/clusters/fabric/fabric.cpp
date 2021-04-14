/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
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

/****************************************************************************
 * @file
 * @brief Implementation for the Descriptor Server Cluster
 ***************************************************************************/

#include "af.h"
#include <app/util/attribute-storage.h>
#include <support/CodeUtils.h>
#include <support/logging/CHIPLogging.h>

#include "gen/af-structs.h"
#include "gen/attribute-id.h"
#include "gen/attribute-type.h"
#include "gen/cluster-id.h"

using namespace chip;

// EmberAfStatus writeAttribute(uint8_t endpoint, AttributeId attributeId, uint8_t * buffer, int32_t index = -1)
// {
//     EmberAfAttributeSearchRecord record;
//     record.endpoint         = endpoint;
//     record.clusterId        = ZCL_DESCRIPTOR_CLUSTER_ID;
//     record.clusterMask      = CLUSTER_MASK_SERVER;
//     record.manufacturerCode = EMBER_AF_NULL_MANUFACTURER_CODE;
//     record.attributeId      = attributeId;

//     // When reading or writing a List attribute the 'index' value could have 3 types of values:
//     //  -1: Read/Write the whole list content, including the number of elements in the list
//     //   0: Read/Write the number of elements in the list, represented as a uint16_t
//     //   n: Read/Write the nth element of the list
//     //
//     // Since the first 2 bytes of the attribute are used to store the number of elements, elements indexing starts
//     // at 1. In order to hide this to the rest of the code of this file, the element index is incremented by 1 here.
//     // This also allows calling writeAttribute() with no index arg to mean "write the length".
//     return emAfReadOrWriteAttribute(&record, NULL, buffer, 0, true, index + 1);
// }

bool emberAfFabricClusterRemoveFabricCallback(chip::FabricId fabricId, chip::NodeId nodeId, uint16_t vendorId)
{
    EmberAfStatus status = EMBER_ZCL_STATUS_FAILURE;
    emberAfSendImmediateDefaultResponse(status);
    return true;
}

bool emberAfFabricClusterGetFabricIdCallback()
{
    EmberAfStatus status = EMBER_ZCL_STATUS_FAILURE;
    emberAfSendImmediateDefaultResponse(status);
    return true;
}

bool emberAfFabricClusterUpdateLabelCallback(chip::ByteSpan label)
{
    EmberAfStatus status = EMBER_ZCL_STATUS_FAILURE;
    emberAfSendImmediateDefaultResponse(status);
    return true;
}