#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <fcntl.h> 
#include <errno.h>
#include <termios.h>
#include <time.h>
#include "setSerial.h"
#include "sendMove.h"
#include "surf.h"
#include "corefunctions.h"

using namespace std;

int main()
{
    int fd; // file description for the serial port
	
    fd = open("/dev/ttyS0", O_RDWR | O_NOCTTY);
	
    if(fd == -1) // if open is unsucessful
    {
	//perror("open_port: Unable to open /dev/ttyS0 - ");
	printf("open_port: Unable to open /dev/ttyS0. \n");
	printf("Error : %s\n", strerror(errno));
    }
    else
    {
	fcntl(fd, F_SETFL, 0);
	printf("port is open !\n");
    }

    int hasBeenSet = setSerial(fd) ;
    if (hasBeenSet != -1) {
        cout << "Serial Port Set !" << endl ;
    }

    int movesDone = 0 ; // this variable is used in the tests to eventually stop moving even if there's no error
    int hasBeenMoved = 1 ; // 1 if no error, anything else breaks the loop
    int coords[3] ; // this array will contain the coordinates to reach
    int* state = (int*)malloc(2*sizeof(int)) ; // for "state" array structure, see details
    state[0] = 0 ;
    int grab = 0 ;

    while(hasBeenMoved==1 && movesDone < 10)
    {
	cout << "Move number : " << movesDone << endl ;

	int** detected = surf(800) ; // the higher the Hessian, the fewer detected keypoints. Bear in mind that if 			no keypoint is detected the program as it is could crash (or fail in the best case). It is advised 			to set a low Hessian. You can adjust the number of detected areas in surf.cpp through the number of 			keypoints necessary to recognize a cluster.

	state = algorithm(state, detected, coords) ;

	hasBeenMoved = 0 ;

	grab = state[1] ;
	
	cout << coords[0] << " " << coords[1] << " " << coords[2] << " and state is " << state[0] << endl ;
	//cout << detected[0][0] << " " << detected[0][1] << " " << detected[0][2] << endl ;
	//coords[0] = detected[0][0] ;
	//coords[1] = detected[0][1] ;
	//coords[2] = detected[0][2] ;

	hasBeenMoved = generate_message(coords, grab, fd) ;

        movesDone ++ ;
	cout << "End of loop iteration" << endl ;
    }

    cout << " -- End of the program -- " << endl ;
    
    close(fd) ;
    
    return(0) ;
}


