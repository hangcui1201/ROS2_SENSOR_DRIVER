## A Collection of ROS2 Sensor Drivers for Projects

### ROS2 version: Dashing  (Ubuntu 18.04)

#### Logitech F710 Joystick

[REFERENCE1](https://www.jetsonhacks.com/2018/08/19/racecar-j-ros-teleoperation/)  
[REFERENCE2](https://github.com/FurqanHabibi/joystick_ros2)  

Switch to "X" mode, not in "D" mode  

$ colcon build --symlink-install  

$ ros2 run joystick_ros2 joystick_ros2  

$ ros2 topic echo /joy  

<a href="url"><img src="./images/F710_1.png" width="600"></a>  
<a href="url"><img src="./images/F710_2.png" width="600"></a>  
<a href="url"><img src="./images/F710_3.png" width="600"></a>  
<a href="url"><img src="./images/F710_4.png" width="600"></a>  

#### HLS LFCD LDS 2D Laser

[HLS LFCD LDS 2D LASER DRIVER](https://github.com/ROBOTIS-GIT/hls_lfcd_lds_driver/tree/dashing-devel)  

$ colcon build --symlink-install  

$ ros2 launch hls_lfcd_lds_driver hlds_laser.launch.py  

$ ros2 run tf2_ros static_transform_publisher 0 0 0 0 0 0 map laser  

$ ros2 launch hls_lfcd_lds_driver view_hlds_laser.launch.py  

<!--
<a href="url"><img src="./images/hls_demo.png" align="left" height="100" width="48" ></a> 
-->
<a href="url"><img src="./images/hls_demo.png" width="600"></a>  
  

#### USB Camera (2D)

[REFERENCE](https://github.com/klintan/ros2_usb_camera)  

$ colcon build --symlink-install  

$ ros2 run usb_camera_driver usb_camera_driver_node  

$ ros2 run image_transport republish raw in:=image_raw compressed out:=image_raw_compressed  

$ ros2 run rqt_image_view rqt_image_view  

<a href="url"><img src="./images/usb_camera_driver_1.png" width="600"></a>  
  
<a href="url"><img src="./images/usb_camera_driver_2.png" width="600"></a>  

#### USB Camera with OpenCV (2D)

[REFERENCE](https://github.com/clydemcqueen/opencv_cam)  

$ colcon build --symlink-install  

$ ros2 run opencv_cam opencv_cam_main  

$ ros2 run rqt_image_view rqt_image_view  


#### ZED Stereo Camera

[ZED Stereo Camera SDK Jetpack 4.2](https://www.stereolabs.com/developers/release/#sdkdownloads_anchor)  

$ sudo /usr/local/zed/tools/'ZED Diagnostic'  

<a href="url"><img src="./images/ZED.png" width="500"></a>  

$ sudo /usr/local/zed/tools/'ZED Explorer'  
