//
//  Human class
//
#include "Human.h"
#define Cos(th) cos(M_PI/180*(th))
#define Sin(th) sin(M_PI/180*(th))
//
//  Constructor
//
Human::Human(const QString tex)
{
   sx = sy = sz = s = v = 1;
   tx = ty = tz = 0;
   if (tex.length()>0) setTexture(tex);
}

//
//  Set scaling
//
void Human::setScale(float dx,float dy,float dz)
{
   sx = dx;
   sy = dy;
   sz = dz;
}

void Human::setGLtranslated(float nx, float ny, float nz){
    tx = nx;
    ty = ny;
    tz = nz;
}

void Human::setTex(float ds, float dv){
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
//  Display the cube
//
void Human::display()
{
   if (!show) return;
   //  Save transformation
   glPushMatrix();
   //  Texture on
   EnableTex();
   //  Gray color default
   useColor(Color(0.5,0.5,0.5));
   //  Value needed by cylinder
   int i;
   int steps = 15;
   float  phi, dphi = 2.*M_PI / (float)(steps);
   //  Overall position transform
   glTranslated(tx,tz,ty);
    
    //  Head
    useTransform(0.5,0.75,0.5);
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
    useTransform(2,1.33,2);
    
    //  Neck
    useTransform(0.3,0.3,0.3);
    glTranslated(0,22,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(cos(phi),-2,sin(phi));
        glVertex3f(cos(phi),2,sin(phi)); }
    glEnd();
    glTranslated(0,-22,0);
    useTransform(3.33,3.33,3.33);
    
    //  Chest
    glRotated(90,0,1,0);
    useTransform(0.5,0.5,0.5);
    glTranslated(0,11,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0.15*sin(phi), 0);
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(cos(phi),sin(phi),-2);
        glVertex3f(cos(phi),sin(phi),+2); }
    glEnd();
    glTranslated(0,-11,0);
    useTransform(2,2,2);
    glRotated(-90,0,1,0);
    
    //  Belly
    useTransform(1,0.5,0.5);
    glTranslated(0,9,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(0.8*cos(phi),-2,0.8*sin(phi));
        glVertex3f(cos(phi),2,sin(phi)); }
    glEnd();
    glTranslated(0,-9,0);
    useTransform(1,2,2);
    
    // Left shoulder
    useTransform(0.5,0.5,0.5);
    glTranslated(-2.2,11,0);
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
    glTranslated(2.2,-11,0);
    useTransform(2,2,2);
    
    // Right shoulder
    useTransform(0.5,0.5,0.5);
    glTranslated(2.2,11,0);
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
    glTranslated(-2.2,-11,0);
    useTransform(2,2,2);
    
    //  Hip
    glRotated(90,0,1,0);
    useTransform(0.45,0.45,0.2);
    glTranslated(0,7,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0.15*sin(phi), 0);
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(cos(phi),sin(phi),-2);
        glVertex3f(cos(phi),sin(phi),+2); }
    glEnd();
    glTranslated(0,-7,0);
    useTransform(2.222,2.222,5);
    glRotated(-90,0,1,0);
    
    // Left buttocks
    useTransform(0.5,0.5,0.5);
    glTranslated(-1,6.25,0);
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
    glTranslated(1,-6.25,0);
    useTransform(2,2,2);
    
    // Right buttocks
    useTransform(0.5,0.5,0.5);
    glTranslated(1,6.25,0);
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
    glTranslated(-1,-6.25,0);
    useTransform(2,2,2);
    
    // Left thign
    glRotated(-5,0,0,1);
    useTransform(0.4,0.5,0.4);
    glTranslated(-2,4,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(cos(phi),-2,sin(phi));
        glVertex3f(1.2*cos(phi),2,1.2*sin(phi)); }
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
        glVertex3f(1.2*cos(phi),2,1.2*sin(phi)); }
    glEnd();
    glTranslated(-2,-4,0);
    useTransform(2.5,2,2.5);
    glRotated(-5,0,0,1);
    
    // Left knee
    useTransform(0.45,0.45,0.45);
    glTranslated(-1.6,2.5,0);
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
    glTranslated(1.6,-2.5,0);
    useTransform(2.222,2.222,2.222);
    
    // Right knee
    useTransform(0.45,0.45,0.45);
    glTranslated(1.6,2.5,0);
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
    glTranslated(-1.6,-2.5,0);
    useTransform(2.222,2.222,2.222);
    
    // Left calf
    glRotated(-5,0,0,1);
    useTransform(0.4,0.7,0.4);
    glTranslated(-2,-0.5,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(0.7*cos(phi),-2,0.7*sin(phi));
        glVertex3f(cos(phi),2,sin(phi)); }
    glEnd();
    glTranslated(2,0.5,0);
    useTransform(2.5,1.4285,2.5);
    glRotated(5,0,0,1);
    
    // Right calf
    glRotated(5,0,0,1);
    useTransform(0.4,0.7,0.4);
    glTranslated(2,-0.5,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(0.7*cos(phi),-2,0.7*sin(phi));
        glVertex3f(cos(phi),2,sin(phi)); }
    glEnd();
    glTranslated(-2,0.5,0);
    useTransform(2.5,1.4285,2.5);
    glRotated(-5,0,0,1);
    
    // Left heel
    useTransform(0.3,0.3,0.3);
    glTranslated(-3.2,-6.3,-0.2);
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
    glTranslated(3.2,6.3,0.2);
    useTransform(3.333,3.333,3.333);
    
    // Right heel
    useTransform(0.3,0.3,0.3);
    glTranslated(3.2,-6.3,-0.2);
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
    glTranslated(-3.2,6.3,0.2);
    useTransform(3.333,3.333,3.333);
    
    //  Left foot
    glRotated(-80,1,0,0);
    useTransform(0.3,0.3,0.3);
    glTranslated(-3.25,-3,-6);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(0.5*cos(phi),-1.4,0.5*sin(phi));
        glVertex3f(cos(phi),2,sin(phi)); }
    glEnd();
    glTranslated(3.25,3,6);
    useTransform(3.333,3.333,3.333);
    glRotated(80,1,0,0);
    
    //  Right foot
    glRotated(-80,1,0,0);
    useTransform(0.3,0.3,0.3);
    glTranslated(3.25,-3,-6);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(0.5*cos(phi),-1.4,0.5*sin(phi));
        glVertex3f(cos(phi),2,sin(phi)); }
    glEnd();
    glTranslated(-3.25,3,6);
    useTransform(3.333,3.333,3.333);
    glRotated(80,1,0,0);
    
    //  Left arm
    glRotated(-5,0,0,1);
    useTransform(0.3,0.4,0.3);
    glTranslated(-5.5,11,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(0.7*cos(phi),-2,0.7*sin(phi));
        glVertex3f(cos(phi),2,sin(phi)); }
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
        glVertex3f(0.7*cos(phi),-2,0.7*sin(phi));
        glVertex3f(cos(phi),2,sin(phi)); }
    glEnd();
    glTranslated(-5.5,-11,0);
    useTransform(3.333,2.5,3.333);
    glRotated(-5,0,0,1);
    
    //  Left elbow
    useTransform(0.25,0.25,0.25);
    glTranslated(-5.5,15,0);
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
    glTranslated(5.5,-15,0);
    useTransform(4,4,4);
    
    //  Right elbow
    useTransform(0.25,0.25,0.25);
    glTranslated(5.5,15,0);
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
    glTranslated(-5.5,-15,0);
    useTransform(4,4,4);
    
    //  Left forearm
    glRotated(90,1,0,0);
    useTransform(0.3,0.4,0.3);
    glTranslated(-4.5,2,-12.5);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(0.7*cos(phi),-2,0.7*sin(phi));
        glVertex3f(0.7*cos(phi),2,0.7*sin(phi)); }
    glEnd();
    glTranslated(4.5,-2,12.5);
    useTransform(3.333,2.5,3.333);
    glRotated(-90,1,0,0);
    
    //  Left fist
    useTransform(0.3,0.3,0.3);
    glTranslated(-4.5,12.5,5.5);
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
    glTranslated(4.5,-12.5,-5.5);
    useTransform(3.333,3.333,3.333);
    
    //  Right forearm
    glRotated(5,0,0,1);
    useTransform(0.3,0.4,0.3);
    glTranslated(5.5,7,0);
    glBegin(GL_TRIANGLE_STRIP);
    for(i = 0, phi = 0.; i <= steps; i ++, phi += dphi) {
        glNormal3f(0.15*cos(phi),0,0.15*sin(phi));
        glTexCoord2f(cos(i)*0.5+0.5,sin(i)*0.5 + 0.5);
        glVertex3f(0.7*cos(phi),-2,0.7*sin(phi));
        glVertex3f(0.7*cos(phi),2,0.7*sin(phi)); }
    glEnd();
    glTranslated(-5.5,-7,0);
    useTransform(3.333,2.5,3.333);
    glRotated(-5,0,0,1);
    
    //  Right fist
    useTransform(0.3,0.3,0.3);
    glTranslated(5,7,0);
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
    glTranslated(4.5,-12.5,-5.5);
    useTransform(3.333,3.333,3.333);
   //  Texture off
   DisableTex();
   //  Undo transofrmations
   glPopMatrix();
}
