#include <NewPing.h>

#define LED 3
#define BTN_START 10
#define TRIG_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 300
#define CYCLE_TIME 50

NewPing sensor(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(115200);
  pinMode(BTN_START, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  //btn listener
  while(digitalRead(BTN_START)==LOW)
    delay(100);
  while(digitalRead(BTN_START)==HIGH)
    delay(100);
  
  while(digitalRead(BTN_START)==LOW){
    delay(CYCLE_TIME);
    digitalWrite(LED, HIGH);
    unsigned int l = sensor.ping();
    Serial.print(sensor.convert_cm(l)); 
    Serial.println("cm");
  }
  digitalWrite(LED, LOW);
  
  while(digitalRead(BTN_START)==HIGH)
    delay(100);
}
