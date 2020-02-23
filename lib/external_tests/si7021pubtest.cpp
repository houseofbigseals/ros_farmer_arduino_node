
#include <ros.h>
#include <std_msgs/Empty.h>
/*
#include <std_msgs/Int16MultiArray.h>

#include <test_pub_device.h>
#include <si7021_pub_device.h>

// global node definition
ros::NodeHandle nh;



char testnodename_1 [] = "test_pub";
char testnodemessage_1 [] = "this is a test pub device message";
char testnodename_2 [] = "test_pub_2";
char testnodemessage_2 [] = "this is a test pub device message 2";

char sihumname_1 [] = "si7021_1_temp_pub";
char sitempname_1 [] = "si7021_1_hum_pub";

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
);
SI7021PubDevice si = SI7021PubDevice(
    &nh,
    sitempname_1,
    sihumname_1,
    1000
);

void setup()
{
    nh.initNode();
}

void loop()
{
    //tpd.nonblocking_publish_loop();
    //tpd2.nonblocking_publish_loop();
    si.nonblocking_publish_loop();
    
    nh.spinOnce();
    delay(10);
}*/