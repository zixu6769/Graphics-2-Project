//
//  Cube class
//
#include "Cube.h"

//
//  Constructor
//
Cube::Cube(const QString tex)
{
   sx = sy = sz = s = v = 1;
   if (tex.length()>0) setTexture(tex);
}

//
//  Set scaling
//
void Cube::setScale(float dx,float dy,float dz)
{
   sx = dx;
   sy = dy;
   sz = dz;
}

void Cube::setTex(float ds, float dv){
    s = ds;
    v = dv;
}

//
//  Display the cube
//
void Cube::display()
{
   if (!show) return;
   //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   useTransform(sx,sy,sz);
   //  Texture on
   EnableTex();
   //  Front
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f( 0, 0, 1);
   glTexCoord2f(0,0); glVertex3f(-1,-1, 1);
   glTexCoord2f(s,0); glVertex3f(+1,-1, 1);
   glTexCoord2f(s,v); glVertex3f(+1,+1, 1);
   glTexCoord2f(0,v); glVertex3f(-1,+1, 1);
   glEnd();
   //  Back
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f( 0, 0,-1);
   glTexCoord2f(0,0); glVertex3f(+1,-1,-1);
   glTexCoord2f(s,0); glVertex3f(-1,-1,-1);
   glTexCoord2f(s,v); glVertex3f(-1,+1,-1);
   glTexCoord2f(0,v); glVertex3f(+1,+1,-1);
   glEnd();
   //  Right
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f(+1, 0, 0);
   glTexCoord2f(0,0); glVertex3f(+1,-1,+1);
   glTexCoord2f(s,0); glVertex3f(+1,-1,-1);
   glTexCoord2f(s,v); glVertex3f(+1,+1,-1);
   glTexCoord2f(0,v); glVertex3f(+1,+1,+1);
   glEnd();
   //  Left
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f(-1, 0, 0);
   glTexCoord2f(0,0); glVertex3f(-1,-1,-1);
   glTexCoord2f(s,0); glVertex3f(-1,-1,+1);
   glTexCoord2f(s,v); glVertex3f(-1,+1,+1);
   glTexCoord2f(0,v); glVertex3f(-1,+1,-1);
   glEnd();
   //  Top
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f( 0,+1, 0);
   glTexCoord2f(0,0); glVertex3f(-1,+1,+1);
   glTexCoord2f(s,0); glVertex3f(+1,+1,+1);
   glTexCoord2f(s,v); glVertex3f(+1,+1,-1);
   glTexCoord2f(0,v); glVertex3f(-1,+1,-1);
   glEnd();
   //  Bottom
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f( 0,-1, 0);
   glTexCoord2f(0,0); glVertex3f(-1,-1,-1);
   glTexCoord2f(s,0); glVertex3f(+1,-1,-1);
   glTexCoord2f(s,v); glVertex3f(+1,-1,+1);
   glTexCoord2f(0,v); glVertex3f(-1,-1,+1);
   glEnd();
   //  Texture off
   DisableTex();
   //  Undo transofrmations
   glPopMatrix();
}
