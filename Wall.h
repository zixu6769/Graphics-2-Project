//
//  Wall class
//  The constructor sets the position, size and rotation
//  All parameters are assigned default values
//
#ifndef WALL_H
#define WALL_H

#include "Object.h"

class Wall: public Object
{
private:
   float sx,sy,sz;  //  Dimensions in X/Y/Z directions
public:
   Wall(const QString tex="");                 //  Constructor
   void setScale(float dx,float dy,float dz);  //  Set scale
   void display();                             //  Render the cube
};

#endif
