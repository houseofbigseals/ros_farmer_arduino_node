#include "relay_sub_device.h"

/*

RelayChannel::RelayChannel(
    uint8_t pin_,
    uint8_t channel_number_
) : pin(pin_), channel_number(channel_number_)
{
    // init this pin as output and set high as default value
    pinMode(this->pin, OUTPUT);
    digitalWrite(this->pin, HIGH);
}


void RelayChannel::setOn()
{
    digitalWrite(this->pin, LOW);
}

void RelayChannel::setOff()
{
    digitalWrite(this->pin, HIGH);
}

RelaySubDevice::RelaySubDevice(
    ros::NodeHandle* nh_,
    char* relay_sub_name_,
    uint8_t relay_arr_len_,
    uint8_t* pinout_
    ) : relay_sub_name(relay_sub_name_), relay_arr_len(relay_arr_len_),
    nh(nh_)
    //, sub(this->relay_sub_name, &(RelaySubDevice::messageCb))
{
    //create sub
    ros::Subscriber<std_msgs::Int16MultiArray> sub_(this->relay_sub_name, RelaySubDevice::messageCb);
    this->sub = &sub_;

    // reserve memory
    RelayChannel rarr[this->relay_arr_len]; //default constructor

    //refill array using uint8_t* pinout_ array
    for(uint8_t i = 0; i< this->relay_arr_len;i++ )
    {
        //set arduino pin from pinout_[i] on place number i
        // so this array holds value for first channel on first place, etc
        rarr[i] = RelayChannel(pinout_[i], i);
    }
    this->relay_arr = rarr;
}
void RelaySubDevice::messageCb(const std_msgs::Int16MultiArray &relay_msg)
{
    // lets parse msg this way:
    // in msg on first place - value for first channel
    // on second place - value for second channel
    // ...
    if(relay_msg.data_length != this->relay_arr_len)
    {
        this->nh->logerror("relay: incorrect size of msg");
    }
    else
    {
        for(uint8_t i = 0; i< this->relay_arr_len; i++ )
        {
            if(relay_msg.data[i] == 0)
            {this->relay_arr[i].setOn();}
            else
            {this->relay_arr[i].setOff();}
        }
    }
}

void RelaySubDevice::topics_init()
{
    this->nh->subscribe(*(this->sub));
}

*/