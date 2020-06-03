#ifndef PP_POINT
#define PP_POINT

class ppPoint {
private:
  double x;
  double y;
  double z;

public:
  ppPoint();
  ppPoint(double x, double y, double z);

  void describe();
};

#endif
