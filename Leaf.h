//
//  Upper part of a tree
//  The constructor sets the position, size and rotation
//  All parameters are assigned default values
//
#ifndef LEAF_H
#define LEAF_H

#include "Object.h"

class Leaf: public Object
{
private:
   float sx,sy,sz;  //  Dimensions in X/Y/Z directions
public:
   Leaf(const QString tex="");                 //  Constructor
   void setScale(float dx,float dy,float dz);  //  Set scale
   void display();                             //  Render the cube
};

#endif
