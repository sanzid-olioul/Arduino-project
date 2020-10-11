void setup() {
  // put your setup code here, to run once:
  pinMode(7,OUTPUT);
}

void loop() {

  for(int i=0;i<=255;i+=5){
    analogWrite(7,i);
    delay(30);
  }
   for(int i=255;i>=0;i-=5){
    analogWrite(7,i);
    delay(30);
  }
  // put your main code here, to run repeatedly:

}
