#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/point_cloud2.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2_ros/transform_broadcaster.h>

class PGARegistrationNode : public rclcpp::Node {
public:
    PGARegistrationNode() : Node("pga_registration_node") {
        // الاشتراك في موضوع السحابة النقطية المدخلة
        subscription_ = this->create_subscription<sensor_msgs::msg::PointCloud2>(
            "/input_cloud", 10, std::bind(&PGARegistrationNode::pointcloud_callback, this, std::placeholders::_1));
        
        // ناشر التحويلات المكانية
        tf_broadcaster_ = std::make_unique<tf2_ros::TransformBroadcaster>(*this);
        
        RCLCPP_INFO(this->get_logger(), "PGA Point Cloud Registration Node initialized successfully.");
    }

private:
    void pointcloud_callback(const sensor_msgs::msg::PointCloud2::SharedPtr msg) {
        // هنا يتم معالجة السحابة عبر محرك PGA وحساب الـ Motor
        RCLCPP_INFO_ONCE(this->get_logger(), "Receiving PointCloud2 data stream...");
    }

    rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr subscription_;
    std::unique_ptr<tf2_ros::TransformBroadcaster> tf_broadcaster_;
};

int main(int argc, char** argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<PGARegistrationNode>());
    rclcpp::shutdown();
    return 0;
}