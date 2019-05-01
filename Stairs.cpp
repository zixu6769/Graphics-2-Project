//
//  Stairs class
//
#include "Stairs.h"

//
//  Constructor
//
Stairs::Stairs(const QString tex)
{
   sx = sy = sz = 1;
   if (tex.length()>0) setTexture(tex);
}

//
//  Set scaling
//
void Stairs::setScale(float dx,float dy,float dz)
{
   sx = dx;
   sy = dy;
   sz = dz;
}

//
//  Display the stair
//
void Stairs::display()
{
   if (!show) return;
   //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   useTransform(sx,sy,sz);
   //  Texture on
   EnableTex();
   //  1
   //  Front
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f( 0, 0, 1);
   glTexCoord2f(0,0); glVertex3f(+4,-2,3);
   glTexCoord2f(1,0); glVertex3f(+4,-1.5,3);
   glTexCoord2f(1,1); glVertex3f(-4,-1.5,3);
   glTexCoord2f(0,1); glVertex3f(-4,-2,3);
   glEnd();
   //  Right
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f(+1, 0, 0);
   glTexCoord2f(0,0); glVertex3f(+4,-2,3);
   glTexCoord2f(1,0); glVertex3f(+4,-2,-7);
   glTexCoord2f(1,1); glVertex3f(+4,-1.5,-7);
   glTexCoord2f(0,1); glVertex3f(+4,-1.5,3);
   glEnd();
   //  Left
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f(-1, 0, 0);
   glTexCoord2f(0,0); glVertex3f(-4,-2,3);
   glTexCoord2f(1,0); glVertex3f(-4,-2,-7);
   glTexCoord2f(1,1); glVertex3f(-4,-1.5,-7);
   glTexCoord2f(0,1); glVertex3f(-4,-1.5,3);
   glEnd();
   //  Top
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f( 0,+1, 0);
   glTexCoord2f(0,0); glVertex3f(4,-1.5,3);
   glTexCoord2f(1,0); glVertex3f(4,-1.5,-7);
   glTexCoord2f(1,1); glVertex3f(-4,-1.5,-7);
   glTexCoord2f(0,1); glVertex3f(-4,-1.5,3);
   glEnd();
    
    //  2
    //  Front
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0, 0, 1);
    glTexCoord2f(0,0); glVertex3f(+4,-1.5,2);
    glTexCoord2f(1,0); glVertex3f(+4,-1,2);
    glTexCoord2f(1,1); glVertex3f(-4,-1,2);
    glTexCoord2f(0,1); glVertex3f(-4,-1.5,2);
    glEnd();
    //  Right
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(+1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(+4,-1.5,2);
    glTexCoord2f(1,0); glVertex3f(+4,-1.5,-7);
    glTexCoord2f(1,1); glVertex3f(+4,-1,-7);
    glTexCoord2f(0,1); glVertex3f(+4,-1,2);
    glEnd();
    //  Left
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(-4,-1.5,2);
    glTexCoord2f(1,0); glVertex3f(-4,-1.5,-7);
    glTexCoord2f(1,1); glVertex3f(-4,-1,-7);
    glTexCoord2f(0,1); glVertex3f(-4,-1,2);
    glEnd();
    //  Top
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0,+1, 0);
    glTexCoord2f(0,0); glVertex3f(4,-1,2);
    glTexCoord2f(1,0); glVertex3f(4,-1,-7);
    glTexCoord2f(1,1); glVertex3f(-4,-1,-7);
    glTexCoord2f(0,1); glVertex3f(-4,-1,2);
    glEnd();
    
    //  3
    //  Front
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0, 0, 1);
    glTexCoord2f(0,0); glVertex3f(+4,-1,1);
    glTexCoord2f(1,0); glVertex3f(+4,-0.5,1);
    glTexCoord2f(1,1); glVertex3f(-4,-0.5,1);
    glTexCoord2f(0,1); glVertex3f(-4,-1,1);
    glEnd();
    //  Right
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(+1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(+4,-1,1);
    glTexCoord2f(1,0); glVertex3f(+4,-1,-7);
    glTexCoord2f(1,1); glVertex3f(+4,-0.5,-7);
    glTexCoord2f(0,1); glVertex3f(+4,-0.5,1);
    glEnd();
    //  Left
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(-4,-1,1);
    glTexCoord2f(1,0); glVertex3f(-4,-1,-7);
    glTexCoord2f(1,1); glVertex3f(-4,-0.5,-7);
    glTexCoord2f(0,1); glVertex3f(-4,-0.5,1);
    glEnd();
    //  Top
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0,+1, 0);
    glTexCoord2f(0,0); glVertex3f(4,-0.5,1);
    glTexCoord2f(1,0); glVertex3f(4,-0.5,-7);
    glTexCoord2f(1,1); glVertex3f(-4,-0.5,-7);
    glTexCoord2f(0,1); glVertex3f(-4,-0.5,1);
    glEnd();
    
    //  4
    //  Front
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0, 0, 1);
    glTexCoord2f(0,0); glVertex3f(+4,-0.5,0);
    glTexCoord2f(1,0); glVertex3f(+4,0,0);
    glTexCoord2f(1,1); glVertex3f(-4,0,0);
    glTexCoord2f(0,1); glVertex3f(-4,-0.5,0);
    glEnd();
    //  Right
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(+1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(+4,-0.5,0);
    glTexCoord2f(1,0); glVertex3f(+4,-0.5,-7);
    glTexCoord2f(1,1); glVertex3f(+4,0,-7);
    glTexCoord2f(0,1); glVertex3f(+4,0,0);
    glEnd();
    //  Left
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(-4,-0.5,0);
    glTexCoord2f(1,0); glVertex3f(-4,-0.5,-7);
    glTexCoord2f(1,1); glVertex3f(-4,0,-7);
    glTexCoord2f(0,1); glVertex3f(-4,0,0);
    glEnd();
    //  Top
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0,+1, 0);
    glTexCoord2f(0,0); glVertex3f(4,0,0);
    glTexCoord2f(1,0); glVertex3f(4,0,-7);
    glTexCoord2f(1,1); glVertex3f(-4,0,-7);
    glTexCoord2f(0,1); glVertex3f(-4,0,0);
    glEnd();
    
    //  5
    //  Front
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0, 0, 1);
    glTexCoord2f(0,0); glVertex3f(+4,0,-1);
    glTexCoord2f(1,0); glVertex3f(+4,0.5,-1);
    glTexCoord2f(1,1); glVertex3f(-4,0.5,-1);
    glTexCoord2f(0,1); glVertex3f(-4,0,-1);
    glEnd();
    //  Right
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(+1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(+4,0,-1);
    glTexCoord2f(1,0); glVertex3f(+4,0,-7);
    glTexCoord2f(1,1); glVertex3f(+4,0.5,-7);
    glTexCoord2f(0,1); glVertex3f(+4,0.5,-1);
    glEnd();
    //  Left
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(-4,0,-1);
    glTexCoord2f(1,0); glVertex3f(-4,0,-7);
    glTexCoord2f(1,1); glVertex3f(-4,0.5,-7);
    glTexCoord2f(0,1); glVertex3f(-4,0.5,-1);
    glEnd();
    //  Top
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0,+1, 0);
    glTexCoord2f(0,0); glVertex3f(4,0.5,-1);
    glTexCoord2f(1,0); glVertex3f(4,0.5,-7);
    glTexCoord2f(1,1); glVertex3f(-4,0.5,-7);
    glTexCoord2f(0,1); glVertex3f(-4,0.5,-1);
    glEnd();
    
    //  6
    //  Front
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0, 0, 1);
    glTexCoord2f(0,0); glVertex3f(+4,0.5,-2);
    glTexCoord2f(1,0); glVertex3f(+4,1,-2);
    glTexCoord2f(1,1); glVertex3f(-4,1,-2);
    glTexCoord2f(0,1); glVertex3f(-4,0.5,-2);
    glEnd();
    //  Right
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(+1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(+4,0.5,-2);
    glTexCoord2f(1,0); glVertex3f(+4,0.5,-7);
    glTexCoord2f(1,1); glVertex3f(+4,1,-7);
    glTexCoord2f(0,1); glVertex3f(+4,1,-2);
    glEnd();
    //  Left
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(-4,0.5,-2);
    glTexCoord2f(1,0); glVertex3f(-4,0.5,-7);
    glTexCoord2f(1,1); glVertex3f(-4,1,-7);
    glTexCoord2f(0,1); glVertex3f(-4,1,-2);
    glEnd();
    //  Top
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0,+1, 0);
    glTexCoord2f(0,0); glVertex3f(4,1,-2);
    glTexCoord2f(1,0); glVertex3f(4,1,-7);
    glTexCoord2f(1,1); glVertex3f(-4,1,-7);
    glTexCoord2f(0,1); glVertex3f(-4,1,-2);
    glEnd();
    
    //  7
    //  Front
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0, 0, 1);
    glTexCoord2f(0,0); glVertex3f(+4,1,-3);
    glTexCoord2f(1,0); glVertex3f(+4,1.5,-3);
    glTexCoord2f(1,1); glVertex3f(-4,1.5,-3);
    glTexCoord2f(0,1); glVertex3f(-4,1,-3);
    glEnd();
    //  Right
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(+1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(+4,1,-3);
    glTexCoord2f(1,0); glVertex3f(+4,1,-7);
    glTexCoord2f(1,1); glVertex3f(+4,1.5,-7);
    glTexCoord2f(0,1); glVertex3f(+4,1.5,-3);
    glEnd();
    //  Left
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(-4,1,-3);
    glTexCoord2f(1,0); glVertex3f(-4,1,-7);
    glTexCoord2f(1,1); glVertex3f(-4,1.5,-7);
    glTexCoord2f(0,1); glVertex3f(-4,1.5,-3);
    glEnd();
    //  Top
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0,+1, 0);
    glTexCoord2f(0,0); glVertex3f(4,1.5,-3);
    glTexCoord2f(1,0); glVertex3f(4,1.5,-7);
    glTexCoord2f(1,1); glVertex3f(-4,1.5,-7);
    glTexCoord2f(0,1); glVertex3f(-4,1.5,-3);
    glEnd();
    
    //  8
    //  Front
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0, 0, 1);
    glTexCoord2f(0,0); glVertex3f(+4,1.5,-4);
    glTexCoord2f(1,0); glVertex3f(+4,2,-4);
    glTexCoord2f(1,1); glVertex3f(-4,2,-4);
    glTexCoord2f(0,1); glVertex3f(-4,1.5,-4);
    glEnd();
    //  Right
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(+1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(+4,1.5,-4);
    glTexCoord2f(1,0); glVertex3f(+4,1.5,-7);
    glTexCoord2f(1,1); glVertex3f(+4,2,-7);
    glTexCoord2f(0,1); glVertex3f(+4,2,-4);
    glEnd();
    //  Left
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(-4,1.5,-4);
    glTexCoord2f(1,0); glVertex3f(-4,1.5,-7);
    glTexCoord2f(1,1); glVertex3f(-4,2,-7);
    glTexCoord2f(0,1); glVertex3f(-4,2,-4);
    glEnd();
    //  Top
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0,+1, 0);
    glTexCoord2f(0,0); glVertex3f(4,2,-4);
    glTexCoord2f(1,0); glVertex3f(4,2,-7);
    glTexCoord2f(1,1); glVertex3f(-4,2,-7);
    glTexCoord2f(0,1); glVertex3f(-4,2,-4);
    glEnd();
    
    //  9
    //  Front
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0, 0, 1);
    glTexCoord2f(0,0); glVertex3f(+4,2,-5);
    glTexCoord2f(1,0); glVertex3f(+4,2.5,-5);
    glTexCoord2f(1,1); glVertex3f(-4,2.5,-5);
    glTexCoord2f(0,1); glVertex3f(-4,2,-5);
    glEnd();
    //  Right
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(+1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(+4,2,-5);
    glTexCoord2f(1,0); glVertex3f(+4,2,-7);
    glTexCoord2f(1,1); glVertex3f(+4,2.5,-7);
    glTexCoord2f(0,1); glVertex3f(+4,2.5,-5);
    glEnd();
    //  Left
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(-4,2,-5);
    glTexCoord2f(1,0); glVertex3f(-4,2,-7);
    glTexCoord2f(1,1); glVertex3f(-4,2.5,-7);
    glTexCoord2f(0,1); glVertex3f(-4,2.5,-5);
    glEnd();
    //  Top
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0,+1, 0);
    glTexCoord2f(0,0); glVertex3f(4,2.5,-5);
    glTexCoord2f(1,0); glVertex3f(4,2.5,-7);
    glTexCoord2f(1,1); glVertex3f(-4,2.5,-7);
    glTexCoord2f(0,1); glVertex3f(-4,2.5,-5);
    glEnd();
    
    //  10
    //  Front
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0, 0, 1);
    glTexCoord2f(0,0); glVertex3f(+4,2.5,-6);
    glTexCoord2f(1,0); glVertex3f(+4,3,-6);
    glTexCoord2f(1,1); glVertex3f(-4,3,-6);
    glTexCoord2f(0,1); glVertex3f(-4,2.5,-6);
    glEnd();
    //  Right
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(+1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(+4,2.5,-6);
    glTexCoord2f(1,0); glVertex3f(+4,2.5,-7);
    glTexCoord2f(1,1); glVertex3f(+4,3,-7);
    glTexCoord2f(0,1); glVertex3f(+4,3,-6);
    glEnd();
    //  Left
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f(-1, 0, 0);
    glTexCoord2f(0,0); glVertex3f(-4,2.5,-6);
    glTexCoord2f(1,0); glVertex3f(-4,2.5,-7);
    glTexCoord2f(1,1); glVertex3f(-4,3,-7);
    glTexCoord2f(0,1); glVertex3f(-4,3,-6);
    glEnd();
    //  Top
    useColor(Color(0.5,0.5,0.5));
    glBegin(GL_QUADS);
    glNormal3f( 0,+1, 0);
    glTexCoord2f(0,0); glVertex3f(4,3,-6);
    glTexCoord2f(1,0); glVertex3f(4,3,-7);
    glTexCoord2f(1,1); glVertex3f(-4,3,-7);
    glTexCoord2f(0,1); glVertex3f(-4,3,-6);
    glEnd();

   //  Texture off
   DisableTex();
   //  Undo transofrmations
   glPopMatrix();
}
