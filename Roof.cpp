//
//  Roof class
//
#include "Roof.h"

//
//  Constructor
//
Roof::Roof(const QString tex)
{
   sx = sy = sz = s = v = 1;
   if (tex.length()>0) setTexture(tex);
}

//
//  Set scaling
//
void Roof::setScale(float dx,float dy,float dz)
{
   sx = dx;
   sy = dy;
   sz = dz;
}

void Roof::setTex(float ds, float dv){
    s = ds;
    v = dv;
}

//
//  Display the roof
//
void Roof::display()
{
   if (!show) return;
   //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   useTransform(sx,sy,sz);
   //  Texture on
   EnableTex();
   //  left
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_TRIANGLES);
   glNormal3f( -1, 1, 0);
   glTexCoord2f(0,0); glVertex3f(-15.1,20,-10);
   glTexCoord2f(s,0); glVertex3f(-15.1,20,20);
   glTexCoord2f(s,v); glVertex3f(0,50,5);
   glEnd();
    // right
    glBegin(GL_TRIANGLES);
    glNormal3f( 1, 1, 0);
    glTexCoord2f(0,0); glVertex3f(15.1,20,-10);
    glTexCoord2f(s,0); glVertex3f(15.1,20,20);
    glTexCoord2f(s,v); glVertex3f(0,50,5);
    glEnd();
    // back
    glBegin(GL_TRIANGLES);
    glNormal3f( 0, 1, -1);
    glTexCoord2f(0,0); glVertex3f(-15.1,20,-10);
    glTexCoord2f(s,0); glVertex3f(15.1,20,-10);
    glTexCoord2f(s,v); glVertex3f(0,50,5);
    glEnd();
    // front
    glBegin(GL_TRIANGLES);
    glNormal3f( 0, 1, 1);
    glTexCoord2f(0,0); glVertex3f(-15.1,20,20);
    glTexCoord2f(s,0); glVertex3f(15.1,20,20);
    glTexCoord2f(s,v); glVertex3f(0,50,5);
    glEnd();
    
    // roof
    glBegin(GL_QUADS);
    glNormal3f( 0, -1, 0);
    glTexCoord2f(0,0); glVertex3f(-15.1,20,-10);
    glTexCoord2f(s,0); glVertex3f(+15.1,20,-10);
    glTexCoord2f(s,v); glVertex3f(+15.1,20,+20);
    glTexCoord2f(0,v); glVertex3f(-15.1,20,+20);
    glEnd();
    
   //  Texture off
   DisableTex();
   //  Undo transofrmations
   glPopMatrix();
}
