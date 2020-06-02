all: main

main:
	g++ main.cpp -o myApp -lglut -lGLU -lGL

run:
	./myApp

clean:
	rm *.o myApp -f
