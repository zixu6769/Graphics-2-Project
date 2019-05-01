//
//  Wall class
//
#include "Wall.h"
#include "Cube.h"
//
//  Constructor
//
Wall::Wall(const QString tex)
{
   sx = sy = sz = 1;
   if (tex.length()>0) setTexture(tex);
}

//
//  Set scaling
//
void Wall::setScale(float dx,float dy,float dz)
{
   sx = dx;
   sy = dy;
   sz = dz;
}

//
//  Display the wall
//
void Wall::display()
{
   if (!show) return;
   //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   useTransform(sx,sy,sz);
   //  Texture on
   EnableTex();
   //  Left main inner layer
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f( 1, 0, 0);
   glTexCoord2f(0,0); glVertex3f(-15,-2, 20);
   glTexCoord2f(4,0); glVertex3f(-15,-2, -10);
   glTexCoord2f(4,4); glVertex3f(-15,20, -10);
   glTexCoord2f(0,4); glVertex3f(-15,20, 20);
   glEnd();
    
   // Left main outer layer
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f( -1, 0, 0);
   glTexCoord2f(0,0); glVertex3f(-15.1,-2, 20);
   glTexCoord2f(4,0); glVertex3f(-15.1,-2, -10);
   glTexCoord2f(4,4); glVertex3f(-15.1,20, -10);
   glTexCoord2f(0,4); glVertex3f(-15.1,20, 20);
   glEnd();

    
   //  Right main inner layer
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f( -1, 0, 0);
   glTexCoord2f(0,0); glVertex3f(15,-2, 20);
   glTexCoord2f(4,0); glVertex3f(15,-2, -10);
   glTexCoord2f(4,4); glVertex3f(15,20, -10);
   glTexCoord2f(0,4); glVertex3f(15,20, 20);
   glEnd();
    
   //  Right main outer layer
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f( 1, 0, 0);
   glTexCoord2f(0,0); glVertex3f(15.1,-2, 20);
   glTexCoord2f(4,0); glVertex3f(15.1,-2, -10);
   glTexCoord2f(4,4); glVertex3f(15.1,20, -10);
   glTexCoord2f(0,4); glVertex3f(15.1,20, 20);
   glEnd();
   
   // Back main inner layer
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f( 0, 0, 1);
   glTexCoord2f(0,0); glVertex3f(-15,-2, -10);
   glTexCoord2f(4,0); glVertex3f(15,-2, -10);
   glTexCoord2f(4,4); glVertex3f(15,20, -10);
   glTexCoord2f(0,4); glVertex3f(-15,20, -10);
   glEnd();
    
   // Back main outer layer
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f( 0, 0, -1);
   glTexCoord2f(0,0); glVertex3f(-15,-2, -10.1);
   glTexCoord2f(4,0); glVertex3f(15,-2, -10.1);
   glTexCoord2f(4,4); glVertex3f(15,20, -10.1);
   glTexCoord2f(0,4); glVertex3f(-15,20, -10.1);
   glEnd();
    
   // Inner left
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f( 1, 0, 0);
   glTexCoord2f(0,0); glVertex3f(-12,-2, 20);
   glTexCoord2f(4,0); glVertex3f(-12,-2,-10);
   glTexCoord2f(4,1); glVertex3f(-12,3,-10);
   glTexCoord2f(0,1); glVertex3f(-12,3, 20);
   glEnd();
    
   // Inner Right
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f( -1, 0, 0);
   glTexCoord2f(0,0); glVertex3f(12,-2,20);
   glTexCoord2f(4,0); glVertex3f(12,-2,-10);
   glTexCoord2f(4,1); glVertex3f(12,3,-10);
   glTexCoord2f(0,1); glVertex3f(12,3, 20);
   glEnd();
    
   // Inner back
   useColor(Color(0.5,0.5,0.5));
   glBegin(GL_QUADS);
   glNormal3f( 0, 0, 1);
   glTexCoord2f(0,0); glVertex3f(12,-2,-7);
   glTexCoord2f(1,0); glVertex3f(12,3,-7);
   glTexCoord2f(1,4); glVertex3f(-12,3,-7);
   glTexCoord2f(0,4); glVertex3f(-12,-2,-7);
   glEnd();
   //  Texture off
   DisableTex();
   //  Undo transofrmations
   glPopMatrix();
}
