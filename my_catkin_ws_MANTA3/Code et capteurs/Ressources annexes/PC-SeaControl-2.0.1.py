
import math
import time
import serial
import threading

ser = serial.Serial(
    port='/dev/tty.usbserial-A602XCIP',
    baudrate= 19200,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    timeout = 0.5
)

ser.flush()

speedrate = 10
anglerate = 5

def send_values(message,distance,angle):
        val = 0
        if message == True:
                val = 1
        i = 0
        mes1 = str(int(val));
        mes2 = str(int(distance));
        mes3 = str(int(angle));
        mes  = '';

        for i in range( 1, 5-len(mes1)):
                mes += '0'
        mes += mes1
        for i in range( 1, 5-len(mes2)):
                mes += '0'
        mes += mes2
        for i in range( 1, 5-len(mes3)):
                mes += '0'
        mes += mes3

        #print("message envoye : " + mes)

        ser.write(mes)
        while ser.outWaiting()>0:
                pass

        time.sleep(0.1)

        
from Tkinter import *
SeaControl = Tk()

start = False
speed = 0
angle = 85
r_time = 0

start_value = StringVar()
speed_value = StringVar()
angle_value = StringVar()

def set_valeur():
        global start, speed, angle
        start_value.set("start = "+str(start))
        speed_value.set("speed = "+str(speed))
        angle_value.set("angle = "+str(angle))

def auto_send():
        print("send")
        global start, speed, angle
        set_valeur()
        send_values(start,speed,angle)
        time.sleep(0.3)


Labelstart    = Label(SeaControl, textvariable = start_value, font=("Helvetica", 16), fg ='black', bg ='white', borderwidth=10)
Labelspeed    = Label(SeaControl, textvariable = speed_value, font=("Helvetica", 16), fg ='black', bg ='white', borderwidth=10)
Labelangle    = Label(SeaControl, textvariable = angle_value, font=("Helvetica", 16), fg ='black', bg ='white', borderwidth=10)

start_button = Button(SeaControl, text = "start", command=auto_send)
start_button.pack()
Labelstart.pack()
Labelspeed.pack()
Labelangle.pack()

set_valeur()

def command(event):
        global start, speed, speedrate, angle, anglerate
        touche = event.keysym
        #print(touche)
        if touche == 'Up':
                speed = speed + speedrate
                if speed > 170:
                        speed = 170
        if touche == 'Down':
                speed = speed - speedrate
                if speed < 0:
                        speed = 0
        if touche == 'Left':
                angle = angle + anglerate
                if angle > 170:
                        angle = 170
        if touche == 'Right':
                angle = angle - anglerate
                if angle < 0:
                        angle = 0
        if touche == 'space':
                start = not start
        if start == False:
                speed = 0
                angle = 85
        set_valeur()
        send_values(start,speed,angle)
        print(start)
        print(speed)
        print(angle)

        
SeaControl.bind('<Key>'  , command   )

class Auto_sender(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)

    def run(self):
        while True:
                auto_send()

sender = Auto_sender()
sender.start()

SeaControl.mainloop()
