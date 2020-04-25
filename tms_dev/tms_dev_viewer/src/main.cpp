//------------------------------------------------------------------------------
// @file   : main.cpp
// @brief  : main function
// @author : Yoonseok Pyo, Masahide Tanaka
// @version: Ver0.9.5 (since 2012.05.17)
// @date   : 2012.11.14
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <QtGui/QApplication>

#include <ros/ros.h>

#include "mainwindow.h"
#include "qnode.hpp"

//------------------------------------------------------------------------------
// Implementation
//------------------------------------------------------------------------------
int main(int argc, char **argv)
{
<<<<<<< HEAD
  QApplication app(argc, argv);
  QNode qnode(argc, argv, "tms_viewer");
  MainWindow window(&qnode);
  window.show();
  return app.exec();
=======
    QApplication app(argc, argv);
    QNode qnode(argc,argv,"tms_viewer");
    MainWindow window(&qnode);
    window.show();
    return app.exec();
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
}

//------------------------------------------------------------------------------
