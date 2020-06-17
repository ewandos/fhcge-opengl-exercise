all: main

main: main.o pp3dLib.o ppObject.o ppRenderer.o ppMeshFactory.o tga.o ppTextureLoader.o
	g++ *.o -o ppGraphics -lglut -lGLU -lGL

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

tga.o: tga.h tga.cpp
	g++ -c tga.cpp

ppTextureLoader.o: ppTextureLoader.h ppTextureLoader.cpp
	g++ -c ppTextureLoader.cpp

run: all
	./ppGraphics -smooth

clean:
	rm *.o ppGraphics -f
