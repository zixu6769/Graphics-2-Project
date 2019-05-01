//
//  OpenGL projectopengl Widget
//

#ifndef PROJECTOPENGL_H
#define PROJECTOPENGL_H

#include "CUgl.h"

class projectopengl : public CUgl
{
Q_OBJECT
private:
   float x0,y0;         //  Model center
   float z0;            //  Zoom level
   int     N;           //  Particle count
   float   zh;          //  Light position
   int     n;           //  Particle count
   float*  Vert;        //  Vertices
   float*  Color;       //  Colors
   float*  Vel;         //  Velocities
   float*  Start;       //  Start time
   QOpenGLTexture* tex; //  Texture
public:
   projectopengl(QWidget* parent=0);                  // Constructor
   QSize sizeHint() const {return QSize(400,400);}    // Default size of widget
public slots:
signals:
    void zoom(QString text); // Zoom level
protected:
    void initializeGL();     // Initialize widget
    void paintGL();          // Draw widget
private:
    void InitPart();
    void DrawPart();
};

#endif
