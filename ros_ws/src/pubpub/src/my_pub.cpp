#include <ros/ros.h>
#include <std_msgs/String.h>

int main (int argc, char **argv){
	ros::init(argc, argv, "my_pub");
	ros::NodeHandle nh;

	ros::Publisher pub = nh.advertise<std_msgs::String>("/my_topic", 10);


	ROS_INFO("Node has been started");

	ros::Rate rate(2);

	while (ros::ok()){
		std_msgs::String msg;
		msg.data = "I'm Publishing!";
		pub.publish(msg);
		rate.sleep();
	}
}
