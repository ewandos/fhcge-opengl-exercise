#include <vector>
#include <iostream>
#include <GL/glut.h>
#include <eigen3/Eigen/Dense>

/*
 * PP_3DLIB
 * Contains data storing classes to:
 * - define attributes of PP_OBJECTS
 * - simplify 3d operations on PP_OBJECTS
 * - abstract 3d components
 */

#ifndef PP_FACE
#define PP_FACE

/*
 * Stores multiple ppPositions that form a chosen face of a ppMesh.
 * A face can be something like a 2d quad or a triangle in 3d space.
 * Such quad or triangle will be merged to a mesh (e.g. a qube).
 */
class ppFace {
private:
  GLenum mode; // type of face (needed by openGL)
  std::string name; // name to identify for example sides of a cube
  std::vector<Eigen::Vector3d> vertices;  // dynamic list of points of face

public:
  ppFace(GLenum mode, std::string name, std::vector<Eigen::Vector3d> vertices);

  GLenum getMode();
  std::string getName();
  std::vector<Eigen::Vector3d> getVertices();
};

#endif

#ifndef PP_MESH
#define PP_MESH

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
