/*

#include "Adafruit_Si7021.h"
#include <ros.h>
#include <std_msgs/Float32.h>



ros::NodeHandle nh;
std_msgs::Float32 si7021_temp_msg;
std_msgs::Float32 si7021_hum_msg;


ros::Publisher si7021_temp("si7021_temp", &si7021_temp_msg);
ros::Publisher si7021_hum("si7021_hum", &si7021_hum_msg);

Adafruit_Si7021 sensor = Adafruit_Si7021();

unsigned long publish_interval = 1000;
unsigned long previous_millis = 0;

void setup() 
{
    nh.initNode();
    nh.advertise(si7021_temp);
    nh.advertise(si7021_hum);

    nh.loginfo("Si7021 test started");

    if (!sensor.begin()) {
    nh.logerror("Did not find Si7021 sensor!");
 }

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
  }
}

void loop() 
{
    unsigned long current_millis = millis();
    if (current_millis - previous_millis >= publish_interval)
    {
        previous_millis = current_millis;
        si7021_hum_msg.data = sensor.readHumidity();
        si7021_temp_msg.data = sensor.readTemperature();

        si7021_temp.publish(&si7021_temp_msg);
        si7021_hum.publish(&si7021_hum_msg);

        nh.spinOnce();
    }
}
*/