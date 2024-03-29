cmake_minimum_required(VERSION 3.5.0)

project(usb_camera_driver)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif()


if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(std_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(camera_info_manager REQUIRED)
find_package(image_transport REQUIRED)
find_package(camera_calibration_parsers REQUIRED)
find_package(OpenCV 3 REQUIRED)

include_directories(include ${cv_bridge_INCLUDE_DIRS})


add_library(usb_camera_driver SHARED
  src/usb_camera_driver.cpp)

target_compile_definitions(usb_camera_driver
  PRIVATE "COMPOSITION_BUILDING_DLL")

ament_target_dependencies(usb_camera_driver
    "rclcpp"
    "sensor_msgs"
    "std_msgs"
    "cv_bridge"
    "camera_info_manager"
    "image_transport"
    "camera_calibration_parsers"
    "OpenCV")

rclcpp_components_register_nodes(usb_camera_driver "usb_camera_driver::CameraDriver")
set(node_plugins "${node_plugins}usb_camera_driver::CameraDriver;$<TARGET_FILE:usb_camera_driver>\n")

install(DIRECTORY config/ DESTINATION share/${PROJECT_NAME}/config)

add_executable(usb_camera_driver_node
  src/usb_camera_driver_node.cpp)
target_link_libraries(usb_camera_driver_node
  usb_camera_driver
  )
ament_target_dependencies(usb_camera_driver_node
  "rclcpp")


install(TARGETS
  usb_camera_driver
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin)


install(TARGETS
usb_camera_driver_node
DESTINATION lib/${PROJECT_NAME})


# Install launch files.
install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
