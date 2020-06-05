#include "ppMeshFactory.h"

ppMesh* ppMeshFactory::getCube(double length) {
  std::vector<ppFace> faces;
  // create faces
  // create vectors for points
  std::vector<ppPosition> front;
  front.push_back(ppPosition(-length, -length, length));
  front.push_back(ppPosition(-length, -length, -length));
  front.push_back(ppPosition(length, -length, -length));
  front.push_back(ppPosition(length, -length, length));

  std::vector<ppPosition> back;
  back.push_back(ppPosition(length, length, length));
  back.push_back(ppPosition(length, length, -length));
  back.push_back(ppPosition(-length, length, -length));
  back.push_back(ppPosition(-length, length, length));

  std::vector<ppPosition> left;
  left.push_back(ppPosition(-length, length, length));
  left.push_back(ppPosition(-length, length, -length));
  left.push_back(ppPosition(-length, -length, -length));
  left.push_back(ppPosition(-length, -length, length));

  std::vector<ppPosition> right;
  right.push_back(ppPosition(length, -length, length));
  right.push_back(ppPosition(length, -length, -length));
  right.push_back(ppPosition(length, length, -length));
  right.push_back(ppPosition(length, length, length));

  std::vector<ppPosition> top;
  top.push_back(ppPosition(-length, length, length));
  top.push_back(ppPosition(-length, -length, length));
  top.push_back(ppPosition(length, -length, length));
  top.push_back(ppPosition(length, length, length));

  std::vector<ppPosition> bottom;
  bottom.push_back(ppPosition(-length, -length, -length));
  bottom.push_back(ppPosition(-length, length, -length));
  bottom.push_back(ppPosition(length, length, -length));
  bottom.push_back(ppPosition(length, -length, -length));

  // add to faces vector
  faces.push_back(ppFace(GL_QUADS, "front", front));
  faces.push_back(ppFace(GL_QUADS, "back", back));
  faces.push_back(ppFace(GL_QUADS, "left", left));
  faces.push_back(ppFace(GL_QUADS, "right", right));
  faces.push_back(ppFace(GL_QUADS, "top", top));
  faces.push_back(ppFace(GL_QUADS, "bottom", bottom));

  // create mesh
  return new ppMesh("cube", faces);
}
