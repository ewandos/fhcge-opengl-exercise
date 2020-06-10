#include "pp3dLib.h"

// ---------- ppPoint ----------

ppPoint::ppPoint(ppVertex* vertex) {
  this->position = vertex->vertexData;
  this->addVertex(vertex);
}

void ppPoint::addVertex(ppVertex* vertex) {
  this->vertices.push_back(vertex);
}

Eigen::Vector3d ppPoint::getPosition() {
  return this->position;
}

std::vector<ppVertex*> ppPoint::getVertices() {
  return this->vertices;
}

// ---------- ppPointFactory ----------

/*
this function takes a vector of vertices and
sums them up in points, based on their coordinates.
this way we end up with a list of points containing n vertices,
which makes the calculation of average normal vectors easier
*/
std::vector<ppPoint*> ppPointFactory::getPointsFromVertices(std::vector<ppVertex*> vertices) {
  std::vector<ppPoint*> points;

  bool done;
  for(ppVertex* vertex : vertices) {
    done = false;

    for(ppPoint* point : points) {

      if(point->getPosition() == vertex->vertexData) {
        point->addVertex(vertex);
        done = true;
      }

    }

    if(done) continue;
    else {
      points.push_back(new ppPoint(vertex));
    }
  }

  return points;
}

// ---------- ppFace ----------

ppFace::ppFace(GLenum mode, std::string name, std::vector<ppVertex*> vertices) {
  // TODO: error handling if insufficient vertices to create a face
  this->mode = mode;
  this->name = name;

  this->vertices = vertices;

  // calculate face normal
  this->faceNormal = this->calcFaceNormal();

  // vertex normals start out with face normal (averaging happens in ppMesh)
  for(ppVertex* vertex : vertices) {
    vertex->normalData = this->faceNormal;
  }

}

/*
function to calculate face normal
*/
Eigen::Vector3d ppFace::calcFaceNormal() {
  Eigen::Vector3d v = this->vertices.at(1)->vertexData - this->vertices.at(0)->vertexData;
  Eigen::Vector3d w = this->vertices.at(2)->vertexData - this->vertices.at(0)->vertexData;
  return v.cross(w).normalized();
}

GLenum ppFace::getMode() {
  return this->mode;
}

std::string ppFace::getName() {
  return this->name;
}

std::vector<ppVertex*> ppFace::getVertices() {
  return this->vertices;
}

Eigen::Vector3d ppFace::getFaceNormal() {
  return this->faceNormal;
}

// ---------- ppMesh ----------

ppMesh::ppMesh(std::string name, std::vector<ppFace> faces) {
  this->name = name;
  this->faces = faces;

  // create vector of all vertices of this mesh
  std::vector<ppVertex*> vertices;
  for(auto face : this->faces) {
    std::vector<ppVertex*> faceVertices = face.getVertices();
    vertices.insert(vertices.end(), faceVertices.begin(), faceVertices.end());
  }
  // get points from all mesh vertices
  this->points = ppPointFactory().getPointsFromVertices(vertices);

  // recalculate the vertex normals
  this->recalculateVertexNormals();
}
/*
recalculate the normals for each vertex of each point
by adding them together, then normalizing
*/
void ppMesh::recalculateVertexNormals() {
  for(ppPoint* point : this->points) {
    Eigen::Vector3d newNormal = Eigen::Vector3d(0.0f, 0.0f, 0.0f);

    for(ppVertex* vertex : point->getVertices()) {
      newNormal += vertex->normalData;
    }
    newNormal = newNormal.normalized();

    for(ppVertex* vertex : point->getVertices()) {
      vertex->normalData = newNormal;
    }
  }
}

std::string ppMesh::getName() {
  return this->name;
}

std::vector<ppFace> ppMesh::getFaces() {
  return this->faces;
}
