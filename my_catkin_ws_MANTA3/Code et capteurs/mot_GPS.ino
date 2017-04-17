#include <Servo.h>

byte servoPinleft = 9;
byte servoPinright = 10;
Servo servoleft;
Servo servoright;

float angleObjectif; // angle of objective from drone in degrees
		// angleobjectif = - angleDrone_nord + angleObjectif_nord
		// angleObjectif_nord = arccos( (lat_objectif - lat_drone)/sqrt((lon_drone-lon_objectif)^2 + (lat_drone-lat_objectif)^2) )
		// angle Drone_nord = angle au nord du drone donné par la centrale inertielle

void setup() {
	servoleft.attach(servoPinleft);
	servoright.attach(servoPinright);

	servoleft.writeMicroseconds(1500); // send "stop" signal to ESC.
	servoright.writeMicroseconds(1500); // send "stop" signal to ESC.

	delay(1000); // delay to allow the ESC to recognize the stopped signal
}

void loop() {
	int signal = 1500; // Set signal value, which should be between 1100 and 1900
//avec les branchements actuels normalement servoleft=moteur droit et servoright=moteur gauche 
//vu qu'on 'augmentait' servoright pour compenser la dérive vers la gauche
	
	if(angleObjectif<-45.0){ //tourne sur place vers la droite

		servoleft.writeMicroseconds(signal-50); // Send signal to ESC.
		servoright.writeMicroseconds(signal-59); // Send signal to ESC.
	}
	else if(angleObjectif<-5.0){ //avance en tournant vers la droite

		servoleft.writeMicroseconds(signal+59); // Send signal to ESC.
		servoright.writeMicroseconds(signal-79); // Send signal to ESC.
	}
	else if(angleObjectif>5.0){ //avance en tournant vers la gauche
	
		servoleft.writeMicroseconds(signal+70); // Send signal to ESC.
		servoright.writeMicroseconds(signal-59); // Send signal to ESC.
	}	
	else if(angleObjectif>45.0){ //tourne sur place vers la gauche
	
		servoleft.writeMicroseconds(signal+50); // Send signal to ESC.
		servoright.writeMicroseconds(signal+50); // Send signal to ESC.
	}	
	else{ //va tout droit
	
	servoleft.writeMicroseconds(signal+50); // Send signal to ESC.
	servoright.writeMicroseconds(signal-50); // Send signal to ESC.
	}

        delay(1000); // Check every 1s if the direction is good


}

