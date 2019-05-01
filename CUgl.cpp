//
//  CU OpenGL Widget
//
//#define GL_GLEXT_PROTOTYPES
#include "CUgl.h"
#include <math.h>
#define Cos(th) cos(M_PI/180*(th))
#define Sin(th) sin(M_PI/180*(th))
//
//  Constructor
//
CUgl::CUgl(QWidget* parent,bool fixed)
    : QOpenGLWidget(parent)
{
   // Enable keyboard detection
   setFocusPolicy (Qt::StrongFocus);
   // Enable mouse detection
   setMouseTracking(true);
   // Hide mouse in the main application
   setCursor(Qt::BlankCursor);
   fps = false;
   day = true;
   eqp = true;
   //  Fixed pipeline
   if (fixed) shader.push_back(NULL);
   //  Draw all objects
   obj = -1;
   Dim = dim = 100;
   fov = 55;
   th = 0;
   ph = 20;
   //  Light settings
   La = 0.1;
   Ld = 1.0;
   Ls = 1.0;
   //  Light position
   Lr = 100;
   zh = 0;
   ylight = 60;
   //  Light animation
   move = true;
   //  100 fps timer connected to tick()
   timer.setInterval(10);
   connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
   timer.start();
   //  Elapsed time timer
   time.start();
}

//
// Set max frame rate
//
void CUgl::maxFPS(bool on)
{
   timer.setInterval(on?0:10);
   format().setSwapInterval(on?0:1);
}

//
//  Timer tick
//
void CUgl::tick()
{
   if (move)
   {
      zh = timer.interval() ? zh+0.1*timer.interval() : fmod(0.090*time.elapsed(),360);
      if (zh>360) zh -= 360;
      update();
   }
}

//
//  Reset view
//
void CUgl::reset()
{
   th = ph = 0;
   dim = Dim;
   eyex = 0;
   eyez = -180;
   eyey = 4;
   //  Request redisplay
   update();
}


//
//  Add object
//
void CUgl::addObject(Object* obj)
{
   objects.push_back(obj);
}

//
//  Set projection
//
void CUgl::setPerspective()
{
   ph = th = 0;
   eyex = 0;
   eyez = -180;
   eyey = 4;
   dim = 100;
   //  Request redisplay
   update();
}

void CUgl::setTime(int on){
    day = on? false:true;
}
//
//  Draw vertex in polar coordinates
//
static void Vertex(double th,double ph)
{
   glVertex3d(Sin(th)*Cos(ph),Cos(th)*Cos(ph),Sin(ph));
}

//
//  Draw a ball at (x,y,z) radius r
//
static void ball(double x,double y,double z,double r)
{
   //  Save transformation
   glPushMatrix();
   //  Offset, scale and rotate
   glTranslated(x,y,z);
   glScaled(r,r,r);
   //  Bands of latitude
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
   //  Undo transofrmations
   glPopMatrix();
}

//
//  Apply light
//
QVector3D CUgl::doLight()
{
   //  Light position
   float x = Lr*Cos(zh);
   float y = ylight;
   float z = Lr*Sin(zh);
   float Position[] = {x,y,z,1.0};
   float Position1[] = {0,4,25,1.0};

   //  OpenGL should normalize normal vectors
   glEnable(GL_NORMALIZE);
   //  Enable lighting
   glEnable(GL_LIGHTING);
    //  glColor sets ambient and diffuse color materials
    glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
   //  Enable light 0
    if(day){
        glColor3f(1,1,0);
        ball(x,y,z,2);
        glEnable(GL_LIGHT0);
        //  Set ambient, diffuse, specular components and position of light 0
        float Ambient[]  = {La,La,La,1.0};
        float Diffuse[]  = {Ld,Ld,Ld,1.0};
        float Specular[] = {Ls,Ls,Ls,1.0};
        glLightfv(GL_LIGHT0,GL_AMBIENT ,Ambient);
        glLightfv(GL_LIGHT0,GL_DIFFUSE ,Diffuse);
        glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);
        glLightfv(GL_LIGHT0,GL_POSITION,Position);
    }
    else{
        //  Set ambient, diffuse, specular components and position of light 0
        float Ambient[]  = {La,La,La,1.0};
        float Diffuse[]  = {Ld,Ld,Ld,1.0};
        float Specular[] = {Ls,Ls,Ls,1.0};
        glLightfv(GL_LIGHT0,GL_AMBIENT ,Ambient);
        glLightfv(GL_LIGHT0,GL_DIFFUSE ,Diffuse);
        glLightfv(GL_LIGHT0,GL_SPECULAR,Specular);
        glLightfv(GL_LIGHT0,GL_POSITION,Position1);
    }
   
   

   //  Light angle
   emit light(int(zh));

   return QVector3D(x,y,z);
    update();
}

//
//  Initialize
//
void CUgl::initializeGL()
{
}

//
//  Throw a fatal error and die
//
void CUgl::Fatal(QString message)
{
   QMessageBox::critical(this,"CUgl",message);
   QApplication::quit();
}


//
//  Apply OpenGL model view projection
//
void CUgl::doModelViewProjection()
{
   //  Window dimensions accounting for retina displays
   int w = width()*devicePixelRatio();
   int h = height()*devicePixelRatio();
   float asp = w / (float)h;
   //  Viewport is whole screen
   glViewport(0,0,w,h);
   //  Set Projection
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   double zmin = dim/16;
   double zmax = 16*dim;
   double ydim = zmin*tan(fov*M_PI/360);
   double xdim = ydim*asp;
   //  First person camera
   if (fps)
   {
      glFrustum(-xdim,+xdim,-ydim,+ydim,zmin,zmax);
       gluLookAt(eyex,eyey,eyez,
                 eyex+dirx,eyey+diry,eyez+dirz,
                 0.0f,1,0.0f);
   }
   //  Perspective
   else{
       glFrustum(-xdim,+xdim,-ydim,+ydim,zmin,zmax);
   }
    
   //  Set ModelView
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   if (fov) glTranslated(0,0,-2*dim);
   glRotated(ph,1,0,0);
   glRotated(th,0,1,0);
   //  Emit angles to display
   emit angles(QString::number(th)+","+QString::number(ph));
}

