#include "ppShape.h"
#include "ppUtility.h"

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
