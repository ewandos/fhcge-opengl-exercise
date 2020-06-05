#include <GL/glut.h>
#include "pp3dLib.h"
#include "ppObject.h"
#include "ppRenderer.h"
#include "ppShapeFactory.h"

int window;

void resize(int width, int height)
{
  // prevent division by zero
  if (height == 0) { height=1; }

  glViewport(200, 200, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
}

void display() {

  ppRenderer renderer;
  // creating test cube

  ppShapeFactory factory;

  ppObject cube = ppObject("cube", factory.getCube(1.0f));

  // glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  renderer.draw(cube);

  glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y) {
  if (key == 27)  {
    glutDestroyWindow(window);
    exit(0);
  }

}

void init(int width, int height) {
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_SMOOTH);
  resize(width, height);
}

int main(int argc, char **argv) {
  // Initialize Library
  glutInit(&argc, argv);

  // Build Window
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
  glutInitWindowSize(2640, 1480);
  glutInitWindowPosition(0, 0);
  window = glutCreateWindow("Incocknito Headshot's Playground");

  // Pass handler functions
  glutDisplayFunc(&display);
  glutReshapeFunc(&resize);
  glutKeyboardFunc(&keyPressed);

  // Initialize openGL
  init(640, 480);


  glutMainLoop();
  return 0;
}
