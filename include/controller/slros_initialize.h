#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "controller_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block controller/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_controller_std_msgs_Float64> Sub_controller_36;

// For Block controller/Subscribe2
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_controller_std_msgs_Float64> Sub_controller_58;

// For Block controller/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_controller_std_msgs_Float64> Pub_controller_38;

void slros_node_init(int argc, char** argv);

#endif
