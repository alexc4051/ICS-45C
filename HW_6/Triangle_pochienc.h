#ifndef TRIANGLE_POCHIENC_H
#define TRIANGLE_POCHIENC_H

#include "Shape_pochienc.h"
#include <cmath>
#include <iostream>
using namespace std;

class Triangle: public Shape
{
 protected: 
    double sidea;
    double sideb;
    double sidec;
 public:
    Triangle( double nsidea, double nsideb, double nsidec, double ncenterX = 0.0, double ncenterY = 0.0)
      : Shape(ncenterX,ncenterY,nsidea), sidea(nsidea), sideb(nsideb), sidec(nsidec)
      {
      }
    virtual double area()
      {
        double p = (sidea+sideb+sidec)/2;
        return sqrt(p * (p-sidea) * (p-sideb) * (p-sidec));
      }
      virtual void draw() const
      {
        cout << "  *\n * *\n*****\n"<<endl;
      }
};

#endif

