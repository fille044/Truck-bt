#include <Servo.h>

Servo myservo;    // create servo object to control a servo

int inputPin =12;    //ECHO pin 
int outputPin=13;    //TRIG pin 
int motor=3;    //Controls the base of transistor to motor
int servo=9;    //Controls power to servo

void setup() {
  Serial.begin(9600); 
  pinMode(inputPin, INPUT); 
  pinMode(outputPin, OUTPUT); 
  pinMode(motor, OUTPUT);
  myservo.attach(servo);   // attaches the servo on pin 9 to the servo object
}

void loop() {
  
  int val=0;
  int i;
  digitalWrite(outputPin, HIGH);    //Trigger ultrasonic detection 
  delayMicroseconds(10); 
  digitalWrite(outputPin, LOW);    //Stop search for detection
  int distance = pulseIn(inputPin, HIGH);    //Read ultrasonic reflection
  distance= distance/58; //Calculate distance
  
  if(distance >=0 && distance <=3){    //Close distance
    digitalWrite(motor,0);
    //for(i=0;i<70;i++){
      myservo.write(100); // sets the servo position according to the scaled value
      delay(200); // waits for it to get to the position
      //myservo.detach();
      //delay(1000);  
    //}
  }

  else{    //Far distance
    digitalWrite(motor,1);
    //for(int i=70;i>0;i--){
      myservo.write(0); // sets the servo position according to the scaled value
      delay(200); // waits for it to get to the position
      //myservo.detach();
      //delay(1000);  
    //}
  }

  Serial.print(distance); //Print distance 
  Serial.print("---");
  Serial.println(i);
  delay(20 ); 
  
}
