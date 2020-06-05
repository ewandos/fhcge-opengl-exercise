#include <vector>
#include <iostream>
#include <GL/glut.h>

#ifndef PP_POSITION
#define PP_POSITION

class ppPosition {
public:
  double x;
  double y;
  double z;

  ppPosition();
  ppPosition(double x, double y, double z);
  void describe();
};

#endif

#ifndef PP_VECTOR
#define PP_VECTOR

class ppVector : public ppPosition {
public:
  ppVector();
  ppVector(double x, double y, double z);
  ppVector operator+(const ppVector& v);
  ppVector operator-(const ppVector& v);
  ppVector operator*(const ppVector& v);
};

#endif

#ifndef PP_SEGMENT
#define PP_SEGMENT

class ppSegment {
private:
  GLenum mode; // type of segment (needed by openGL)
  std::string name; // name to identify for example sides of a cube
  std::vector<ppPosition> points;  // dynamic list of points of segment

public:
  ppSegment(GLenum mode, std::string name, std::vector<ppPosition> points);

  GLenum getMode();
  std::string getName();
  std::vector<ppPosition> getPoints();
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
