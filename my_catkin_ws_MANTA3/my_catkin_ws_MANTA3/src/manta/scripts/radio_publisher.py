#!/usr/bin/env python

## Talker that publishes radio messages
## to the 'radio' topic

import rospy
import time
import serial
import math
from manta.msg import Radio
#from std_msgs  import Float32

def talker():
        ser = serial.Serial(
            port='/dev/ttyUSB0' ,
            baudrate=19200 ,
            parity=serial.PARITY_NONE ,
            stopbits=serial.STOPBITS_ONE ,
            bytesize=serial.EIGHTBITS,
            timeout = 0.5 ,
        )

        out = ''
        while ser.inWaiting()>0:
            out+=ser.read(1)

        mes1=''
        mes2=''
        mes3=''

	rospy.init_node('radio_publisher', anonymous=True)
	pub = rospy.Publisher('radio', Radio, queue_size=1)
	#pub2 = rospy.Publisher('heading_set_point', Float32, queue_size=10)
        now = rospy.get_rostime()
        new = rospy.get_rostime()
	r = Radio()
	r.message = 0
        r.valeur1 = 0
        r.valeur2 = 85
	#h = Float32()

	rate = rospy.Rate(20) # 20hz
        while not rospy.is_shutdown():
            if ser.inWaiting()>11:
                now = rospy.get_rostime()
		for i in range(1,5):
			mes1 += ser.read(1)
		for i in range(1,5):
			mes2 += ser.read(1)
		for i in range(1,5):
			mes3 += ser.read(1)
		if mes1.isdigit():
			r.message = int(mes1)
		if mes2.isdigit():
			r.valeur1 = int(mes2)
		if mes3.isdigit():
			r.valeur2 = int(mes3)
		
		#if mes1 == 2:
		#	h = float(mes3)
		#	pub2.publish(h)
			
		mes1 = ''
		mes2 = ''
		mes3 = ''
            else:
                new = rospy.get_rostime()
		print(new.secs - now.secs)
                if new.secs - now.secs > 1:
                    r.message = 0
                    r.valeur1 = 0
                    r.valeur2 = 85
            rospy.loginfo(r)
            pub.publish(r)
            rate.sleep()
	ser.close()
        

if __name__ == '__main__':
    try:
        talker()
	
    except rospy.ROSInterruptException:
        pass

