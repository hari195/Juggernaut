 // Use this code to test your motor with the Arduino board:

// if you need PWM, just use the PWM outputs on the Arduino
// and instead of digitalWrite, you should use the analogWrite command

// --------------------------------------------------------------------------- Motors
int motor_right[] = {6, 7};
int motor_left[] = {8, 9};

// --------------------------------------------------------------------------- Setup
void setup() {
 Serial.begin(9600);

 // Setup motors
 int i;
 for(i = 0; i < 2; i++){
 pinMode(motor_left[i], OUTPUT);
 pinMode(motor_right[i], OUTPUT);
 }

}

// --------------------------------------------------------------------------- Loop
void loop() { 

 drive_forward();
 delay(1000);
 motor_stop();
 Serial.println("1");

 drive_backward();
delay(1000);
motor_stop();
Serial.println("2");

 turn_right();
 delay(1050);
 motor_stop();
 Serial.println("3");
delay(1000);
 turn_left();
 delay(1030);
 motor_stop();
 Serial.println("4"); 

 motor_stop();
 delay(1050);
 motor_stop();
 Serial.println("5");
 delay(1000);
 
}

// --------------------------------------------------------------------------- Drive

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
