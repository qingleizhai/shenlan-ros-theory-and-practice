#include<math.h>

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <std_msgs/Int8.h>
#include <std_msgs/String.h>

#define STATUS_EXPLORING    (0)
#define STATUS_CLOSE_TARGET (1)
#define STATUS_GO_HOME      (2)

#define GET_TARGET_SIZE     (90000)

ros::Publisher vel_pub;
ros::Publisher cmd_pub;
ros::Publisher voice_pub;

int status_flag = STATUS_EXPLORING;

// 接收到订阅的消息后，会进入消息回调函数
void poseCallback(const geometry_msgs::Pose::ConstPtr& msg)
{
    // 将接收到的消息打印出来
    ROS_INFO("Target pose: x:%0.6f, y:%0.6f, z:%0.6f", msg->position.x, msg->position.y, msg->position.z);

    /******************************请补充此处代码（开始）*******************************************/












    /******************************请补充此处代码（结束）*******************************************/
}

int main(int argc, char **argv)
{
	// ROS节点初始化
	ros::init(argc, argv, "move_to_target");

	// 创建节点句柄
	ros::NodeHandle n;

    // 创建一个Subscriber，订阅名为/turtle1/pose的topic，注册回调函数poseCallback
    ros::Subscriber pose_sub = n.subscribe("/object_detect_pose", 10, poseCallback);
	// 创建一个Publisher，发布名为cmd_vel的topic，消息类型为geometry_msgs::Twist，队列长度10
	vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
	// 创建一个Publisher，发布名为cmd_vel的topic，消息类型为std_msgs::Int8，队列长度10
	cmd_pub = n.advertise<std_msgs::Int8>("/exploring_cmd", 10);
    // 发布语音输出内容    
    voice_pub = n.advertise<std_msgs::String>("voiceWords", 1000); 

    // 循环等待回调函数
    ros::spin();

	return 0;
}
