#define INFRARED_PIN 9
#define LED_PIN 11
#define BTN_PIN 13
#define ECHO_PIN 2
#define TRIG_PIN 3
#define USONIC_DIV 58.0

long time = 0;
char space = 9;
  
long singleMeasurement()
{
  long duration = 0;
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  time+=10;
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  return (((float) duration / USONIC_DIV) * 10.0);
}

void setup() {
  Serial.begin(115200);
  pinMode(BTN_PIN, INPUT);
  pinMode(INFRARED_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIG_PIN, LOW);
}

void loop() {
  while(digitalRead(INFRARED_PIN)==LOW)
    delay(10);
  
  digitalWrite(LED_PIN, HIGH);
  time=0; 
  while(digitalRead(BTN_PIN)==LOW){
    long distance = singleMeasurement();
    Serial.print(time);
    Serial.print(space);
    Serial.println(distance);
    delay(10);
    time+=10;
  }
  digitalWrite(LED_PIN, LOW);
}
