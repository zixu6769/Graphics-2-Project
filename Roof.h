//
//  Roof class
//  The constructor sets the position, size and rotation
//  All parameters are assigned default values
//
#ifndef ROOF_H
#define ROOF_H

#include "Object.h"

class Roof: public Object
{
private:
   float sx,sy,sz;  //  Dimensions in X/Y/Z directions
   float s,v;       //  Texture repeat time
public:
   Roof(const QString tex="");                 //  Constructor
   void setScale(float dx,float dy,float dz);  //  Set scale
   void setTex(float s, float v);              //  Set texture repeat time
   void display();                             //  Render the cube
};

#endif
