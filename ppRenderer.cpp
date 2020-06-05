#include "ppRenderer.h"

void ppRenderer::draw(ppObject obj, ppPosition* p) {

  ppPosition pos;
  if(p == nullptr) {
    pos = obj.getPosition();
  } else {
    pos = *p;
  }

  glLoadIdentity();
  glTranslatef(pos.x, pos.y, pos.z);

  // get segments of shape
  std::vector<ppSegment> segments = obj.getShape()->getSegments();

  // iterate over segments
  for(auto seg : segments) {
    // get points of segment
    std::vector<ppPosition> vertices = seg.getPositions();
    // begin drawing
    glBegin(seg.getMode());
    // iterate over vertices (positions)
    for(auto vertex : vertices) {
      glVertex3f(vertex.x, vertex.y, vertex.z);
    }
    // end drawing
    glEnd();
  }
}

void ppRenderer::draw(ppObject obj) {
  draw(obj, nullptr);
}
