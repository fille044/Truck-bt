int inputPin =12; //ECHO pin
int outputPin=13; //TRIG pin

void setup()
{
  Serial.begin(9600);
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
}
 
void loop()
{ 
  digitalWrite(outputPin, LOW); //Trigger ultrasonic detection 
  delayMicroseconds(10);
  digitalWrite(outputPin, HIGH);
  int distance = pulseIn(inputPin, HIGH); //Read ultrasonic reflection
  distance= distance/58; //Calculate distance

  Serial.println(distance); //Print distance
  delay(20);
}

