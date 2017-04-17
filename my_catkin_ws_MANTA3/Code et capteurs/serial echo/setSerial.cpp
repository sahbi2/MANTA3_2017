#include <iostream>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <errno.h>
#include <termios.h>
#include <time.h>

using namespace std;

int setSerial(int fd)
{
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
