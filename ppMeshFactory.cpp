#include "ppMeshFactory.h"

ppMesh* ppMeshFactory::getCubeMesh(double length) {
  std::vector<ppFace> faces;
  std::vector<ppPoint*> points;

  // front face
  std::vector<ppVertex*> front;
  front.push_back(new ppVertex(-length/2, -length/2, length/2));
  front.push_back(new ppVertex(-length/2, -length/2, -length/2));
  front.push_back(new ppVertex(length/2, -length/2, -length/2));
  front.push_back(new ppVertex(length/2, -length/2, length/2));
  // back face
  std::vector<ppVertex*> back;
  back.push_back(new ppVertex(length/2, length/2, length/2));
  back.push_back(new ppVertex(length/2, length/2, -length/2));
  back.push_back(new ppVertex(-length/2, length/2, -length/2));
  back.push_back(new ppVertex(-length/2, length/2, length/2));

  std::vector<ppVertex*> left;
  left.push_back(new ppVertex(-length/2, length/2, length/2));
  left.push_back(new ppVertex(-length/2, length/2, -length/2));
  left.push_back(new ppVertex(-length/2, -length/2, -length/2));
  left.push_back(new ppVertex(-length/2, -length/2, length/2));

  std::vector<ppVertex*> right;
  right.push_back(new ppVertex(length/2, -length/2, length/2));
  right.push_back(new ppVertex(length/2, -length/2, -length/2));
  right.push_back(new ppVertex(length/2, length/2, -length/2));
  right.push_back(new ppVertex(length/2, length/2, length/2));

  std::vector<ppVertex*> top;
  top.push_back(new ppVertex(-length/2, length/2, length/2));
  top.push_back(new ppVertex(-length/2, -length/2, length/2));
  top.push_back(new ppVertex(length/2, -length/2, length/2));
  top.push_back(new ppVertex(length/2, length/2, length/2));

  std::vector<ppVertex*> bottom;
  bottom.push_back(new ppVertex(-length/2, -length/2, -length/2));
  bottom.push_back(new ppVertex(-length/2, length/2, -length/2));
  bottom.push_back(new ppVertex(length/2, length/2, -length/2));
  bottom.push_back(new ppVertex(length/2, -length/2, -length/2));

  faces.push_back(ppFace(GL_QUADS, "front", front));
  faces.push_back(ppFace(GL_QUADS, "back", back));
  faces.push_back(ppFace(GL_QUADS, "left", left));
  faces.push_back(ppFace(GL_QUADS, "right", right));
  faces.push_back(ppFace(GL_QUADS, "top", top));
  faces.push_back(ppFace(GL_QUADS, "bottom", bottom));

  return new ppMesh("cube", faces);

}
