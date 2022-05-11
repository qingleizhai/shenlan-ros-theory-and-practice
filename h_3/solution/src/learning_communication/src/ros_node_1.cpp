/**
 * 该例程将发布chatter话题，消息类型String
 */
 
#include <sstream>
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose.h"


void Turtle1PoseCallback(const turtlesim::Pose& pose)
{
    ROS_INFO("pose(x, y, theta):(%f, %f, %f)", pose.x, pose.y, pose.theta);
}

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "ros_node_1");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个Publisher
    ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);

    // 创建一个Subscriber
    ros::Subscriber sub = n.subscribe("/turtle1/pose", 1000, Turtle1PoseCallback);
	
    // 设置循环的频率
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok())
    {
        // 初始化std_msgs::String类型的消息
        geometry_msgs::Twist msg;
        msg.linear.x = 0.5; 
        msg.angular.z = 0.5; 

        // 发布消息
        pub.publish(msg);

        // 调用回调函数
        ros::spinOnce();

        // 按照循环频率延时
        loop_rate.sleep();
        ++count;
    }

    return 0;
}
