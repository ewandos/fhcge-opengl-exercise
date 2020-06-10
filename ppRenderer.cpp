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
  // get rotation
  std::vector<double> rot = obj.getRotation();
  // rotation in XYZ Euler
  glRotatef(rot.at(0), 1.0f, 0.0f, 0.0f);
  glRotatef(rot.at(1), 0.0f, 1.0f, 0.0f);
  glRotatef(rot.at(2), 0.0f, 0.0f, 1.0f);

  // get faces of mesh
  std::vector<ppFace> faces = obj.getMesh()->getFaces();

  // iterate over faces
  for(auto face : faces) {
    // get vertices of face
    std::vector<ppVertex*> vertices = face.getVertices();
    // begin drawing
    glBegin(face.getMode());
    // for each vertex
    for(ppVertex* vertex : vertices) {
      // draw its normal
      glNormal3f(vertex->normalData[0], vertex->normalData[1], vertex->normalData[2]);
      // draw the vertex
      glVertex3f(vertex->vertexData[0], vertex->vertexData[1], vertex->vertexData[2]);
    }
    // end drawing
    glEnd();

  }
}

void ppRenderer::draw(ppObject obj) {
  draw(obj, nullptr);
}
