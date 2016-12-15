int motor_fw = 11;
int motor_bw = 10;
int motor_mode = 9;


void setup() {
  // put your setup code here, to run once:
  pinMode(motor_fw, OUTPUT);    //Framåt
  pinMode(motor_bw, OUTPUT);    //Bakåt
  pinMode(motor_mode, OUTPUT);    //Sätter på/stänger av motor
  Serial.begin(9600);   //Startar monitorn
}

void loop() {
  int counter;

  digitalWrite(motor_mode,1);
  digitalWrite(motor_fw,1);
  delay(1000); 
  digitalWrite(motor_fw,0);
  delay(500);
  digitalWrite(motor_bw,1);
  delay(1000);
  digitalWrite(motor_bw,0);
  digitalWrite(motor_mode,0);
  delay(3000);
  
  /*
  for(int i = 30; i<255; i++){  //Motorn börjar rotera vid 30, max vid 255
    analogWrite(motor, i);    //Motorn snurrar med effekt i
    delay(50);    //Väntar 100ms för att bygga upp moment sakta

    counter = i/2.55;
    Serial.print("\nprocent = ");   //Skriver ut
    Serial.print(counter);    //Skriver ut värdet för i
  } 
  */
    

}
