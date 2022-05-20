/**
 * 该例程监听tf数据，完成数据的坐标变换
 */

#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <functional>



void transformPoint(const tf::TransformListener& listener){
  geometry_msgs::PointStamped laser_point;

  laser_point.header.frame_id = "base_laser";

  laser_point.header.stamp = ros::Time();

	//随机laser point
  laser_point.point.x = rand() % 10;
  laser_point.point.y = rand() % 10;
  laser_point.point.z = rand() % 10;

  try{
    geometry_msgs::PointStamped base_point;
		
		listener.waitForTransform("base_link", "base_laser", ros::Time(0), ros::Duration(3.0));
		
    listener.transformPoint("base_link", laser_point, base_point);
		
    ROS_INFO("base_laser: (%.2f, %.2f. %.2f) -----> base_link: (%.2f, %.2f, %.2f) at time %.2f",
							laser_point.point.x, laser_point.point.y, laser_point.point.z,
							base_point.point.x, base_point.point.y, base_point.point.z, 
							base_point.header.stamp.toSec());
  }
  catch(tf::TransformException& ex){
    ROS_ERROR("Received an exception trying to transform a point from base_laser ----> base_link: %s", ex.what());
  }

}

int main(int argc, char** argv)
{
	// 初始化ROS节点
	ros::init(argc, argv, "tf_listener");

    // 创建节点句柄
	ros::NodeHandle node;

	// 创建tf的监听器
	tf::TransformListener listener;

	// timer 创建回调函数
	ros::Timer timer = node.createTimer(ros::Duration(1.0), std::bind(&transformPoint, std::ref(listener)));

	ros::Rate rate(100);
	while (node.ok())
	{
		// 执行回调函数
		ros::spinOnce();

		rate.sleep();
	}
	return 0;
};
