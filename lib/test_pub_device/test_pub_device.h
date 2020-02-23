#ifndef ROS_FARM_TEST_PUB_DEVICE_H
#define ROS_FARM_TEST_PUB_DEVICE_H


#include <std_msgs/String.h>
#include <base_device.h>

class TestPubDevice : public BasePubDevice
{
    public:
    char* pub_name;
    std_msgs::String str_msg;
    ros::NodeHandle* nh;
    unsigned long publish_interval;  //ms
    unsigned long previous_millis;
    ros::Publisher test_pub;//("si7021_temp", &si7021_temp_msg);
    //TestPubDevice();
    TestPubDevice(
        ros::NodeHandle* nh_,
        char* pub_name_,
        char* message_text_,
        unsigned long publish_interval_
        );
    void topics_init();
    void publish_once();
    void nonblocking_publish_loop();
};

#endif