//
//  Cloth class
//
#include "Cloth.h"
#define Cos(th) cos(M_PI/180*(th))
#define Sin(th) sin(M_PI/180*(th))
//
//  Constructor
//
Cloth::Cloth(const QString tex)
{
   sx = sy = sz = s = v = 1;
   tx = ty = tz = 0;
   if (tex.length()>0) setTexture(tex);
}

//
//  Set scaling
//
void Cloth::setScale(float dx,float dy,float dz)
{
   sx = dx;
   sy = dy;
   sz = dz;
}

void Cloth::setGLtranslated(float nx, float ny, float nz){
    tx = nx;
    ty = ny;
    tz = nz;
}

void Cloth::setTex(float ds, float dv){
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
//  Display the cloth
//
void Cloth::display()
{
   if (!show) return;
   //  Save transformation
   glPushMatrix();
   //  Texture on
   EnableTex();
   //  Gray color default
   useColor(Color(1,0.0,0.0));
   //  Value needed by cylinder
   int i;
   int steps = 15;
   float  phi, dphi = 2.*M_PI / (float)(steps);
   //  Overall position transform
   glTranslated(tx,tz,ty);
    
    // Left thign
    glRotated(-5,0,0,1);
    useTransform(0.4,0.5,0.4);
    glTranslated(-2,4,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(cos(phi),-2,sin(phi));
        glVertex3f(1.4*cos(phi),2,1.4*sin(phi)); }
    glEnd();
    glTranslated(2,-4,0);
    useTransform(2.5,2,2.5);
    glRotated(5,0,0,1);
    
    // Right thign
    glRotated(5,0,0,1);
    useTransform(0.4,0.5,0.4);
    glTranslated(2,4,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(cos(phi),-2,sin(phi));
        glVertex3f(1.4*cos(phi),2,1.4*sin(phi)); }
    glEnd();
    glTranslated(-2,-4,0);
    useTransform(2.5,2,2.5);
    glRotated(-5,0,0,1);
    
    //  Left arm
    glRotated(-5,0,0,1);
    useTransform(0.3,0.4,0.3);
    glTranslated(-5.5,11,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(0.8*cos(phi),-2,0.8*sin(phi));
        glVertex3f(1.2*cos(phi),2,1.2*sin(phi)); }
    glEnd();
    glTranslated(5.5,-11,0);
    useTransform(3.333,2.5,3.333);
    glRotated(5,0,0,1);
    
    //  Right arm
    glRotated(5,0,0,1);
    useTransform(0.3,0.4,0.3);
    glTranslated(5.5,11,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(0.8*cos(phi),-2,0.8*sin(phi));
        glVertex3f(1.2*cos(phi),2,1.2*sin(phi)); }
    glEnd();
    glTranslated(-5.5,-11,0);
    useTransform(3.333,2.5,3.333);
    glRotated(-5,0,0,1);
    
    // Left shoulder
    useTransform(0.55,0.55,0.55);
    glTranslated(-2.2,10,0);
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
    glTranslated(2.2,-10,0);
    useTransform(1.818,1.818,1.818);
    
    // Right shoulder
    useTransform(0.55,0.55,0.55);
    glTranslated(2.2,10,0);
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
    glTranslated(-2.2,-10,0);
    useTransform(1.818,1.818,1.818);
    
    // Underwear
    glRotated(90,0,1,0);
    useTransform(0.45,0.45,0.2);
    glTranslated(0,7,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0.15*sin(phi), 0);
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(1.1*cos(phi),1.1*sin(phi),-2);
        glVertex3f(1.1*cos(phi),1.1*sin(phi),+2); }
    glEnd();
    glTranslated(0,-7,0);
    useTransform(2.222,2.222,5);
    glRotated(-90,0,1,0);
    
    // Left knee
    useTransform(0.5,0.5,0.5);
    glTranslated(-1.4,2.5,0);
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
    glTranslated(1.4,-2.5,0);
    useTransform(2,2,2);
    
    // Right knee
    useTransform(0.5,0.5,0.5);
    glTranslated(1.4,2.5,0);
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
    glTranslated(-1.4,-2.5,0);
    useTransform(2,2,2);
    
   //  Texture off
   DisableTex();
   //  Undo transofrmations
   glPopMatrix();
}
