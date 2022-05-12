/**
 * 该例程将请求/spawn服务，turtlesim::Spawn
 */
 
#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "ros_node_2");

    // 创建节点句柄
    ros::NodeHandle n;

    // 创建一个client，service消息类型是turtlesim::Spawn
    ros::ServiceClient client = n.serviceClient<turtlesim::Spawn>("/spawn");

    // 创建turtlesim::Spawn类型的service消息
    turtlesim::Spawn srv;
    srv.request.name = "turtle2";
    srv.request.x = 8;
    srv.request.y = 2;
    
    // 发布service请求，等待应答结果
    if (client.call(srv))
    {
        ROS_INFO("Response.name : %s", srv.response.name.c_str());
    }
    else
    {
        ROS_ERROR("Failed to call service /spawn");
        return 1;
    }

    return 0;
}

