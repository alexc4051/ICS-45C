#ifndef CIRCLE_POCHIENC_H
#define CIRCLE_POCHIENC_H

#include "Shape_pochienc.h"
#include <iostream>
using namespace std;

class Circle:public Shape
{private:
    const double PI = 3.1415926535897;
 protected: 
    double radius;
 public:
    Circle( double nradius, double ncenterX = 0.0, double ncenterY = 0.0)
      : Shape(ncenterX,ncenterY,nradius), radius(nradius)
      {
      }
    virtual double area()
      {
        return PI*(radius)*(radius);
      }
      virtual void draw() const
      {
        cout << " ***  \n*   * \n*   * \n ***" << endl;
      }
};

#endif