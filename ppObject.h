#include "pp3dLib.h"
#include <GL/glut.h>

#ifndef PP_OBJECT
#define PP_OBJECT

class ppObject {
private:
  std::string name;
  ppShape* shape;

  // std::vector<double> coordinates;
  // std::vector<double> velocity;
  // std::vector<double> acceleration;
public:
  ppObject(std::string name, ppShape* shape);

  std::string getName();
  void draw();

  // spawn object at x, y, z and set shape
  //Object(std::vector<double> location, matrix vertices);

  // add vector to current coordinates
  // void move(std::vector<double> update);

  //void setLoc(void);

  // some function to update velocity (based on acceleration?)
  // some function to update acceleration

  // some function to manipulate object's shape

  /*
  some function to draw the object
  this includes resetting to the identity matrix,
  translating based on the current coordinates
  and then drawing a polygon based on the object's shape
  */
};

#endif
