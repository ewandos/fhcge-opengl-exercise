#include "pp3dLib.h"

// ---------- ppPoint ----------

ppPoint::ppPoint() {
  this->x = 0;
  this->y = 0;
  this->z = 0;
}

ppPoint::ppPoint(double x, double y, double z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

void ppPoint::describe() {
  std::cout << "x: " << this->x << std::endl;
  std::cout << "y: " << this->y << std::endl;
  std::cout << "z: " << this->z << std::endl;
}

ppPoint ppPoint::operator+(const ppPoint& p) {
   ppPoint point;
   point.x = this->x + p.x;
   point.y = this->y + p.y;
   point.z = this->z + p.z;
   return point;
}

// ---------- ppSegment ----------

ppSegment::ppSegment(GLenum mode, std::string name, std::vector<ppPoint> points) {
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

std::vector<ppPoint> ppSegment::getPoints() {
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
