void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(2,INPUT);
}

void loop() {
  int sig = digitalRead(2);
  if(sig==1){
    digitalWrite(13,HIGH);
  }
  if(sig==0){
    digitalWrite(13,LOW);
  }
  Serial.println(sig);
}
