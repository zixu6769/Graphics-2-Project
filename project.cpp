//
//  CSCI-4239 Final Project
//  Zijun Xu
//

#include <QApplication>
#include "projectviewer.h"

//
//  Main function
//
int main(int argc, char *argv[])
{
   //  Create the application
   QApplication app(argc,argv);
   //  Create and show view widget
   projectviewer view;
   view.show();
   //  Main loop for application
   return app.exec();
}
