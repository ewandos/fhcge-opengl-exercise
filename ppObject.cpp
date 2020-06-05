#include "ppObject.h"

ppObject::ppObject(std::string name, ppMesh* mesh) {
  this->name = name;
  this->mesh = mesh;
  this->position = ppPosition();
}

ppMesh* ppObject::getMesh() {
  return this->mesh;
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
