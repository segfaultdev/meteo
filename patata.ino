// ESP8266 -> pins 2(arduino's RX, esp's TX), 3(arduino's TX, esp's RX) and 4(CH_PD)
// DHT11 -> pin 5
// LCD1602 -> pins SDA and SCL
// LDR(?) -> pin A0

// ESP8266 lib: https://github.com/ekstrand/ESP8266wifi
// DHT11 lib: https://github.com/adidax/dht11

#include <SoftwareSerial.h>
#include <SerialESP8266wifi.h>

#define PIN_SOFT_RX 2
#define PIN_SOFT_TX 3
#define PIN_CH_PD   4
#define PIN_DHT     5
#define PIN_LDR     A0

#define SERVER_PORT "8000"
#define SSID "MURCIAEDUCA-DOC"
#define PASSWORD "eeccmurcia2017"

SoftwareSerial soft_serial(PIN_SOFT_RX, PIN_SOFT_TX);
SerialESP8266wifi wifi(soft_serial, soft_serial, PIN_CH_PD, Serial);

dht11 sensor;

void setup() {
  soft_serial.begin(9600);

  wifi.setTransportToTCP();
  wifi.endSendWithNewline(true);
  
  if (wifi.begin()) {
    wifi.connectToAP(SSID, PASSWORD);
    wifi.startLocalServer(SERVER_PORT);
  }
}

void loop() {
  static WifiConnection *connections;
  wifi.checkConnections(&connections);
  
  for (int i = 0; i < MAX_CONNECTIONS; i++) {
    if (connections[i].connected) {
      WifiMessage msg = wifi.getIncomingMessage();
      sensor.read(PIN_DHT);
      
      char data[256];
      sprintf(data, "%d %d %d", analogRead(A0), sensor.humidity, sensor.temperature);
      
      wifi.send(msg.channel, data);
    }
  }
}
