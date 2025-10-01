// Write a program using two ultrasonic sensors and Arduino Uno to pause and play a video in youtube when the distance between the sensors is less than 10 cm. The video should be paused when the distance between the sensors is greater than 10 cm and should be played when the distance between the sensors is less than 10 cm. 

#include <Servo.h>
Servo myservo;
int trigPin1 = 2;
int echoPin1 = 3;
int trigPin2 = 4;
int echoPin2 = 5;
int ledPin = 13;
long duration1, duration2;
int distance1, distance2;
int pos = 0;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(ledPin, OUTPUT);
  myservo.attach(9);
  myservo.write(0);
}
void loop() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = duration1*0.034/2;
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = duration2*0.034/2;
  Serial.print("Distance1: ");
  Serial.print(distance1);
  Serial.print("cm");
  Serial.print(" Distance2: ");
  Serial.print(distance2);
  Serial.println("cm");
  if (distance1 < 10 && distance2 < 10) {
    digitalWrite(ledPin, HIGH);
    myservo.write(90);
    delay(1000);
    myservo.write(0);
    delay(1000);
  }
  else {
    digitalWrite(ledPin, LOW);
    myservo.write(0);
  }
}

