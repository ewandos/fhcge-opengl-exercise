#include "ppShapeCube.h"

ppShapeCube::ppShapeCube(double length) {
  this->front[0] = ppPoint(0.0f, 0.0f, 0.0f);
  this->front[1] = ppPoint(length, 0.0f, 0.0f);
  this->front[2] = ppPoint(length, length, 0.0f);
  this->front[3] = ppPoint(0.0f, length, 0.0f);

  this->back[0] = ppPoint(0.0f, 0.0f, length);
  this->back[1] = ppPoint(length, 0.0f, length);
  this->back[2] = ppPoint(length, length, length);
  this->back[3] = ppPoint(0.0f, length, length);

  this->left[0] = ppPoint(length, 0.0f, 0.0f);
  this->left[0] = ppPoint(length, 0.0f, length);
  this->left[0] = ppPoint(length, length, length);
  this->left[0] = ppPoint(length, length, 0.0f);

  this->right[0] = ppPoint(0.0f, 0.0f, 0.0f);
  this->right[0] = ppPoint(0.0f, 0.0f, length);
  this->right[0] = ppPoint(0.0f, length, length);
  this->right[0] = ppPoint(0.0f, length, 0.0f);

  this->top[0] = ppPoint(0.0f, length, 0.0f);
  this->top[0] = ppPoint(0.0f, length, length);
  this->top[0] = ppPoint(length, length, length);
  this->top[0] = ppPoint(length, length, 0.0f);

  this->bottom[0] = ppPoint(0.0f, 0.0f, 0.0f);
  this->bottom[0] = ppPoint(length, 0.0f, 0.0f);
  this->bottom[0] = ppPoint(length, 0.0f, length);
  this->bottom[0] = ppPoint(0.0f, 0.0f, length);
}
