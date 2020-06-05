#include "ppShapeFactory.h"

ppShape* ppShapeFactory::getCube(double length) {
  std::vector<ppSegment> segments;
  // create segments
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

  // add to segments vector
  segments.push_back(ppSegment(GL_QUADS, "front", front));
  segments.push_back(ppSegment(GL_QUADS, "back", back));
  segments.push_back(ppSegment(GL_QUADS, "left", left));
  segments.push_back(ppSegment(GL_QUADS, "right", right));
  segments.push_back(ppSegment(GL_QUADS, "top", top));
  segments.push_back(ppSegment(GL_QUADS, "bottom", bottom));

  // create shape
  return new ppShape("cube", segments);
}
