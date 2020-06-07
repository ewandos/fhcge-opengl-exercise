#include "pp3dLib.h"
#include <GL/glut.h>

#ifndef PP_OBJECT
#define PP_OBJECT

class ppObject {
private:
  std::string name;
  ppMesh* mesh;
  Eigen::Vector3d position;
  std::vector<double> rotation;

  // ppVector velocity;
  // ppVector acceleration;
public:
  ppObject(std::string name, ppMesh* mesh);

  std::string getName();

  ppMesh* getMesh();

  void setPosition(Eigen::Vector3d pos);
  Eigen::Vector3d getPosition();

  void setRotation(double xRot, double yRot, double zRot);
  std::vector<double> getRotation();

  //void rotateAround(ppObject parent, double d);
  /*
  translate toward parent's coordinates
  rotate around parent

  call draw
  */

  // spawn object at x, y, z and set mesh
  //Object(std::vector<double> location, matrix vertices);

  // add vector to current coordinates
  // void move(std::vector<double> update);

  //void setLoc(void);

  // some function to update velocity (based on acceleration?)
  // some function to update acceleration

  // some function to manipulate object's mesh

  /*
  some function to draw the object
  this includes resetting to the identity matrix,
  translating based on the current coordinates
  and then drawing a polygon based on the object's mesh
  */
};

#endif
