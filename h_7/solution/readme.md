1.结果：

​	作业1： https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/blob/main/h_7/solution/homework_1.mp4

​	作业2：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/blob/main/h_7/solution/homework_2.mp4

2.代码：

​	作业1：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/blob/9ebf47a6621b846cae5901195ffb3433c56281ca/h_7/solution/src/robot_vision/scripts/face_detector.py#L64

​	作业2：https://github.com/qingleizhai/shenlan-ros-theory-and-practice-homework/blob/main/h_7/solution/src/tensorflow_object_detector/scripts/object_subscriber.py

3.操作流程： 

      作业1 ：
      roslaunch my_robot_gazebo display_robot_gazebo_run.launch
      roslaunch robot_vision usb_cam.launch
      roslaunch robot_vision face_detector.launch
      rqt_image_view
      作业2:
      roslaunch my_robot_gazebo display_robot_gazebo_run.launch
      source tensorflow/bin/activate
      roslaunch tensorflow_object_detector usb_cam_detector.launch
