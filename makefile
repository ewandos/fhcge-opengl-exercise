all: main

main: main.o ppUtility.o ppShapeCube.o
	g++ main.o ppUtility.o -o myApp -lglut -lGLU -lGL

main.o: main.cpp
	g++ -c main.cpp

ppUtility.o: ppUtility.h ppUtility.cpp
	g++ -c ppUtility.cpp

ppShapeCube.o: ppShapeCube.h ppShapeCube.cpp
	g++ -c ppShapeCube.cpp

run: all
	./myApp

clean:
	rm *.o myApp -f
