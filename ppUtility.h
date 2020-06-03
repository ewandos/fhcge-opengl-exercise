#include <iostream>

class ppPoint {
private:
  double x;
  double y;
  double z;

public:
  ppPoint() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
  }
  ppPoint(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
  }

  void describe() {
    std::cout << "x: " << this->x << std::endl;
    std::cout << "y: " << this->y << std::endl;
    std::cout << "z: " << this->z << std::endl;
  }

};
