// Motor A connections
int enA = 12;
int in1 = 11;
int in2 = 10;
// Motor B connections
int enB = 2;
int in3 = 3;
int in4 = 4;
int a;
int laser = 9;
#include <Servo.h>
#include <Wire.h>
#include <NewPing.h>
//delcare the pins used for recieving an echo and trig calculations to find proximity
#define TRIG_PIN 6
#define ECHO_PIN 7
int c = 0;
NewPing sonar(TRIG_PIN, ECHO_PIN, 400); 
Servo blade;

void setup() {
  Serial.begin(9600);
	// Set all the motor control pins to outputs
	pinMode(enA, OUTPUT);
	pinMode(enB, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
  pinMode(laser, OUTPUT);
  digitalWrite(laser, LOW);	
	// Turn off motors - Initial state
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);
  analogWrite(enA, 255);
	analogWrite(enB, 255);
  blade.attach(13);
  blade.write(0);
  /*
  // Configure Accelerometer Sensitivity - Full Scale Range (default +/- 2g)
  Wire.beginTransmission(MPU);
  Wire.write(0x1C);                  //Talk to the ACCEL_CONFIG register (1C hex)
  Wire.write(0x10);                  //Set the register bits as 00010000 (+/- 8g full scale range)
  Wire.endTransmission(true);
  // Configure Gyro Sensitivity - Full Scale Range (default +/- 250deg/s)
  Wire.beginTransmission(MPU);
  Wire.write(0x1B);                   // Talk to the GYRO_CONFIG register (1B hex)
  Wire.write(0x10);                   // Set the register bits as 00010000 (1000deg/s full scale)
  Wire.endTransmission(true);
  delay(20);
  */
  delay(20);
}

void loop() {
  a= sonar.ping_cm();
    //if it is closer than 115cm(subject to change), then isfor is 0, meaning it goes backwards now
  if(a <= 10 && a != 0){
 //   isfor = 0;
    stop();
    digitalWrite(laser, HIGH);
    blade.write(90);
    delay(2000);
    blade.write(0);
  }
  else{
    forwards();
    digitalWrite(laser, LOW);
  }
	/*forwards();
	delay(1000);
  forwards();
	delay(1000);
  backwards();
	delay(1000);
  r();
	delay(1000);
  l();
	delay(1000);*/
  
}
void stop(){
  digitalWrite(in2, LOW);
	digitalWrite(in1, LOW);
	digitalWrite(in4, LOW);
	digitalWrite(in3, LOW);
}
void forwards(){
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}
void backwards(){
	digitalWrite(in2, HIGH);
	digitalWrite(in1, LOW);
	digitalWrite(in4, HIGH);
	digitalWrite(in3, LOW);
}
void r(){
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
	digitalWrite(in4, HIGH);
	digitalWrite(in3, LOW);
}
void l(){
  digitalWrite(in2, HIGH);
	digitalWrite(in1, LOW);
	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);
}