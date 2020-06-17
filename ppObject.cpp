#include "ppObject.h"

ppObject::ppObject(std::string identifier, ppMesh* mesh) {
  this->identifier = identifier;
  this->mesh = mesh;
  this->position = Eigen::Vector3d();
  this->rotation = {0.0f, 0.0f, 0.0f};
  this->texture = nullptr;
}

void ppObject::setIdentifier(std::string identifier) {
  this->identifier = identifier;
}

std::string ppObject::getIdentifier() {
  return this->identifier;
}

void ppObject::setMesh(ppMesh* mesh) {
  this->mesh = mesh;
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

void ppObject::setTexture(GLuint* texture) {
  this->texture = texture;
}

GLuint* ppObject::getTexture() {
  return this->texture;
}

bool ppObject::isTextured() {
  return this->texture != nullptr;
}
