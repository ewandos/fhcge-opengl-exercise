#include "pp3dLib.h"
#include <GL/glut.h>

#ifndef PP_OBJECT
#define PP_OBJECT

class ppObject {
private:
  std::string identifier;
  ppMesh* mesh;
  Eigen::Vector3d position;
  std::vector<double> rotation;
  GLuint* texture;

public:
  ppObject(std::string identifier, ppMesh* mesh);

  void setIdentifier(std::string identifier);
  std::string getIdentifier();

  void setMesh(ppMesh* mesh);
  ppMesh* getMesh();

  void setPosition(Eigen::Vector3d pos);
  Eigen::Vector3d getPosition();

  void setRotation(double xRot, double yRot, double zRot);
  std::vector<double> getRotation();

  void setTexture(GLuint* texture);
  GLuint* getTexture();
  bool isTextured();
};

#endif
