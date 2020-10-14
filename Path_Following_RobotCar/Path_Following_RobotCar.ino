#include<AFMotor.h>
#define left 50
#define right 51
AF_DCMotor motor1(1, MOTOR12_64KHZ); 
AF_DCMotor motor2(2, MOTOR12_64KHZ);
AF_DCMotor motor3(3, MOTOR34_64KHZ);
AF_DCMotor motor4(4, MOTOR34_64KHZ);
int Left=0;
int Right =0;

void setup() {
  //Serial.begin(9600);
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  digitalWrite(left,HIGH);
  digitalWrite(right,HIGH);
}

void loop() {
  Left = digitalRead(left);
  Right = digitalRead(right);
  if(!Left && !Right){
    goForward();
  }
  if(!Left && Right){
    goLeft();
  }
  if(Left && !Right){
    goRight();
  }
  if(Left && Right){
    Stop();
  }
}

void goForward(){
  int Mspeed=10;
  while(!Left && !Right){
    motor1.setSpeed(Mspeed);
    motor1.run(FORWARD);
    motor2.setSpeed(Mspeed);
    motor2.run(FORWARD);
    motor3.setSpeed(Mspeed);
    motor3.run(FORWARD);
    motor4.setSpeed(Mspeed);
    motor4.run(FORWARD);
    //delay(200);
    Mspeed+=5;
    if(Mspeed >255){
      Mspeed = 255;
    }
    Left = digitalRead(left);
    Right = digitalRead(right);
  }
}

void goLeft(){
  int Mspeed=50;
  while(!Left && Right){
    motor1.setSpeed(Mspeed);
    motor1.run(RELEASE);
    motor2.setSpeed(Mspeed);
    motor2.run(RELEASE);
    motor3.setSpeed(Mspeed);
    motor3.run(RELEASE);
    motor4.setSpeed(Mspeed);
    motor4.run(FORWARD);
    //delay(200);
    Mspeed+=5;
    if(Mspeed >255){
      Mspeed = 255;
    }
    Left = digitalRead(left);
    Right = digitalRead(right);
  }
}

void goRight(){
  int Mspeed=50;
  while(Left && !Right){
    motor1.setSpeed(Mspeed);
    motor1.run(RELEASE);
    motor2.setSpeed(Mspeed);
    motor2.run(RELEASE);
    motor3.setSpeed(Mspeed);
    motor3.run(FORWARD);
    motor4.setSpeed(Mspeed);
    motor4.run(RELEASE);
    //delay(200);
    Mspeed+=5;
    if(Mspeed >255){
      Mspeed = 255;
    }
    Left = digitalRead(left);
    Right = digitalRead(right);
  }
}
void Stop(){
  while(Left && Right){
    motor1.setSpeed(0);
    motor1.run(RELEASE);
    motor2.setSpeed(0);
    motor2.run(RELEASE);
    motor3.setSpeed(0);
    motor3.run(RELEASE);
    motor4.setSpeed(0);
    motor4.run(RELEASE);
   
    //delay(200);
    Left = digitalRead(left);
    Right = digitalRead(right);
  }
}
