//
//  Back of skybox
//  The constructor sets the position, size and rotation
//  All parameters are assigned default values
//
#ifndef SKYBACK_H
#define SKYBACK_H

#include "Object.h"

class Skyback: public Object
{
private:
   float sx,sy,sz;  //  Dimensions in X/Y/Z directions
public:
   Skyback(const QString tex="");                 //  Constructor
   void setScale(float dx,float dy,float dz);  //  Set scale
   void display();                             //  Render the cube
};

#endif
