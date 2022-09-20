#include <Servo.h>

const int lowestPin = 11; //Lowest pin for LED used
const int highestPin = 13; // Highest pin for LED used
const int rLed = 13;
const int yLed = 12;
const int gLed = 11;
const int trigPin = 10; // Pin used for trig on ultrasonic sensor
const int echoPin = 9; // Pin used for echo on ultrasonic sensor
long dur = 0;
int dist = 0;
Servo serv; //create servo object;
int pos = 0;

void setup() {
 for(int thisPin = lowestPin;thisPin <= highestPin;thisPin++)
 {
  pinMode(thisPin,OUTPUT);
 }
 //sets inital states of LEDs
  digitalWrite(rLed, HIGH);
  digitalWrite(yLed, LOW);
  digitalWrite(gLed, LOW);

  pinMode(trigPin, OUTPUT); // Sets the trig pin as an output
  pinMode(echoPin, INPUT); // Sets the echo pin as an input
  Serial.begin(9600);

  serv.attach(6); //assigns servo on pin 6 to servo object
  serv.write(0);
}
void loop() {
digitalWrite(trigPin, LOW); //Clears trigPin
delayMicroseconds(2);  
digitalWrite(trigPin, HIGH); //sets trigPin on HIGH for 10 microseconds
delayMicroseconds(10);
digitalWrite(trigPin, LOW); //Returns trigPin to low state

dur = pulseIn(echoPin, HIGH); //Reads echoPin, returns sound wave travel time in seconds
dist = dur * (0.034/2); //Calculates distance

if (dist <= 8)
{
  digitalWrite(rLed, LOW); // Turns red led off
  delay(500);
  digitalWrite(yLed, HIGH); // Turns Yellow led on
  delay(2000);
  serv.write(90); //lifts paper straw arm
  digitalWrite(yLed, LOW); // Turns yellow led off
  delay(500);
  digitalWrite(gLed, HIGH); // Turns green led on
  delay(10000);
  digitalWrite(gLed, LOW); // Turns green led off
  serv.write(0); //lowers paper straw arm
  delay(500);
  digitalWrite(rLed, HIGH); // Turns red led on
  
}
}
