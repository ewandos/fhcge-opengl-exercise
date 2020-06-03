#include "ppUtility.h"

#ifndef PP_SHAPE_CUBE
#define PP_SHAPE_CUBE

class ppShapeCube {
private:
  double length;
  ppPoint front[4];
  ppPoint back[4];
  ppPoint left[4];
  ppPoint right[4];
  ppPoint top[4];
  ppPoint bottom[4];

public:
  ppShapeCube(double length);
};

#endif
