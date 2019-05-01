//
//  Right of skybox
//
#include "Skyright.h"

//
//  Constructor
//
Skyright::Skyright(const QString tex)
{
   sx = sy = sz = 1;
   if (tex.length()>0) setTexture(tex);
}

//
//  Set scaling
//
void Skyright::setScale(float dx,float dy,float dz)
{
   sx = dx;
   sy = dy;
   sz = dz;
}

void Skyright::display()
{
   if (!show) return;
   //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   useTransform(sx,sy,sz);
   //  Texture on
   EnableTex();

   //  Right
   useColor(Color(1,1,1));
   glBegin(GL_QUADS);
   glNormal3f(+1, 0, 0);
   glTexCoord2f(0,0); glVertex3f(+500,-500,+500);
   glTexCoord2f(1,0); glVertex3f(+500,-500,-500);
   glTexCoord2f(1,1); glVertex3f(+500,+500,-500);
   glTexCoord2f(0,1); glVertex3f(+500,+500,+500);
   glEnd();
   
   //  Texture off
   DisableTex();
   //  Undo transofrmations
   glPopMatrix();
}
