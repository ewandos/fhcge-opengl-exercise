all: main

main: main.o pp3dLib.o ppObject.o
	g++ main.o pp3dLib.o ppObject.o -o myApp -lglut -lGLU -lGL

main.o: main.cpp
	g++ -c main.cpp

pp3dLib.o: pp3dLib.h pp3dLib.cpp
	g++ -c pp3dLib.cpp

ppObject.o: ppObject.h ppObject.cpp
	g++ -c ppObject.cpp

run: all
	./myApp

clean:
	rm *.o myApp -f
