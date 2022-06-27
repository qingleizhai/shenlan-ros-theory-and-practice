1.结果：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/blob/main/h_8/solution/homework.mp4

2.代码：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/blob/dc214ea7de162ba698ba46604eef245815beb189/h_8/solution/src/robot_voice/src/voice_assistant.cpp#L140

3.操作流程： 

      roslaunch my_robot_gazebo display_robot_gazebo_run.launch
      roslaunch robot_voice voice_assistant.launch
      rostopic pub /voiceWakeup std_msgs/String data: '1'
      接着发送指令
