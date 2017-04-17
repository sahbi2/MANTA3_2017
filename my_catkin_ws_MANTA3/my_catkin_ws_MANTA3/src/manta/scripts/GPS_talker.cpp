/*
 * Ce fichier reçoit les données du GPS Phidget 1040_0 et les publie sur un topic dédié.
 * --mars 2017--
 *
 * La structure de ce Publisher est celle proposée par le tutoriel du wikiROS : http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber(c%2B%2B) 
 * Outre la structure ROS qui est implémentée dans le main, 5 fonctions sont déclarées : 
 * 	int CCONV AttachHandler(CPhidgetHandle phid, void *userptr)
 * 	int CCONV DetachHandler(CPhidgetHandle phid, void *userptr)
 * 	int CCONV ErrorHandler(CPhidgetHandle phid, void *userptr, int ErrorCode, const char *unknown)
 * 	int CCONV fixChange(CPhidgetGPSHandle phid, void *userPtr, int status)
 * 	int CCONV posnChange(CPhidgetGPSHandle phid, void *userPtr, double latitude, double longitude, double altitude)
 * Elles sont issues des exemples fournis par Phidget21 qui sont implémentés en C++ et disponibles dans le dossier téléchargement de la Pi.
 * 
 * Seule la fonction posnChange(), appelée systématiquement lorsque le GPS émet des données, a été modifée.
 * Au lieu de simplement print les données, elle les enregistre dans des variables globales déclarées en-tête de ce fichier.
 * C'est le contenu de ces variables globales qui est utilisé dans le main, et plus particulièrement dans la boule while (ros::ok), pour créer le message qui est sera publié.
 * 
 * Concernant ce message, il faut, pour que le package robot_localisation fonctionne, mettre les données au format sensor_msgs/NavSatFix. 
 * Lorsque les problèmes de dépendances avec cette librairie auront été résolus il suffira d'instancier en global une instance de NavSatFix et de remplir les chamsp un par un dans la fonction posnChange()
 *
 */





// %Tag(FULLTEXT)%
// %Tag(ROS_HEADER)%
#include "ros/ros.h"
// %EndTag(ROS_HEADER)%
// %Tag(MSG_HEADER)%
#include "std_msgs/String.h"
// %EndTag(MSG_HEADER)%
#include <sstream>

#include <stdio.h>

#include <phidget21.h>

#include "sys/time.h"

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */


//global variables that contain the info to be sent
double lat;
double longi;
double spd;


int CCONV AttachHandler(CPhidgetHandle phid, void *userptr)
{
        GPSTime time;
        CPhidgetGPSHandle gps = (CPhidgetGPSHandle)phid;
        if(!CPhidgetGPS_getTime(gps, &time))
                printf("Attach handler ran at: %02d:%02d:%02d.%03d\n", time.tm_hour, time.tm_min, time.tm_sec, time.tm_ms);
        else
                printf("Attach handler ran!\n");
        return 0;
}

int CCONV DetachHandler(CPhidgetHandle phid, void *userptr)
{
        printf("Detach handler ran!\n");
        return 0;
}

int CCONV ErrorHandler(CPhidgetHandle phid, void *userptr, int ErrorCode, const char *unknown)
{
        printf("Error handler ran!\n");
        return 0;
}
int CCONV fixChange(CPhidgetGPSHandle phid, void *userPtr, int status)
{
        printf("Fix change event: %d\n", status);
        return 0;
}

