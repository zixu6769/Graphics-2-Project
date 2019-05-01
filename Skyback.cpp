//
//  Back of skybox
//
#include "Skyback.h"

//
//  Constructor
//
Skyback::Skyback(const QString tex)
{
   sx = sy = sz = 1;
   if (tex.length()>0) setTexture(tex);
}

//
//  Set scaling
//
void Skyback::setScale(float dx,float dy,float dz)
{
   sx = dx;
   sy = dy;
   sz = dz;
}

void Skyback::display()
{
   if (!show) return;
   //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   useTransform(sx,sy,sz);
   //  Texture on
   EnableTex();

   //  Back
   useColor(Color(1,1,1));
   glBegin(GL_QUADS);
   glNormal3f( 0, 0,-1);
   glTexCoord2f(0,0); glVertex3f(+500,-500,-500);
   glTexCoord2f(1,0); glVertex3f(-500,-500,-500);
   glTexCoord2f(1,1); glVertex3f(-500,+500,-500);
   glTexCoord2f(0,1); glVertex3f(+500,+500,-500);
   glEnd();
   
   //  Texture off
   DisableTex();
   //  Undo transofrmations
   glPopMatrix();
}
