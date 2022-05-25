/*
  SparkFun Inventor’s Kit
  Circuit 1B-Potentiometer

  Changes how fast an LED connected to pin 13 blinks, based on a potentiometer connected to pin A0

  This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
  This code is completely free for any use.

  View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v41
  Download code at: https://github.com/sparkfun/SIK-Guide-Code
*/

int potPositionr;       //this variable will hold a value based on the position of the potentiometer
int potPositionb;
int potPositiong;
int potPositiony;

void setup()
{
  Serial.begin(9600);       //start a serial connection with the computer

  pinMode(13, OUTPUT);      //set pin 13 as an output for red LED
  pinMode(12,OUTPUT);       //set pin 12 as an output for blue LED
  pinMode(11,OUTPUT);       //set pin 11 as an output for green LED
  pinMode(10, OUTPUT);      //set pin 10 as an output for yellow LED
}

void loop()
{
  //read the position of the pot
  //RED
  potPositionr = analogRead(A0);    //set potPosition to a number between 0 and 1023 based on how far the knob is turned
  potPositionb = 2*analogRead(A0);
  potPositiong = analogRead(A0)/2;
  potPositiony = analogRead(A0)*4;
  Serial.println(potPositionr);     //print the value of potPosition in the serial monitor on the computer

  //change the LED blink speed based on the pot value
  digitalWrite(13, HIGH);           // Turn on the LED
  
  delay(potPositionr);              // delay for as many milliseconds as potPosition (0-1023)

  digitalWrite(13, LOW);            // Turn off the LED
  delay(potPositionr);              // delay for as many milliseconds as potPosition (0-1023)

  digitalWrite (12, HIGH);
  delay(potPositionb);

  digitalWrite(12,LOW);
  delay(potPositionb);

  digitalWrite(11,HIGH);
  delay(potPositionb);

  digitalWrite (11, LOW);
  delay(potPositiong);
  
  digitalWrite (10, HIGH);
  delay(potPositiony);

  digitalWrite(10, LOW);
  delay(potPositiony);
 
}
