#include <Servo.h>

Servo myservo;    // create servo object to control a servo

int inputPin =12;    //ECHO pin 
int outputPin=13;    //TRIG pin 
int servo=6;    //Controls power to servo
int motor_fw = 11;
int motor_bw = 10;
int motor_mode = 9;

void setup() {
  Serial.begin(9600); 
  pinMode(inputPin, INPUT); 
  pinMode(outputPin, OUTPUT); 
  pinMode(motor_fw, OUTPUT);
  pinMode(motor_bw, OUTPUT);
  pinMode(motor_mode, OUTPUT);
  myservo.attach(servo);   // attaches the servo on pin 9 to the servo object
}

int convert(int distance){
  distance=distance/58;
  Serial.print(distance);
  Serial.println("---");
  return distance;
}

void loop() {
  int val=0;
  digitalWrite(outputPin, LOW);    //Trigger ultrasonic detection 
  delayMicroseconds(10); 
  digitalWrite(outputPin, HIGH);    //Stop search for detection
  int distance = pulseIn(inputPin, HIGH);    //Read ultrasonic reflection
  distance= distance/58; //Calculate distance
  distance = convert(distance);
  digitalWrite(motor_mode,1);

  if(distance >=0 && distance <=3){    //Close distance
    digitalWrite(motor_bw,0);
    delay(500);
    myservo.write(0);
    delay(500);
    analogWrite(motor_fw, 200);
  }
  
  else{    //Far distance
    digitalWrite(motor_fw,0);
    delay(500);
    digitalWrite(motor_bw,1);
    myservo.write(120);
    delay(500);
  }

  delay(20); 
}
