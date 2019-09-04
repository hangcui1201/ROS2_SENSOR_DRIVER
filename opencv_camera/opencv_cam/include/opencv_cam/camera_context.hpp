#ifndef OPENCV_CAM_CONTEXT_HPP
#define OPENCV_CAM_CONTEXT_HPP

#include <math.h>
#include <string>
#include <iostream>

#include "ros2_shared/context_macros.hpp"

#include <ament_index_cpp/get_package_share_directory.hpp>

std::string package_share_directory = "/home/cui/ros2_ws/install/opencv_cam/share/opencv_cam/config/camera.yaml";

namespace opencv_cam {

#define OPENCV_CAM_ALL_PARAMS \
  CXT_MACRO_MEMBER(file, bool, false)                                       /* Read from file vs. read from device */ \
  CXT_MACRO_MEMBER(filename, std::string, "")                               /* Filename, ignored if playback is false */ \
  CXT_MACRO_MEMBER(fps, int, 0)                                             /* Playback fps, ignored if playback is false*/ \
  CXT_MACRO_MEMBER(index, int, 1)                                           /* Device index, see cv::VideoCaptureAPIs */ \
  CXT_MACRO_MEMBER(camera_info_path, std::string, package_share_directory)  /* Camera info path */ \
  CXT_MACRO_MEMBER(camera_frame_id, std::string, "camera_frame")            /* Camera frame id */ \
/* End of list */

#undef CXT_MACRO_MEMBER
#define CXT_MACRO_MEMBER(n, t, d) CXT_MACRO_DEFINE_MEMBER(n, t, d)

  struct CameraContext
  {
    OPENCV_CAM_ALL_PARAMS
  };

} // namespace opencv_cam

#endif // OPENCV_CAM_CONTEXT_HPP
