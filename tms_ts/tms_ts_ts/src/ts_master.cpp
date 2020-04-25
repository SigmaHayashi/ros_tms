<<<<<<< HEAD
// rosrun nodelet nodelet load tms_ts_nodelet/TS nodelet_manager __name:=ts_nodelet1 ts_nodelet1/tms_ts:=req1
// rosrun nodelet nodelet load tms_ts_nodelet/TS nodelet_manager __name:=nodelet1 nodelet1/tms_ts:=req1
=======
//rosrun nodelet nodelet load tms_ts_nodelet/TS nodelet_manager __name:=ts_nodelet1 ts_nodelet1/tms_ts:=req1
//rosrun nodelet nodelet load tms_ts_nodelet/TS nodelet_manager __name:=nodelet1 nodelet1/tms_ts:=req1
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
#include <tms_ts/ts_master.hpp>

int TmsTsMaster::state_condition = -1;
int TmsTsMaster::loop_counter = 0;
bool TmsTsMaster::abort = false;

<<<<<<< HEAD
std::list< TmsTsMaster::Task > task_list_;
// return first data of the list
int at_rostime(void)
{
  std::list< TmsTsMaster::Task >::iterator it = task_list_.begin();
=======
std::list<TmsTsMaster::Task> task_list_;
// return first data of the list
int at_rostime(void)
{
  std::list<TmsTsMaster::Task>::iterator it = task_list_.begin();
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  return it->rostime;
}

int at_taskID0(void)
{
<<<<<<< HEAD
  std::list< TmsTsMaster::Task >::iterator it = task_list_.begin();
=======
  std::list<TmsTsMaster::Task>::iterator it = task_list_.begin();
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  return it->task_id;
}

int at_robotID0(void)
{
<<<<<<< HEAD
  std::list< TmsTsMaster::Task >::iterator it = task_list_.begin();
=======
  std::list<TmsTsMaster::Task>::iterator it = task_list_.begin();
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  return it->robot_id;
}

int at_objectID0(void)
{
<<<<<<< HEAD
  std::list< TmsTsMaster::Task >::iterator it = task_list_.begin();
=======
  std::list<TmsTsMaster::Task>::iterator it = task_list_.begin();
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  return it->object_id;
}

int at_userID0(void)
{
<<<<<<< HEAD
  std::list< TmsTsMaster::Task >::iterator it = task_list_.begin();
=======
  std::list<TmsTsMaster::Task>::iterator it = task_list_.begin();
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  return it->user_id;
}

int at_placeID0(void)
{
<<<<<<< HEAD
  std::list< TmsTsMaster::Task >::iterator it = task_list_.begin();
=======
  std::list<TmsTsMaster::Task>::iterator it = task_list_.begin();
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  return it->place_id;
}

int at_priority(void)
{
<<<<<<< HEAD
  std::list< TmsTsMaster::Task >::iterator it = task_list_.begin();
=======
  std::list<TmsTsMaster::Task>::iterator it = task_list_.begin();
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  return it->priority;
}

std::string TmsTsMaster::run_nodelet_manager = "rosrun nodelet nodelet manager __name:=nodelet_manager\n";
std::string TmsTsMaster::rosrun = "rosrun nodelet nodelet load tms_ts_nodelet/ROS_TMS_TS nodelet_manager __name:=";
std::string TmsTsMaster::node_name = "ts_nodelet";
std::string TmsTsMaster::service_name = "request";

boost::posix_time::time_duration const td = boost::posix_time::seconds(3);

TmsTsMaster::TmsTsMaster(int argc, char **argv)
{
  // task initializer
<<<<<<< HEAD
  for (uint32_t i = 0; i < MAX_TASK_NUM * 2; i++)
  {
    task_manager[i].num = boost::lexical_cast< std::string >(i);
=======
  for (uint32_t i=0; i<MAX_TASK_NUM*2; i++)
  {
    task_manager[i].num = boost::lexical_cast<std::string>(i);
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    task_manager[i].flag = 0;
  }

  // ros init
  ros::init(argc, argv, "tms_ts_master");
  ros::NodeHandle n;
  service = n.advertiseService("tms_ts_master", &TmsTsMaster::ts_master_callback, this);
  state_control_srv = n.advertiseService("ts_state_control", &TmsTsMaster::stsCallback, this);
}

// rosspin
void TmsTsMaster::ros_spin()
{
  ros::MultiThreadedSpinner spinner(2);
  spinner.spin();
}

<<<<<<< HEAD
std::string TmsTsMaster::CreateSrvCall(long long int rostime, int task_id, int robot_id, int object_id, int user_id,
                                       int place_id, int priority, int thread_num)
{
  // std::string s_rostime = boost::lexical_cast<std::string>(rostime);
  ROS_INFO("CreateSrvCall");
  std::string s_rostime("0");
  // string s_task_id = IntToString(task_id);
  std::string s_task_id = boost::lexical_cast< std::string >(task_id);
  std::string s_robot_id = boost::lexical_cast< std::string >(robot_id);
  std::string s_object_id = boost::lexical_cast< std::string >(object_id);
  std::string s_user_id = boost::lexical_cast< std::string >(user_id);
  std::string s_place_id = boost::lexical_cast< std::string >(place_id);
  std::string s_priority = boost::lexical_cast< std::string >(priority);

  // rosservice call /request{num} "rostime" "task_id" "robot_id" "object_id" "user_id" "place_id" "priority"\n
=======
std::string TmsTsMaster::CreateSrvCall(long long int rostime, int task_id, int robot_id, int object_id,
  int user_id, int place_id, int priority, int thread_num)
{
  //std::string s_rostime = boost::lexical_cast<std::string>(rostime);
  std::string s_rostime("0");
  //string s_task_id = IntToString(task_id);
  std::string s_task_id = boost::lexical_cast<std::string>(task_id);
  std::string s_robot_id = boost::lexical_cast<std::string>(robot_id);
  std::string s_object_id = boost::lexical_cast<std::string>(object_id);
  std::string s_user_id = boost::lexical_cast<std::string>(user_id);
  std::string s_place_id = boost::lexical_cast<std::string>(place_id);
  std::string s_priority = boost::lexical_cast<std::string>(priority);

  //rosservice call /request{num} "rostime" "task_id" "robot_id" "object_id" "user_id" "place_id" "priority"\n
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  std::string command("rosservice call /");
  command += service_name;
  command += task_manager[thread_num].num;
  command += " \"";
  command += s_rostime;
  command += "\" \"";
  command += s_task_id;
  command += "\" \"";
  command += s_robot_id;
  command += "\" \"";
  command += s_object_id;
  command += "\" \"";
  command += s_user_id;
  command += "\" \"";
  command += s_place_id;
  command += "\" \"";
  command += s_priority;
  command += "\"\n";

  return command;
}

std::string TmsTsMaster::CreateRunCmd(int thread_num)
{
  std::string command;
  std::string space(" ");
  std::string enter("\n");

<<<<<<< HEAD
  command = rosrun + node_name;
=======
  command = rosrun+node_name;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  command += task_manager[thread_num].num;
  command += space;
  command += node_name;
  command += task_manager[thread_num].num;
  command += "/tms_ts:=";
  command += service_name;
  command += task_manager[thread_num].num;
  command += enter;
  return command;
}

<<<<<<< HEAD
bool TmsTsMaster::ExecuteCmd(const char *buf)
{
  int ret;
  std::cout << buf << std::endl;  // subtask
=======
bool TmsTsMaster::ExecuteCmd(const char* buf)
{
  int ret;
  std::cout << buf << std::endl; // subtask
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

  ret = system(buf);

  // Cannot run the command
<<<<<<< HEAD
  if (ret != 0)
=======
  if(ret != 0)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    ROS_ERROR("Shut down system call\n");
    return false;
  }
<<<<<<< HEAD
  ROS_INFO("return true");
=======
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  return true;
}

// store request data to tasklist
<<<<<<< HEAD
bool TmsTsMaster::ts_master_callback(tms_msg_ts::ts_req::Request &req, tms_msg_ts::ts_req::Response &res)
=======
bool TmsTsMaster::ts_master_callback(tms_msg_ts::ts_req::Request &req,
  tms_msg_ts::ts_req::Response &res)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
{
  ROS_INFO("in callback function.\n");

  ros::Time time_now = ros::Time::now();
  Task tmp_task;
  tmp_task.task_id = req.task_id;
  tmp_task.robot_id = req.robot_id;
  tmp_task.object_id = req.object_id;
  tmp_task.user_id = req.user_id;
  tmp_task.place_id = req.place_id;
  tmp_task.priority = req.priority;
  tmp_task.rostime = time_now.toNSec();
  task_list_.push_back(tmp_task);

  // sort first condition：priority, second condition：rostime
  task_list_.sort(pred());
<<<<<<< HEAD
  std::list< Task >::iterator it = task_list_.begin();

  while (it != task_list_.end())
=======
  std::list<Task>::iterator it = task_list_.begin();

  while( it != task_list_.end() )
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
  {
    std::cout << it->task_id << std::endl;
    std::cout << it->priority << std::endl;
    ++it;  // iterator +1
  }
<<<<<<< HEAD
  res.result = 1;  // success
  return true;
}

bool TmsTsMaster::stsCallback(tms_msg_ts::ts_state_control::Request &req, tms_msg_ts::ts_state_control::Response &res)
{
  if (req.type == 0)  // judge segment(from TS)
  {
    if (req.cc_subtasks == 0)
    {
      while (loop_counter < 1)  // TIMEOUT
=======
  res.result = 1; // success
  return true;
}

bool TmsTsMaster::stsCallback(tms_msg_ts::ts_state_control::Request &req,
  tms_msg_ts::ts_state_control::Response &res)
{
  if (req.type == 0) // judge segment(from TS)
  {
    if (req.cc_subtasks == 0)
    {
      while (loop_counter < 1) // TIMEOUT
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
      {
        if (abort == true)
        {
          abort = false;
          break;
        }
      }

      if (state_condition == 0)
      {
<<<<<<< HEAD
        state_condition = -1;  // initialize
        loop_counter = 0;      // initialize
=======
        state_condition = -1; // initialize
        loop_counter = 0; // initialize
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        res.result = 1;
        return true;
      }
      else
      {
        ROS_ERROR("Sequential task stopped due to subtask return false");
<<<<<<< HEAD
        state_condition = -1;  // initialize
        loop_counter = 0;      // initialize
=======
        state_condition = -1; // initialize
        loop_counter = 0; // initialize
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        res.result = 0;
        return false;
      }
    }
    else if (req.cc_subtasks >= 2)
    {
<<<<<<< HEAD
      while (loop_counter < req.cc_subtasks)  // TIMEOUT
=======
      while (loop_counter < req.cc_subtasks) // TIMEOUT
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
      {
        if (abort == true)
        {
          abort = false;
          break;
        }
      }

<<<<<<< HEAD
      if (state_condition == (req.cc_subtasks - 1))
      {
        state_condition = -1;  // initialize
        loop_counter = 0;      // initialize
=======
      if (state_condition == (req.cc_subtasks-1))
      {
        state_condition = -1; // initialize
        loop_counter = 0; // initialize
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        res.result = 1;
        return true;
      }
      else
      {
        ROS_ERROR("Concurrence task stopped due to subtask return false");
<<<<<<< HEAD
        state_condition = -1;  // initialize
        loop_counter = 0;      // initialize
=======
        state_condition = -1; // initialize
        loop_counter = 0; // initialize
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        res.result = 0;
        return false;
      }
    }
    else
    {
      ROS_ERROR("Illegal subtasks number.");
      state_condition = -1;
      loop_counter = 0;
      return false;
    }
  }
  else if (req.type == 1)
<<<<<<< HEAD
  {  // update segment(from RP)
=======
  { // update segment(from RP)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    // req.state
    //            0 : error occurred
    // other number : succeed subtask
    if (req.state == 0)
    {
      ROS_ERROR("Error %d: %s", req.state, req.error_msg.c_str());
      loop_counter++;
      return false;
    }
    state_condition += req.state;
    loop_counter++;
    return true;
  }
  else if (req.type == 2)
<<<<<<< HEAD
  {  // abort instruction(from RC)
=======
  { // abort instruction(from RC)
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
    //** 今はRPで呼び出したRCのプログラムがfalseで返ってきたときにtype2でエラーをTSに通知する
    ROS_ERROR("Error %d: %s", req.state, req.error_msg.c_str());
    abort = true;
    return false;
  }
  else
  {
    ROS_ERROR("Illegal type number.");
    return false;
  }
}

<<<<<<< HEAD
bool TmsTsMaster::addThread(int thread_num,const char* arg1,const char* arg2)
{
  bool has_completed;
  threads[thread_num] = new boost::thread(boost::bind(&TmsTsMaster::ExecuteCmd, this, arg1));
  // service call to nodelet_node from threads[i+MAX_TASK_NUM]
  has_completed = threads[thread_num]->timed_join(td);
  threads[thread_num+MAX_TASK_NUM] = new boost::thread(boost::bind(&TmsTsMaster::ExecuteCmd, this, arg2));
  // service call to nodelet_node from threads[i+MAX_TASK_NUM]
  has_completed = threads[thread_num+MAX_TASK_NUM]->timed_join(td);
}

int main(int argc, char **argv)
{
  task_list_.clear();
  TmsTsMaster ts(argc, argv);  // instance
=======
int main(int argc, char **argv)
{
  task_list_.clear();
  TmsTsMaster ts(argc, argv); // instance
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7

  static std::string manager = ts.run_nodelet_manager;

  // run nodelet manager
  boost::thread thread0(boost::bind(&TmsTsMaster::ExecuteCmd, &ts, manager.c_str()));
  boost::thread thread1(boost::bind(&TmsTsMaster::ros_spin, &ts));
  // thread array for running task
<<<<<<< HEAD
  // boost::thread *threads[MAX_TASK_NUM * 2];

  ros::Rate loop_rate(1);  // 1Hz

  while (ros::ok())
  {
    if (task_list_.empty() == 1)
    {  // No task
    }
    else
    {
      for (int i = 0; i < MAX_TASK_NUM; i++)
      {
        if (ts.task_manager[i].flag == 0)  // unused thread
=======
  boost::thread *threads[MAX_TASK_NUM*2];

  bool has_completed;
  ros::Rate loop_rate(1); // 1Hz

  while(ros::ok())
  {
    if (task_list_.empty() == 1)
    { // No task
    }
    else
    {
      for (int i=0; i<MAX_TASK_NUM; i++)
      {
        if (ts.task_manager[i].flag == 0) // unused thread
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        {
          ts.task_manager[i].flag = 1;
          ROS_INFO("Thread number is %d", i);
          // store task data and delete from list
<<<<<<< HEAD
          std::string srv_req = ts.CreateSrvCall(at_rostime(), at_taskID0(), at_robotID0(), at_objectID0(),
                                                 at_userID0(), at_placeID0(), at_priority(), i);
          task_list_.pop_front();
          ts.addThread(i,(ts.CreateRunCmd(i)).c_str(),srv_req.c_str());

          // run node with threads[i]
          // threads[i] = new boost::thread(boost::bind(&TmsTsMaster::ExecuteCmd, &ts, (ts.CreateRunCmd(i)).c_str()));
          // // service call to nodelet_node from threads[i+MAX_TASK_NUM]
          // has_completed = threads[i]->timed_join(td);
          // threads[i + MAX_TASK_NUM] = new boost::thread(boost::bind(&TmsTsMaster::ExecuteCmd, &ts, srv_req.c_str()));
          break;
        }
        else if (i == MAX_TASK_NUM - 1)
        {
          ROS_WARN("No free-thread! Sleep for 3.0 seconds.\n");
          ros::Duration(3.0).sleep();
          i = 0;  // repeat
=======
          std::string srv_req = ts.CreateSrvCall(at_rostime(), at_taskID0(), at_robotID0(), at_objectID0(), at_userID0(), at_placeID0(), at_priority(), i);
          task_list_.pop_front();
          // run node with threads[i]
          threads[i] = new boost::thread(boost::bind(&TmsTsMaster::ExecuteCmd, &ts,(ts.CreateRunCmd(i)).c_str()));
          // service call to nodelet_node from threads[i+MAX_TASK_NUM]
          has_completed = threads[i]->timed_join(td);
          threads[i+MAX_TASK_NUM] = new boost::thread(boost::bind(&TmsTsMaster::ExecuteCmd, &ts, srv_req.c_str()));
          break;
        }
        else if (i == MAX_TASK_NUM-1)
        {
          ROS_WARN("No free-thread! Sleep for 3.0 seconds.\n");
          ros::Duration(3.0).sleep();
          i = 0; // repeat
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
        }
      }
    }
    loop_rate.sleep();
  }
  return 0;
}
