#include "pp3dLib.h"

// ---------- ppPosition ----------

ppPosition::ppPosition() {
  this->x = 0;
  this->y = 0;
  this->z = 0;
}

ppPosition::ppPosition(double x, double y, double z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

void ppPosition::describe() {
  std::cout << "x:" << this->x << ", ";
  std::cout << "y:" << this->y << ", ";
  std::cout << "z:" << this->z << std::endl;
}

// ---------- ppVector ----------

ppVector::ppVector() : ppPosition() {}

ppVector::ppVector(double x, double y, double z) : ppPosition(x, y, z) {}

ppVector ppVector::operator+(const ppVector& v) {
   ppVector vector;
   vector.x = this->x + v.x;
   vector.y = this->y + v.y;
   vector.z = this->z + v.z;
   return vector;
}

ppVector ppVector::operator-(const ppVector& v) {
    ppVector vector;
    vector.x = this->x - v.x;
    vector.y = this->y - v.y;
    vector.z = this->z - v.z;
    return vector;
}

ppVector ppVector::operator*(const ppVector& v) {
    ppVector vector;
    vector.x = this->x * v.x;
    vector.y = this->y * v.y;
    vector.z = this->z * v.z;
    return vector;
}

// ---------- ppFace ----------

ppFace::ppFace(GLenum mode, std::string name, std::vector<ppPosition> positions) {
  this->mode = mode;
  this->name = name;
  this->positions = positions;
}

GLenum ppFace::getMode() {
  return this->mode;
}

std::string ppFace::getName() {
  return this->name;
}

std::vector<ppPosition> ppFace::getPositions() {
  return this->positions;
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
