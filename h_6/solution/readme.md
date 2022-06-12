1.结果：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/blob/main/h_6/solution/result.mp4

2.代码：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/tree/main/h_6/solution/src

3.操作流程： 

      作业1 ：
      roslaunch my_robot_gazebo display_robot_gazebo_run.launch
      roslaunch mbot_teleop mbot_teleop.launch
      作业2:
      roslaunch my_robot_gazebo display_robot_gazebo_camera_lidar.launch
      roslaunch my_robot_gazebo display_robot_rviz.launch
      rostopic pub -r 10 /cmd_vel geometry_msgs/Twist "linear:
      x: 2.0
      y: 0.0
      z: 0.0
      angular:
      x: 0.0
      y: 0.0
      z: 2.0
