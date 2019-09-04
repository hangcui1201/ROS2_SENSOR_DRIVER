#include "opencv_cam/subscriber_node.hpp"

namespace opencv_cam
{

  ImageSubscriberNode::ImageSubscriberNode(const rclcpp::NodeOptions &options) :
    Node("image_subscriber", options)
  {
    sub_ = this->create_subscription<sensor_msgs::msg::Image>(
      "image_raw", 10,
      [this](sensor_msgs::msg::Image::UniquePtr msg)
      {
        static bool receiving = false;

        if (!receiving) {
          receiving = true;
          RCLCPP_INFO(get_logger(), "receiving messages");
        }

#undef SHOW_ADDRESS
#ifdef SHOW_ADDRESS
        static int count = 0;
        RCLCPP_INFO(get_logger(), "%d, %p", count++, reinterpret_cast<std::uintptr_t>(msg.get()));
#else
        (void) this;
        (void) msg;
#endif
      });

    RCLCPP_INFO(get_logger(), "ready");
  }

} // namespace opencv_cam

#include "rclcpp_components/register_node_macro.hpp"

RCLCPP_COMPONENTS_REGISTER_NODE(opencv_cam::ImageSubscriberNode)