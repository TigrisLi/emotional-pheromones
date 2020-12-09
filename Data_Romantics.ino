#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>

PulseSensorPlayground pulseSensor;

int btnExcite = 2;
int btnHappy = 3;
int btnLove = 4;
int btnAngry = 5;
int btnDisappoint = 6;
int btnSad = 7;

int mtrExcite = 8;
int mtrHappy = 9;
int mtrLove = 10;
int mtrAngry = 11;
int mtrDisappoint = 12;
int mtrSad = 13;

int motorFan = A5;

int pulseSensor1 = A4;
int pulseSensor2 = A3;

int heart1;        // incoming raw data (signal value range 0-1024)
int heart2;
int threshold = 550;  // signal data to count as 'heart beat'


void setup() {
  
  Serial.begin(9600);
  
  pinMode(btnExcite, INPUT);
  pinMode(btnHappy, INPUT);
  pinMode(btnLove, INPUT);
  pinMode(btnAngry, INPUT);
  pinMode(btnDisappoint, INPUT);
  pinMode(btnSad, INPUT);
  
  pinMode(motorFan, OUTPUT);
    
  pinMode(mtrExcite, OUTPUT);
  pinMode(mtrHappy, OUTPUT);
  pinMode(mtrLove, OUTPUT);
  pinMode(mtrAngry, OUTPUT);
  pinMode(mtrDisappoint, OUTPUT);
  pinMode(mtrSad, OUTPUT);

  // PulseSensor
  pulseSensor.analogInput(pulseSensor1);
  pulseSensor.analogInput(pulseSensor2);
  pulseSensor.setThreshold(threshold);
  
}


void loop() {

  int myBPM = pulseSensor.getBeatsPerMinute();
  
  heart1 = analogRead(pulseSensor1);
  heart2 = analogRead(pulseSensor2);

  if (pulseSensor.sawStartOfBeat()) {
    Serial.println("Heartbeat BPM: ");
    Serial.print(myBPM);
  }
  
  if (digitalRead(motorFan) == HIGH && heart1 > threshold && heart2 > threshold) {
    digitalWrite(motorFan, LOW);
    Serial.println("Fan is OFF");
  }

  // Buttons for Emotion Diffuser
  if (digitalRead(btnSad) == LOW) {
    digitalWrite(mtrSad, HIGH);   // liquid dispenser is OFF
    digitalWrite(motorFan, HIGH);
  } else
  if (digitalRead(btnSad) == HIGH) {
    Serial.println("Sad button pressed");
    digitalWrite(motorFan, LOW);
    Serial.println("Fan is ON");
    digitalWrite(mtrSad, LOW);    // liquid dispenser is ON
    digitalWrite(mtrDisappoint, HIGH);
    digitalWrite(mtrAngry, HIGH);
    digitalWrite(mtrLove, HIGH);
    digitalWrite(mtrHappy, HIGH);
    digitalWrite(mtrExcite, HIGH);
    delay(2000);
    digitalWrite(mtrSad, HIGH);
    Serial.println("Sad liquid dispensed");

  }

  if (digitalRead(btnDisappoint) == LOW) {
    digitalWrite(mtrDisappoint, HIGH);
    digitalWrite(motorFan, HIGH);
  } else
  if (digitalRead(btnDisappoint) == HIGH) {
    Serial.println("Disappointment button pressed");
    digitalWrite(motorFan, LOW);
    Serial.println("Fan is ON");
    digitalWrite(mtrDisappoint, LOW);
    digitalWrite(mtrSad, HIGH);
    digitalWrite(mtrAngry, HIGH);
    digitalWrite(mtrLove, HIGH);
    digitalWrite(mtrHappy, HIGH);
    digitalWrite(mtrExcite, HIGH);
    delay(2000);
    digitalWrite(mtrDisappoint, HIGH);
    Serial.println("Disappointment liquid dispensed");
  }

  if (digitalRead(btnAngry) == LOW) {
    digitalWrite(mtrAngry, HIGH);
  } else
  if (digitalRead(btnAngry) == HIGH) {
    Serial.println("Angry button pressed");
    digitalWrite(motorFan, HIGH);
    Serial.println("Fan is ON");
    digitalWrite(mtrAngry, LOW);
    digitalWrite(mtrSad, HIGH);
    digitalWrite(mtrDisappoint, HIGH);
    digitalWrite(mtrLove, HIGH);
    digitalWrite(mtrHappy, HIGH);
    digitalWrite(mtrExcite, HIGH);
    delay(2000);
    digitalWrite(mtrAngry, HIGH);
    Serial.println("Angry liquid dispensed");
  }

  if (digitalRead(btnLove) == LOW) {
    digitalWrite(mtrLove, HIGH);
  } else
  if (digitalRead(btnLove) == HIGH) {
    Serial.println("Love button pressed");
    digitalWrite(mtrLove, LOW);
    digitalWrite(mtrSad, HIGH);
    digitalWrite(mtrDisappoint, HIGH);
    digitalWrite(mtrAngry, HIGH);
    digitalWrite(mtrHappy, HIGH);
    digitalWrite(mtrExcite, HIGH);
    delay(2000);
    digitalWrite(mtrLove, HIGH);
    Serial.println("Love liquid dispensed");
  }

  if (digitalRead(btnHappy) == LOW) {
    digitalWrite(mtrHappy, HIGH);
  } else
  if (digitalRead(btnHappy) == HIGH) {
    Serial.println("Happy button pressed");
    digitalWrite(mtrHappy, LOW);
    digitalWrite(mtrSad, HIGH);
    digitalWrite(mtrDisappoint, HIGH);
    digitalWrite(mtrAngry, HIGH);
    digitalWrite(mtrLove, HIGH);
    digitalWrite(mtrExcite, HIGH);
    delay(2000);
    digitalWrite(mtrHappy, HIGH);
    Serial.println("Happy liquid dispensed");
  }

  if (digitalRead(btnExcite) == LOW) {
    digitalWrite(mtrExcite, HIGH);
  } else
  if (digitalRead(btnExcite) == HIGH) {
    Serial.println("Excite button pressed");
    digitalWrite(mtrExcite, LOW);
    digitalWrite(mtrSad, HIGH);
    digitalWrite(mtrDisappoint, HIGH);
    digitalWrite(mtrAngry, HIGH);
    digitalWrite(mtrLove, HIGH);
    digitalWrite(mtrHappy, HIGH);
    delay(2000);
    digitalWrite(mtrExcite, HIGH);
    Serial.println("Excitement liquid dispensed");
  }
  delay(20);
  
}
