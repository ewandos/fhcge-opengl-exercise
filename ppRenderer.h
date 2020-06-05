#include <GL/glut.h>
#include "ppObject.h"

#ifndef PP_RENDERER
#define PP_RENDERER

class ppRenderer {
public:
  void draw(ppObject obj);
};

#endif
