

int motor_right[] = {6, 7};
int motor_left[] = {8, 9};
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

 // Setup motors
 int i;
 for(i = 0; i < 2; i++){
 pinMode(motor_left[i], OUTPUT);
 pinMode(motor_right[i], OUTPUT);
 }
}

void loop() {
  // put your main code here, to run repeatedly: 
  drive_forward();
  sense();
 delay(1000);
 motor_stop();
 Serial.println("1");

 drive_backward();sense();
delay(1000);
motor_stop();
Serial.println("2");

 turn_right();sense();
 delay(1050);
 motor_stop();
 Serial.println("3");
delay(1000);
 turn_left();sense();
 delay(1030);
 motor_stop();
 Serial.println("4"); 

 motor_stop();sense();
 delay(1050);
 motor_stop();
 Serial.println("5");
 delay(1000);
}

void motor_stop(){
 digitalWrite(motor_left[0], LOW); 
 digitalWrite(motor_left[1], LOW); 

 digitalWrite(motor_right[0], LOW); 
 digitalWrite(motor_right[1], LOW);
 delay(25);
}

void turn_right(){
 digitalWrite(motor_left[0], HIGH); 
 digitalWrite(motor_left[1], LOW); 

 digitalWrite(motor_right[0], HIGH); 
 digitalWrite(motor_right[1], LOW); 
}

void turn_left(){
 digitalWrite(motor_left[0], LOW); 
 digitalWrite(motor_left[1], HIGH); 

 digitalWrite(motor_right[0], LOW); 
 digitalWrite(motor_right[1], HIGH); 
}

void drive_backward(){
 digitalWrite(motor_left[0], LOW); 
 digitalWrite(motor_left[1], HIGH); 

 digitalWrite(motor_right[0], HIGH); 
 digitalWrite(motor_right[1], LOW);
}

void drive_forward(){
 digitalWrite(motor_left[0], HIGH); 
 digitalWrite(motor_left[1], LOW); 

 digitalWrite(motor_right[0], LOW); 
 digitalWrite(motor_right[1], HIGH); 
}

void sense()
{

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
Serial.print("      ");
Serial.print(valueright);
Serial.print("      ");
Serial.println(valueleft);
delay(10);


}
