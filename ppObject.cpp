#include "ppObject.h"

ppObject::ppObject(std::string name, ppShape* shape) {
  this->name = name;
  this->shape = shape;
}

ppShape* ppObject::getShape() {
  return this->shape;
}

void ppObject::setPosition(ppPosition pos) {
  this->position = pos;
}

ppPosition ppObject::getPosition() {
  return this->position;
}

std::string ppObject::getName() {
  return this->name;
}

// TODO: draw at coordinates, i.e. implement glTranslatef here
void ppObject::draw() {
  // get segments of shape
  std::vector<ppSegment> segments = this->shape->getSegments();
  glLoadIdentity();
  glTranslatef(this->position.x, this->position.y, this->position.z);
  for(auto seg : segments) {
    // get points of segment
    std::vector<ppPosition> positions = seg.getPositions();
    // begin drawing
    glBegin(seg.getMode());
    // iterate over positions
    for(auto pos : positions) {
      glVertex3f(pos.x, pos.y, pos.z);
    }
    // end drawing
    glEnd();
  }
}
