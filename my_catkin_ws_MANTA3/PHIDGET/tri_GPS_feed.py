#!/usr/bin/python
# -*-coding:Latin-1 -*

def joinAfterSymbol(liste, car):
   string = ''
   for elt in liste:
      string += elt + car
   return string

def joinAfter(liste):
   string = ''
   for elt in liste:
      string += elt
   return string



def CoordsOutOfLine(string) :
	list1= string.split(': ',5)
	#print list1
	list_mod=[list1[2],list1[3],list1[4]]
	#print list_mod

	string1=joinAfterSymbol(list_mod,",");
	#print string1
	list2= string1.split(',',6);
	#print list2

	list_mod2 = [list2[0], list2[2], list2[4]]
	#print list_mod2

	#print "try to delete le back"
	string2=joinAfterSymbol(list_mod2,"\n")
	#print string2
	list3 = string2.split('\n',6)
	#print list3

	final_list=list3[0], list3[1], list3[2]

	final_str=joinAfterSymbol(final_list,";")
	#print(final_str)
	return final_str

def TestLine(string):
	list1= string.split(': ',5)
	if list1[0] == "Position Change event" and len(list1)==5:
		return 1
	return 0
	

#-----------------------------------------------------------------------------



fichier = open("/home/pi/Téléchargements/phidget21-c-examples-2.1.8.20151217/test_GPS/GPS_feed/gps_feed_ext.txt", "r")

lignes = fichier.readlines()


result=open("/home/pi/Téléchargements/phidget21-c-examples-2.1.8.20151217/test_GPS/GPS_feed_cleaned_ext.txt", "w");

for line in lignes :
	if TestLine(line)==1:
		stringus = CoordsOutOfLine(line)
		result.write(stringus)
		result.write("\n")


fichier.close()
result.close();
