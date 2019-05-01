//
//  Mask class
//  The constructor sets the position, size and rotation
//  All parameters are assigned default values
//
#ifndef MASK_H
#define MASK_H

#include "Object.h"

class Mask: public Object
{
private:
   float sx,sy,sz;  //  Dimensions in X/Y/Z directions
   float s,v;       //  Texture repeat time
   float tx, ty, tz;
public:
   Mask(const QString tex="");                 //  Constructor
   void setScale(float dx,float dy,float dz);  //  Set scale
   void setGLtranslated(float nx, float ny, float nz);
   void setTex(float s, float v);              //  Set texture repeat time
   void display();                             //  Render the cube
};

#endif
