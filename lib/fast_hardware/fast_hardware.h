#ifndef ROS_FARM_FAST_HARDWARE_H
#define ROS_FARM_FAST_HARDWARE_H

#include <ros.h>

class FastHardware : public ArduinoHardware
{
  public:
  // especially for using in turtlebro`s mainboard arduino
  FastHardware():ArduinoHardware(&Serial, 115200){};
};


#endif