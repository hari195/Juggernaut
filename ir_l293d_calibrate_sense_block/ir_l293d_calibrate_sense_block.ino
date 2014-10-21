int motor_right[] = {6, 7};
int motor_left[] = {8, 9};
int emitterleft=4;
int emitterright=2;
int emitterfront=3;
int frontin=A2;
int rightin=A3;
int leftin=A1;
int turndelay=580;
int red=13;
int green=12;
int strip=0;
int q;

int r,l,f,key,rightlow,leftlow,frontlow,i,fvalues[5],rvalues[5],lvalues[5];
float rightref,leftref,frontref,valueleft,valueright,valuefront;
void setup() {
  // put your setup code here, to run once:
initialize();
emitteron();
calibrate();

}

void loop() {
 for(q=1;q>0;q++){
  
  digital();
  /*
if(l==0&&r!=0)
  {drive_forward();
     delay(300);
     motor_stop();
    if(l==0)
    { key=1;goto g;}
    else{strip++;continue;}
    
  }
  if(r==0&&l!=0)
 {drive_forward();
     delay(300);
     motor_stop();
   if(r==0) 
  {key=3;goto g;}
   
    else 
    {strip++;continue;}
  } */
  
if(l==0)//Case to move left
  {
    
      key=1;
     
     
  } 
  
else if(f==0)//Case to go straight
key=2;
else if(r==0)//Case to move left
  {
    
      key=3;
     
     
  } 
else//Case for u turn
key=4;
g:
Serial.println("gotoworked!!");

drive_forward();
delay(200);
motor_stop();
switch(key)
{case 1:
drive_forward();
delay(1800);
motor_stop();
delay(500);
if(strip%2==0)
{digitalWrite(red,HIGH);
delay(1500);
digitalWrite(red,LOW);}
else
{digitalWrite(green,HIGH);
delay(500);
digitalWrite(green,LOW);}
strip=0;

turn_left();
delay(turndelay);
motor_stop();
drive_forward();
delay(350);
motor_stop();
break;
case 2:
drive_forward();
delay(250);
motor_stop();
break;
case 3:
drive_forward();
delay(1800);
motor_stop();
delay(500);
if(strip%2==0)
{digitalWrite(red,HIGH);
delay(1500);
digitalWrite(red,LOW);}
else
{digitalWrite(green,HIGH);
delay(1500);
digitalWrite(green,LOW);}
strip=0;
turn_right();
delay(turndelay);
motor_stop();
drive_forward();
delay(350);
motor_stop();
break;
case 4:
turn_right();
delay(turndelay);

delay(100);
turn_right();
delay(turndelay);
delay(100);
break;
}
  
  
  
 } }





//Function to read vlaues from all recievers and store it
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


Serial.print(valueleft);
Serial.print("l      ");
Serial.print(valuefront);
Serial.print("f      ");
Serial.print(valueright);
Serial.println("r");
delay(10);


}



//Function to read the status of right sensor
int rightblock(int rightread){

if(rightread<=rightref)
{return 1;}
else 
{return 0;}
}



//Function to read the status of the front sensor
int frontblock(int frontread){
if(frontread<=frontref)
{return 1;}
else 
{return 0;}
}



//Function to read the status of the left sensor
int leftblock(int leftread){
if(leftread<=leftref)
{return 1;}
else 
{return 0;}
}


//Function to calibrate values of all sensors
void calibrate()
{
  
  //front calibration
digitalWrite(red,HIGH);
digitalWrite(green,HIGH);
delay(3000);
digitalWrite(red,LOW);
digitalWrite(green,LOW);


delay(350); 
sense();
frontref=valuefront;

digitalWrite(red,HIGH);
delay(3000);
digitalWrite(red,LOW);

delay(350); 
sense();
frontlow=valuefront;
 
turn_right();
delay(turndelay);
motor_stop();


  //left calibration
  digitalWrite(red,HIGH);
digitalWrite(green,HIGH);
delay(3000);
digitalWrite(red,LOW);
digitalWrite(green,LOW);

delay(350); 
sense();
leftref=valueleft;

digitalWrite(red,HIGH);
delay(3000);
digitalWrite(red,LOW);

delay(350); 
  sense();
leftlow=valueleft;

 digitalWrite(red,HIGH);
digitalWrite(green,HIGH);
delay(3000);
digitalWrite(red,LOW);
digitalWrite(green,LOW);






//right calibration



delay(350); 
sense();
rightref=valueright;
 
digitalWrite(red,HIGH);
delay(3000);
digitalWrite(red,LOW);

delay(350); 
 sense();
rightlow=valueright;


rightref*=1.2;
leftref*=1.2;
frontref*=1.2;
  
Serial.print(leftref);Serial.print("      ");
  Serial.print(leftlow);Serial.print("      ");
  Serial.print(frontref);Serial.print("      ");
  Serial.print(frontlow);Serial.print("      ");
  Serial.print(rightref);Serial.print("      ");
  Serial.println(rightlow);
}



//Function to switch all emitters on
void emitteron()
{
  digitalWrite(emitterfront,HIGH);
  digitalWrite(emitterright,HIGH);
  digitalWrite(emitterleft,HIGH);
}




//Function to set all pinModes
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




//Function to stop both the motors
void motor_stop(){
 digitalWrite(motor_left[0], LOW); 
 digitalWrite(motor_left[1], LOW); 

 digitalWrite(motor_right[0], LOW); 
 digitalWrite(motor_right[1], LOW);
 delay(25);
}



//Function to turn right
void turn_right(){
 digitalWrite(motor_left[0], HIGH); 
 digitalWrite(motor_left[1], LOW); 

 digitalWrite(motor_right[0], HIGH); 
 digitalWrite(motor_right[1], LOW); 
 
}

//Function to turn left

void turn_left(){
 digitalWrite(motor_left[0], LOW); 
 digitalWrite(motor_left[1], HIGH); 

 digitalWrite(motor_right[0], LOW); 
 digitalWrite(motor_right[1], HIGH); 

}


//Function to drive backwards
void drive_backward(){
 digitalWrite(motor_left[0], LOW); 
 digitalWrite(motor_left[1], HIGH); 

 digitalWrite(motor_right[0], HIGH); 
 digitalWrite(motor_right[1], LOW);
}



//Function to drive forward
void drive_forward(){
 digitalWrite(motor_left[0], HIGH); 
 digitalWrite(motor_left[1], LOW); 

 digitalWrite(motor_right[0], LOW); 
 digitalWrite(motor_right[1], HIGH); 
}

//Function to read digital values and store it
void digital(){sense();
  r=rightblock(valueright);
  l=leftblock(valueleft);
  f=frontblock(valuefront);
  Serial.print(l);Serial.print("    ");
  Serial.print(f);Serial.print("    ");
  Serial.print(r);Serial.println(" ");
}
