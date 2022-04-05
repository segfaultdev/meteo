// ESP8266 -> pins 2(arduino's RX, esp's TX), 3(arduino's TX, esp's RX) and 4(CH_PD)
// DHT11 -> pin 3
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

#define SERVER_PORT "2121"
#define SSID "YourSSID"
#define PASSWORD "YourPassword"

void setup() {
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
