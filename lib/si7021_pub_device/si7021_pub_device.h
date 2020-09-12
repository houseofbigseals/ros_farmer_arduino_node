#ifndef ROS_FARM_SI7021_PUB_DEVICE_H
#define ROS_FARM_SI7021_PUB_DEVICE_H


#include <sensor_msgs/Temperature.h>
#include <std_msgs/String.h>
#include <base_device.h>
#include <ros/time.h>
#include "std_msgs/Float32.h"
#include "Adafruit_Si7021.h"

class SI7021PubDevice : public BasePubDevice
{
    public:
    Adafruit_Si7021 sensor = Adafruit_Si7021();
    char* temp_pub_name;
    char* hum_pub_name;
    //std_msgs::Float32 temp_msg;
    //std_msgs::Float32 hum_msg;
    sensor_msgs::Temperature temp_msg;
    sensor_msgs::Temperature hum_msg;
    bool init_error;
    //ros::NodeHandle* nh;
    ros::NodeHandle_<ArduinoHardware, 5, 5, 1024, 1024>* nh;
    unsigned long publish_interval;  //ms
    unsigned long previous_millis;
    ros::Publisher hum_pub; //("si7021_temp", &si7021_temp_msg);
    ros::Publisher temp_pub;
    


    SI7021PubDevice(
        //ros::NodeHandle* nh_,
        ros::NodeHandle_<ArduinoHardware, 5, 5, 1024, 1024> * nh_,
        char* temp_pub_name_,
        char* hum_pub_name_,
        unsigned long publish_interval_
        );
    void publish_once();
    void nonblocking_publish_loop();
    void topics_init();
};

#endif