int val=0;
int octave = 165;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    val = analogRead(A0);
    if(val<1000){
       for(int i=0;i<10;i++){
        tone(2,octave,250);
        octave+=250;
        delay(100);
      }
      for(int i=0;i<10;i++){
        tone(2,octave,250);
        octave-=250;
        delay(100);
      }
      octave = 165;
    }
    Serial.println(val);
}
