#include "Adafruit_Si7021.h"
#include "DHT.h"
#include <ros.h>
//#include <std_msgs/String.h>
#include <std_msgs/Float32.h>

/*class NewHardware : public ArduinoHardware
{
  public:
  NewHardware():ArduinoHardware(&Serial, 115200){};
};
ros::NodeHandle_<NewHardware>  nh;
*/
/*
#define DHTPIN 2 
#define DHTTYPE DHT11


ros::NodeHandle nh;
//std_msgs::String str_msg;
std_msgs::Float32 si7021_temp_msg;
std_msgs::Float32 si7021_hum_msg;
std_msgs::Float32 dht11_hum_msg;
std_msgs::Float32 dht11_temp_msg;

ros::Publisher si7021_temp("si7021_temp", &si7021_temp_msg);
ros::Publisher si7021_hum("si7021_hum", &si7021_hum_msg);
ros::Publisher dht11_hum("dht11_hum", &dht11_hum_msg);
ros::Publisher dht11_temp("dht11_temp", &dht11_temp_msg);

Adafruit_Si7021 sensor = Adafruit_Si7021();
DHT dht(DHTPIN, DHTTYPE);

unsigned long publish_interval = 1000;
unsigned long previous_millis = 0;

void nosetup() 
{
    nh.initNode();
    nh.advertise(si7021_temp);
    nh.advertise(si7021_hum);
    nh.advertise(dht11_hum);
    nh.advertise(dht11_temp);

    nh.loginfo("Si7021 test started");

    if (!sensor.begin()) {
    nh.logerror("Did not find Si7021 sensor!");
       /* while(true)
        {
            ; // do nothing because of fatal error
        }*/
/*    }

    dht.begin();

    /*
    nh.loginfo("Found model ");
    switch(sensor.getModel()) {
        case SI_Engineering_Samples:
        nh.loginfo("SI engineering samples"); break;
        case SI_7013:
        nh.loginfo("Si7013"); break;
        case SI_7020:
        nh.loginfo("Si7020"); break;
        case SI_7021:
        nh.loginfo("Si7021"); break;
        case SI_UNKNOWN:
        default:
        nh.loginfo("Unknown");
  }*/
  /*
  nh.loginfo(" Rev(");
  nh.loginfo(sensor.getRevision());
  nh.loginfo(")");
  nh.loginfo(" Serial #"); nh.loginfo(sensor.sernum_a, HEX); nh.loginfo(sensor.sernum_b, HEX);
  */
/*  
}

void noloop() 
{
    unsigned long current_millis = millis();
    if (current_millis - previous_millis >= publish_interval)
    {
        previous_millis = current_millis;
        si7021_hum_msg.data = sensor.readHumidity();
        si7021_temp_msg.data = sensor.readTemperature();

        si7021_temp.publish(&si7021_temp_msg);
        si7021_hum.publish(&si7021_hum_msg);


        dht11_hum_msg.data = dht.readHumidity();
        dht11_temp_msg.data = dht.readTemperature();

        dht11_hum.publish(&dht11_hum_msg);
        dht11_temp.publish(&dht11_temp_msg);

        nh.spinOnce();
    }
}
*/