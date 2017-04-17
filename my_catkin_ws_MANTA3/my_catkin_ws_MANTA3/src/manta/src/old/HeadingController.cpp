#include "HeadingController.h"

HeadingController::HeadingController(double p, double i, double d, double i_max, double i_min): command(0), heading_set_point(0), heading_measure(0)
{
	pid.initPid(6.0, 1.0, 2.0, 0.3, -0.3);
}

double HeadingController::getCommand()
{
	return command;
}

double HeadingController::getMeasure()
{
	return heading_measure;
}

double HeadingController::getSetPoint()
{
	return heading_set_point;
}

ros::Time HeadingController::getLastTime()
{
	return last_time;
}

void HeadingController::updateSetPoint(const std_msgs::Float32 set_point_msg)
{
	ROS_INFO("I heard the set point message");
	heading_set_point= (double) set_point_msg.data;
}

void HeadingController::updateMeasure(const std_msgs::Float32 measure_msg)
{
	ROS_INFO("I heard the measure message");
	heading_measure = (double) measure_msg.data;
}

void HeadingController::updateLastTime(ros::Time time)
{
	last_time = time;
}

void HeadingController::computeCommand()
{
	ros::Time time = ros::Time::now();
	command = pid.computeCommand(heading_set_point - heading_measure, time - last_time);
	updateLastTime(time);
}

