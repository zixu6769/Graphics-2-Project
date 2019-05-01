//
//  CU OpenGL Widget
//

#ifndef CUGL_H
#define CUGL_H

#include <QtOpenGL>
#include <QString>
#include <QVector>
#include "Object.h"
#include "glu.h"

class CUgl : public QOpenGLWidget
{
Q_OBJECT
private:
   float            La,Ld,Ls; // Light intensity
   float            Lr;       // Light radius
   float            zh;       // Light angle
   float            ylight;   // Light elevation
   bool             move;     // Moving light
   int              obj;      // Selected Object
   QTimer           timer;    // Timer for animations
protected:
   QElapsedTimer    time;     // Track elapsed time
   QVector<Object*> objects;  // Objects
   bool             mouse;    // Mouse pressed
   QPoint           pos;      // Mouse position
   int              fov;      // Field of view
   float            Dim;      // Default size
   float            dim;      // Display size
   int              th,ph;    // Display angles
   bool             fps;      // First person camera
   bool             eqp;      // Wear equipments
   QVector<QOpenGLShaderProgram*> shader; // Shaders
   // Direction variables
   float dirx;
   float diry;
   float dirz;
   // Angles for rotation
   float viewangle;
   float updown;
   // For moving sideway
   float crossx;
   float crossz;
public:
   // FPS camera position
   float eyex;
   float eyey;
   float eyez;
   bool  day;
   CUgl(QWidget* parent=0,bool fixed=true);        // Constructor
   QSize sizeHint() const {return QSize(400,400);} // Default size of widget
public slots:
   void reset();
   void setPerspective();                          // Set perspective
   void setTime(int on);
   void addObject(Object* obj);                     // Add object
   void maxFPS(bool);                               // Set max fps
   void addShader(QString vert,QString frag,QString names=""); // Add shader
   void addShader3(QString vert,QString geom,QString frag);    // Add shader
protected:
   void initializeGL();                             // Initialization
   void mousePressEvent(QMouseEvent*);              // Mouse pressed
   void mouseReleaseEvent(QMouseEvent*);            // Mouse released
   void mouseMoveEvent(QMouseEvent*);               // Mouse moved
   void wheelEvent(QWheelEvent*);                   // Mouse wheel
   void keyPressEvent(QKeyEvent*);                  // Key pressed
   void Fatal(QString message);                     // Error handler
   QVector3D doLight();                             // Enable light
   void doModelViewProjection();                    // Apply projection
   float getTime() {return 0.001*time.elapsed();}   // Elapsed time in seconds
   QOpenGLTexture* loadImage(const QString file);   // Method to load texture
private slots:
   void tick();                                     // Method to capture timer ticks
signals:
   void light(int angle);                           // Signal for light angle
   void angles(QString text);                       // Signal for view angles
};

#endif
