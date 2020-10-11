int val=0;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    val = analogRead(A0);
    Serial.println(val);
  }
}
