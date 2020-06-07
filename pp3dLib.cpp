#include "pp3dLib.h"

// ---------- ppFace ----------

ppFace::ppFace(GLenum mode, std::string name, std::vector<Eigen::Vector3d> vertices) {
  // TODO: error handling if insufficient vertices to create a face
  this->mode = mode;
  this->name = name;
  this->vertices = vertices;

  // calculate face normal
  Eigen::Vector3d v = vertices.at(1) - vertices.at(0);
  Eigen::Vector3d w = vertices.at(2) - vertices.at(0);
  this->normal = v.cross(w).normalized();
}

GLenum ppFace::getMode() {
  return this->mode;
}

std::string ppFace::getName() {
  return this->name;
}

std::vector<Eigen::Vector3d> ppFace::getVertices() {
  return this->vertices;
}

Eigen::Vector3d ppFace::getNormal() {
  return this->normal;
}

// ---------- ppMesh ----------

ppMesh::ppMesh(std::string name, std::vector<ppFace> faces) {
  this->name = name;
  this->faces = faces;
}

std::string ppMesh::getName() {
  return this->name;
}

std::vector<ppFace> ppMesh::getFaces() {
  return this->faces;
}
