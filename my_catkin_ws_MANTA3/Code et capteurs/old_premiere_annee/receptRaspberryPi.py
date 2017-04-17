import serial
import time
import math
 
ser = serial.Serial('/dev/tty.usbmodem1411', 115200)

ser_radio = serial.Serial(
    port='/dev/tty.usbserial-A602XCIP',
    baudrate= 19200,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout = 0.5
)

moteur1 = 0
moteur2 = 0
message = 0

distance = 0;
angle = 0;

def receive_command():

        mes1 = ''
        mes2 = ''
        mes3 = ''

        global message
        global distance
        global angle
        
        i = 0
        
        if ser_radio.inWaiting() > 11:
                
                for i in range(1,5):
                        mes1 += ser_radio.read(1)
                for i in range(1,5):
                        mes2 += ser_radio.read(1)
                for i in range(1,5):
                        mes3 += ser_radio.read(1)
                        
                message  = int(mes1)
                distance = int(mes2)
                angle    = int(mes3)

                print("message  : " + str(message))
                print("distance : " + str(distance))
                print("angle    : " + str(angle))


def eval_command():

        global moteur1
        global moteur2
        global distance
        global angle

        moteur1 = int(109./300 * distance * 1./180 * angle + 70)
        moteur2 = int(109./300 * distance * 1./180 * (180 - angle) + 70)

        
def complete_message(value) :
        
        if len(value) == 1:
            out_message = '0' + '0' + '0' + value
        elif len(value) == 2:
            out_message = '0' + '0'       + value
        elif len(value) == 3:
            out_message = '0'             + value
        return out_message


while True:
        
        if ser_radio.inWaiting() > 11:
                
                receive_command()
                eval_command()
                            
                mes1 = str(complete_message(str(message)))
                mes2 = str(complete_message(str(moteur1)))
                mes3 = str(complete_message(str(moteur2)))
                
                print("message ar : " + mes1)
                print("moteur1 ar : " + mes2)
                print("moteur2 ar : " + mes3)

                ser.write(mes1)
                ser.write(mes2)
                ser.write(mes3)

