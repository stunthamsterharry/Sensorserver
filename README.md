# Sensorserver
 ESP8266 Wifi-AP  TCP to Serial forwarder
 by StunthamsterHarry

Situation: Sensor Data from an unattached accelerometer-devide (NodeMCU+ AXDL345)
needed to be transferred to desktop PC, lokal WLAM is unreliable. 
So I decided to use an intermediate EPS8266_S01, that offers a WIFI-AP 
and is inserted into the Desktops USB Port. 

This repository Holds the code for this Intermediate EPS8266_S01 (can also be any compatoble NodeMCU)

It creates a WIFI-AP with SSID "SensorServer". A Sensor device then automatically 
acesses this WiFi, opens a TCP-connection to Port 160169 and sends its Data.
The Sensorserver simply forwards all traffic to Serial and vice versa, so the
Arduino IDE can communicate with the device, Data Graphs can be shown in the SerialPlotter and
commands can be sent to the SensorDevice.
(see d1mini_accelerometer for my 1st application)

Important: Plug in the SensorServer device before swithing on the Sensor. 
 
