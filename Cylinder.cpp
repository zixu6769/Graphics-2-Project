//
//  Draw a cylinder
//
#include "Cylinder.h"

//
//  Constructor
//
Cylinder::Cylinder(const QString tex)
{
   sx = sy = sz = 1;
   if (tex.length()>0) setTexture(tex);
}

//
//  Set scaling
//
void Cylinder::setScale(float dx,float dy,float dz)
{
   sx = dx;
   sy = dy;
   sz = dz;
}

//
//  Display the cylinder
//
void Cylinder::display()
{
   if (!show) return;
   //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   useTransform(sx,sy,sz);
   //  Texture on
   EnableTex();
   useColor(Color(0.5,0.5,0.5));
    int i;
    int steps = 15;
    float  phi, dphi = 2.*M_PI / (float)(steps);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi), 0, 0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(cos(phi), -2, sin(phi));
        glVertex3f(cos(phi), 0, sin(phi)); }
    glEnd();
   //  Texture off
   DisableTex();
   //  Undo transofrmations
   glPopMatrix();
}
