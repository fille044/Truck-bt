int motor_fw = 11;
int motor_bw = 10;
int motor_mode = 9;


void setup() {
  // put your setup code here, to run once:
  pinMode(motor_fw, OUTPUT);
  pinMode(motor_bw, OUTPUT);
  pinMode(motor_mode, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
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
}
