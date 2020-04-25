//------------------------------------------------------------------------------
// Ifdefs
//------------------------------------------------------------------------------
#ifndef QNODE_HPP
#define QNODE_HPP

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <QThread>
#include <QStringListModel>
#include <qapplication.h>

#include <ros/ros.h>

#include <string>

#include <tms_msg_ss/bas_behavior_data.h>

//------------------------------------------------------------------------------
// Structs
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Namespaces
//------------------------------------------------------------------------------
<<<<<<< HEAD
namespace bas_graph
{
=======
namespace bas_graph {

>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
//------------------------------------------------------------------------------
// Class
//------------------------------------------------------------------------------
class QNode : public QThread
{
<<<<<<< HEAD
  Q_OBJECT

public:
  QNode(int argc, char** argv);
  virtual ~QNode();

  bool init();
  void run();
  void shutdown();

  tms_msg_ss::bas_behavior_data m_bas_behavior_data;

Q_SIGNALS:
  void rosShutdown();

private:
  void behaviorCallback(const tms_msg_ss::bas_behavior_data::ConstPtr& msg);

  int init_argc;
  char** init_argv;

  ros::Subscriber bas_graph_subscriber;
  ros::Publisher bas_graph_publisher;
};

//------------------------------------------------------------------------------
}  // namespace bas_graph
=======
    Q_OBJECT

public:
    QNode(int argc, char** argv );
	virtual ~QNode();

    bool init();
	void run();
    void shutdown();

    tms_msg_ss::bas_behavior_data m_bas_behavior_data;

Q_SIGNALS:
    void rosShutdown();

private:
    void behaviorCallback(const tms_msg_ss::bas_behavior_data::ConstPtr& msg);

    int init_argc;
	char** init_argv;

    ros::Subscriber bas_graph_subscriber;
    ros::Publisher  bas_graph_publisher;
};

//------------------------------------------------------------------------------
}       // namespace bas_graph
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#endif  // QNODE_HPP

//------------------------------------------------------------------------------
