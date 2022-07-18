#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
#include <IRremoteESP8266.h>
#include <IRsend.h>

#define BLYNK_PRINT Serial

const uint16_t kIrLed = 4;
char auth[] = "6tFnFw840I2JRcOBlqpiBFnQ3IFKDnwr";
char ssid[] = "Phylano";
char pass[] = "luwakwhitekop1";
float hif, hic;
byte t, h, f;
boolean AC = false;
int jeda = 1000;
int on_off, up_down;

BlynkTimer timer;
DHT dht (5, DHT22);
IRsend irsend(kIrLed);

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  dht.begin();
  irsend.begin();
  timer.setInterval(100L, main_code);
}

BLYNK_WRITE(V10){
  on_off = param.asInt();
}
BLYNK_WRITE(V1){
  up_down = param.asInt();
}

void loop(){
  Blynk.run();
  timer.run();
}
