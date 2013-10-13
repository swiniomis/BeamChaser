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


void setup()
{
  Serial.begin(9600);
  AFMS.begin();
  pinMode(photoPinP1, INPUT);
  pinMode(photoPinL1, INPUT); 
//  pinMode(photoPinP2, INPUT);
//  pinMode(photoPinL2, INPUT);


}

void loop()
{

  LeftMotor->run(FORWARD);
  RightMotor->run(FORWARD);
  valP = (analogRead(photoPinL1));
  valL = (analogRead(photoPinP1));
  diff=(valL-valP)/10;
 
if (diff < 40 && diff >1) diff=40;
//if (diff <=4 && diff >=-4) diff=0;
if (diff > -40 && diff <-1) diff=-40;


  RightMotor->setSpeed(150+diff);
  LeftMotor->setSpeed(150-diff);  
//  Serial.print(valP);
//  Serial.print(" ");
//  Serial.println(valL);
  delay(150);
}
