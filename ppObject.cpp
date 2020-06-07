#include "ppObject.h"

ppObject::ppObject(std::string name, ppMesh* mesh) {
  this->name = name;
  this->mesh = mesh;
  this->position = Eigen::Vector3d();
  this->rotation = {0.0f, 0.0f, 0.0f};
}

std::string ppObject::getName() {
  return this->name;
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

void ppObject::setRotation(double xRot, double yRot, double zRot) {
  this->rotation.at(0) = xRot;
  this->rotation.at(1) = yRot;
  this->rotation.at(2) = zRot;
}

std::vector<double> ppObject::getRotation() {
  return this->rotation;
}
