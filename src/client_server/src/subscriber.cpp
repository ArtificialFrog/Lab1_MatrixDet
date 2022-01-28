#include "ros/ros.h"
#include "calculator/CountDeterminant.h"
#include "std_msgs/Float32.h" 
#include <iostream>

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
    
 return true;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "count_det_server");
    ros::NodeHandle n;
    
    ros::ServiceServer service = n.advertiseService("count_det_server", calculation);
    
    ROS_INFO_STREAM("READY");
    ros::spin();
    
    return 0;
}
