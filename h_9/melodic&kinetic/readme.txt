完成轨迹, 不接受进一步的数据。
rosservice call /finish_trajectory 0
序列化保存其当前状态
rosservice call /write_state "{filename: '${HOME}/Downloads/mymap.pbstream'}"
将pbstream转换为pgm和yaml
rosrun cartographer_ros cartographer_pbstream_to_ros_map -map_filestem=${HOME}/Downloads/mymap -pbstream_filename=${HOME}/Downloads/mymap.pbstream -resolution=0.05
生成对应的pgm和yaml，放于${HOME}/Downloads/mymap目录下

启动深度相机：

Kinect for Xbox 360
$ roslaunch openni_launch openni.launch depth_registration:=true
或新驱动
$ roslaunch freenect_launch freenect.launch depth_registration:=true
Mapping mode/建图模式：

启动rtabmapviz:
$ roslaunch rtabmap_ros rtabmap.launch rtabmap_args:="--delete_db_on_start"
启动rviz:
$ roslaunch rtabmap_ros rtabmap.launch rtabmap_args:="--delete_db_on_start" rviz:=true rtabmapviz:=false
参数"--delete_db_on_start"用于启动前先清除旧数据库

也可以进入界面后，选择"Edit->Delete memory"来清除旧数据库

或者调用命令 $ rosservice call /rtabmap/reset

效果图：

启用外部的里程数据，增加参数
"visual_odometry:=false odom_topic:=/my_odometry".
地图数据保存在 ~/.ros/rtabmap.db

可利databaseViewer工具查看数据库

$ rtabmap-databaseViewer ~/.ros/rtabmap.db
Localization mode/定位模式

在定位模式下，必须创建了足够大的地图（> 30个位置）
在rtabmapviz（GUI）中，单击“Detection”菜单中的“Localization”。
通过查看地图中的位置，RTAB-Map将通过查找闭环来定位。
一旦找到闭环，就会纠正里程，并且当前的云将在地图中对齐。
重定位方法：
$ rosservice call /rtabmap/reset_odom
或者界面下 Detection->"Reset odometry"
也可以通过启动luanch文件进入定位模式
<node name="rtabmap" pkg="rtabmap_ros" type="rtabmap" output="screen" args="">
   ...
   <param name="Mem/IncrementalMemory" type="string" value="false"/>
</node>
主要设置"Mem/IncrementalMemory" to "false"来启用定位模式

不能增加参数"--delete_db_on_start"

新版本可以直接执行：

$ roslaunch rtabmap_ros rtabmap.launch localization:=true
在GUI中,点击 Edit->"Download map" 从rtabmap节点下载地图。
一开始，您应该看到当前显示的云不与地图对齐，这是正常的，因为每次启动时都会重新设置里程。
通过查看地图中的位置，RTAB-Map将通过查找闭环来定位。
一旦找到闭环，量程就会被校正，并且当前的云将在地图中对齐。
参考：

http://wiki.ros.org/rtabmap_ros/Tutorials/HandHeldMapping




