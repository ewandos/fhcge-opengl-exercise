#include "pp3dLib.h"

// ---------- ppFace ----------

ppFace::ppFace(GLenum mode, std::string name, std::vector<Eigen::Vector3d> vertices) {
  this->mode = mode;
  this->name = name;
  this->vertices = vertices;
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
