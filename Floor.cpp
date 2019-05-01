//
//  Floor class
//
#include "Floor.h"

//
//  Constructor
//
Floor::Floor(const QString tex)
{
   sx = sy = sz = 1;
   if (tex.length()>0) setTexture(tex);
}

//
//  Set scaling
//
void Floor::setScale(float dx,float dy,float dz)
{
   sx = dx;
   sy = dy;
   sz = dz;
}

//
//  Display the floor
//
void Floor::display()
{
   if (!show) return;
   //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   useTransform(sx,sy,sz);
   //  Texture on
   EnableTex();
   //  First floor
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0, 1, 0);
    glTexCoord2f(0,0); glVertex3f(15,-2, 20);
    glTexCoord2f(1,0); glVertex3f(-15,-2, 20);
    glTexCoord2f(1,1); glVertex3f(-15,-2, -10);
    glTexCoord2f(0,1); glVertex3f(15,-2, -10);
    glEnd();
    
    // Second floor left side
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0, 1, 0);
    glTexCoord2f(0,0); glVertex3f(-12,3, 20);
    glTexCoord2f(1,0); glVertex3f(-15,3, 20);
    glTexCoord2f(1,1); glVertex3f(-15,3, -10);
    glTexCoord2f(0,1); glVertex3f(-12,3, -10);
    glEnd();
    
    // Second floor right side
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0, 1, 0);
    glTexCoord2f(0,0); glVertex3f(12,3, 20);
    glTexCoord2f(1,0); glVertex3f(15,3, 20);
    glTexCoord2f(1,1); glVertex3f(15,3, -10);
    glTexCoord2f(0,1); glVertex3f(12,3, -10);
    glEnd();
    
    // Second floor back side
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0, 1, 0);
    glTexCoord2f(0,0); glVertex3f(-15,3, -10);
    glTexCoord2f(1,0); glVertex3f(15,3, -10);
    glTexCoord2f(1,1); glVertex3f(15,3, -7);
    glTexCoord2f(0,1); glVertex3f(-15,3, -7);
    glEnd();
    
   //  Texture off
   DisableTex();
   //  Undo transofrmations
   glPopMatrix();
}
