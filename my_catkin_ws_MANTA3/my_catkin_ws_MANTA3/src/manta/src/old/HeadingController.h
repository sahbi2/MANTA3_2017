#ifndef HEADINGCONTROLLER_H_
#define HEADINGCONTROLLER_H_

#include "ros/ros.h"
#include "control_toolbox/pid.h"
#include "std_msgs/Float32.h"

class HeadingController
{
	private:
	
	control_toolbox::Pid pid;
	double heading_set_point;
	double heading_measure;
	double command;
	ros::Time last_time;

	public:

	HeadingController(double p, double i, double d, double i_max, double i_min);
	double getCommand();
	double getMeasure();
	double getSetPoint();
	ros::Time getLastTime();
	void updateSetPoint(const std_msgs::Float32 set_point_msg);
	void updateMeasure(const std_msgs::Float32 measure_msg);
	void updateLastTime(ros::Time time);
	void computeCommand();
};

#endif /* HEADINGCONTROLLER_H_ */

