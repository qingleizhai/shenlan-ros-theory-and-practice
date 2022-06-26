#!/usr/bin/env python
# -*- coding: utf-8 -*-
import rospy
from geometry_msgs.msg import Twist
from vision_msgs.msg import Detection2D, Detection2DArray, ObjectHypothesisWithPose

def object_subscriber():
    rospy.init_node('object_subscriber')

    rospy.Subscriber("objects", Detection2DArray, objectCallback)

    rospy.spin()

def vel_Control(x, y, w, h):
        speed = 0.5
        turn = 0.5
        line_x = 0
        th = 0
        control_speed = 0
        control_turn = 0
        rospy.loginfo("x %d, y %d, w %d, h %d", x, y, w, h)
       
        if (x <= 160):
            th = 1
        if (x > 320):
            th = -1
        if (w < 160):
            line_x = -1
        if (w > 260):
            line_x = 1
        
        control_speed = speed * line_x
        control_turn = turn * th

        twist = Twist()
        twist.linear.x = control_speed
        twist.linear.y = 0
        twist.linear.z = 0
        twist.angular.x = 0
        twist.angular.y = 0
        twist.angular.z = control_turn
        cmd_pub.publish(twist)

def vel_stop():
    twist = Twist()
    twist.linear.x = 0
    twist.linear.y = 0
    twist.linear.z = 0
    twist.angular.x = 0
    twist.angular.y = 0
    twist.angular.z = 0
    cmd_pub.publish(twist)

def objectCallback(obj):
    for i in range(len(obj.detections)):
        if (47 == int(obj.detections[i].results[0].id)):
            rospy.loginfo("obj.resulta.id %d obj.bbox.center.x %d obj.bbox.center.y %d obj.bbox.size_x %d obj.bbox.size_y %d", int(obj.detections[i].results[0].id), obj.detections[i].bbox.center.x, obj.detections[i].bbox.center.y, obj.detections[i].bbox.size_x, obj.detections[i].bbox.size_y)

            vel_Control(obj.detections[i].bbox.center.x, obj.detections[i].bbox.center.y, obj.detections[i].bbox.size_x, obj.detections[i].bbox.size_y)

        if (47 != int(obj.detections[i].results[0].id)):
            vel_stop()

if __name__ == '__main__':
    cmd_pub = rospy.Publisher("/cmd_vel", Twist, queue_size = 10)
    object_subscriber();