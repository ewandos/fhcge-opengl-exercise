#include <vector>
#include <iostream>
#include <GL/glut.h>

#ifndef PP_POINT
#define PP_POINT

class ppPoint {
public:
  double x;
  double y;
  double z;

  ppPoint();
  ppPoint(double x, double y, double z);

  ppPoint operator+(const ppPoint& p);
  void describe();
};

#endif

#ifndef PP_SEGMENT
#define PP_SEGMENT

class ppSegment {
private:
  GLenum mode; // type of segment (needed by openGL)
  std::string name; // name to identify for example sides of a cube
  std::vector<ppPoint> points;  // dynamic list of points of segment

public:
  ppSegment(GLenum mode, std::string name, std::vector<ppPoint> points);

  GLenum getMode();
  std::string getName();
  std::vector<ppPoint> getPoints();
};

#endif

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