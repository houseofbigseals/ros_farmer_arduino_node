
#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Int16MultiArray.h>


ros::NodeHandle nh;

void messageCb(const std_msgs::Int16MultiArray &toggle_msg)
{
    if(toggle_msg.data[0] == 0)
    {digitalWrite(2, LOW);}
    else {digitalWrite(2, HIGH);}

    if(toggle_msg.data[1] == 0)
    {digitalWrite(3, LOW);}
    else {digitalWrite(3, HIGH);}

    if(toggle_msg.data[2] == 0)
    {digitalWrite(4, LOW);}
    else {digitalWrite(4, HIGH);}

    if(toggle_msg.data[3] == 0)
    {digitalWrite(5, LOW);}
    else {digitalWrite(5, HIGH);}

    if(toggle_msg.data[4] == 0)
    {digitalWrite(6, LOW);}
    else {digitalWrite(6, HIGH);}

    if(toggle_msg.data[5] == 0)
    {digitalWrite(7, LOW);}
    else {digitalWrite(7, HIGH);}

    if(toggle_msg.data[6] == 0)
    {digitalWrite(8, LOW);}
    else {digitalWrite(8, HIGH);}

    if(toggle_msg.data[7] == 0)
    {digitalWrite(9, LOW);}
    else {digitalWrite(9, HIGH);}
}

ros::Subscriber<std_msgs::Int16MultiArray> sub("eight_relay", &messageCb );

void setup()
{
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);

    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);

    nh.initNode();
    nh.subscribe(sub);
}

void loop()
{
    nh.spinOnce();
    delay(10);
}
