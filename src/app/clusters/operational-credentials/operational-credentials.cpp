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
 * @brief Implementation for the Operational Credentials Cluster
 ***************************************************************************/

#include "CHIPDeviceManager.h"
#include "af.h"
#include <app/util/attribute-storage.h>
#include <platform/CHIPDeviceLayer.h>
#include <support/CodeUtils.h>
#include <support/logging/CHIPLogging.h>
#include <transport/AdminPairingTable.h>
#include <app/server/Server.h>

#include "gen/af-structs.h"
#include "gen/attribute-id.h"
#include "gen/attribute-type.h"
#include "gen/cluster-id.h"
#include "gen/command-id.h"

using namespace chip;
using namespace ::chip::DeviceManager;
using namespace ::chip::DeviceLayer;

EmberAfStatus writeFabricAttribute(uint8_t endpoint, AttributeId attributeId, uint8_t * buffer, int32_t index = -1)
{
    EmberAfAttributeSearchRecord record;
    record.endpoint         = endpoint;
    record.clusterId        = ZCL_OPERATIONAL_CREDENTIALS_CLUSTER_ID;
    record.clusterMask      = CLUSTER_MASK_SERVER;
    record.manufacturerCode = EMBER_AF_NULL_MANUFACTURER_CODE;
    record.attributeId      = attributeId;

    // When reading or writing a List attribute the 'index' value could have 3 types of values:
    //  -1: Read/Write the whole list content, including the number of elements in the list
    //   0: Read/Write the number of elements in the list, represented as a uint16_t
    //   n: Read/Write the nth element of the list
    //
    // Since the first 2 bytes of the attribute are used to store the number of elements, elements indexing starts
    // at 1. In order to hide this to the rest of the code of this file, the element index is incremented by 1 here.
    // This also allows calling writeAttribute() with no index arg to mean "write the length".
    emberAfDoorLockClusterPrintln("Fabric: Writing element");
    return emAfReadOrWriteAttribute(&record, NULL, buffer, 0, true, index + 1);
}

EmberAfStatus writeFabric(FabricId fabricId, NodeId nodeId, uint16_t vendorId, int32_t index)
{
    emberAfDoorLockClusterPrintln("Fabric: Trying to write a new fabric");
    EmberAfStatus status    = EMBER_ZCL_STATUS_SUCCESS;
    AttributeId attributeId = ZCL_FABRICS_ATTRIBUTE_ID;

    uint16_t fabricCount = 1;
    EmberAfFabricDescriptor fabricDescriptor;
    fabricDescriptor.FabricId = fabricId;
    fabricDescriptor.NodeId   = nodeId;
    fabricDescriptor.VendorId = vendorId;
    // char const * charLabel = "HomeLabel"; 
    // uint8_t *charPointer = (uint8_t *)charLabel;
    // fabricDescriptor.Label = chip::ByteSpan(charPointer + 1u, emberAfStringLength(charPointer));


    status = writeFabricAttribute(0, attributeId, (uint8_t *) &fabricDescriptor, index);
    VerifyOrReturnError(status == EMBER_ZCL_STATUS_SUCCESS, status);
    return writeFabricAttribute(0, attributeId, (uint8_t *) &fabricCount);
}

CHIP_ERROR writeAdminsIntoFabricsListAttribute(void)
{
    ChipLogProgress(Discovery, "Call to writeAdminsIntoFabricsListAttribute");
    auto pairing = GetGlobalAdminPairingTable().cbegin();
    int32_t fabricIndex = 0;
    while (pairing != GetGlobalAdminPairingTable().cend())
    { 
        NodeId nodeId = pairing->GetNodeId();
        uint64_t fabricId = pairing->GetFabricId();
        uint16_t vendorId = pairing->GetVendorId();
        if (nodeId != kUndefinedNodeId && fabricId != kUndefinedFabricId)
        {
            ChipLogProgress(Discovery, "Found admin paring for fabric %" PRIX64 ", node %" PRIX64, fabricId,
                        nodeId);
            if (writeFabric(fabricId, nodeId, vendorId, fabricIndex) != EMBER_ZCL_STATUS_SUCCESS)
            {
                ChipLogError(Discovery, "Failed to write admin with fabricId %" PRIX64 " in fabrics list", fabricId);
            }
            fabricIndex ++;
        }
        pairing++;
    }
    ChipLogProgress(Discovery, "Storing %" PRIX32 " admins in fabrics list attribute.", fabricIndex);
    if (writeFabricAttribute(0, ZCL_FABRICS_ATTRIBUTE_ID, (uint8_t *) &fabricIndex) != EMBER_ZCL_STATUS_SUCCESS)
    {
        ChipLogError(Discovery, "Failed to write admin count %" PRIX32 " in fabrics list", fabricIndex);
    }
    return CHIP_NO_ERROR;
}

void emberAfPluginOperationalCredentialsServerInitCallback(void)
{
    EmberAfStatus status = EMBER_ZCL_STATUS_SUCCESS;

    for (uint8_t index = 0; index < emberAfEndpointCount(); index++)
    {
        EndpointId endpoint = emberAfEndpointFromIndex(index);
        if (!emberAfContainsCluster(endpoint, ZCL_OPERATIONAL_CREDENTIALS_CLUSTER_ID))
        {
            continue;
        }

        // Loop through admin pairing table list
        // For each index, write the attribute in
    }
    VerifyOrReturn(status == EMBER_ZCL_STATUS_SUCCESS, ChipLogError(Zcl, "emberAfPluginOperationalCredentialsServerInitCallback failed"));
}

bool emberAfOperationalCredentialsClusterRemoveFabricCallback(chip::FabricId fabricId, chip::NodeId nodeId, uint16_t vendorId)
{
    // Go through admin pairing table and remove the element
    // Then fetch the attribute list and find the right element (or maybe just use the admin pairing table index)
    // Then rewrite the entire attribute list (no choice for now)
    emberAfPrintln(EMBER_AF_PRINT_DEBUG, "OpCreds: RemoveFabric"); // TODO: Generate emberAfFabricClusterPrintln
    EmberAfStatus status = EMBER_ZCL_STATUS_FAILURE;
    emberAfSendImmediateDefaultResponse(status);
    return true;
}

bool emberAfOperationalCredentialsClusterGetFabricIdCallback()
{
    emberAfDoorLockClusterPrintln("Fabric: GetFabricID");
    uint64_t fabricID = emberAfCurrentCommand()->source;
    emberAfFillExternalBuffer((ZCL_CLUSTER_SPECIFIC_COMMAND | ZCL_FRAME_CONTROL_SERVER_TO_CLIENT), ZCL_OPERATIONAL_CREDENTIALS_CLUSTER_ID,
                              ZCL_GET_FABRIC_ID_RESPONSE_COMMAND_ID, "y", fabricID);
    EmberStatus sendStatus = emberAfSendResponse();
    if (EMBER_SUCCESS != sendStatus)
    {
        emberAfDoorLockClusterPrintln("Fabric: failed to send %s response: 0x%x", "get_fabric_id", sendStatus);
    }
    // writeFabric(fabricID, 12345, 5, 0);
    return true;
}

bool emberAfOperationalCredentialsClusterUpdateFabricLabelCallback(uint8_t * Label)
{
    emberAfPrintln(EMBER_AF_PRINT_DEBUG, "OpCreds: UpdateFabricLabel to %s", (char*) Label);
    // Go look at admin table using fabricId + update the label
    // Then find equivalent value in attribute list and update it.
    EmberAfStatus status = EMBER_ZCL_STATUS_FAILURE;
    emberAfSendImmediateDefaultResponse(status);
    return true;
}
