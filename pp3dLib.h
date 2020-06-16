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

#ifndef PP_3D_LIB
#define PP_3D_LIB

/*
lowest in the pp3dLib hierarchy, ppVertex stores
the vertex coordinates and normal vector data
*/
typedef struct vertex {
  Eigen::Vector3d vertexData;
  Eigen::Vector3d normalData;
  Eigen::Vector2d uvData;
  vertex(double x, double y, double z) {
    this->vertexData = Eigen::Vector3d(x, y, z);
  }
} ppVertex;

/*
ppPoint consists of n vertices with identical coordinates
*/
class ppPoint {
private:
  Eigen::Vector3d position;
  std::vector<ppVertex*> vertices;
public:
  ppPoint(ppVertex* vertex);
  void addVertex(ppVertex*);

  Eigen::Vector3d getPosition();
  std::vector<ppVertex*> getVertices();

};

/*
used for calculating which vertices lie on the same coordinates
*/
class ppPointFactory {
public:
  std::vector<ppPoint*>getPointsFromVertices(std::vector<ppVertex*>);
};

/*
stores all ppVertex that form a face
stores the mode of the face (needed by glBegin())
calculates and stores the normal of the face
assigns the face normal to the ppVertex
(the normals of ppVertex are recalculated in ppMesh)
*/
class ppFace {
private:
  GLenum mode; // type of face (needed by openGL)
  std::string name; // name to identify for example sides of a cube
  std::vector<ppVertex*> vertices;  // dynamic list of points of face
  Eigen::Vector3d faceNormal;
  std::vector<Eigen::Vector2d> uvCoords;

  Eigen::Vector3d calcFaceNormal();
  void calcUVCoordinates();

public:
  ppFace(GLenum mode, std::string name, std::vector<ppVertex*> vertices);

  GLenum getMode();
  std::string getName();

  std::vector<ppVertex*> getVertices();

  Eigen::Vector3d getFaceNormal();
};

/*
stores n faces that form the mesh
also stores a list of ppPoints, with which
the normals of each ppVertex are recalculated
*/
class ppMesh {
private:
  std::string name;
  std::vector<ppFace> faces;
  std::vector<ppPoint*> points;

public:
  ppMesh(std::string name, std::vector<ppFace>);

  void recalculateVertexNormals();

  std::string getName();
  std::vector<ppFace> getFaces();

};

#endif
