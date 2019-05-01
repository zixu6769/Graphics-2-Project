//
//  Mask class
//
#include "Mask.h"
#define Cos(th) cos(M_PI/180*(th))
#define Sin(th) sin(M_PI/180*(th))
//
//  Constructor
//
Mask::Mask(const QString tex)
{
   sx = sy = sz = s = v = 1;
   tx = ty = tz = 0;
   if (tex.length()>0) setTexture(tex);
}

//
//  Set scaling
//
void Mask::setScale(float dx,float dy,float dz)
{
   sx = dx;
   sy = dy;
   sz = dz;
}

void Mask::setGLtranslated(float nx, float ny, float nz){
    tx = nx;
    ty = ny;
    tz = nz;
}

void Mask::setTex(float ds, float dv){
    s = ds;
    v = dv;
}

//
//  Display the armor
//
void Mask::display()
{
   if (!show) return;
   //  Save transformation
   glPushMatrix();
   //  Texture on
   EnableTex();
   //  Gray color default
   useColor(Color(0.8,0.8,0.8));
   //  Overall position transform
   glTranslated(tx,tz,ty);
    useColor(Color(0.5,0.5,0.5));
    
    useTransform(0.6,0.5,0.5);
    glTranslated(0,14,0.3);
    glRotated(-45,0,1,0);
    glBegin(GL_QUADS);
    glNormal3f( 0, 0, 1);
    glTexCoord2f(0,0); glVertex3f(-1,-0.5, 1);
    glTexCoord2f(s,0); glVertex3f(+1,-1, 1);
    glTexCoord2f(s,v); glVertex3f(+1,+1, 1);
    glTexCoord2f(0,v); glVertex3f(-1,+0.5, 1);
    glEnd();
    glRotated(45,0,1,0);
    glTranslated(0,-14,-0.3);
    useTransform(1.666,2,2);
    
    useTransform(0.6,0.5,0.5);
    glTranslated(1.4,14,1.7);
    glRotated(225,0,1,0);
    glBegin(GL_QUADS);
    glNormal3f( 0, 0, 1);
    glTexCoord2f(0,0); glVertex3f(-1,-0.5, 1);
    glTexCoord2f(s,0); glVertex3f(+1,-1, 1);
    glTexCoord2f(s,v); glVertex3f(+1,+1, 1);
    glTexCoord2f(0,v); glVertex3f(-1,+0.5, 1);
    glRotated(-225,0,1,0);
    glTranslated(-1.4,-14,-1.7);
    useTransform(1.666,2,2);
    glEnd();
    
   //  Texture off
   DisableTex();
   //  Undo transofrmations
   glPopMatrix();
}
