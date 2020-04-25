#ifndef _VOICE_RECEIVER_H
#define _VOICE_RECEIVER_H

#include "tms_ur_gaze_server/recognized_text.h"
#include "tms_ur_gaze_server/object_list.h"
#include "tms_msg_rp/rp_arrow.h"

#include <ros/ros.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>

class VoiceReceiver
{
private:
  ros::NodeHandle* nh_;
  ros::ServiceServer server_;
  ros::ServiceClient client_, arrow_client_;
<<<<<<< HEAD
  std::map< std::string, std::string* > hash_;
  std::vector< std::string > value_;

=======
  std::map<std::string, std::string*> hash_;
  std::vector<std::string> value_;
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
public:
  VoiceReceiver(ros::NodeHandle* nh);
  ~VoiceReceiver();
  void ListCandidates(std::string tag, tms_ur_gaze_server::object_list* srv);
<<<<<<< HEAD
  bool Callback(tms_ur_gaze_server::recognized_text::Request& req, tms_ur_gaze_server::recognized_text::Response& res);
=======
  bool Callback(tms_ur_gaze_server::recognized_text::Request  &req,
                tms_ur_gaze_server::recognized_text::Response &res);
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
};

#endif
