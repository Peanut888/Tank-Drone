/*
 * Justin Lam
 * Mars Rover Program
 * Wireless Experiment 3 RX
 * 05/02/16
 */

#include <Servo.h>
#include <EasyTransfer.h>

EasyTransfer ET;

int servoPan = 5;
int servoTilt = 6;

struct RECIEVE_DATA_STRUCTURE{
  int degree1;
  int degree2;
};

RECIEVE_DATA_STRUCTURE txdata;

Servo servo1;
Servo servo2;

void setup(){
  servo1.attach(servoPan);
  servo2.attach(servoTilt);

  Serial.begin(9600);
  
  ET.begin(details(txdata), &Serial);
  
  servo1.write(90);
  servo2.write(90);
}

void loop(){
  if(ET.receiveData()){
    servo1.write(txdata.degree1);
    servo2.write(txdata.degree2);
  }
}

