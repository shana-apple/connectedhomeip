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

// THIS FILE IS GENERATED BY ZAP

#include <cinttypes>
#include <cstdint>

#include "af-structs.h"
#include "app/util/util.h"
#include "call-command-handler.h"
#include "callback.h"
#include "cluster-id.h"
#include "command-id.h"

#include <app/InteractionModelEngine.h>

// Currently we need some work to keep compatible with ember lib.
#include <util/ember-compatibility-functions.h>

namespace chip {
namespace app {

// Cluster specific command parsing

namespace clusters {

namespace WindowCovering {

void DispatchServerCommand(app::Command * command, CommandId commandId, EndpointId endpointId, TLV::TLVReader & dataTlv)
{
    {
        switch (commandId)
        {
        case ZCL_WINDOW_COVERING_DOWN_CLOSE_COMMAND_ID: {
            // TODO(#5098) We should pass the Command Object and EndpointId to the cluster callbacks.
            emberAfWindowCoveringClusterWindowCoveringDownCloseCallback();
            break;
        }
        case ZCL_WINDOW_COVERING_GO_TO_LIFT_PERCENTAGE_COMMAND_ID: {
            CHIP_ERROR TLVError = CHIP_NO_ERROR;
            uint8_t percentageLiftValue;

            while ((TLVError = dataTlv.Next()) == CHIP_NO_ERROR)
            {
                switch (TLV::TagNumFromTag(dataTlv.GetTag()))
                {
                case 0:
                    TLVError = dataTlv.Get(percentageLiftValue);
                    break;
                default:
                    // Unsupported tag, ignore it.
                    ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
                    break;
                }
                if (TLVError != CHIP_NO_ERROR)
                {
                    ChipLogProgress(Zcl, "Failed to decode TLV data with tag %" PRIx32 ": %" PRId32,
                                    TLV::TagNumFromTag(dataTlv.GetTag()), TLVError);
                }
            }
            // TODO(#5098) We should pass the Command Object and EndpointId to the cluster callbacks.
            emberAfWindowCoveringClusterWindowCoveringGoToLiftPercentageCallback(percentageLiftValue);
            break;
        }
        case ZCL_WINDOW_COVERING_GO_TO_LIFT_VALUE_COMMAND_ID: {
            CHIP_ERROR TLVError = CHIP_NO_ERROR;
            uint16_t liftValue;

            while ((TLVError = dataTlv.Next()) == CHIP_NO_ERROR)
            {
                switch (TLV::TagNumFromTag(dataTlv.GetTag()))
                {
                case 0:
                    TLVError = dataTlv.Get(liftValue);
                    break;
                default:
                    // Unsupported tag, ignore it.
                    ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
                    break;
                }
                if (TLVError != CHIP_NO_ERROR)
                {
                    ChipLogProgress(Zcl, "Failed to decode TLV data with tag %" PRIx32 ": %" PRId32,
                                    TLV::TagNumFromTag(dataTlv.GetTag()), TLVError);
                }
            }
            // TODO(#5098) We should pass the Command Object and EndpointId to the cluster callbacks.
            emberAfWindowCoveringClusterWindowCoveringGoToLiftValueCallback(liftValue);
            break;
        }
        case ZCL_WINDOW_COVERING_GO_TO_TILT_PERCENTAGE_COMMAND_ID: {
            CHIP_ERROR TLVError = CHIP_NO_ERROR;
            uint8_t percentageTiltValue;

            while ((TLVError = dataTlv.Next()) == CHIP_NO_ERROR)
            {
                switch (TLV::TagNumFromTag(dataTlv.GetTag()))
                {
                case 0:
                    TLVError = dataTlv.Get(percentageTiltValue);
                    break;
                default:
                    // Unsupported tag, ignore it.
                    ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
                    break;
                }
                if (TLVError != CHIP_NO_ERROR)
                {
                    ChipLogProgress(Zcl, "Failed to decode TLV data with tag %" PRIx32 ": %" PRId32,
                                    TLV::TagNumFromTag(dataTlv.GetTag()), TLVError);
                }
            }
            // TODO(#5098) We should pass the Command Object and EndpointId to the cluster callbacks.
            emberAfWindowCoveringClusterWindowCoveringGoToTiltPercentageCallback(percentageTiltValue);
            break;
        }
        case ZCL_WINDOW_COVERING_GO_TO_TILT_VALUE_COMMAND_ID: {
            CHIP_ERROR TLVError = CHIP_NO_ERROR;
            uint16_t tiltValue;

            while ((TLVError = dataTlv.Next()) == CHIP_NO_ERROR)
            {
                switch (TLV::TagNumFromTag(dataTlv.GetTag()))
                {
                case 0:
                    TLVError = dataTlv.Get(tiltValue);
                    break;
                default:
                    // Unsupported tag, ignore it.
                    ChipLogProgress(Zcl, "Unknown TLV tag during processing.");
                    break;
                }
                if (TLVError != CHIP_NO_ERROR)
                {
                    ChipLogProgress(Zcl, "Failed to decode TLV data with tag %" PRIx32 ": %" PRId32,
                                    TLV::TagNumFromTag(dataTlv.GetTag()), TLVError);
                }
            }
            // TODO(#5098) We should pass the Command Object and EndpointId to the cluster callbacks.
            emberAfWindowCoveringClusterWindowCoveringGoToTiltValueCallback(tiltValue);
            break;
        }
        case ZCL_WINDOW_COVERING_STOP_COMMAND_ID: {
            // TODO(#5098) We should pass the Command Object and EndpointId to the cluster callbacks.
            emberAfWindowCoveringClusterWindowCoveringStopCallback();
            break;
        }
        case ZCL_WINDOW_COVERING_UP_OPEN_COMMAND_ID: {
            // TODO(#5098) We should pass the Command Object and EndpointId to the cluster callbacks.
            emberAfWindowCoveringClusterWindowCoveringUpOpenCallback();
            break;
        }
        default: {
            // Unrecognized command ID, error status will apply.
            // TODO: Encode response for command not found
            ChipLogError(Zcl, "Unknown command %" PRIx16 " for cluster %" PRIx16, commandId, ZCL_WINDOW_COVERING_CLUSTER_ID);
            break;
        }
        }
    }
}

} // namespace WindowCovering

} // namespace clusters

void DispatchSingleClusterCommand(chip::ClusterId aClusterId, chip::CommandId aCommandId, chip::EndpointId aEndPointId,
                                  chip::TLV::TLVReader & aReader, Command * apCommandObj)
{
    ChipLogDetail(Zcl, "Received Cluster Command: Cluster=%" PRIx16 " Command=%" PRIx8 " Endpoint=%" PRIx8, aClusterId, aCommandId,
                  aEndPointId);
    Compatibility::SetupEmberAfObjects(apCommandObj, aClusterId, aCommandId, aEndPointId);
    switch (aClusterId)
    {
    case ZCL_WINDOW_COVERING_CLUSTER_ID:
        clusters::WindowCovering::DispatchServerCommand(apCommandObj, aCommandId, aEndPointId, aReader);
        break;
    default:
        // Unrecognized cluster ID, error status will apply.
        // TODO: Encode response for Cluster not found
        ChipLogError(Zcl, "Unknown cluster %" PRIx16, aClusterId);
        break;
    }
    Compatibility::ResetEmberAfObjects();
}

} // namespace app
} // namespace chip
