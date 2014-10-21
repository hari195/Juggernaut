int valuepin=11;
int IRemitter=3;
int value;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(IRemitter,OUTPUT);
digitalWrite(IRemitter,LOW);
pinMode(valuepin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  digitalWrite(IRemitter,HIGH);           // turning the IR LEDs off to read the IR coming from the ambient
delay(100);
value=digitalRead(valuepin);
Serial.println(value); 
digitalWrite(IRemitter,LOW);delay(50);}
