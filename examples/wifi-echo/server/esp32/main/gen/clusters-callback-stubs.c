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

// This callback file is created for your convenience. You may add application
// code to this file. If you regenerate this file over a previous version, the
// previous version will be overwritten and any code you have added will be
// lost.

#include "af.h"

/** @brief Identify Cluster Identify Query Response
 *
 *
 *
 * @param timeout   Ver.: always
 */
bool emberAfIdentifyClusterIdentifyQueryResponseCallback(uint16_t timeout)
{
    return false;
}

/** @brief Identify Cluster Start Feedback Callback
 *
 *
 *
 * @param endpoint Endpoint id
 * @param identifyTime Identify time
 */
bool emberAfPluginIdentifyStartFeedbackCallback(uint8_t endpoint, uint16_t identifyTime)
{
    return false;
}

/** @brief Identify Cluster Stop Feedback Callback
 *
 *
 *
 * @param endpoint Endpoint id
 */
bool emberAfPluginIdentifyStopFeedbackCallback(uint8_t endpoint)
{
    return false;
}

/** @brief Basic Cluster Reset To Factory Defaults
 *
 *
 *
 */
bool emberAfBasicClusterResetToFactoryDefaultsCallback(void)
{
    return false;
}

/** @brief Door Lock Cluster Get Log Record
 *
 *
 *
 * @param logIndex   Ver.: always
 */
bool emberAfDoorLockClusterGetLogRecordCallback(uint16_t logIndex)
{
    return false;
}

/** @brief Groups Cluster Add Group Response
 *
 *
 *
 * @param status   Ver.: always
 * @param groupId   Ver.: always
 */
bool emberAfGroupsClusterAddGroupResponseCallback(uint8_t status, uint16_t groupId)
{
    return false;
}

/** @brief Groups Cluster Get Group Membership Response
 *
 *
 *
 * @param capacity   Ver.: always
 * @param groupCount   Ver.: always
 * @param groupList   Ver.: always
 */
bool emberAfGroupsClusterGetGroupMembershipResponseCallback(uint8_t capacity, uint8_t groupCount, uint8_t * groupList)
{
    return false;
}

/** @brief Groups Cluster Remove Group Response
 *
 *
 *
 * @param status   Ver.: always
 * @param groupId   Ver.: always
 */
bool emberAfGroupsClusterRemoveGroupResponseCallback(uint8_t status, uint16_t groupId)
{
    return false;
}

/** @brief Groups Cluster View Group Response
 *
 *
 *
 * @param status   Ver.: always
 * @param groupId   Ver.: always
 * @param groupName   Ver.: always
 */
bool emberAfGroupsClusterViewGroupResponseCallback(uint8_t status, uint16_t groupId, uint8_t * groupName)
{
    return false;
}

/** @brief IAS Zone Cluster Zone Enroll Request
 *
 *
 *
 * @param zoneType   Ver.: always
 * @param manufacturerCode   Ver.: always
 */
bool emberAfIasZoneClusterZoneEnrollRequestCallback(uint16_t zoneType, uint16_t manufacturerCode)
{
    return false;
}

/** @brief IAS Zone Cluster Zone Enroll Response
 *
 *
 *
 * @param enrollResponseCode   Ver.: always
 * @param zoneId   Ver.: always
 */
bool emberAfIasZoneClusterZoneEnrollResponseCallback(uint8_t enrollResponseCode, uint8_t zoneId)
{
    return false;
}

/** @brief IAS Zone Cluster Zone Status Change Notification
 *
 *
 *
 * @param zoneStatus   Ver.: always
 * @param extendedStatus   Ver.: always
 * @param zoneId   Ver.: since ha-1.2-05-3520-29
 * @param delay   Ver.: since ha-1.2-05-3520-29
 */
bool emberAfIasZoneClusterZoneStatusChangeNotificationCallback(uint16_t zoneStatus, uint8_t extendedStatus, uint8_t zoneId,
                                                               uint16_t delay)
{
    return false;
}

/** @brief Scenes Cluster Add Scene Response
 *
 *
 *
 * @param status   Ver.: always
 * @param groupId   Ver.: always
 * @param sceneId   Ver.: always
 */
