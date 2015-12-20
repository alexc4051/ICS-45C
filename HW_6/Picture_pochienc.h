#ifndef PICTURE_POCHIENC_H
#define PICTURE_POCHIENC_H

#include "Rectangle_pochienc.h"
#include "Square_pochienc.h"
#include "Triangle_pochienc.h"
#include "Circle_pochienc.h"
#include "Shape_pochienc.h"
#include <iostream>
using namespace std;

typedef class ShapeLinkedListPair * ShapeLinkedList;
class ShapeLinkedListPair
{
public:
  Shape * info;
  ShapeLinkedList next;
  ShapeLinkedListPair( Shape * newInfo, ShapeLinkedList newNext )
    : info(newInfo), next( newNext )
  {
  }
};


class Picture
{
  ShapeLinkedList head;
public:
  Picture()
    : head( 0 )
  {
  }
  void add( Shape * a )
  {
    head = new ShapeLinkedListPair( a, head );
  }
  double totalArea()
  {
    double total = 0.0;
    for (ShapeLinkedList p = head; p != 0; p = p->next)
      total += p->info->area();
    return total;
  }
  void drawAll()
  {
    for (ShapeLinkedList p=head; p!= 0; p = p->next)
      p->info->draw();
  }
  ~Picture()
  { ShapeLinkedList temp;
    for (ShapeLinkedList p = head; p != 0; )
    {
      temp = p;
      p = p->next;
      delete temp;
    }
  }  
};

#endif