int valueleft,valueright,valuefront;
int emitterleft=4;
int emitterright=2;
int emitterfront=3;
int frontin=A2;
int rightin=A0;
int leftin=A1;



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(frontin,INPUT);
pinMode(rightin,INPUT);
pinMode(leftin,INPUT);
pinMode(emitterleft,OUTPUT);
pinMode(emitterright,OUTPUT);
pinMode(emitterfront,OUTPUT);

digitalWrite(emitterfront,HIGH);
digitalWrite(emitterright,HIGH);
digitalWrite(emitterleft,HIGH);

}


void loop() {
  // put your main code here, to run repeatedly: 
 
digitalWrite(emitterfront,HIGH);
digitalWrite(emitterright,HIGH);
digitalWrite(emitterleft,HIGH);
delay(50); 
 valuefront=analogRead(frontin);
valueright=analogRead(rightin);
valueleft=analogRead(leftin);
digitalWrite(emitterfront,LOW);
digitalWrite(emitterright,LOW);
digitalWrite(emitterleft,LOW);
Serial.print(valuefront);
Serial.print("f      ");
Serial.print(valueright);
Serial.print("r      ");
Serial.print(valueleft);
Serial.println("l");
delay(10);

}
