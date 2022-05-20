/**
 * 该例程产生tf数据，用来广播 base_link -> base_laser的变换关系
 */

#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv)
{
    // 初始化ROS节点
	ros::init(argc, argv, "tf_broadcaster");

	// 创建句柄
	ros::NodeHandle node;

	// 创建tf的广播器
	static tf::TransformBroadcaster br;

	ros::Rate r(100);

  // 初始化tf数据
	tf::Transform transform;
	transform.setOrigin( tf::Vector3(0.1, 0.0, 0.2) );
	tf::Quaternion q;
	q.setRPY(0, 0, 0);
	transform.setRotation(q);

	while(node.ok()) {
		// 广播base_link与base_laser坐标系之间的tf数据
		br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "base_link", "base_laser"));
		r.sleep();
	}
	
	return 0;
};


