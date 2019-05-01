//
//  Upper part of a tree
//
#include "Leaf.h"

//
//  Constructor
//
Leaf::Leaf(const QString tex)
{
   sx = sy = sz = 1;
   if (tex.length()>0) setTexture(tex);
}

//
//  Set scaling
//
void Leaf::setScale(float dx,float dy,float dz)
{
   sx = dx;
   sy = dy;
   sz = dz;
}

//
//  Display the leaf
//
void Leaf::display()
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
    // Layer 1
    int i;
    int steps = 15;
    float  phi, dphi = 2.*M_PI / (float)(steps);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi), 0, 0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(1.5*cos(phi), 0, 1.5*sin(phi));
        glVertex3f(0,2,0); }
    glEnd();
    
    
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi), 0, 0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(1.3*cos(phi), 1, 1.3*sin(phi));
        glVertex3f(0,3,0); }
    glEnd();
    
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi), 0, 0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(1.1*cos(phi), 2, 1.1*sin(phi));
        glVertex3f(0,4,0); }
    glEnd();
   
   //  Texture off
   DisableTex();
   //  Undo transofrmations
   glPopMatrix();
}
