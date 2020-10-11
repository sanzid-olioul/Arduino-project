void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(8,OUTPUT);
}
void loop() {
  int val = analogRead(A0);
  if(val<=100){
    digitalWrite(8,HIGH);
  }
  else{
     digitalWrite(8,LOW);
  }
  Serial.println(val);
  delay(500);
}
