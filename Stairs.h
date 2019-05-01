//
//  Stairs class
//  The constructor sets the position, size and rotation
//  All parameters are assigned default values
//
#ifndef STAIRS_H
#define STAIRS_H

#include "Object.h"

class Stairs: public Object
{
private:
   float sx,sy,sz;  //  Dimensions in X/Y/Z directions
public:
   Stairs(const QString tex="");                 //  Constructor
   void setScale(float dx,float dy,float dz);  //  Set scale
   void display();                             //  Render the cube
};

#endif
