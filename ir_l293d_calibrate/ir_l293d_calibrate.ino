



int motor_right[] = {6, 7};
int motor_left[] = {8, 9};
int valueleft,valueright,valuefront;
int emitterleft=4;
int emitterright=2;
int emitterfront=3;
int frontin=A2;
int rightin=A0;
int leftin=A1;
int turndelay=580;
int red=13;
int green=12;
int rightref,leftref,frontref,rightlow,leftlow,frontlow;

void setup() {
  // put your setup code here, to run once:
initialize();
calibrate();
}

void loop() {int test;
  
  delay(50);sense();
  test=rightblock(valueright);
  Serial.println(test);
}

int rightblock(int rightread){
if(rightread<=(rightref+0.25*rightref))
return 1;
else 
return 0;
}

int frontblock(int frontread){
if(frontread<=(frontref+0.25*frontref))
return 1;
else 
return 0;
}


int leftblock(int leftread){
if(leftread<=(leftref+0.25*leftref))
return 1;
else 
return 0;
}



void calibrate()
{//left calibration
  digitalWrite(red,HIGH);
digitalWrite(green,HIGH);
delay(3000);
digitalWrite(red,LOW);
digitalWrite(green,LOW);
digitalWrite(emitterleft,HIGH);
delay(350); 
 leftref=analogRead(leftin); 
 digitalWrite(emitterleft,LOW);
digitalWrite(red,HIGH);
delay(3000);
digitalWrite(red,LOW);
digitalWrite(emitterleft,HIGH);
delay(350); 
 leftlow=analogRead(leftin); 
 digitalWrite(emitterleft,LOW);
 digitalWrite(red,HIGH);
digitalWrite(green,HIGH);
delay(3000);
digitalWrite(red,LOW);
digitalWrite(green,LOW);

leftref=2*leftref;

//front calibration


digitalWrite(emitterfront,HIGH);
delay(350); 
 frontref=analogRead(frontin); 
 digitalWrite(emitterfront,LOW);
digitalWrite(red,HIGH);
delay(3000);
digitalWrite(red,LOW);
digitalWrite(emitterfront,HIGH);
delay(350); 
 frontlow=analogRead(frontin); 
 digitalWrite(emitterfront,LOW);
 digitalWrite(red,HIGH);
digitalWrite(green,HIGH);
delay(3000);
digitalWrite(red,LOW);
digitalWrite(green,LOW);

frontref=2*frontref;


//right calibration


digitalWrite(emitterright,HIGH);
delay(350); 
 rightref=analogRead(rightin); 
 digitalWrite(emitterright,LOW);
digitalWrite(red,HIGH);
delay(3000);
digitalWrite(red,LOW);
digitalWrite(emitterright,HIGH);
delay(350); 
 rightlow=analogRead(rightin); 
 digitalWrite(emitterright,LOW);
 digitalWrite(red,HIGH);
digitalWrite(green,HIGH);
delay(3000);
digitalWrite(red,LOW);
digitalWrite(green,LOW);

rightref=2*rightref;


Serial.print(leftref);Serial.print("      ");
  Serial.print(leftlow);Serial.print("      ");
  Serial.print(frontref);Serial.print("      ");
  Serial.print(frontlow);Serial.print("      ");
  Serial.print(rightref);Serial.print("      ");
  Serial.println(rightlow);
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

void initialize(){
  Serial.begin(9600);

pinMode(frontin,INPUT);
pinMode(rightin,INPUT);
pinMode(leftin,INPUT);
pinMode(emitterleft,OUTPUT);
pinMode(emitterright,OUTPUT);
pinMode(emitterfront,OUTPUT);
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
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
 delay(turndelay);
}

void turn_left(){
 digitalWrite(motor_left[0], LOW); 
 digitalWrite(motor_left[1], HIGH); 

 digitalWrite(motor_right[0], LOW); 
 digitalWrite(motor_right[1], HIGH); 
 delay(turndelay);
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

