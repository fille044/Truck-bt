#include <Servo.h>

Servo myservo;  // Skapar objektet Servo för att styra servon

void setup() {
  myservo.attach(6);  // Kopplar servon till kontakt 9 på Arduino
}

void loop() {
  for(int i=0;i<70;i++){    //Höjer gafflar med 1 grad per 40ms, till 70 grader. 
    myservo.write(i);
    delay(40); 
  }
  for(int i=70;i>0;i--){    //Sänker gafflar med 1 grad per 40ms, till 0 grader.  
    myservo.write(i);
    delay(40); 
  }
}
