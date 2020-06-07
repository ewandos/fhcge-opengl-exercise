#include "ppRenderer.h"

void ppRenderer::draw(ppObject obj, Eigen::Vector3d* p) {

  Eigen::Vector3d pos;
  if(p == nullptr) {
    pos = obj.getPosition();
  } else {
    pos = *p;
  }

  glLoadIdentity();
  glTranslatef(pos[0], pos[1], pos[2]);

  // get faces of mesh
  std::vector<ppFace> faces = obj.getMesh()->getFaces();

  // iterate over faces
  for(auto seg : faces) {
    // get points of face
    std::vector<Eigen::Vector3d> vertices = seg.getVertices();
    // begin drawing
    glBegin(seg.getMode());
    // iterate over vertices (positions)
    for(auto vertex : vertices) {
      glVertex3f(vertex[0], vertex[1], vertex[2]);
    }
    // end drawing
    glEnd();
  }
}

void ppRenderer::draw(ppObject obj) {
  draw(obj, nullptr);
}
