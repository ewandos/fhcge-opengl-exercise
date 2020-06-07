#include "ppObject.h"

ppObject::ppObject(std::string name, ppMesh* mesh) {
  this->name = name;
  this->mesh = mesh;
  this->position = Eigen::Vector3d();
}

ppMesh* ppObject::getMesh() {
  return this->mesh;
}

void ppObject::setPosition(Eigen::Vector3d pos) {
  this->position = pos;
}

Eigen::Vector3d ppObject::getPosition() {
  return this->position;
}

std::string ppObject::getName() {
  return this->name;
}
