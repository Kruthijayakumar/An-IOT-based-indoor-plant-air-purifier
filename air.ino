//void setup() {
  // put your setup code here, to run once:

}

//void loop() {
  // put your main code here, to run repeatedly:

//}
#define BLYNK_TEMPLATE_ID "TMPL7LEHylkj"
#define BLYNK_DEVICE_NAME "sanj"
#define BLYNK_AUTH_TOKEN "hRuHLIprEI9fetNPZCxu4OSTqcp4JkCo"
#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

int sensor_input=;

char auth[]=BLYNK_AUTH_TOKEN;

char ssid[]="V2025";
char pass[]="sanjana25";

BlynkTimer timer;

void sendSensor()
{
  int analog_data=analogRead(sensor_input);
  Serial.println(analog_data);
  delay(300);
  Blynk.virtualWrite(V0,analog_data);
  delay(300);
}

void setup()
{

  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
  timer.setinterval(100l,sendSensor);
}

void loop()
{

  Blynk.run();
  timer.run();
}
