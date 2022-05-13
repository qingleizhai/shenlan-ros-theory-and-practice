1、运行结果：

  a) 作业1：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/blob/main/h_3/solution/hw1.mp4
  
  b) 作业2：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/blob/main/h_3/solution/hw2.mp4
  
  c) 作业3：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/blob/main/h_3/solution/hw3.mp4
  
2、代码：

  a) 作业1：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/blob/main/h_3/solution/src/learning_communication/src/ros_node_1.cpp
  
  b) 作业2：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/blob/main/h_3/solution/src/learning_communication/src/ros_node_2.cpp
  
  c) 作业3：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/blob/main/h_3/solution/src/learning_communication/src/ros_node_3.cpp
  
3、操作流程：

  a) 作业1：1. 启动节点 rosrun turtlesim turtlesim_node； 2， 启动节点 rosrun learning_communication ros_node_1 让海龟圆周运动并输出海龟实时位置。
  
  b) 作业2：1. 启动节点 rosrun turtlesim turtlesim_node； 2， 启动节点 rosrun learning_communication ros_node_2  产生的新海龟。
  
  c) 作业3：1. 启动节点 rosrun turtlesim turtlesim_node； 2， 启动节点 rosrun learning_communication ros_node_3； 
    
    3，通过命令行rosservice call /command_turtle "new_turtle_name: 'turtle2'
                                controlled_turtle_name: ''
                                status: 0
                                linear: {x: 0.0, y: 0.0, z: 0.0}
                                angular: {x: 0.0, y: 0.0, z: 0.0}"  产生若干位置随即的新海龟
                                
    4，通过命令行rosservice call /command_turtle "new_turtle_name: ''
                                controlled_turtle_name: 'turtle1'
                                status: 1
                                linear: {x: 0.5, y: 0.0, z: 0.0}
                                angular: {x: 0.0, y: 0.0, z: 0.5}"  让指定海龟圆周运动
                                
    5，通过命令行rosservice call /command_turtle "new_turtle_name: ''
                                controlled_turtle_name: 'turtle1'
                                status: 0
                                linear: {x: 0.5, y: 0.0, z: 0.0}
                                angular: {x: 0.0, y: 0.0, z: 0.5}"  让指定停止海龟圆周运动
                                
     注：status 表示海龟运动状态，0 是停止运动，1是开始圆周运动


  
