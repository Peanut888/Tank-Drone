/*
 * Justin Lam
 * Mars Rover Program
 * Wireless Esperiment 3 TX
 * 05/02/16
 */
#include <EasyTransfer.h>

EasyTransfer ET;

int joyX = A0; // Attach x-axis of joystick to Analog Pin 0.
int joyY = A1; // Attach y-axis of joystick to Analog Pin 1.

int val1 = 0;
int val2 = 0;
int read1 = 0;
int read2 = 0;

struct SEND_DATA_STRUCTURE{
  int degree1;
  int degree2;
};

SEND_DATA_STRUCTURE txdata;

void setup(){
  pinMode(joyX, INPUT); // Set x-axis of joystick as an input.
  pinMode(joyY, INPUT); // Set y-axis of joystick as an input.

  ET.begin(details(txdata), &Serial);

  Serial.begin(9600); // Initialise serial communication.
}

void loop(){
  // Pan
  read1 = analogRead(joyX); // Read the input from the x-axis of the joystick.
  val1 = map(read1, 0, 1032, 0, 180); // Scale the values
  txdata.degree1 = val1; // Send values over serial.
  delay(100); 

  // Tilt 
  read2 = analogRead(joyY); // Read the input from the y-axis of the joystick.
  val2 = map(read2, 0, 1032, 0, 180); // Scale the value
  txdata.degree2 = val2 ; // Send values over serial.
  delay(100);

  ET.sendData();
}




