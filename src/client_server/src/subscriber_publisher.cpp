#include "ros/ros.h"
#include "calculator/CountDeterminant.h"
#include "std_msgs/Float32.h" 
#include <iostream>

ros::Publisher publisher;
ros::Subscriber subscriber;

bool calculation(calculator::CountDeterminant::Request &req,
                 calculator::CountDeterminant::Response &res)
{     
 res.det = req.x11 * req.x22 * req.x33 +
           req.x12 * req.x23 * req.x31 +
           req.x13 * req.x21 * req.x32 -
           req.x13 * req.x22 * req.x31 -
           req.x12 * req.x21 * req.x33 -
           req.x11 * req.x23 * req.x32;

 ROS_INFO_STREAM("determinant = " << res.det);
 
 std_msgs::Float32 det;
 det.data = float(res.det);
 publisher.publish(det);
    
 return true;
}

void parity_check(const std_msgs::Float32::ConstPtr& msg)
{
    float determinant = msg->data;
      
	if (int(determinant) == 0 || int(determinant) % 2 == 0)
	ROS_INFO_STREAM("even");
	else
	ROS_INFO_STREAM("odd");
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "count_det_server");
    ros::NodeHandle n;
    
    ros::ServiceServer service = n.advertiseService("count_det_server", calculation);
    
    publisher = n.advertise<std_msgs::Float32>("topic_parity", 10);
    subscriber = n.subscribe("topic_parity", 10, parity_check);
    
    ROS_INFO_STREAM("ready");
    ros::spin();
    
    return 0;
}
