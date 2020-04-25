#ifndef NODE_HPP
#define NODE_HPP

//------------------------------------------------------------------------------
#include <QStringListModel>
#include <QThread>

#include <string>

#include <ros/ros.h>

//------------------------------------------------------------------------------
class QNode : public QThread
{
<<<<<<< HEAD
  Q_OBJECT

public:
  int init_argc;
  char** init_argv;
  const std::string node_name;

  QNode(int argc, char** argv, const std::string& name);
  virtual ~QNode();

  bool init();
  void run();
  void shutdown();

Q_SIGNALS:
  void rosShutdown();
};

#endif  // NODE_HPP
=======
Q_OBJECT

public:
    int init_argc;
    char** init_argv;
    const std::string node_name;

    QNode(int argc, char** argv, const std::string &name );
    virtual ~QNode();

    bool init();
    void run();
    void shutdown();

Q_SIGNALS:
    void rosShutdown();
};

#endif // NODE_HPP
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

//------------------------------------------------------------------------------
