#include <AFMotor.h>
#include <Servo.h>
#define echoPin 26
#define trigPin 28

  Servo servo;
  AF_DCMotor motor1(1);
  AF_DCMotor motor2(2);
  AF_DCMotor motor3(3);
  AF_DCMotor motor4(4);
  long duration;
  int distance;
  void left90();
  void right90();
  void turn180();
  void shortrev();
  int ultrasonic();

void setup() {
  Serial.begin(9600);
  
  // motor setup
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);

  //servo setup
  servo.attach(22);
  servo.write(145);

  //ultrasonic setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {  
  motor1.run(FORWARD);
  motor2.run(FORWARD);  
  motor3.run(FORWARD);  
  motor4.run(FORWARD);
  distance = ultrasonic();
  //Serial.println(distance); 

  if (distance < 30){
      motor1.run(RELEASE);
      motor2.run(RELEASE);  
      motor3.run(RELEASE);  
      motor4.run(RELEASE);
      delay(1000); 
      for(int i=90;i<=190;i++){
        servo.write(i);
        delay(15);
        distance = ultrasonic();
          if (distance > 30 && i < 145){
            delay(1000);
            servo.write(145);
            delay(1000);
            right90();
            break;}
          else if(distance > 30 && i > 145){
            delay(1000);
            servo.write(145);
            delay(1000);
            left90();
            break;}
          else if(i >180){
            delay(1000);
            servo.write(145);
            shortrev();
            turn180();
            break;
          }
      }
  }
}

void left90() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  delay(520);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void right90() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
  delay(520);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void turn180() {
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
  delay(1000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void shortrev(){
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(1000);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

int ultrasonic(){
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration *0.034/2;
  return distance;
}
