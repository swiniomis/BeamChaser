/*

Beam Follower Class Robot (światłolub)
 __\/_          _           _    _  ______       _ 
/  ___|        (_)         | |  (_) | ___ \     (_)
\ `--.__      ___ _ __  ___| | ___  | |_/ /   _  _ 
 `--. \ \ /\ / / | '_ \/ __| |/ / | |    / | | || |
/\__/ /\ V  V /| | | | \__ \   <| | | |\ \ |_| || |
\____/  \_/\_/ |_|_| |_|___/_|\_\_| \_| \_\__, || |
                                           __/ |/ |
                                          |___/__/ 
Świniomiś Semniconductor 2013                           
*/

// Adafruit Shield Library
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

Adafruit_DCMotor *LeftMotor = AFMS.getMotor(1);
Adafruit_DCMotor *RightMotor = AFMS.getMotor(2);

int photoPinP1 = 0;  // right phototransistor pins
//int photoPinP2 = 1;
int photoPinL1 = 3;  // left phototransistor pin
//int photoPinL2 = 4;

int valP = 0;
int valL =0;
int diff =0;
int stab=0;

void setup()
{
  Serial.begin(9600);
  AFMS.begin();
  pinMode(photoPinP1, INPUT);
  pinMode(photoPinL1, INPUT); 
//  pinMode(photoPinP2, INPUT);
//  pinMode(photoPinL2, INPUT);

/*  LeftMotor->setSpeed(150);
  LeftMotor->run(FORWARD);
  LeftMotor->run(RELEASE);
  RightMotor->setSpeed(150);
  RightMotor->run(FORWARD);
  RightMotor->run(RELEASE);
  */
}

void loop()
{

  LeftMotor->run(FORWARD);
  RightMotor->run(FORWARD);
  valP = (analogRead(photoPinL1))/10;
  valL = (analogRead(photoPinP1))/10;
  diff=valL-valP;
//stab=diff;
//  if (diff<25); diff=25;
//  if (stab<10); diff=0;

  RightMotor->setSpeed(120+diff);
  LeftMotor->setSpeed(120-diff);  
  Serial.print(120+diff);
  Serial.print(" ");
  Serial.println(120-diff);
  delay(150);
}
