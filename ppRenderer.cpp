#include "ppRenderer.h"

void ppRenderer::draw(ppObject obj, Eigen::Vector3d* p) {
  GLuint texture;

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

  if (obj.isTextured()) {
    texture = obj.getTexture();
    std::cout << "TEXTURED!" << std::endl;
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texture);
  }

  // get faces of mesh
  std::vector<ppFace> faces = obj.getMesh()->getFaces();

  // iterate over faces
  for(auto face : faces) {
    // get points of face
    std::vector<Eigen::Vector3d> vertices = face.getVertices();
    // begin drawing
    glBegin(face.getMode());
    // get normal of face
    Eigen::Vector3d normal = face.getNormal();
    // set normal
    glNormal3f(normal[0], normal[1], normal[2]);
    // iterate over vertices (positions)


    // TESTING!!!
    int i = 0;
    for(auto vertex : vertices) {
      switch(i) {
        case 0:
          glTexCoord2f(0.0f, 0.0f);
          i++;
          break;
        case 1:
          glTexCoord2f(1.0f, 0.0f);
          i++;
          break;
        case 2:
          glTexCoord2f(1.0f, 1.0f);
          i++;
          break;
        case 3:
          glTexCoord2f(0.0f, 1.0f);
          i = 0;
          break;
      }
      // set vertex
      glVertex3f(vertex[0], vertex[1], vertex[2]);
    }
    // end drawing
    glEnd();
  }

  glDisable(GL_TEXTURE_2D);
}

void ppRenderer::draw(ppObject obj) {
  draw(obj, nullptr);
}
