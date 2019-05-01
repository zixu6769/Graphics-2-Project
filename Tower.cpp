//
//  Tower class
//
#include "Tower.h"

//
//  Constructor
//
Tower::Tower(const QString tex)
{
   sx = sy = sz = 1;
   if (tex.length()>0) setTexture(tex);
}

//
//  Set scaling
//
void Tower::setScale(float dx,float dy,float dz)
{
   sx = dx;
   sy = dy;
   sz = dz;
}

//
//  Display the tower
//
void Tower::display()
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
    // Lower half of the tower
    int i;
    int steps = 15;
    float  phi, dphi = 2.*M_PI / (float)(steps);
    
    
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi), 0, 0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(1*cos(phi), 0, 1*sin(phi));
        glVertex3f(1*cos(phi), 8, 1*sin(phi)); }
    //glTexCoord2f(1.0f, 0.5f);
    glEnd();
   
    //cap
    glBegin(GL_POLYGON);
    float theta = 0;
    glNormal3f( 0, -1, 0);
    for(int i = 0; i<360; i++){
        theta=i*3.142/180;
        glTexCoord2f(cos(theta)*0.5+0.5,sin(theta)*0.5 + 0.5);
        glVertex3f(1.5*sin(theta), 8, 1.5*cos(theta));
    }
    glEnd();
    
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi), 0, 0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(1.5*cos(phi), 8, 1.5*sin(phi));
        glVertex3f(0, 13, 0); }
    //glTexCoord2f(1.0f, 0.5f);
    glEnd();
   //  Texture off
   DisableTex();
   //  Undo transofrmations
   glPopMatrix();
}
