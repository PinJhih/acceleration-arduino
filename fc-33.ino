#define LED_PIN 13
#define INFRARED_PIN 9
#define SIGNAL_PIN 7
#define BTN_START 11
#define CYCLE_TIME 1

int count = 0;
bool status = false;
bool read =false;
char space = 9;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(INFRARED_PIN, INPUT);
  pinMode(BTN_START, INPUT);
  pinMode(SIGNAL_PIN, INPUT);
}

void loop() {
  while(digitalRead(BTN_START)==LOW)
    delay(10);
  while(digitalRead(BTN_START)==HIGH)
    delay(10);
    
  int time=0; 
  count=0;
  
  digitalWrite(LED_PIN, HIGH);
  while(digitalRead(INFRARED_PIN)==LOW){
    read = digitalRead(SIGNAL_PIN);
    if(read!=status)
      if(read==HIGH){
        Serial.print(count);
        Serial.print(space);
        Serial.println(time);
        Serial.println();
        count++;
      }
    status = read;
    delay(CYCLE_TIME);
    time+=CYCLE_TIME;
  }
  digitalWrite(LED_PIN, LOW);
}
