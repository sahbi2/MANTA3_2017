#include "ros/ros.h"
#include "std_msgs/Float32.h"
#include "control_toolbox/pid.h"
#include "HeadingController.h"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "heading_controller");

  ros::NodeHandle n;

  double p, i, d, i_max, i_min;
  n.param("control_p", p, 6.0);
  n.param("control_i", i, 1.0);
  n.param("control_d", d, 2.0);
  n.param("control_i_max", i_max, 0.3);
  n.param("control_i_min", i_min, -0.3);

  HeadingController heading_controller(p,i,d,i_max,i_min); 

  ros::Publisher command_pub = n.advertise<std_msgs::Float32>("command", 1000);
  ros::Subscriber set_point_sub = n.subscribe("heading_set_point", 1000, &HeadingController::updateSetPoint, &heading_controller);
  ros::Subscriber measure_sub = n.subscribe("heading_measure", 1000, &HeadingController::updateMeasure, &heading_controller);

  ros::Rate loop_rate(10);

  int count = 0;
  heading_controller.updateLastTime(ros::Time::now());
  while (ros::ok())
  {
    std_msgs::Float32 command_msg;

    //Command processed by the PID
    heading_controller.computeCommand();

    //Get the command stored in the class
    command_msg.data = (float) heading_controller.getCommand();

    //Send the command message
    command_pub.publish(command_msg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

  return 0;
}

