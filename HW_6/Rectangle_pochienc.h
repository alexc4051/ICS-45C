#ifndef RECTANGLE_POCHIENC_H
#define RECTANGLE_POCHIENC_H

#include "Square_pochienc.h"

class Rectangle:public Square
{
 protected: 
    double upside;
 public:
    Rectangle( double nside, double nupside, double ncenterX = 0.0, double ncenterY = 0.0)
      : Square(nside, centerX, ncenterY), upside(nupside)
      {
      }
    virtual double area()
      {
        return upside*Square::side;
      }
      virtual void draw() const
      {
        if (upside < Square::side)
            cout << "******\n*    *\n******" << endl;
        else
            cout << "***\n* *\n* *\n***"<<endl;
      }
};

#endif

