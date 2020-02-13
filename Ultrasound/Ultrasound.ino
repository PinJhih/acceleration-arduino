#define LED_PIN 3
#define BTN_START 8
#define TRIG_PIN 12
#define ECHO_PIN 13
#define USONIC_DIV 58.0
#define MEASURE_SAMPLE_DELAY 10
#define MEASURE_SAMPLES 5

long time=0;
  
long singleMeasurement()
{
  long duration = 0;
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  return (((float) duration / USONIC_DIV) * 10.0);
}

long measure()
{
  long measureSum = 0;
  for (int i = 0; i < MEASURE_SAMPLES; i++)
  {
    delay(MEASURE_SAMPLE_DELAY);
    measureSum += singleMeasurement();
  }
  return measureSum / MEASURE_SAMPLES;
}

void setup() {
  Serial.begin(115200);
  pinMode(BTN_START, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIG_PIN, LOW);
}

void loop() {
  //btn listener
  while(digitalRead(BTN_START)==LOW)
    delay(100);
  while(digitalRead(BTN_START)==HIGH)
    delay(100);
  
  digitalWrite(LED_PIN, HIGH);
  time=0; 
  while(digitalRead(BTN_START)==LOW){
    long distance = measure();
    Serial.println("Time:" + time); 
    Serial.println("distance:" + distance); 
  }
  digitalWrite(LED_PIN, LOW);
  
  while(digitalRead(BTN_START)==HIGH)
    delay(100);
}
