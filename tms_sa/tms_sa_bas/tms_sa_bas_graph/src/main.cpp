//------------------------------------------------------------------------------
// @file   : main.cpp
// @brief  : implement mainwindow
// @author : Yoonseok Pyo, Masahide Tanaka
// @version: Ver0.4 (since 2012.06.05)
// @date   : 2012.11.26
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "mainwindow.hpp"

//------------------------------------------------------------------------------
// Implementation
//------------------------------------------------------------------------------
int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  bas_graph::MainWindow window(argc, argv);
  window.resize(950, 870);
  window.show();
  return app.exec();
}

//------------------------------------------------------------------------------
