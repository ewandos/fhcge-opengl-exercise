#include "ppObject.h"

ppObject::ppObject(std::string name, ppShape* shape) {
  this->name = name;
  this->shape = shape;
  this->position = ppPosition();
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