/******************************************************************/
/*************************  Mouse Events  *************************/
/******************************************************************/

//
//  Mouse pressed
//
void CUgl::mousePressEvent(QMouseEvent* e)
{
   pos = e->pos();  //  Remember mouse location
}

//
//  Mouse released
//
void CUgl::mouseReleaseEvent(QMouseEvent*)
{
}

//
//  Mouse moved
//
void CUgl::mouseMoveEvent(QMouseEvent* e)
{
    QPoint d = e->pos()-pos;  //  Change in mouse location
    viewangle -= d.x();
    updown -= d.y();
    if(updown > 89)
        updown = 89;
    else if (updown < -89)
        updown = -89;
    dirx = Sin(viewangle);
    diry = Sin(updown);
    dirz = Cos(viewangle);
    pos = e->pos();           //  Remember new location
    update();                 //  Request redisplay
}

/******************************************************************/
/*************************  Keyboard Events  **********************/
/******************************************************************/
void CUgl::keyPressEvent(QKeyEvent* k){
    //  Overall control
    if(k->key() == Qt::Key_L){
        day = 1-day;
    }
    else if(k->key() == Qt::Key_M){
        fps = 1-fps;
        setPerspective();
    }
    else if(k->key() == Qt::Key_P){
        eqp = 1-eqp;
    }
    //  First person camera controls
    if(fps){
        if(k->key() == Qt::Key_W){
            eyex += dirx * 1.5 ;
            eyez += dirz * 1.5 ;
        }
        else if(k->key() == Qt::Key_S){
            eyex -= dirx;
            eyez -= dirz;
        }
        else if(k->key() == Qt::Key_A){
            crossx = -dirz;
            crossz = dirx;
            eyex -= crossx;
            eyez -= crossz;
        }
        else if(k->key() == Qt::Key_D){
            crossx = -dirz;
            crossz = dirx;
            eyex += crossx;
            eyez += crossz;
        }
        else if(k->key() == Qt::Key_1){
            eyey -= 1;
        }
        else if(k->key() == Qt::Key_2){
            eyey += 1;
        }
    }
    //  Perspective controls
    else{
        if(k->key() == Qt::Key_Right){
            th += 5;
        }
        else if(k->key() == Qt::Key_Left){
            th -= 5;
        }
        else if(k->key() == Qt::Key_Up){
            ph += 5;
        }
        else if(k->key() == Qt::Key_Down){
            ph -= 5;
        }
    }
}
//
//  Mouse wheel
//
void CUgl::wheelEvent(QWheelEvent* e)
{
    if(!fps){
        //  Zoom out
        if (e->delta()<0)
            dim += 0.1;
        //  Zoom in
        else if (dim>1)
            dim -= 0.1;
        //  Request redisplay
        update();
    }
}

//
//  Load shader
//
void CUgl::addShader(QString vert,QString frag,QString names)
{
   QOpenGLFunctions glf(QOpenGLContext::currentContext());
   QStringList name = names.split(',');
   QOpenGLShaderProgram* prog = new QOpenGLShaderProgram;
   //  Vertex shader
   if (vert.length() && !prog->addShaderFromSourceFile(QOpenGLShader::Vertex,vert))
      Fatal("Error compiling "+vert+"\n"+prog->log());
   //  Fragment shader
   if (frag.length() && !prog->addShaderFromSourceFile(QOpenGLShader::Fragment,frag))
      Fatal("Error compiling "+frag+"\n"+prog->log());
   //  Bind Attribute Locations
   for (int k=0;k<name.size();k++)
      if (name[k].length())
         glf.glBindAttribLocation(prog->programId(),k,name[k].toLatin1().data());
   //  Link
   if (!prog->link())
      Fatal("Error linking shader\n"+prog->log());
   //  Push onto stack
   else
      shader.push_back(prog);
}

//
//  Load shader
//
void CUgl::addShader3(QString vert,QString geom,QString frag)
{
   QOpenGLShaderProgram* prog = new QOpenGLShaderProgram;
   //  Vertex shader
   if (vert.length() && !prog->addShaderFromSourceFile(QOpenGLShader::Vertex,vert))
      Fatal("Error compiling "+vert+"\n"+prog->log());
   //  Fragment shader
   if (geom.length() && !prog->addShaderFromSourceFile(QOpenGLShader::Geometry,geom))
      Fatal("Error compiling "+geom+"\n"+prog->log());
   //  Fragment shader
   if (frag.length() && !prog->addShaderFromSourceFile(QOpenGLShader::Fragment,frag))
      Fatal("Error compiling "+frag+"\n"+prog->log());
   //  Link
   if (!prog->link())
      Fatal("Error linking shader\n"+prog->log());
   //  Push onto stack
   else
      shader.push_back(prog);
}

//
//  Load image to texture unit
//
QOpenGLTexture* CUgl::loadImage(const QString file)
{
   QOpenGLTexture *tex = new QOpenGLTexture(QImage(file).mirrored());
   tex->setMinificationFilter(QOpenGLTexture::Linear);
   tex->setMagnificationFilter(QOpenGLTexture::Linear);
   return tex;
}
