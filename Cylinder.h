//
//  Cylinder class
//  The constructor sets the position, size and rotation
//  All parameters are assigned default values
//
#ifndef CYLINDER_H
#define CYLINDER_H

#include "Object.h"

class Cylinder: public Object
{
private:
   float sx,sy,sz;  //  Dimensions in X/Y/Z directions
public:
   Cylinder(const QString tex="");                 //  Constructor
   void setScale(float dx,float dy,float dz);  //  Set scale
   void display();                             //  Render the cube
};

#endif
