#include <GL/glut.h>
#include "pp3dLib.h"
#include "ppObject.h"

int window;

// this function needs to be implemented as a constructor (ppObject polymorphism)
ppObject createTestCube() {
  // create vector for segments
  std::vector<ppSegment> segments;
  // create segments
  // create vectors for points
  std::vector<ppPoint> front;
  front.push_back(ppPoint(0.0f, 0.0f, 0.0f));
  front.push_back(ppPoint(1.0f, 0.0f, 0.0f));
  front.push_back(ppPoint(1.0f, 1.0f, 0.0f));
  front.push_back(ppPoint(0.0f, 1.0f, 0.0f));

  std::vector<ppPoint> back;
  back.push_back(ppPoint(0.0f, 0.0f, 1.0f));
  back.push_back(ppPoint(1.0f, 0.0f, 1.0f));
  back.push_back(ppPoint(1.0f, 1.0f, 1.0f));
  back.push_back(ppPoint(0.0f, 1.0f, 1.0f));

  std::vector<ppPoint> left;
  left.push_back(ppPoint(1.0f, 0.0f, 0.0f));
  left.push_back(ppPoint(1.0f, 0.0f, 1.0f));
  left.push_back(ppPoint(1.0f, 1.0f, 1.0f));
  left.push_back(ppPoint(1.0f, 1.0f, 0.0f));

  std::vector<ppPoint> right;
  right.push_back(ppPoint(0.0f, 0.0f, 0.0f));
  right.push_back(ppPoint(0.0f, 0.0f, 1.0f));
  right.push_back(ppPoint(0.0f, 1.0f, 1.0f));
  right.push_back(ppPoint(0.0f, 1.0f, 0.0f));

  std::vector<ppPoint> top;
  top.push_back(ppPoint(0.0f, 1.0f, 0.0f));
  top.push_back(ppPoint(0.0f, 1.0f, 1.0f));
  top.push_back(ppPoint(1.0f, 1.0f, 1.0f));
  top.push_back(ppPoint(1.0f, 1.0f, 0.0f));

  std::vector<ppPoint> bottom;
  bottom.push_back(ppPoint(0.0f, 0.0f, 0.0f));
  bottom.push_back(ppPoint(1.0f, 0.0f, 0.0f));
  bottom.push_back(ppPoint(1.0f, 0.0f, 1.0f));
  bottom.push_back(ppPoint(0.0f, 0.0f, 1.0f));

  // add to segments vector
  segments.push_back(ppSegment(GL_QUADS, "front", front));
  segments.push_back(ppSegment(GL_QUADS, "back", back));
  segments.push_back(ppSegment(GL_QUADS, "left", left));
  segments.push_back(ppSegment(GL_QUADS, "right", right));
  segments.push_back(ppSegment(GL_QUADS, "top", top));
  segments.push_back(ppSegment(GL_QUADS, "bottom", bottom));

  // create shape
  ppShape* cubeShape = new ppShape("cubeShape", segments);

  // create object
  ppObject cube = ppObject("cube", cubeShape);

  return cube;
}

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

  // creating test cube
  ppObject cube = createTestCube();

  // glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glTranslatef(-2.0f, -1.5f, -6.0f);

  cube.draw();

  /*
  glBegin(GL_POLYGON);
  glVertex3f( 0.0f, 1.0f, 0.0f);
  glVertex3f( 1.0f,-1.0f, 0.0f);
  glVertex3f(-1.0f,-1.0f, 0.0f);
  glEnd();

  glTranslatef(3.0f,0.0f,0.0f);


  glBegin(GL_QUADS);
  glVertex3f(-1.0f, 1.0f, 0.0f);
  glVertex3f( 1.0f, 1.0f, 0.0f);
  glVertex3f( 1.0f,-1.0f, 0.0f);
  glVertex3f(-1.0f,-1.0f, 0.0f);
  glEnd();
  */

  glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y)
{
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
