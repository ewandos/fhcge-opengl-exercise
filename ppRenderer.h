#include <GL/glut.h>
#include "ppObject.h"
#include <eigen3/Eigen/Dense>

#ifndef PP_RENDERER
#define PP_RENDERER

class ppRenderer {
public:
  void draw(ppObject obj, GLuint texture);
  void draw(ppObject obj, Eigen::Vector3d* p, GLuint texture);
};

#endif
