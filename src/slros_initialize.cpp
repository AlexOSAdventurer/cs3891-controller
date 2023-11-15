#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "controller";

// For Block controller/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_controller_std_msgs_Float64> Sub_controller_36;

// For Block controller/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_controller_std_msgs_Float64> Sub_controller_58;

// For Block controller/Publish
SimulinkPublisher<std_msgs::Float64, SL_Bus_controller_std_msgs_Float64> Pub_controller_38;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

