#ifndef SQUARE_POCHIENC_H
#define SQUARE_POCHIENC_H

#include <iostream>
#include "Shape_pochienc.h"
using namespace std;

class Square:public Shape 
{
 protected: 
    double side;
 public:
    Square( double nside = 0.00, int ncenterX = 0, int ncenterY = 0)
	:Shape(ncenterX,ncenterY,nside), side(nside)
      {
      }
    virtual double area()
      {
        return side*side;
      }
    virtual void draw() const
      {
        cout << "****\n*  *\n****"<<endl;
      } 
};

#endif