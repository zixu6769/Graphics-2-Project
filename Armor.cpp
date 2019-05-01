//
//  Armor class
//
#include "Armor.h"
#define Cos(th) cos(M_PI/180*(th))
#define Sin(th) sin(M_PI/180*(th))
//
//  Constructor
//
Armor::Armor(const QString tex)
{
   sx = sy = sz = s = v = 1;
   tx = ty = tz = 0;
   if (tex.length()>0) setTexture(tex);
}

//
//  Set scaling
//
void Armor::setScale(float dx,float dy,float dz)
{
   sx = dx;
   sy = dy;
   sz = dz;
}

void Armor::setGLtranslated(float nx, float ny, float nz){
    tx = nx;
    ty = ny;
    tz = nz;
}

void Armor::setTex(float ds, float dv){
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
//  Display the armor
//
void Armor::display()
{
   if (!show) return;
   //  Save transformation
   glPushMatrix();
   //  Texture on
   EnableTex();
   //  Gray color default
   useColor(Color(0.8,0.8,0.8));
   //  Value needed by cylinder
   int i;
   int steps = 15;
   float  phi, dphi = 2.*M_PI / (float)(steps);
   //  Overall position transform
   glTranslated(tx,tz,ty);
    
    
    //  Helmet
    useTransform(0.6,0.76,0.6);
    glTranslated(0,9.2,0);
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
    glTranslated(0,-9.2,0);
    useTransform(1.666,1.3158,1.666);
    
    //  Right shoulder armor
    useTransform(0.6,0.76,0.6);
    glTranslated(2.3,7.3,0);
    glRotated(50,0,0,1);
    for (int ph=-90;ph<90;ph+=10)
    {
        glBegin(GL_QUAD_STRIP);
        for (int th=0;th<=180;th+=20)
        {
            Vertex(th,ph);
            Vertex(th,ph+10);
        }
        glEnd();
    }
    glRotated(-50,0,0,1);
    glTranslated(-2.3,-7.3,0);
    useTransform(1.666,1.3158,1.666);
    
    //  Left shoulder armor
    useTransform(0.6,0.76,0.6);
    glTranslated(-2.3,7.3,0);
    glRotated(-50,0,0,1);
    for (int ph=-90;ph<90;ph+=10)
    {
        glBegin(GL_QUAD_STRIP);
        for (int th=180;th<=360;th+=20)
        {
            Vertex(th,ph);
            Vertex(th,ph+10);
        }
        glEnd();
    }
    glRotated(50,0,0,1);
    glTranslated(2.3,-7.3,0);
    useTransform(1.666,1.3158,1.666);
    
    //  Chest armor
    useTransform(0.6,0.7,0.7);
    glTranslated(0,8,0);
    glRotated(90,0,1,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0.15*sin(phi), 0);
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(cos(phi),sin(phi),-2);
        glVertex3f(cos(phi),sin(phi),+2); }
    glEnd();
    glRotated(-90,0,1,0);
    glTranslated(0,-8,0);
    useTransform(1.666,1.4286,1.4286);
    
    //  Belly armor 1
    useTransform(1,0.5,0.5);
    glTranslated(0,8.2,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(1.1*cos(phi),1,1.1*sin(phi));
        glVertex3f(1.1*cos(phi),2,1.1*sin(phi)); }
    glEnd();
    glTranslated(0,-8.2,0);
    useTransform(1,2,2);
    
    //  Belly armor 2
    useTransform(1,0.5,0.5);
    glTranslated(0,8.25,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(1*cos(phi),0,1*sin(phi));
        glVertex3f(1*cos(phi),1,1*sin(phi)); }
    glEnd();
    glTranslated(0,-8.25,0);
    useTransform(1,2,2);
    
    //  Belly armor 3
    useTransform(1,0.5,0.5);
    glTranslated(0,8.3,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(0.9*cos(phi),-1,0.9*sin(phi));
        glVertex3f(0.9*cos(phi),0,0.9*sin(phi)); }
    glEnd();
    glTranslated(0,-8.3,0);
    useTransform(1,2,2);
    
    //  Belly armor 4
    useTransform(1,0.5,0.5);
    glTranslated(0,8.4,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(0.85*cos(phi),-2,0.85*sin(phi));
        glVertex3f(0.85*cos(phi),-1,0.85*sin(phi)); }
    glEnd();
    glTranslated(0,-8.4,0);
    useTransform(1,2,2);
    
    //  Belt
    useTransform(1,0.5,0.6);
    glTranslated(0,8,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(1.1*cos(phi),-2,1.1*sin(phi));
        glVertex3f(1.1*cos(phi),-1,1.1*sin(phi)); }
    glEnd();
    glTranslated(0,-8.4,0);
    useTransform(1,2,1.6666);
    
    //  Left knee armor
    useTransform(0.5,0.5,0.5);
    glTranslated(-1.5,2.5,0.5);
    glRotated(-90,0,1,0);
    for (int ph=-90;ph<90;ph+=10)
    {
        glBegin(GL_QUAD_STRIP);
        for (int th=0;th<=180;th+=20)
        {
            Vertex(th,ph);
            Vertex(th,ph+10);
        }
        glEnd();
    }
    glRotated(90,0,1,0);
    glTranslated(1.5,-2.5,-0.5);
    useTransform(2,2,2);
    
    
    //  Right knee armor
    useTransform(0.5,0.5,0.5);
    glTranslated(1.5,2.5,0.5);
    glRotated(-90,0,1,0);
    for (int ph=-90;ph<90;ph+=10)
    {
        glBegin(GL_QUAD_STRIP);
        for (int th=0;th<=180;th+=20)
        {
            Vertex(th,ph);
            Vertex(th,ph+10);
        }
        glEnd();
    }
    glRotated(90,0,1,0);
    glTranslated(-1.5,-2.5,-0.5);
    useTransform(2,2,2);
    
    //  Left calf armor
    useTransform(0.5,0.7,0.5);
    glTranslated(-1.65,-0.5,0);
    glRotated(-7,0,0,1);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(0.7*cos(phi),-2,0.7*sin(phi));
        glVertex3f(cos(phi),2,sin(phi)); }
    glEnd();
    glRotated(7,0,0,1);
    glTranslated(1.65,0.5,0);
    useTransform(2,1.4285,2);
    
    //  Right calf armor
    useTransform(0.5,0.7,0.5);
    glTranslated(1.65,-0.5,0);
    glRotated(7,0,0,1);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(0.7*cos(phi),-2,0.7*sin(phi));
        glVertex3f(cos(phi),2,sin(phi)); }
    glEnd();
    glRotated(-7,0,0,1);
    glTranslated(-1.65,0.5,0);
    useTransform(2,1.4285,2);
    
    //  Left shoe
    useTransform(0.5,0.5,0.5);
    glTranslated(-1.92,-3.5,1.8);
    glRotated(-80,1,0,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(0,-1.7,0);
        glVertex3f(0.9*cos(phi),2,0.9*sin(phi)); }
    glEnd();
    glRotated(80,1,0,0);
    glTranslated(1.92,3.5,-1.8);
    useTransform(2,2,2);
    
    //  Right shoe
    useTransform(0.5,0.5,0.5);
    glTranslated(1.92,-3.5,1.8);
    glRotated(-80,1,0,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(0,-1.7,0);
        glVertex3f(0.9*cos(phi),2,0.9*sin(phi)); }
    glEnd();
    glRotated(80,1,0,0);
    glTranslated(-1.92,3.5,-1.8);
    useTransform(2,2,2);
    
    //  Left heel
    useTransform(0.35,0.35,0.35);
    glTranslated(-3,-4.5,-0.5);
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
    glTranslated(3,4.5,0.5);
    useTransform(2.857,2.857,2.857);
    
    //  Right heel
    useTransform(0.35,0.35,0.35);
    glTranslated(3,-4.5,-0.5);
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
    glTranslated(-3,4.5,0.5);
    useTransform(2.857,2.857,2.857);
    
    //  Left forearm armor
    glRotated(90,1,0,0);
    useTransform(0.3,0.4,0.3);
    glTranslated(-4.5,2,-13.2);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(1.2*cos(phi),-2,1.2*sin(phi));
        glVertex3f(0.7*cos(phi),2,0.7*sin(phi)); }
    glEnd();
    glTranslated(4.5,-2,13.2);
    useTransform(3.333,2.5,3.333);
    glRotated(-90,1,0,0);
    
    //  Right forearm armor
    glRotated(5,0,0,1);
    useTransform(0.3,0.4,0.3);
    glTranslated(5.55,8,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(0.7*cos(phi),-2,0.7*sin(phi));
        glVertex3f(1.2*cos(phi),2,1.2*sin(phi)); }
    glEnd();
    glTranslated(-5.55,-8,0);
    useTransform(3.333,2.5,3.333);
    glRotated(-5,0,0,1);
    
    //  Left glove
    useTransform(0.35,0.35,0.35);
    glTranslated(-3.9,11.3,4.7);
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
    glTranslated(3.9,-11.3,-4.7);
    useTransform(2.857,2.857,2.857);
    
    //  Right glove
    useTransform(0.35,0.35,0.35);
    glTranslated(4.3,6.5,0);
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
    glTranslated(-4.3,-6.5,-0.35);
    useTransform(2.857,2.857,2.857);
   //  Texture off
   DisableTex();
   //  Undo transofrmations
   glPopMatrix();
}
