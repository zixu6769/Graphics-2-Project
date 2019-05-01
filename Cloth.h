//
//  Cloth class
//  The constructor sets the position, size and rotation
//  All parameters are assigned default values
//
#ifndef Cloth_H
#define Cloth_H

#include "Object.h"

class Cloth: public Object
{
private:
   float sx,sy,sz;  //  Dimensions in X/Y/Z directions
   float s,v;       //  Texture repeat time
   float tx, ty, tz;
public:
   Cloth(const QString tex="");                 //  Constructor
   void setScale(float dx,float dy,float dz);  //  Set scale
   void setGLtranslated(float nx, float ny, float nz);
   void setTex(float s, float v);              //  Set texture repeat time
   void display();                             //  Render the cube
};

#endif
