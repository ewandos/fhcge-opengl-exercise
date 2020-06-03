#include "ppUtility.h"
#include <vector>

#ifndef PP_SHAPE
#define PP_SHAPE

class ppShape {
private:
  // store "segments" aka list of ppSegment
  std::string name;
  std::vector<ppSegment> segments;

public:
  ppShape(std::string name, std::vector<ppSegment>);

  std::string getName();
  std::vector<ppSegment> getSegments();

};

#endif
