//
//  Floor class
//  The constructor sets the position, size and rotation
//  All parameters are assigned default values
//
#ifndef FLOOR_H
#define FLOOR_H

#include "Object.h"

class Floor: public Object
{
private:
   float sx,sy,sz;  //  Dimensions in X/Y/Z directions
public:
   Floor(const QString tex="");                //  Constructor
   void setScale(float dx,float dy,float dz);  //  Set scale
   void display();                             //  Render the Floor
};

#endif
