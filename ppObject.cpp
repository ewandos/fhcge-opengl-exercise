#include "ppObject.h"

ppObject::ppObject(std::string name, ppShape* shape) {
  this->name = name;
  this->shape = shape;
}

std::string ppObject::getName() {
  return this->name;
}

// TODO: draw at coordinates, i.e. implement glTranslatef here
void ppObject::draw() {
  // get segments of shape
  std::vector<ppSegment> segments = this->shape->getSegments();
  // LOAD IDENTITY CAN ONLY WORK HERE IF glTranslatef HAPPENS HERE!!!!!!!!
  // glLoadIdentity();
  // iterate over segments
  for(auto seg = std::begin(segments); seg != std::end(segments); ++seg) {
    // get points of segment
    std::vector<ppPosition> points = seg->getPoints();
    // begin drawing
    glBegin(seg->getMode());
    // iterate over points
    for(auto pt = std::begin(points); pt != std::end(points); ++pt) {
      glVertex3f(pt->x, pt->y, pt->z);
    }
    // end drawing
    glEnd();
  }
}
