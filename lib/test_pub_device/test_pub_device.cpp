#include "test_pub_device.h"

TestPubDevice::TestPubDevice(
    ros::NodeHandle* nh_,
    char* pub_name_,
    char* message_text_,
    unsigned long publish_interval_
    )
    : pub_name{pub_name_}, str_msg(), test_pub(pub_name, &str_msg)
{
    this->nh = nh_;
    this->str_msg.data = message_text_;

    this->publish_interval = publish_interval_;
    this->previous_millis = millis();
}

void TestPubDevice::topics_init()
{
    this->nh->advertise(this->test_pub);
    this->nh->loginfo(this->pub_name);
}

void TestPubDevice::publish_once()
{
    this->nh->loginfo(this->pub_name);
    this->test_pub.publish(&(this->str_msg));
}

void TestPubDevice::nonblocking_publish_loop()
{
    unsigned long current_millis = millis();
    if (current_millis - this->previous_millis >= this->publish_interval)
    {
        this->nh->loginfo(this->pub_name);
        this->test_pub.publish(&(this->str_msg));
        this->nh->spinOnce(); // do we need this? check
        // update timer
        this->previous_millis = current_millis;
    }
}