int CCONV posnChange(CPhidgetGPSHandle phid, void *userPtr, double latitude, double longitude, double altitude)
{
        GPSDate date;
        GPSTime time;
        CPhidgetGPSHandle gps = (CPhidgetGPSHandle)phid;
        double heading, velocity;
	
        //printf("Position Change event: lat: %3.4lf, long: %4.4lf, alt: %5.4lf\n", latitude, longitude, altitude);
        //if(!CPhidgetGPS_getDate(gps, &date) && !CPhidgetGPS_getTime(gps, &time))
                //printf(" Date: %02d/%02d/%02d Time %02d:%02d:%02d.%03d\n", date.tm_mday, date.tm_mon, date.tm_year, time.tm_hour, time.tm_min, time.tm_sec, time.tm_ms);
        //if(!CPhidgetGPS_getHeading(gps, &heading) && !CPhidgetGPS_getVelocity(gps, &velocity))
                //printf(" Heading: %3.2lf, Velocity: %4.3lf\n",heading, velocity);
	lat = latitude;
	longi = longitude;
        
	if(!CPhidgetGPS_getHeading(gps, &heading) && !CPhidgetGPS_getVelocity(gps, &velocity))
	{
		spd = velocity;
	}

        return 0;
}


int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */

//init of the global variables 
   spd = 0;
// %Tag(INIT)%
  ros::init(argc, argv, "GPS_talker");
// %EndTag(INIT)%

  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
// %Tag(NODEHANDLE)%
  ros::NodeHandle n;
// %EndTag(NODEHANDLE)%

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */
// %Tag(PUBLISHER)%
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("gps", 1000);
// %EndTag(PUBLISHER)%

// %Tag(LOOP_RATE)%
  ros::Rate loop_rate(1);
// %EndTag(LOOP_RATE)%

  /**
   * A count of how many messages we have sent. This is used to create
   * a unique string for each message.
   */
// %Tag(ROS_OK)%
   int result;
   CPhidgetGPSHandle gps;
//CPhidget_enableLogging(PHIDGET_LOG_VERBOSE, NULL);

//---------initialisation du GPS, inspiré des exemples procurés par Phidget-----------------
  CPhidgetGPS_create(&gps);

  CPhidget_set_OnAttach_Handler((CPhidgetHandle)gps, AttachHandler, NULL);
  CPhidget_set_OnDetach_Handler((CPhidgetHandle)gps, DetachHandler, NULL);
  CPhidget_set_OnError_Handler((CPhidgetHandle)gps, ErrorHandler, NULL);

  CPhidgetGPS_set_OnPositionChange_Handler(gps, posnChange, NULL);
  CPhidgetGPS_set_OnPositionFixStatusChange_Handler(gps, fixChange, NULL);

  CPhidget_open((CPhidgetHandle)gps, -1);
  //Wait for 10 seconds, otherwise exit
  if(result = CPhidget_waitForAttachment((CPhidgetHandle)gps, 10000))
  {
  	 const char *err;
         CPhidget_getErrorDescription(result, &err);
         printf("Problem waiting for attachment: %s\n", err);
         return 1;
  }
//----------------------------------------

  int count = 0;//counts the number of messages sent
  
  while (ros::ok())
  {
    	/**
     	* This is a message object. You stuff it with data, and then publish it.
    	*/
	// %Tag(FILL_MESSAGE)%
    	std_msgs::String msg;

        printf("Latitude %d, longitude %d, speed %d",lat,longi,spd);

    	std::stringstream ss;
    	ss <<lat<<","<< longi <<","<< spd;
    	msg.data = ss.str();
	// %EndTag(FILL_MESSAGE)%

	// %Tag(ROSCONSOLE)%
    	ROS_INFO("%s", msg.data.c_str());
	// %EndTag(ROSCONSOLE)%

    	/**
     	* The publish() function is how you send messages. The parameter
     	* is the message object. The type of this object must agree with the type
     	* given as a template parameter to the advertise<>() call, as was done
     	* in the constructor above.
     	*/
	// %Tag(PUBLISH)%
    	chatter_pub.publish(msg);
	// %EndTag(PUBLISH)%

	// %Tag(SPINONCE)%
    	ros::spinOnce();
	// %EndTag(SPINONCE)%

	// %Tag(RATE_SLEEP)%
    	loop_rate.sleep();//param de frequence plus haut
	// %EndTag(RATE_SLEEP)%
   	++count;
  }

  CPhidget_close((CPhidgetHandle)gps);
  CPhidget_delete((CPhidgetHandle)gps);
  return 0;
}
// %EndTag(FULLTEXT)%
