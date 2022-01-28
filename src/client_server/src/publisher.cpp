#include "ros/ros.h"
#include "calculator/CountDeterminant.h"
#include <iostream>

int main(int argc, char **argv)
{
ros::init(argc, argv, "count_det_publisher");

ros::NodeHandle n;
ros::ServiceClient client = n.serviceClient<calculator::CountDeterminant>("count_det_server");
calculator::CountDeterminant srv;
   
    while (ros::ok())
    {
     float a[9];
    
     ROS_INFO_STREAM("Enter 9 elements of a 3x3 matrix");
     std::cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8];
    
     srv.request.x11 = a[0];
     srv.request.x12 = a[1];
     srv.request.x13 = a[2];
     srv.request.x21 = a[3];
     srv.request.x22 = a[4];
     srv.request.x23 = a[5];
     srv.request.x31 = a[6];
     srv.request.x32 = a[7];
     srv.request.x33 = a[8];
    
        if (client.call(srv))
        { 
         ROS_INFO_STREAM("determinant = " << srv.response.det);
          
		    if (int(srv.response.det) == 0 || int(srv.response.det) % 2 == 0)
	   	    ROS_INFO_STREAM("even");
		    else
	   	    ROS_INFO_STREAM("odd");
        }
        else
        {         
         ROS_INFO_STREAM("Failed to call service");
         return 1;
        }
    }

return 0;
}

