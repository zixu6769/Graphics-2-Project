//
//  Front of skybox
//  The constructor sets the position, size and rotation
//  All parameters are assigned default values
//
#ifndef SKYFRONT_H
#define SKYFRONT_H

#include "Object.h"

class Skyfront: public Object
{
private:
   float sx,sy,sz;  //  Dimensions in X/Y/Z directions
public:
   Skyfront(const QString tex="");                 //  Constructor
   void setScale(float dx,float dy,float dz);  //  Set scale
   void display();                             //  Render the cube
};

#endif
