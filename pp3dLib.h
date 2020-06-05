#include <vector>
#include <iostream>
#include <GL/glut.h>

/*
 * PP_3DLIB
 * Contains data storing classes to:
 * - define attributes of PP_OBJECTS
 * - simplify 3d operations on PP_OBJECTS
 * - abstract 3d components
 */

#ifndef PP_POSITION
#define PP_POSITION

/*
 * Stores a position in 3d space
 */
class ppPosition {
public:
  double x;
  double y;
  double z;

  ppPosition();
  ppPosition(double x, double y, double z);
  void describe();
};

#endif

#ifndef PP_VECTOR
#define PP_VECTOR

/*
 * Stores a vector in 3d space & can compute +, -, * operations
 */
class ppVector : public ppPosition {
public:
  ppVector();
  ppVector(double x, double y, double z);
  ppVector operator+(const ppVector& v);
  ppVector operator-(const ppVector& v);
  ppVector operator*(const ppVector& v);
};

#endif

#ifndef PP_SEGMENT
#define PP_SEGMENT

/*
 * Stores multiple ppPositions that form a chosen face of a ppMesh.
 * A face can be something like a 2d quad or a triangle in 3d space.
 * Such quad or triangle will be merged to a mesh (e.g. a qube).
 */
class ppFace {
private:
  GLenum mode; // type of face (needed by openGL)
  std::string name; // name to identify for example sides of a cube
  std::vector<ppPosition> positions;  // dynamic list of points of face

public:
  ppFace(GLenum mode, std::string name, std::vector<ppPosition> positions);

  GLenum getMode();
  std::string getName();
  std::vector<ppPosition> getPositions();
};

#endif

#ifndef PP_SHAPE
#define PP_SHAPE

/*
 * Stores multiple ppFaces to form a mesh of an object.
 * A mesh can be something like a 3d cube in 3d space.
 */
class ppMesh {
private:
  std::string name;
  std::vector<ppFace> faces;

public:
  ppMesh(std::string name, std::vector<ppFace>);

  std::string getName();
  std::vector<ppFace> getFaces();

};

#endif
