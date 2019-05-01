//
//  Tower class
//  The constructor sets the position, size and rotation
//  All parameters are assigned default values
//
#ifndef TOWER_H
#define TOWER_H

#include "Object.h"

class Tower: public Object
{
private:
   float sx,sy,sz;  //  Dimensions in X/Y/Z directions
public:
   Tower(const QString tex="");                 //  Constructor
   void setScale(float dx,float dy,float dz);  //  Set scale
   void display();                             //  Render the cube
};

#endif
