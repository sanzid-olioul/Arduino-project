int freq = 256;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(8,OUTPUT);
  pinMode(5,OUTPUT);
}
void loop() {
  int val = analogRead(A0);
  if(val<=100){
    digitalWrite(8,HIGH);
    for(int i=freq;i<=2560;i+=256){
      tone(5,i,200);
      delay(250);
    }
  }
  else{
     digitalWrite(8,LOW);
  }
  Serial.println(val);
  delay(500);
}