bool emberAfScenesClusterAddSceneResponseCallback(uint8_t status, uint16_t groupId, uint8_t sceneId)
{
    return false;
}

/** @brief Scenes Cluster Get Scene Membership Response
 *
 *
 *
 * @param status   Ver.: always
 * @param capacity   Ver.: always
 * @param groupId   Ver.: always
 * @param sceneCount   Ver.: always
 * @param sceneList   Ver.: always
 */
bool emberAfScenesClusterGetSceneMembershipResponseCallback(uint8_t status, uint8_t capacity, uint16_t groupId, uint8_t sceneCount,
                                                            uint8_t * sceneList)
{
    return false;
}

/** @brief Scenes Cluster Remove All Scenes Response
 *
 *
 *
 * @param status   Ver.: always
 * @param groupId   Ver.: always
 */
bool emberAfScenesClusterRemoveAllScenesResponseCallback(uint8_t status, uint16_t groupId)
{
    return false;
}

/** @brief Scenes Cluster Remove Scene Response
 *
 *
 *
 * @param status   Ver.: always
 * @param groupId   Ver.: always
 * @param sceneId   Ver.: always
 */
bool emberAfScenesClusterRemoveSceneResponseCallback(uint8_t status, uint16_t groupId, uint8_t sceneId)
{
    return false;
}

/** @brief Scenes Cluster Store Scene Response
 *
 *
 *
 * @param status   Ver.: always
 * @param groupId   Ver.: always
 * @param sceneId   Ver.: always
 */
bool emberAfScenesClusterStoreSceneResponseCallback(uint8_t status, uint16_t groupId, uint8_t sceneId)
{
    return false;
}

/** @brief Scenes Cluster View Scene Response
 *
 *
 *
 * @param status   Ver.: always
 * @param groupId   Ver.: always
 * @param sceneId   Ver.: always
 * @param transitionTime   Ver.: always
 * @param sceneName   Ver.: always
 * @param extensionFieldSets   Ver.: always
 */
bool emberAfScenesClusterViewSceneResponseCallback(uint8_t status, uint16_t groupId, uint8_t sceneId, uint16_t transitionTime,
                                                   uint8_t * sceneName, uint8_t * extensionFieldSets)
{
    return false;
}

// endpoint_config.h callbacks, grep'd from SDK, comment these out as clusters come in

void emberAfIasZoneClusterClientInitCallback(uint8_t endpoint) {}
void emberAfIasZoneClusterServerInitCallback(uint8_t endpoint) {}
void emberAfIasZoneClusterServerMessageSentCallback(EmberOutgoingMessageType type, uint16_t indexOrDestination,
                                                    EmberApsFrame * apsFrame, uint16_t msgLen, uint8_t * message,
                                                    EmberStatus status)
{}

EmberAfStatus emberAfIasZoneClusterServerPreAttributeChangedCallback(uint8_t endpoint, EmberAfAttributeId attributeId,
                                                                     EmberAfAttributeType attributeType, uint8_t size,
                                                                     uint8_t * value)
{
    return EMBER_ZCL_STATUS_SUCCESS;
}

void emberAfPluginReportingInitCallback(void) {}
void emberAfPollControlClusterServerAttributeChangedCallback(uint8_t endpoint, EmberAfAttributeId attributeId) {}
void emberAfPollControlClusterServerInitCallback(uint8_t endpoint) {}
void emberAfPluginPollControlServerStackStatusCallback(EmberStatus status) {}
EmberAfStatus emberAfPollControlClusterServerPreAttributeChangedCallback(uint8_t endpoint, EmberAfAttributeId attributeId,
                                                                         EmberAfAttributeType attributeType, uint8_t size,
                                                                         uint8_t * value)
{
    return EMBER_ZCL_STATUS_SUCCESS;
}

void emberAfPluginIasZoneClientZdoCallback(EmberNodeId emberNodeId, EmberApsFrame * apsFrame, uint8_t * message, uint16_t length) {}

void emberAfPluginIasZoneClientWriteAttributesResponseCallback(EmberAfClusterId clusterId, uint8_t * buffer, uint16_t bufLen) {}

void emberAfPluginIasZoneClientReadAttributesResponseCallback(EmberAfClusterId clusterId, uint8_t * buffer, uint16_t bufLen) {}
