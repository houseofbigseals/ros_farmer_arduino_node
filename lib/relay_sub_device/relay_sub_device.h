#ifndef ROS_FARM_RELAY_SUB_DEVICE_H
#define ROS_FARM_RELAY_SUB_DEVICE_H
/*
#include <std_msgs/String.h>
#include <base_device.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int16MultiArray.h>

class RelayChannel
{
    // subclass to store info about relay type and other
    public:
    uint8_t pin;
    uint8_t channel_number;
    RelayChannel(
        uint8_t pin_ = 100,
        uint8_t channel_number_ = 100
    );
    void setOn();
    void setOff();
};

class RelaySubDevice //: public BaseSubDevice
{
    public:
    char* relay_sub_name;
    
    uint8_t relay_arr_len;  //less then 32 so uint8_t
    RelayChannel* relay_arr;
    
    ros::NodeHandle* nh;
    ros::Subscriber<std_msgs::Int16MultiArray> * sub; //("eight_relay", &messageCb );
    bool init_error;
    
    RelaySubDevice(
        ros::NodeHandle* nh_,
        char* relay_sub_name_,
        uint8_t relay_arr_len_,
        uint8_t* pinout_
        );
    void topics_init();
    void messageCb(const std_msgs::Int16MultiArray &relay_msg);
};

*/

#endif