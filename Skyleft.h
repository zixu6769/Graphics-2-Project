//
//  Cube class
//  The constructor sets the position, size and rotation
//  All parameters are assigned default values
//
#ifndef SKYLEFT_H
#define SKYLEFT_H

#include "Object.h"

class Skyleft: public Object
{
private:
   float sx,sy,sz;  //  Dimensions in X/Y/Z directions
public:
   Skyleft(const QString tex="");                 //  Constructor
   void setScale(float dx,float dy,float dz);  //  Set scale
   void display();                             //  Render the cube
};

#endif
