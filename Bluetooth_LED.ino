#include <SoftwareSerial.h>
SoftwareSerial bt(2,3); // RX TX It's Reversed...
const int ledCount = 10;
int leds[ledCount] = {4,5,6,7,8,9,10,11,12,13};

void allOff() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(leds[i], LOW);
  }
}

void waveEffect(int d) {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(leds[i], HIGH);
    delay(d);
    digitalWrite(leds[i], LOW);
  }
  for (int i = ledCount - 1; i >= 0; i--) {
    digitalWrite(leds[i], HIGH);
    delay(d);
    digitalWrite(leds[i], LOW);
  }
}

void knightRider(int d) {
  for (int i = 0; i < ledCount; i++) {
    allOff();
    digitalWrite(leds[i], HIGH);
    delay(d);
  }
  for (int i = ledCount - 1; i >= 0; i--) {
    allOff();
    digitalWrite(leds[i], HIGH);
    delay(d);
  }
}

void pulseEffect(int d) {
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < ledCount; i++) {
      digitalWrite(leds[i], HIGH);
    }
    delay(d);
    allOff();
    delay(d);
  }
}

void explosionEffect(int d) {
  int center1 = ledCount / 2 - 1;
  int center2 = ledCount / 2;

  for (int i = 0; i <= center1; i++) {
    digitalWrite(leds[center1 - i], HIGH);
    digitalWrite(leds[center2 + i], HIGH);
    delay(d);
  }

  delay(200);
  allOff();
}

void spiralFast(int d) {
  for (int round = 0; round < 3; round++) {
    for (int i = 0; i < ledCount; i++) {
      digitalWrite(leds[i], HIGH);
      delay(d);
    }
    for (int i = 0; i < ledCount; i++) {
      digitalWrite(leds[i], LOW);
      delay(d);
    }
  }
}

void setup() {
  Serial.begin(9600);
  bt.begin(9600);
  Serial.println("Bluetooth Ready");
  for (int i = 0; i < ledCount; i++) {
    pinMode(leds[i], OUTPUT);
  }
}


void loop() {
  if(bt.available()){
    char data = bt.read();
    Serial.println("Reacived  :");
    Serial.println(data);
    
    if(data == 'a'){
      waveEffect(60);
    }
    
    else if (data == 'b'){
     knightRider(40);
    }

    else if (data == 'c'){
     
     pulseEffect(150);
    }

    else if (data == 'd'){
     explosionEffect(80);
    }
    else if (data == 'e'){
      spiralFast(30);
    }
  }
}