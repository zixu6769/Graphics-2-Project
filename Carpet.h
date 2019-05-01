//
//  Carpet class
//  The constructor sets the position, size and rotation
//  All parameters are assigned default values
//
#ifndef CARPET_H
#define CARPET_H

#include "Object.h"

class Carpet: public Object
{
private:
   float sx,sy,sz;  //  Dimensions in X/Y/Z directions
public:
   Carpet(const QString tex="");               //  Constructor
   void setScale(float dx,float dy,float dz);  //  Set scale
   void display();                             //  Render the cube
};

#endif
