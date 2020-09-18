#ifndef ROS_FARM_BMP180_PUB_DEVICE_H
#define ROS_FARM_BMP180_PUB_DEVICE_H


#include <sensor_msgs/Temperature.h>
#include <std_msgs/String.h>
#include <base_device.h>
#include <ros/time.h>
#include "std_msgs/Float32.h"
#include <Adafruit_BMP085.h>

class BMP180PubDevice : public BasePubDevice
{
    public:
    Adafruit_BMP085 bmp = Adafruit_BMP085();
    char* temp_pub_name;
    char* pressure_pub_name;
    sensor_msgs::Temperature temp_msg;
    sensor_msgs::Temperature pressure_msg;
    bool init_error;
    //ros::NodeHandle* nh;
    ros::NodeHandle_<ArduinoHardware, 5, 5, 1024, 2048>* nh;
    unsigned long publish_interval;  //ms
    unsigned long previous_millis;
    ros::Publisher pressure_pub;
    ros::Publisher temp_pub;
    
    BMP180PubDevice(
        //ros::NodeHandle* nh_,
        ros::NodeHandle_<ArduinoHardware, 5, 5, 1024, 2048>* nh_,
        char* temp_pub_name_,
        char* pressure_pub_name_,
        unsigned long publish_interval_
        );
    void publish_once();
    void nonblocking_publish_loop();
    void topics_init();
};

#endif