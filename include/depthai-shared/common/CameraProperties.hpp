#pragma once

#include "depthai-shared/common/CameraBoardSocket.hpp"
#include "depthai-shared/common/CameraImageOrientation.hpp"
#include "depthai-shared/common/CameraSensorType.hpp"

namespace dai {

/**
 * CameraProperties structure
 *
 * Characterizes detected cameras on board
 */
struct CameraProperties {
    /**
     * Board socket where the camera was detected
     */
    CameraBoardSocket socket;
    /**
     * Camera sensor name, e.g: "IMX378", "OV9282"
     */
    std::string sensorName;
    /**
     * Maximum sensor resolution
     */
    uint16_t width, height;
    /**
     * Default camera orientation, board dependent
     */
    CameraImageOrientation orientation;
    /**
     * List of supported types of processing for the given camera.
     *
     * For some sensors it's not possible to determine if they are color or mono
     * (e.g. OV9782 and OV9282), so this could return more than one entry
     */
    std::vector<CameraSensorType> supportedTypes;
    /**
     *  Whether an autofocus VCM IC was detected
     */
    bool hasAutofocus;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CameraProperties, socket, sensorName, width, height, orientation, supportedTypes, hasAutofocus);
};

}  // namespace dai
