all: main

main: main.o pp3dLib.o ppObject.o ppRenderer.o ppMeshFactory.o
	g++ main.o pp3dLib.o ppObject.o ppRenderer.o ppMeshFactory.o -o myApp -lglut -lGLU -lGL

main.o: main.cpp
	g++ -c main.cpp

pp3dLib.o: pp3dLib.h pp3dLib.cpp
	g++ -c pp3dLib.cpp

ppObject.o: ppObject.h ppObject.cpp
	g++ -c ppObject.cpp

ppRenderer.o: ppRenderer.h ppRenderer.cpp
	g++ -c ppRenderer.cpp

ppShapeFactory.o: ppMeshFactory.h ppMeshFactory.cpp
	g++ -c ppMeshFactory.cpp

run: all
	./myApp

clean:
	rm *.o myApp -f
