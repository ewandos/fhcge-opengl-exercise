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

// ---------- ppSegment ----------

ppSegment::ppSegment(GLenum mode, std::string name, std::vector<ppPosition> points) {
  this->mode = mode;
  this->name = name;
  this->points = points;
}

GLenum ppSegment::getMode() {
  return this->mode;
}

std::string ppSegment::getName() {
  return this->name;
}

std::vector<ppPosition> ppSegment::getPoints() {
  return this->points;
}

// ---------- ppShape ----------

ppShape::ppShape(std::string name, std::vector<ppSegment> segments) {
  this->name = name;
  this->segments = segments;
}

std::string ppShape::getName() {
  return this->name;
}

std::vector<ppSegment> ppShape::getSegments() {
  return this->segments;
}
