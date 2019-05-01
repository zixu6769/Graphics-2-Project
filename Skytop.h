//
//  Top of skybox
//  The constructor sets the position, size and rotation
//  All parameters are assigned default values
//
#ifndef SKYTOP_H
#define SKYTOP_H

#include "Object.h"

class Skytop: public Object
{
private:
   float sx,sy,sz;  //  Dimensions in X/Y/Z directions
public:
   Skytop(const QString tex="");                 //  Constructor
   void setScale(float dx,float dy,float dz);  //  Set scale
   void display();                             //  Render the cube
};

#endif
