//
//  projectviewer Widget
//

#include <QComboBox>
#include <QLabel>
#include <QGridLayout>
#include "projectviewer.h"

//
//  Constructor
//
projectviewer::projectviewer()
{
   //  Set window title
   setWindowTitle(tr("Project: Zijun Xu"));
   //  Create new OpenGL widget
   ogl = new projectopengl;
   //  Center position
   Xpos = new QDoubleSpinBox();
   Ypos = new QDoubleSpinBox();
   Zpos = new QSlider(Qt::Horizontal);
   Xpos->setRange(-100,100);Xpos->setDecimals(6);Xpos->setSingleStep(0.1);
   Ypos->setRange(-100,100);Ypos->setDecimals(6);Ypos->setSingleStep(0.1);
   Zpos->setRange(0,100);
   //  Reset
   QPushButton* rst = new QPushButton("Reset");
   //  Quit
   QPushButton* quit = new QPushButton("Quit");
   //  Set layout of child widgets
   QGridLayout* layout = new QGridLayout;
   layout->addWidget(ogl,0,0,11,1);
   layout->addWidget(rst,9,1);
   layout->addWidget(quit,10,1);
    
   //  Manage resizing
   layout->setColumnStretch(0,100);
   layout->setColumnMinimumWidth(0,100);
   layout->setRowStretch(9,100);
   setLayout(layout);

   //  Connect wchild widgets
   connect(rst  ,SIGNAL(pressed()),this,SLOT(reset()));
   connect(quit,SIGNAL(pressed()) , qApp,SLOT(quit()));
}

//
//  Reset view
//
void projectviewer::reset()
{
   Xpos->setValue(0);
   Ypos->setValue(0);
   Zpos->setValue(0);
   ogl->reset();
}
