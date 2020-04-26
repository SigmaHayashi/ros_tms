# ROS-TMS for Smart Previewed Reality
Smart Previewed Realityのために改造されたROS-TMS

# 導入方法
本家ROS-TMSのWikiを参照

本家ROS-TMS : https://github.com/irvs/ros_tms

Wiki : https://github.com/irvs/ros_tms/wiki

# 本家ROS-TMSとの差異
太字のパッケージは本家ROS-TMSと差異有り

* dependency
* ros_tms
* tms_db
* tms_dev
* tms_legacy
* **tms_msg**  
     msgやsrvを追加

* **tms_rc**  
     tms_rc_smartpalにsmartpal_control_unity/scripts/smartpal_arm_control_unity.pyを追加  
     ※ moveitで計画されたロボットアームの動作計画をTopic Messageとして取得し，HoloLens(Unity)に送信する

* **tms_rp**  
     rostms_bringup, rostms_description下にあるファイルを適宜変更

* tms_rs
* tms_sa
* tms_sd
* tms_ss
* **tms_ts**  
     * 本家のtms_ts_subtask.cppをtms_ts_subtask_common.cppに命名変更
     * tms_ts_subtask.cpp  
          StepByStepでロボットを移動させる際のtms_ts

     * **tms_ts_subtask_for_preview.cpp (推奨)**  
          Seriesでロボットを移動させる際のtms_ts  
          ロボットアームの動作に関してはこちらもStepByStepで実装してある（MoveItからの動作計画の取得周辺をSeriesで実装するのが手間だったため）

* **tms_ur**  
     tms_ur_notificationの追加  
     ※ 詳しい説明 : [tms_ur/tms_ur_notification](https://github.com/SigmaHayashi/ros_tms_for_smart_previewed_reality/tree/master/tms_ur/tms_ur_notification)

# Smart Previewed Reality
Smart Previewed Realityと，その実行方法等については，そちらを参照

Smart Previewed Reality : https://github.com/SigmaHayashi/Smart-Previewed-Reality

***
***
以下は本家ROS-TMSのREADME
***

# ROS-TMS
* It is a service robot system with an informationally structured environment referred to the ROS-TMS. This system enables the integration of various data from distributed sensors, as well as storage of these data in an on-line database and the planning of the service motion of a robot using real-time information about the surroundings.

# Reference information
* Wiki > https://github.com/irvs/ros_tms/wiki
* Web > http://irvs.github.io/ros_tms
* Paper > Yoonseok Pyo, Kouhei Nakashima, Shunya Kuwahata, Ryo Kurazume, Tokuo Tsuji, Ken’ichi Morooka, Tsutomu Hasegawa, Service robot system with an informationally structured environment, Robotics and Autonomous Systems, Volume 74, Part A, December 2015, Pages 148-165, ISSN 0921-8890, http://dx.doi.org/10.1016/j.robot.2015.07.010.

# Version and developer information
* date : 2016.02.12 (since 2012.5.1 ROS-TMS / since 2005.11.1 TMS)
* current version : 4.0.1 (2016.02.12)
* director :

 Prof. Ryo Kurazume,  Assistant Prof. Akihiro Kawamura

* maintainer :

 Akihiro Kawamura (kawamura at ait.kyushu-u.ac.jp)

 Junya Sakamoto (sakamoto at irvs.ait.kyushu-u.ac.jp)

* developer :

 2016 : Yuta Watanabe, Akio Shigekane, Daisuke Inada, Kazuto Nakashima, Yuta Horikawa, Junya Sakamoto

 2015 : Yoonseok Pyo, Masatomo Onishi, Yuta Watanabe, Akio Shigekane, Daisuke Inada, Kazuto Nakashima, Yuta Horikawa, Junya Sakamoto

 2014 : Yoonseok Pyo, Yuka Hashiguchi, Tetsuro Oishi, Kazuya Suginohara, Kazuto Nakashima, Yuta Watanabe, Daisuke Inada, Akio Shigekane, Tokuo Tsuji, Omar Alaoui

 2013 : Yoonseok Pyo, Akihiro Nagata, Shunya Kuwahata, Kouhei Nakashima, Kazuya Kusaka, Yuka Hashiguchi, Tetsuro Oishi, Kazuya Suginohara, Tokuo Tsuji

 2012 : Yoonseok Pyo, Masahide Tanaka, Akihiro Nagata, Tokuo Tsuji

* dependency software :
 * Ubuntu 14.04 LTS 64BIT
 * ROS Indigo
 * mongodb 2.6
 * pymongo 2.6.3
 * opencv 2.4.8
 * libpcl-1.7-all libopenni2-0 etc...
 * pcl_ros
 * ARIA 2.8.1 (http://robots.mobilerobots.com/wiki/ARIA)
