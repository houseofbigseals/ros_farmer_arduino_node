
#include <ros.h>
//#include <std_msgs/Empty.h>

//#include <std_msgs/Int16MultiArray.h>

#include <test_pub_device.h>
#include <si7021_pub_device.h>
#include <bmp180_pub_device.h>
//#include <relay_sub_device.h>
#include <std_msgs/Int16MultiArray.h>

// global node definition
//ros::NodeHandle nh;
ros::NodeHandle_<ArduinoHardware, 5, 5, 1024, 2048> nh;

/*
char testnodename_1 [] = "test_pub";
char testnodemessage_1 [] = "this is a test pub device message";
char testnodename_2 [] = "test_pub_2";
char testnodemessage_2 [] = "this is a test pub device message 2";
*/
char sihumname_1 [] = "si7021_1_hum_pub";
char sitempname_1 [] = "si7021_1_temp_pub";

char bmppressurename_1 [] = "bmp180_1_pressure_pub";
char bmptempname_1 [] = "bmp180_1_temp_pub";
/*
TestPubDevice tpd = TestPubDevice(
    &nh,
    testnodename_1,
    testnodemessage_1,
    1000
);
TestPubDevice tpd2 = TestPubDevice(
    &nh,
    testnodename_2,
    testnodemessage_2,
    2500
);*/
SI7021PubDevice si = SI7021PubDevice(
    &nh,
    sitempname_1,
    sihumname_1,
    1000
);

BMP180PubDevice bmp = BMP180PubDevice(
    &nh,
    bmptempname_1,
    bmppressurename_1,
    1000
);

//char relay_1_sub [] = "relay_1_sub";
//uint8_t pinout[] = {6, 7};

//RelaySubDevice* rel;

// monkey code to global static callback
// sorry
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


void setup()
{
    nh.initNode();


    /*
    RelaySubDevice rel_ = RelaySubDevice(
    &nh,
    relay_1_sub,
    2,
    pinout
    );

    rel_.topics_init();

    //rel = &rel_;  
    */

    // monkey code to init subscriber 
    // sorry

    // init relay pins
    //sorry
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

    ros::Subscriber<std_msgs::Int16MultiArray> relay_sub("relay_1_sub", &messageCb );

    nh.subscribe(relay_sub);

    nh.requestSyncTime(); //?
    si.topics_init();
    bmp.topics_init();
    //tpd.topics_init();
    //tpd2.topics_init();
}

void loop()
{
    //tpd.nonblocking_publish_loop();
    //tpd2.nonblocking_publish_loop();
    si.nonblocking_publish_loop();
    bmp.nonblocking_publish_loop();

    nh.requestSyncTime();
    nh.spinOnce();
    delay(10);
}