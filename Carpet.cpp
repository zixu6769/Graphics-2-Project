//
//  Carpet class
//
#include "Carpet.h"

//
//  Constructor
//
Carpet::Carpet(const QString tex)
{
   sx = sy = sz = 1;
   if (tex.length()>0) setTexture(tex);
}

//
//  Set scaling
//
void Carpet::setScale(float dx,float dy,float dz)
{
   sx = dx;
   sy = dy;
   sz = dz;
}

//
//  Display the Carpet
//
void Carpet::display()
{
   if (!show) return;
   //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   useTransform(sx,sy,sz);
   //  Texture on
   EnableTex();
   //  Front
   useColor(Color(1,0,0));
   glBegin(GL_QUADS);
   glNormal3f( 0, 1, 0);
   glTexCoord2f(0,0); glVertex3f(+2.5,-1.99, 20);
   glTexCoord2f(1,0); glVertex3f(+2.5,-1.99, 3);
   glTexCoord2f(1,1); glVertex3f(-2.5,-1.99, 3);
   glTexCoord2f(0,1); glVertex3f(-2.5,-1.99, 20);
   glEnd();
   //  Texture off
   DisableTex();
   //  Undo transofrmations
   glPopMatrix();
}
