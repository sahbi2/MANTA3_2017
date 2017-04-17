#include <Servo.h>

byte servoPinleft = 9;
byte servoPinright = 10;
Servo servoleft;
Servo servoright;

void setup() {
	servoleft.attach(servoPinleft);
	servoright.attach(servoPinright);

	servoleft.writeMicroseconds(1500); // send "stop" signal to ESC.
	servoright.writeMicroseconds(1500); // send "stop" signal to ESC.

	delay(1000); // delay to allow the ESC to recognize the stopped signal
}

void loop() {
	int signal = 1500; // Set signal value, which should be between 1100 and 1900

	servoleft.writeMicroseconds(signal+200); // Send signal to ESC.
	servoright.writeMicroseconds(signal-255); // Send signal to ESC.

        delay(10000);

	servoleft.writeMicroseconds(signal); // Send signal to ESC.
	servoright.writeMicroseconds(signal); // Send signal to ESC.

        delay(30000);
}

