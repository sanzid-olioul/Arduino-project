int up=0;
int loq=1025;
int val=0;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(8,OUTPUT);
  while(millis()<5000){
    val = analogRead(8);
    if(val>up){
      up = val;
    }
    if(val<loq){
      loq = val;
    }
  }
}
void loop() {
  val = analogRead(A0);
  int fade = 0;
  fade = map(val,0,255,up,loq);
  analogWrite(8,255-fade);
}
