#include <GL/glut.h>
#include <eigen3/Eigen/Dense>

#include "pp3dLib.h"
#include "ppObject.h"
#include "ppRenderer.h"
#include "ppMeshFactory.h"
#include "ppTextureLoader.h"


int window;
GLuint texture;
// pp libraries related variables
ppMeshFactory factory;
ppRenderer renderer;
ppTextureLoader texLoader;
// object related variables
ppObject cube = ppObject("cubeMesh", factory.getCubeMesh(1.0f));
// translation and rotation
double xRot = 0.0f;
double yRot = 0.0f;
double zRot = 0.0f;
double xOff = 0.0f;
double yOff = 0.0f;
double zOff = 0.0f;
bool translating = false;
bool rotating = false;
bool xDir = false;
bool yDir = false;
bool zDir = false;

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

void display() {

  // glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


  if(translating) {
    Eigen::Vector3d newPos = Eigen::Vector3d(xOff, yOff, zOff);
    cube.setPosition(newPos);
  }
  if(rotating) {
    cube.setRotation(xRot, yRot, zRot);
  }

  // draw cube
  renderer.draw(cube);
  glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y) {
  if (key == 27)  {
    glutDestroyWindow(window);
    exit(0);
  }

  /* TRANSLATING + ROTATING */

  // if 'g' is pressed, toggle translating if not rotating
  // + disable any directions
  if(key == 'g' && !rotating) {
    if(translating) {
      std::cout << "translating turned off" << std::endl;
      std::cout << "directions reset" << std::endl;
      std::cout << "offsets reset" << std::endl;
      translating = false;
      xDir = yDir = zDir = false;
      xOff = cube.getPosition()[0];
      yOff = cube.getPosition()[1];
      zOff = cube.getPosition()[2];
    }
    else {
      std::cout << "translating turned on" << std::endl;
      translating = true;
    }
  }
  // if 'r' is pressed, toggle rotating if not translating
  // + disable any directions
  if(key == 'r' && !translating) {
    if(rotating) {
      std::cout << "rotation turned off" << std::endl;
      std::cout << "axes reset" << std::endl;
      std::cout << "rotation offsets reset" << std::endl;
      rotating = false;
      xDir = yDir = zDir = false;
    }
    else {
      std::cout << "rotating turned on" << std::endl;
      rotating = true;
    }
  }

  // if translating or rotating, register direction
  if(key == 'x' && (translating || rotating)) {
    std::cout << "xDir turned on" << std::endl;
    xDir = true;
  }
  if(key == 'y' && (translating || rotating)) {
    yDir = true;
    std::cout << "yDir turned on" << std::endl;
  }
  if(key == 'z' && (translating || rotating)) {
    zDir = true;
    std::cout << "zDir turned on" << std::endl;
  }

  // if change rotation and translation offset
  if(key == 'w') {
    if(translating) {
      if(xDir) xOff += 0.1f;
      if(yDir) yOff += 0.1f;
      if(zDir) zOff += 0.1f;
    }
    if(rotating) {
      if(xDir) xRot += 12.0f;
      if(yDir) yRot += 12.0f;
      if(zDir) zRot += 12.0f;
    }
  }
  if(key == 's') {
    if(translating) {
      if(xDir) xOff += -0.1f;
      if(yDir) yOff += -0.1f;
      if(zDir) zOff += -0.1f;
    }
    if(rotating) {
      if(xDir) xRot += -12.0f;
      if(yDir) yRot += -12.0f;
      if(zDir) zRot += -12.0f;
    }
  }

  display();
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
  glDepthFunc(GL_SMOOTH);

  resize(width, height);

  texLoader.init();
}

int main(int argc, char **argv) {
  // Initialize Library
  glutInit(&argc, argv);

  // Build Window
  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
  glutInitWindowSize(640, 480);
  glutInitWindowPosition(0, 0);
  window = glutCreateWindow("Incocknito Headshot's Playground");

  // Pass handler functions
  glutDisplayFunc(&display);
  glutReshapeFunc(&resize);
  glutKeyboardFunc(&keyPressed);

  // Initialize openGL
  init(640, 480);

  // set object properties
  // set texture
  cube.setTexture(texLoader.getTexture());
  // set position
  cube.setPosition(Eigen::Vector3d(0.0f, 0.0f, -6.0f));
  cube.setRotation(0.0f, 0.0f, 0.0f);
  // translation and rotation variables to original value
  xOff = cube.getPosition()[0];
  yOff = cube.getPosition()[1];
  zOff = cube.getPosition()[2];
  xRot = cube.getRotation().at(0);
  yRot = cube.getRotation().at(1);
  xRot = cube.getRotation().at(2);

  glutMainLoop();
  return 0;
}
