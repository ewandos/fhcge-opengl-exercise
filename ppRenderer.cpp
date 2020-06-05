#include "ppRenderer.h"

void ppRenderer::draw(ppObject obj) {
  // get segments of shape

  ppPosition pos = obj.getPosition();

  glLoadIdentity();
  glTranslatef(pos.x, pos.y, pos.z);

  std::vector<ppSegment> segments = obj.getShape()->getSegments();
  for(auto seg : segments) {
    // get points of segment
    std::vector<ppPosition> vertices = seg.getPositions();
    // begin drawing
    glBegin(seg.getMode());
    // iterate over positions
    for(auto vertex : vertices) {
      glVertex3f(vertex.x, vertex.y, vertex.z);
    }
    // end drawing
    glEnd();
  }
}
