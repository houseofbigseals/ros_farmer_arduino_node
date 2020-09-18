#include "bmp180_pub_device.h"

BMP180PubDevice::BMP180PubDevice(
    //ros::NodeHandle* nh_,
    ros::NodeHandle_<ArduinoHardware, 5, 5, 1024, 2048>* nh_,
    char* temp_pub_name_,
    char* pressure_pub_name_,
    unsigned long publish_interval_
    ) : temp_pub_name{temp_pub_name_}, pressure_pub_name{pressure_pub_name_}, temp_msg(), pressure_msg(),  
    pressure_pub(pressure_pub_name, &pressure_msg), temp_pub(temp_pub_name, &temp_msg)
{
    this->previous_millis = millis();
    this->nh = nh_;
    this->publish_interval = publish_interval_;
    this->init_error = false;
}

void BMP180PubDevice::topics_init()
{
    this->nh->advertise(this->pressure_pub);
    this->nh->advertise(this->temp_pub);

    this->nh->loginfo(this->temp_pub_name);
    this->nh->loginfo(this->pressure_pub_name);
    

    if (!this->bmp.begin())
    {
        this->init_error = true;
        this->nh->logerror("bmp180 init err");
    }
}

void BMP180PubDevice::publish_once()
{
    float p = this->bmp.readPressure();
    float t = this->bmp.readTemperature();
    if (p == NAN)
    {
        this->nh->logerror("bmp read p err");
    }
    else
    {
        this->nh->loginfo(this->pressure_pub_name);
        this->pressure_msg.temperature = p;
        this->pressure_msg.header.stamp = this->nh->now();
        this->pressure_pub.publish(&(this->pressure_msg));
    }
    if (t == NAN)
    {
        this->nh->logerror("bmp180 read t err");
    }
    else
    {
        this->nh->loginfo(this->temp_pub_name);
        this->temp_msg.temperature = t;
        this->temp_msg.header.stamp = this->nh->now();
        this->temp_pub.publish(&(this->temp_msg));
    }
    // spin
    this->nh->spinOnce();
}

void BMP180PubDevice::nonblocking_publish_loop()
{
    unsigned long current_millis = millis();
    if (current_millis - this->previous_millis >= this->publish_interval)
    {
        this->publish_once();
        this->previous_millis = current_millis;
    }
}