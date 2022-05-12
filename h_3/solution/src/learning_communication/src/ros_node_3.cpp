/**
 * 该例程将执行/show_person服务，服务数据类型learning_communication::PersonSrv
 */
 
#include <ros/ros.h>
#include "turtlesim/Spawn.h"
#include "learning_communication/SpawnTurtleSrv.h"

// service回调函数，输入参数req，输出参数res
bool SpawnTurtleCallback(learning_communication::SpawnTurtleSrv::Request  &req,
                         learning_communication::SpawnTurtleSrv::Response &res)
{
    // 显示请求数据
    ROS_INFO("turtle name: %s", req.name.c_str());

     // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个client，service消息类型是turtlesim::Spawn
    ros::ServiceClient client = n.serviceClient<turtlesim::Spawn>("/spawn");

    // 创建turtlesim::Spawn类型的service消息
    turtlesim::Spawn srv;
    srv.request.name = req.name;
    srv.request.x = 8;
    srv.request.y = 2;
    
    // 发布service请求，等待应答结果
    if (client.call(srv))
    {
        ROS_INFO("Response.name : %s", srv.response.name.c_str());
        res.result = true;
    }
    else
    {
        ROS_ERROR("Failed to call service /spawn");
        res.result = true;
    }

	// 设置反馈数据
	

    return true;
}

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "ros_node_3");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个名为/show_person的server，注册回调函数personCallback
    ros::ServiceServer person_service = n.advertiseService("/spawn_turtle", SpawnTurtleCallback);

    // 循环等待回调函数
    ROS_INFO("Ready to spawn_turtle informtion.");
    ros::spin();

    return 0;
}


