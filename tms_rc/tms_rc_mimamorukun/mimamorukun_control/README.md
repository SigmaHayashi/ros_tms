# tms_rc_mimamorukun_control
<<<<<<< HEAD
## Network setup
Setup ethernet port of PC as below.
- `IP Address`: 192.168.11.10
- `Subnet Mask`: 255.255.255.0
- `Default Gateway`: 192.168.11.96
- `DNS`: 192.168.11.1

You can check IP address and port setting of `chairbot` by connecting usb to Mbed(micro controller) in robot.

---
## Minimal control node.
Launch below
=======
---
## Minimal control program.
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
```
roslaunch tms_rc_mimamorukun_control minimal.launch
```
This node serve
* Subcrive topic for control **velocity**
* Publish topics for **odometry** and **tf** information

<<<<<<< HEAD
You must launch this file first at all.  
If you want to change IP address and port setting, you must modify minimal.launch.
=======
You must launch this file first at all.

If you want to change IP address and port setting, you must modify minimal.launch.
You can check IP address and port setting by connecting usb to Mbed(micro controller) in robot.
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7


---
### Joystick control
<<<<<<< HEAD
Launch below.  
```
sudo chmod a+rw /dev/input/js0
roslaunch tms_rc_mimamorukun_control joyop.launch
```

* `'0' button`: unlock control
* `'1' button`: lock control
* `'4' button`: enable Analog Stick during pushing down
* `'1' analog stick`: control velocity
* `'0' analog stick`: control angular

Use below command to install depending packages
```
sudo apt-get install ros-indigo-yocs-joyop ros-indigo-joy
```
----
### Keyboard control
Launch below.
```
roslaunch tms_rc_mimamorukun_control keyop.launch
```
* `'e' key`: enable sending velocity command
* `arrow keys` : control velocity

Use below command to install depending packages
=======
```
roslaunch tms_rc_mimamorukun_control joyop.launch
```
Make sure to ``yocs-joyop`` is installed.
If not, run command below
```
sudo apt-get install ros-indigo-yocs-joyop
```

### Keyboard control
```
roslaunch tms_rc_mimamorukun_control keyop.launch
```
Make sure to ``kobuki_keyop`` is installed.
If not, run command below
>>>>>>> 51ecc3540900cfe208d8c2ca1ecaf2184d407ca7
```
sudo apt-get install ros-indigo-kobuki_keyop
```
