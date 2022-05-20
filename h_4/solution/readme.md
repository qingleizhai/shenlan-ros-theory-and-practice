1、作业1：

  a) 运行结果：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/blob/main/h_4/solution/hw1.mp4

  b) 代码：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/tree/main/h_4/solution/src/learning_launch/launch

  c) 操作流程： 

    1，启动launch文件 ros_node_1.launch 测试结果后关闭；
    
    2，启动launch文件 ros_node_2.launch 测试结果后关闭；
    
    3，I 启动launch文件 ros_node_3.launch, 
    
    II 通过命令行rosservice call /command_turtle "new_turtle_name: 'turtle2'
                                controlled_turtle_name: ''
                                status: 0
                                linear: {x: 0.0, y: 0.0, z: 0.0}
                                angular: {x: 0.0, y: 0.0, z: 0.0}"  产生若干位置随即的新海龟
                                
    III，通过命令行rosservice call /command_turtle "new_turtle_name: ''
                                controlled_turtle_name: 'turtle1'
                                status: 1
                                linear: {x: 0.5, y: 0.0, z: 0.0}
                                angular: {x: 0.0, y: 0.0, z: 0.5}"  让指定海龟圆周运动
                                
    IV，通过命令行rosservice call /command_turtle "new_turtle_name: ''
                                controlled_turtle_name: 'turtle1'
                                status: 0
                                linear: {x: 0.5, y: 0.0, z: 0.0}
                                angular: {x: 0.0, y: 0.0, z: 0.5}"  让指定停止海龟圆周运动
                                
     注：status 表示海龟运动状态，0 是停止运动，1是开始圆周运动.
 2、作业2：

​    运行结果：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/blob/main/h_4/solution/hw2.mp4

3、作业3：

​	运行结果：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/blob/main/h_4/solution/hw3.png

​	代码：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/tree/main/h_4/solution/src/learning_tf/src

​	操作流程：通过命令 roslaunch learning_tf start_tf_demo.launch 启动节点.
