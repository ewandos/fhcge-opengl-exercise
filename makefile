all: main

main:
	g++ main.cpp ppUtility.h -o myApp -lglut -lGLU -lGL

run: all
	./myApp

clean:
	rm *.o myApp -f
