#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <errno.h>
#include <termios.h>
#include <time.h>
#include <ros/ros.h>
#include <manta/Echo.h>
#include "std_msgs/String.h"
#include <sstream>

using namespace std;

int setSerial(int fd) {
    struct termios port_settings;      // structure to store the port settings in

    cfsetispeed(&port_settings, B9600);    // set baud rates
    cfsetospeed(&port_settings, B9600);

    port_settings.c_cflag |= CLOCAL | CREAD ;
    port_settings.c_cflag &= ~PARENB;    // set no parity, stop bits, data bits
    port_settings.c_cflag &= ~CSIZE;
    port_settings.c_cflag |= CS8;

    port_settings.c_cc[VTIME] = 200 ; // 20 seconds delay before read times out (must be >0 and <=255)
	
    tcsetattr(fd, TCSANOW, &port_settings);    // apply the settings to the port
    return(fd);
}

double getProfondeur(int fd) {
	int buffer[5];
	char data[1];
	int i = 0;
	int j;
	double profondeur = 0.0;
	
	read(fd, &data, sizeof(char));
	do {		
		read(fd, &data, sizeof(char));		
		if(data[0]=='0' || data[0]=='1' || data[0]=='2' || data[0]=='3' || data[0]=='4' || data[0]=='5' || data[0]=='6' || data[0]=='7' || data[0]=='8' || data[0]=='9') {					
			j = data[0] - 48;
			buffer[i] = j;
			i++;			
		}
	} while(data[0] != 'm');
	profondeur = (double) buffer[0]*100 + (double) buffer[1]*10 + (double) buffer[2] + (double) buffer[3]/10 + (double) buffer[4]/100;
	return profondeur; 
}

int main(int argc, char **argv) {
	int fd;
	
	fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);
	if(fd == -1) {
		printf("open_port: Unable to open /dev/ttyS0. \n");
		printf("Error : %s\n", strerror(errno));
	}
	else {
		fcntl(fd, F_SETFL, 0);
		printf("port is open !\n");
	}

	int hasBeenSet = setSerial(fd) ;
	if (hasBeenSet != -1) {
		cout << "Serial Port Set !" << endl ;
	}

	ros::init(argc, argv, "talker");
  	ros::NodeHandle n;

  	ros::Publisher echo_pub = n.advertise<manta::Echo>("/echo/data", 1000);
  	ros::Rate loop_rate(10);

  	while (ros::ok())  {
    		manta::Echo echo_data;
		echo_data.profondeur = getProfondeur(fd);

    		echo_pub.publish(echo_data);
    		ros::spinOnce();
    		loop_rate.sleep();
  	}

 	return 0;
}
// %EndTag(FULLTEXT)%
