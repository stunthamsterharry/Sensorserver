// connects a incoming TCP connection frome a Sensor Node to the Serial terminal via usb
// for esp8266-S01

#include <ESP8266WiFi.h>
#define SSID "SensorServer"
#define PASSWORD "notMyPassword"
#define PORT ((uint16_t)160169)
WiFiServer server(PORT);


void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  Serial.setRxBufferSize(4096);
  delay(1000);
  Serial.println("****************  WIFI SensorServer **************");
  WiFi.softAP(SSID, PASSWORD);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("connect to IP address: ");
  Serial.println(myIP);
  server.begin();
  Serial.println(" Wailting for connection");
}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available();
  if (client) {
    if (client.connected()) {
      Serial.println("Client Connected");
    }

    while (client.connected()) {
      if (client.available() ) {
        // read data from the connected client
        Serial.write(client.read());
      }
      //Send Data to connected client
      if (Serial.available() ) {
        client.write(Serial.read());
      }
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}
