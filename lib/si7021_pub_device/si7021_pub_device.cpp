
#include <si7021_pub_device.h>

SI7021PubDevice::SI7021PubDevice(
    //ros::NodeHandle* nh_,
    ros::NodeHandle_<ArduinoHardware, 5, 5, 1024, 1024>* nh_,
    char* temp_pub_name_,
    char* hum_pub_name_,
    unsigned long publish_interval_
    ) : temp_pub_name{temp_pub_name_}, hum_pub_name{hum_pub_name_}, temp_msg(), hum_msg(),  
    hum_pub(hum_pub_name, &hum_msg), temp_pub(temp_pub_name, &temp_msg)
{
    this->previous_millis = millis();
    this->nh = nh_;
    this->publish_interval = publish_interval_;
    this->init_error = false;

    //this->sensor.begin();
}

void SI7021PubDevice::topics_init()
{


        this->nh->advertise(this->hum_pub);
        this->nh->advertise(this->temp_pub);

        this->nh->loginfo(this->temp_pub_name);
        this->nh->loginfo(this->hum_pub_name);
    

    if (!this->sensor.begin()) 
    {
        this->init_error = true;
        this->nh->logerror("si7021 init err");
    }
}

void SI7021PubDevice::publish_once()
{

    //update msgs data
    float h = this->sensor.readHumidity();
    float t = this->sensor.readTemperature();
    if (h == NAN)
    {
        this->nh->logerror("si7021 read h err");
    }
    else
    {
        this->nh->loginfo(this->hum_pub_name);
        //this->hum_msg.data = h;
        this->hum_msg.temperature = h;
        this->hum_msg.header.stamp = this->nh->now();
        //this->hum_msg.header.stamp.nsec = this->nh->now().toNsec();
        this->hum_pub.publish(&(this->hum_msg));
    }
    if (t == NAN)
    {
        
        
        this->nh->logerror("si7021 read t err");
    }
    else
    {
        this->nh->loginfo(this->temp_pub_name);
        //this->temp_msg.data = t;
        this->temp_msg.temperature = t;
        this->temp_msg.header.stamp = this->nh->now();//.toSec();
        //this->temp_msg.header.stamp.nsec = this->nh->now().toNsec();
        this->temp_pub.publish(&(this->temp_msg));
    }
    // spin
    this->nh->spinOnce();
    
}

void SI7021PubDevice::nonblocking_publish_loop()
{
    unsigned long current_millis = millis();
    if (current_millis - this->previous_millis >= this->publish_interval)
    {
        this->publish_once();
        this->previous_millis = current_millis;
    }
}

