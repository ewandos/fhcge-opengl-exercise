#include "ppMeshFactory.h"

ppMesh* ppMeshFactory::getCube(double length) {
  std::vector<ppFace> faces;
  // create faces
  // create vectors for points
  std::vector<Eigen::Vector3d> front;
  front.push_back(Eigen::Vector3d(-length, -length, length));
  front.push_back(Eigen::Vector3d(-length, -length, -length));
  front.push_back(Eigen::Vector3d(length, -length, -length));
  front.push_back(Eigen::Vector3d(length, -length, length));

  std::vector<Eigen::Vector3d> back;
  back.push_back(Eigen::Vector3d(length, length, length));
  back.push_back(Eigen::Vector3d(length, length, -length));
  back.push_back(Eigen::Vector3d(-length, length, -length));
  back.push_back(Eigen::Vector3d(-length, length, length));

  std::vector<Eigen::Vector3d> left;
  left.push_back(Eigen::Vector3d(-length, length, length));
  left.push_back(Eigen::Vector3d(-length, length, -length));
  left.push_back(Eigen::Vector3d(-length, -length, -length));
  left.push_back(Eigen::Vector3d(-length, -length, length));

  std::vector<Eigen::Vector3d> right;
  right.push_back(Eigen::Vector3d(length, -length, length));
  right.push_back(Eigen::Vector3d(length, -length, -length));
  right.push_back(Eigen::Vector3d(length, length, -length));
  right.push_back(Eigen::Vector3d(length, length, length));

  std::vector<Eigen::Vector3d> top;
  top.push_back(Eigen::Vector3d(-length, length, length));
  top.push_back(Eigen::Vector3d(-length, -length, length));
  top.push_back(Eigen::Vector3d(length, -length, length));
  top.push_back(Eigen::Vector3d(length, length, length));

  std::vector<Eigen::Vector3d> bottom;
  bottom.push_back(Eigen::Vector3d(-length, -length, -length));
  bottom.push_back(Eigen::Vector3d(-length, length, -length));
  bottom.push_back(Eigen::Vector3d(length, length, -length));
  bottom.push_back(Eigen::Vector3d(length, -length, -length));

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
