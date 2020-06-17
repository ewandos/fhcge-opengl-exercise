#include "ppMeshFactory.h"

ppMesh* ppMeshFactory::getCubeMesh(double length) {
  std::vector<ppFace> faces;

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

  return new ppMesh("cubeMesh", faces);

}

ppMesh* ppMeshFactory::getPyramidMesh(double length, double height) {
  std::vector<ppFace> faces;
  std::vector<ppPoint*> points;

  // base face
  std::vector<ppVertex*> base;
  base.push_back(new ppVertex(-length/2, 0.0f, length/2));
  base.push_back(new ppVertex(length/2, 0.0f, length/2));
  base.push_back(new ppVertex(length/2, 0.0f, -length/2));
  base.push_back(new ppVertex(-length/2, 0.0f, -length/2));
  // front triangle
  std::vector<ppVertex*> front;
  front.push_back(new ppVertex(-length/2, 0.0f, length/2));
  front.push_back(new ppVertex(0.0f, height, 0.0f));
  front.push_back(new ppVertex(length/2, 0.0f, length/2));
  // back triangle
  std::vector<ppVertex*> back;
  back.push_back(new ppVertex(-length/2, 0.0f, -length/2));
  back.push_back(new ppVertex(0.0f, height, 0.0f));
  back.push_back(new ppVertex(length/2, 0.0f, -length/2));
  // left triangle
  std::vector<ppVertex*> left;
  left.push_back(new ppVertex(-length/2, 0.0f, length/2));
  left.push_back(new ppVertex(0.0f, height, 0.0f));
  left.push_back(new ppVertex(-length/2, 0.0f, -length/2));
  // right triangle
  std::vector<ppVertex*> right;
  right.push_back(new ppVertex(length/2, 0.0f, length/2));
  right.push_back(new ppVertex(0.0f, height, 0.0f));
  right.push_back(new ppVertex(length/2, 0.0f, -length/2));

  faces.push_back(ppFace(GL_QUADS, "base", base));
  faces.push_back(ppFace(GL_TRIANGLES, "front", front));
  faces.push_back(ppFace(GL_TRIANGLES, "back", back));
  faces.push_back(ppFace(GL_TRIANGLES, "left", left));
  faces.push_back(ppFace(GL_TRIANGLES, "right", right));

  return new ppMesh("pyramidMesh", faces);
}
