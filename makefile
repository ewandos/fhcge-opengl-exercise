all: main

main: main.o ppUtility.o ppShape.o ppObject.o
	g++ main.o ppUtility.o ppShape.o ppObject.o -o myApp -lglut -lGLU -lGL

main.o: main.cpp
	g++ -c main.cpp

ppUtility.o: ppUtility.h ppUtility.cpp
	g++ -c ppUtility.cpp

ppShape.o: ppShape.h ppShape.cpp
	g++ -c ppShape.cpp

ppObject.o: ppObject.h ppObject.cpp
	g++ -c ppObject.cpp

run: all
	./myApp

clean:
	rm *.o myApp -f
