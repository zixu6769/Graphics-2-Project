//
//  Sword class
//
#include "Sword.h"
#define Cos(th) cos(M_PI/180*(th))
#define Sin(th) sin(M_PI/180*(th))
//
//  Constructor
//
Sword::Sword(const QString tex)
{
   sx = sy = sz = s = v = 1;
   tx = ty = tz = 0;
   if (tex.length()>0) setTexture(tex);
}

//
//  Set scaling
//
void Sword::setScale(float dx,float dy,float dz)
{
   sx = dx;
   sy = dy;
   sz = dz;
}

void Sword::setGLtranslated(float nx, float ny, float nz){
    tx = nx;
    ty = ny;
    tz = nz;
}

void Sword::setTex(float ds, float dv){
    s = ds;
    v = dv;
}

static void Vertex(double th,double ph)
{
    float s = th/360;
    float t = ph/180+0.5;
    float x = Sin(th)*Cos(ph);
    float y =         Sin(ph);
    float z = Cos(th)*Cos(ph);
    //  For a sphere at the origin, the position
    //  and normal vectors are the same
    glTexCoord2f(s,t);
    glNormal3f(x,y,z);
    glVertex3f(x,y,z);
}

//
//  Display the sword
//
void Sword::display()
{
   if (!show) return;
   //  Save transformation
   glPushMatrix();
   //  Texture on
   EnableTex();
   //  Gray color default
   useColor(Color(0.62,0.32,0.17));
   //  Value needed by cylinder
   int i;
   int steps = 15;
   float  phi, dphi = 2.*M_PI / (float)(steps);
   //  Overall position transform
   glTranslated(tx,tz,ty);
  
    // Hold
    useTransform(0.1,1.5,0.1);
    glTranslated(-13,2,17);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(1*cos(phi),0,1*sin(phi));
        glVertex3f(1*cos(phi),1,1*sin(phi)); }
    glEnd();
    glTranslated(13,-2,-17);
    useTransform(10,0.666,10);
    
    // Bottom
    useColor(Color(0.9,0.9,0.7));
    useTransform(0.2,0.2,0.2);
    glTranslated(-6.5,15,8.5);
    for (int ph=-90;ph<90;ph+=10)
    {
        glBegin(GL_QUAD_STRIP);
        for (int th=0;th<=360;th+=20)
        {
            Vertex(th,ph);
            Vertex(th,ph+10);
        }
        glEnd();
    }
    glTranslated(6.5,-15,-8.5);
    useTransform(5,5,5);
    // Mid
    useTransform(0.1,0.1,0.8);
    glTranslated(-13,45,2.15);
    //  Front
    glBegin(GL_QUADS);
    glNormal3f( 0, 0, 1);
    glTexCoord2f(0,0); glVertex3f(-1,-1, 1);
    glTexCoord2f(s,0); glVertex3f(+1,-1, 1);
    glTexCoord2f(s,v); glVertex3f(+1,+1, 1);
    glTexCoord2f(0,v); glVertex3f(-1,+1, 1);
    glEnd();
    //  Back
    glBegin(GL_QUADS);
    glNormal3f( 0, 0,-1);
    glTexCoord2f(0,0); glVertex3f(+1,-1,-1);
    glTexCoord2f(s,0); glVertex3f(-1,-1,-1);
    glTexCoord2f(s,v); glVertex3f(-1,+1,-1);
    glTexCoord2f(0,v); glVertex3f(+1,+1,-1);
    glEnd();
    //  Right
    glBegin(GL_QUADS);
    glNormal3f(+1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(+1,-1,+1);
    glTexCoord2f(s,0); glVertex3f(+1,-1,-1);
    glTexCoord2f(s,v); glVertex3f(+1,+1,-1);
    glTexCoord2f(0,v); glVertex3f(+1,+1,+1);
    glEnd();
    //  Left
    glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(-1,-1,-1);
    glTexCoord2f(s,0); glVertex3f(-1,-1,+1);
    glTexCoord2f(s,v); glVertex3f(-1,+1,+1);
    glTexCoord2f(0,v); glVertex3f(-1,+1,-1);
    glEnd();
    //  Top
    glBegin(GL_QUADS);
    glNormal3f( 0,+1, 0);
    glTexCoord2f(0,0); glVertex3f(-1,+1,+1);
    glTexCoord2f(s,0); glVertex3f(+1,+1,+1);
    glTexCoord2f(s,v); glVertex3f(+1,+1,-1);
    glTexCoord2f(0,v); glVertex3f(-1,+1,-1);
    glEnd();
    //  Bottom
    glBegin(GL_QUADS);
    glNormal3f( 0,-1, 0);
    glTexCoord2f(0,0); glVertex3f(-1,-1,-1);
    glTexCoord2f(s,0); glVertex3f(+1,-1,-1);
    glTexCoord2f(s,v); glVertex3f(+1,-1,+1);
    glTexCoord2f(0,v); glVertex3f(-1,-1,+1);
    glEnd();
    glTranslated(13,-45,-2.15);
    useTransform(10,10,1.25);
    
    // Blade body
    useColor(Color(0.6,0.6,0.6));
    useTransform(0.05,2,0.25);
    glTranslated(-26,3.25,6.75);
    //  Front
    glBegin(GL_QUADS);
    glNormal3f( 0, 0, 1);
    glTexCoord2f(0,0); glVertex3f(-1,-1, 1);
    glTexCoord2f(s,0); glVertex3f(+1,-1, 1);
    glTexCoord2f(s,v); glVertex3f(+1,+1, 1);
    glTexCoord2f(0,v); glVertex3f(-1,+1, 1);
    glEnd();
    //  Back
    glBegin(GL_QUADS);
    glNormal3f( 0, 0,-1);
    glTexCoord2f(0,0); glVertex3f(+1,-1,-1);
    glTexCoord2f(s,0); glVertex3f(-1,-1,-1);
    glTexCoord2f(s,v); glVertex3f(-1,+1,-1);
    glTexCoord2f(0,v); glVertex3f(+1,+1,-1);
    glEnd();
    //  Right
    glBegin(GL_QUADS);
    glNormal3f(+1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(+1,-1,+1);
    glTexCoord2f(s,0); glVertex3f(+1,-1,-1);
    glTexCoord2f(s,v); glVertex3f(+1,+1,-1);
    glTexCoord2f(0,v); glVertex3f(+1,+1,+1);
    glEnd();
    //  Left
    glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(-1,-1,-1);
    glTexCoord2f(s,0); glVertex3f(-1,-1,+1);
    glTexCoord2f(s,v); glVertex3f(-1,+1,+1);
    glTexCoord2f(0,v); glVertex3f(-1,+1,-1);
    glEnd();
    //  Top
    glBegin(GL_QUADS);
    glNormal3f( 0,+1, 0);
    glTexCoord2f(0,0); glVertex3f(-1,+1,+1);
    glTexCoord2f(s,0); glVertex3f(+1,+1,+1);
    glTexCoord2f(s,v); glVertex3f(+1,+1,-1);
    glTexCoord2f(0,v); glVertex3f(-1,+1,-1);
    glEnd();
    //  Bottom
    glBegin(GL_QUADS);
    glNormal3f( 0,-1, 0);
    glTexCoord2f(0,0); glVertex3f(-1,-1,-1);
    glTexCoord2f(s,0); glVertex3f(+1,-1,-1);
    glTexCoord2f(s,v); glVertex3f(+1,-1,+1);
    glTexCoord2f(0,v); glVertex3f(-1,-1,+1);
    glEnd();
    //  point
    glBegin(GL_TRIANGLES);
    glNormal3f( -1,0, 0);
    glTexCoord2f(0,0); glVertex3f(-1,+1,+1);
    glTexCoord2f(s,0); glVertex3f(-1,+1,-1);
    glTexCoord2f(s,v); glVertex3f(+0,+1.5,0);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glNormal3f( +1,0, 0);
    glTexCoord2f(0,0); glVertex3f(1,+1,+1);
    glTexCoord2f(s,0); glVertex3f(1,+1,-1);
    glTexCoord2f(s,v); glVertex3f(+0,+1.5,0);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glNormal3f( 0,0, 1);
    glTexCoord2f(0,0); glVertex3f(-1,+1,+1);
    glTexCoord2f(s,0); glVertex3f(1,+1,+1);
    glTexCoord2f(s,v); glVertex3f(+0,+1.5,0);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glNormal3f( 0,0, -1);
    glTexCoord2f(0,0); glVertex3f(-1,+1,-1);
    glTexCoord2f(s,0); glVertex3f(1,+1,-1);
    glTexCoord2f(s,v); glVertex3f(+0,+1.5,0);
    glEnd();
    
    glTranslated(13,-45,-2.15);
    useTransform(10,10,1.25);
    
   //  Texture off
   DisableTex();
   //  Undo transofrmations
   glPopMatrix();
}
