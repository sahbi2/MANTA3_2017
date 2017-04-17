IoT : sendMove.o setSerial.o corefunctions.o main.o surf.o
	g++ sendMove.o setSerial.o corefunctions.o surf.o main.o -o control `pkg-config opencv --libs`

sendMove.o : sendMove.cpp
	g++ -c sendMove.cpp -Wall `pkg-config opencv --cflags`

setSerial.o : setSerial.cpp
	g++ -c setSerial.cpp -Wall `pkg-config opencv --cflags`

corefunctions.o : corefunctions.cpp
	g++ -c corefunctions.cpp -Wall `pkg-config opencv --cflags`

surf.o : surf.cpp
	g++ -c surf.cpp -Wall `pkg-config opencv --cflags`

main.o : main.cpp sendMove.h setSerial.h surf.h corefunctions.h
	g++ -c main.cpp -Wall `pkg-config opencv --cflags`

clean : 
	rm -rf *.o

mrproper : clean
	rm -rf control
