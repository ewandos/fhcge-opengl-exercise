#include "pp3dLib.h"

#ifndef PP_SHAPE_FACTORY
#define PP_SHAPE_FACTORY

class ppMeshFactory {
public:
  ppMesh* getCube(double length);
  ppMesh* getPyramid(double length, double height);

  ppMesh* getTestCube(double length);
};

#endif
