#include <GL/glut.h>
#include "ppObject.h"
#include <eigen3/Eigen/Dense>
#include <iostream>

#ifndef PP_RENDERER
#define PP_RENDERER

class ppRenderer {
  GLuint texture;

public:
  void draw(ppObject obj);
  void draw(ppObject obj, Eigen::Vector3d* p);
};

#endif
