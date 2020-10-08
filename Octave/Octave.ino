
int octave = 165;
void setup() {
  // put your setup code here, to run once:
  pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  for(int i=0;i<10;i++){
    tone(3,octave,250);
    octave+=250;
    delay(100);
  }
  for(int i=0;i<10;i++){
    tone(3,octave,250);
    octave-=250;
    delay(100);
  }
  octave = 165;
}
