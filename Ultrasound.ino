#include <NewPing.h>

#define BTN_START 10
#define TRIG_PIN 12
#define ECHO_PIN 11
#define MAX_TIME 10
#define MAX_DISTANCE 100

NewPing sensor(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(115200);
  pinMode(BTN_START, INPUT);
}

void loop() {
  //btn listener
  while(digitalRead(BTN_START)==LOW){
    delay(100);
  }
  while(digitalRead(BTN_START)==HIGH){
    delay(100);
  }
  
  for(short i=0;i!=MAX_TIME*10;i++){
    delay(100);
    unsigned int l = sensor.ping();
    Serial.print(sensor.convert_cm(l)); 
    Serial.println("cm");
  }
}
