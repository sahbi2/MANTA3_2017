
import math
import time
import serial

#ser = serial.Serial(
#    port='COM6',
#    baudrate= 19200,
#    parity=serial.PARITY_NONE,
#    stopbits=serial.STOPBITS_ONE,
#    bytesize=serial.EIGHTBITS,
#    timeout = 0.5
#)


def send_values(message,distance,angle):

        i = 0
        mes1 = str(int(message));
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

        print("message envoye : " + mes)

 #       ser.write(mes)
 #       while ser.outWaiting()>0:
 #               pass

        time.sleep(0.1)


        
from Tkinter import *
fenetre = Tk()

zone_controle = Canvas(fenetre, width=800, height=600)

zone_controle.pack()

bouton_centre = PhotoImage(file="Blue_Button.gif")
bouton_direct = PhotoImage(file="Yellow_Button.gif")
direction = {"x": 0, "y": 0, "item": None}

start = False
distance = 0;
angle = 0;
compteur = 0;

def start_navigation():
        global start
        start = not start

start_button = Button(fenetre, text="START", command=start_navigation)
start_button.pack(side = BOTTOM)

def create_token(x,y):
        zone_controle.create_image(x+400,y+300, anchor=CENTER, image=bouton_direct, tags="token")

def OnTokenButtonPress(event):
        direction["x"] = event.x
        direction["y"] = event.y
    
def OnTokenMotion(event):

        global compteur
        
        delta_x = event.x - direction["x"]
        delta_y = event.y - direction["y"]
        zone_controle.move("token", delta_x, delta_y)
        direction["x"] = event.x
        direction["y"] = event.y
        distance = abs(math.sqrt((direction["x"]-400)*(direction["x"]-400) + (direction["y"]-300)*(direction["y"]-300)))
        angle    = abs(math.atan2(direction["y"]-300,direction["x"]-300)*180/math.pi)

        message = 0;
        if start:
                message = 1;

        if compteur == 10:
                send_values(message,distance,angle)
                compteur = 0
        else:
                compteur += 1
        

zone_controle.create_image(400,300, anchor=CENTER, image=bouton_centre)
create_token(0,0)

zone_controle.tag_bind("token", "<ButtonPress-1>"   , OnTokenButtonPress   )
zone_controle.tag_bind("token", "<B1-Motion>"       , OnTokenMotion        )


fenetre.mainloop()
