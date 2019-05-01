#ifndef projectV_H
#define projectV_H

#include <QWidget>
#include <QSlider>
#include <QDoubleSpinBox>
#include "projectopengl.h"

class projectviewer : public QWidget
{
Q_OBJECT
private:
   QDoubleSpinBox* Xpos;
   QDoubleSpinBox* Ypos;
   QSlider*        Zpos;
   projectopengl*    ogl;
private slots:
   void reset();        //  Reset angles
public:
    projectviewer();
};

#endif
