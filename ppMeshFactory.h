#include "pp3dLib.h"

#ifndef PP_MESH_FACTORY
#define PP_MESH_FACTORY

class ppMeshFactory {
public:
  ppMesh* getCubeMesh(double length);
  ppMesh* getPyramidMesh(double length, double height);
};

#endif
