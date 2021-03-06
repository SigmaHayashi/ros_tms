//------------------------------------------------------------------------------
// @file   : main.cpp
// @brief  : implement mainwindow
// @author : Yoonseok Pyo
// @version: Ver0.6 (since 2012.06.05)
// @date   : 2012.11.26
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include "../include/tms_ss_fss_graph/mainwindow.hpp"

//------------------------------------------------------------------------------
// Implementation
//------------------------------------------------------------------------------
int main(int argc, char **argv)
{
  QApplication app(argc, argv);
  fss_graph::MainWindow window(argc, argv);
  window.resize(1900, 900);
  window.show();
  return app.exec();
}

//------------------------------------------------------------------------------
