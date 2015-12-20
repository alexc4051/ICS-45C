#ifndef SHAPE_POCHIENC_H
#define SHAPE_POCHIENC_H

class Shape
{
protected:
  int centerX;
  int centerY;
  double length;
public: 
Shape(int ncenterX = 0.00,	int ncenterY = 0.00, double nlength = 0.00)
  :centerX(ncenterX), centerY(ncenterY), length(nlength)
  {  }
virtual double area() = 0;
virtual void draw() const = 0; 
virtual ~Shape() {}
};

#endif