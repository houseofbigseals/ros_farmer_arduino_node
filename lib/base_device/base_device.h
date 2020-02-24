#ifndef ROS_FARM_BASE_DEVICE_H
#define ROS_FARM_BASE_DEVICE_H


#include <ros.h>
//#include <std_msgs/String.h>
//#include <std_msgs/Float32.h>

// constants definition

// error codes for devices debug topic

// sensor data publish errors 
// 0x10-0x19

const uint8_t ROS_FARM_GET_RAW_DATA_FROM_SENSOR_ERROR = 0x12;
const uint8_t ROS_FARM_INIT_SENSOR_ERROR = 0x11;
const uint8_t ROS_FARM_UNKNOWN_SENSOR_ERROR = 0x13;
// device subscriber error
// 0x20-0x29
const uint8_t ROS_FARM_INIT_DEVICE_ERROR = 0x21;
const uint8_t ROS_FARM_SET_MODE_TO_DEVICE_ERROR = 0x22;
const uint8_t ROS_FARM_UNKNOWN_DEVICE_ERROR = 0x23;
// other errors
const uint8_t ROS_FARM_UNKNOWN_SYSTEM_ERROR = 0xFF;

class BasePubDevice
{
    public:
    //virtual void init() = 0;
    virtual void publish_once() = 0;
    virtual void nonblocking_publish_loop() = 0;
};

class BaseSubDevice
{
    public:
    //virtual void init() = 0;
    virtual void messageCb() = 0;
};

#endif