/**
 * 该例程将执行/show_person服务，服务数据类型learning_communication::PersonSrv
 */
 
#include <ros/ros.h>
#include <cstdlib>
#include <unordered_map>
#include "turtlesim/Spawn.h"
#include "geometry_msgs/Twist.h"
#include "learning_communication/CommandTurtleSrv.h"


class RosNode {

public:
    RosNode() {};

    ~RosNode() {};

    void Init(RosNode& ros_node, const ros::NodeHandle& n);

    void Run();

    // service回调函数，输入参数req，输出参数res
    bool CommandTurtleCallback(learning_communication::CommandTurtleSrv::Request &req,
                               learning_communication::CommandTurtleSrv::Response &res);

private:
    // 创建节点句柄
    ros::NodeHandle n_;

    // 声明一个server
    ros::ServiceServer spawn_turtle_service_;

    // 声明一个client
    ros::ServiceClient spawn_client_;

    // // 声明一个publisher
    // ros::Publisher cmd_vel_pub_;

    // int status_ = 0;
    // geometry_msgs::Twist msg_;

    std::unordered_map<std::string, ros::Publisher> pub_map_;
    std::unordered_map<std::string, int> status_map_;
    std::unordered_map<std::string, geometry_msgs::Twist> msg_map_;

};

// service回调函数，输入参数req，输出参数res
bool RosNode::CommandTurtleCallback(learning_communication::CommandTurtleSrv::Request &req,
                                    learning_communication::CommandTurtleSrv::Response &res)
{
    // 显示请求数据
    ROS_INFO("new turtle name: %s, controlled turtle name: %s, status: %d", 
              req.new_turtle_name.c_str(), req.controlled_turtle_name.c_str(), req.status);
    if (!req.new_turtle_name.empty()) {
        turtlesim::Spawn srv;
        srv.request.name = req.new_turtle_name;
        srv.request.x = rand() % 10;
        srv.request.y = rand() % 10;
        
        // 发布service请求，等待应答结果
        if (spawn_client_.call(srv))
        {
            ROS_INFO("Response.name : %s", srv.response.name.c_str());
            res.result = "/spawn is called successfully, spawn new turtlesim";
        }
        else
        {
            ROS_ERROR("Failed to call service /spawn");
            res.result = "/spawn is called failed";
        }
    }

    if (!req.controlled_turtle_name.empty()) {
        ros::Publisher cmd_vel_pub = n_.advertise<geometry_msgs::Twist>("/" + req.controlled_turtle_name + "/cmd_vel", 1000);
        pub_map_[req.controlled_turtle_name] = cmd_vel_pub;

        geometry_msgs::Twist msg;
        msg.angular = req.angular;
        msg.linear = req.linear;

        status_map_[req.controlled_turtle_name] = req.status;
        msg_map_[req.controlled_turtle_name] = msg;


        res.result = "publish /" + req.controlled_turtle_name + "/cmd_vel is created successfully";
    }
    return true;
}

void RosNode::Init(RosNode& ros_node, const ros::NodeHandle& n)
{
    n_ = n;
    //创建一个名为/show_person的server，注册回调函数personCallback
    spawn_turtle_service_ = n_.advertiseService("/command_turtle", &RosNode::CommandTurtleCallback, this);
    
    //创建一个client，service消息类型是turtlesim::Spawn
    spawn_client_ = n_.serviceClient<turtlesim::Spawn>("/spawn");
}

void RosNode::Run()
{
    // 循环等待回调函数
    ROS_INFO("Ready to command_turtle informtion.");

    // 设置循环的频率
    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok())
    {
        // 调用回调函数
        ros::spinOnce();
        // 遍历所有发布的话题，update发布内容
        for (auto iter = status_map_.begin(); iter != status_map_.end(); ++iter) {
            if (iter->second > 0) {
                // 发布消息
                pub_map_[iter->first].publish(msg_map_[iter->first]);

                // 按照循环频率延时
                loop_rate.sleep();
                ++count;
            }
        }
    }
}

int main(int argc, char **argv)
{
    // ROS节点初始化
    ros::init(argc, argv, "ros_node_3");

    // 创建节点句柄
    ros::NodeHandle n;

    RosNode ros_node;

    ros_node.Init(ros_node, n);

    ros_node.Run();

    return 0;
}


