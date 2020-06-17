#include <GL/glut.h>
#include <eigen3/Eigen/Dense>

#include "pp3dLib.h"
#include "ppObject.h"
#include "ppRenderer.h"
#include "ppMeshFactory.h"
#include "ppTextureLoader.h"


int window;
GLuint texture;
ppMeshFactory factory;
ppRenderer renderer;
ppTextureLoader texLoader;

void resize(int width, int height)
{
  // prevent division by zero
  if (height == 0) { height=1; }

  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, (GLfloat)width/(GLfloat)height, 0.1f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
}

double xRot = 0.0f;
double yRot = 0.0f;
double zRot = 0.0f;
double size = 1.0f;

void display() {

  // glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  ppObject cube = ppObject("cube", factory.getCubeMesh(1.0f));
  cube.setPosition(Eigen::Vector3d(0.0f, 0.0f, -6.0f));
  cube.setRotation(xRot, yRot, zRot);
  cube.setTexture(texLoader.getTexture());

  renderer.draw(cube);
  glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y) {
  if (key == 27)  {
    glutDestroyWindow(window);
    exit(0);
  }

  if(key == 97) {
    size += 0.01f;
    display();
  }
  if(key == 115) {
    yRot += 1.0f;
    display();
  }
  if(key == 100) {
    zRot += 1.0f;
    display();
  }

}

void init(int width, int height) {
  GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat mat_shininess[] = { 5.0 };
  GLfloat light_position[] = { -10.0f, 10.0f, 10.0f, 0.0f };

  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);

  glShadeModel(GL_SMOOTH);

  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glClearDepth(1.0);
  glDepthFunc(GL_LESS);

  resize(width, height);

  texLoader.init();
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
