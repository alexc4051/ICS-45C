#include "Square_pochienc.h"
#include "Circle_pochienc.h"
#include "Triangle_pochienc.h"
#include "Rectangle_pochienc.h"
#include "Picture_pochienc.h"

int main()
{ 
  Picture pictures;
  pictures.add(new Triangle(5,5,5));
  pictures.add(new Triangle(4,3,5));
  pictures.add(new Circle(5));
  pictures.add(new Circle(10));
  pictures.add(new Square(5.0,0,0));
  pictures.add(new Square (10.0));
  pictures.add(new Rectangle(4,8));
  pictures.add(new Rectangle(8,4));

  pictures.drawAll();
  cout <<"Total Area: " << pictures.totalArea() << endl;

  return 0;
}
