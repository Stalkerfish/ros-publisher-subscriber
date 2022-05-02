#include <ros/ros.h>
#include <std_msgs/String.h>

void callback_receive_pubed_data(const std_msgs::String& msg){
	ROS_INFO("Message received : %s", msg.data.c_str());
}

int main (int argc, char **argv){

	ros::init(argc, argv, "my_sub");
	ros::NodeHandle nh;

	ros::Subscriber sub = nh.subscribe("/my_topic", 1000, callback_receive_pubed_data );

	ros::spin();
}
