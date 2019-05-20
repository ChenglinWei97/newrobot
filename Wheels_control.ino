// defines pins numbers
const int pwmR = 3 ; 
const int in_1R = 7 ;
const int in_2R = 8 ; //RIGHT MOTOR pins
const int pwmL = 5 ; 
const int in_1L = 12 ;
const int in_2L = 11 ; //LEFT MOTOR pins
const int TrigM = 9;
const int EchoM = 10; //Middle Sonic sensor
const int TrigL = 2;
const int EchoL = 4; //Left Sonic sensor
const int TrigR = 6;
const int EchoR = 13; //Right Sonic sensor
// defines variables
const int speed_normal = 100 ; //Default speed for normal motor movements
long duration_m;
long duration_l;
long duration_r;
long distance_m;
long distance_l;
long distance_r;
int speed_l;
int speed_r;
int inDigit=0;
void setup() {
pinMode(pwmR,OUTPUT) ;   //we have to set PWM pin as output
pinMode(in_1R,OUTPUT) ;  //Logic pins are also set as output
pinMode(in_2R,OUTPUT) ;
pinMode(pwmL,OUTPUT) ;   //we have to set PWM pin as output
pinMode(in_1L,OUTPUT) ;  //Logic pins are also set as output
pinMode(in_2L,OUTPUT) ;
pinMode(TrigM, OUTPUT); // Sets the trigPin as an Output
pinMode(EchoM, INPUT); // Sets the echoPin as an Input
pinMode(TrigL, OUTPUT);
pinMode(EchoL, INPUT); 
pinMode(TrigR, OUTPUT);
pinMode(EchoR, INPUT);
Serial.begin(9600); // Starts the serial communication
}
long ping_measure(int trig, int echo){
long duration;
long distance;
digitalWrite(trig, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echo, HIGH);
// Calculating the distance
distance= duration*0.034/2;
return distance;
}
void GoForward(int speed_L, int speed_R){
  //For Going Forward
digitalWrite(in_1R,HIGH) ;
digitalWrite(in_2R,LOW) ;
analogWrite(pwmR,speed_R) ;
digitalWrite(in_1L,HIGH) ;
digitalWrite(in_2L,LOW) ;
analogWrite(pwmL,speed_L) ;
}
void GoBackward(int speed_L, int speed_R){
  //For Going Forward
digitalWrite(in_1R,LOW) ;
digitalWrite(in_2R,HIGH) ;
analogWrite(pwmR,speed_R) ;
digitalWrite(in_1L,LOW) ;
digitalWrite(in_2L,HIGH) ;
analogWrite(pwmL,speed_L) ;
}
void brake(int time){
  digitalWrite(in_1L,HIGH) ;
  digitalWrite(in_2L,HIGH) ;
  digitalWrite(in_1R,HIGH) ;
  digitalWrite(in_2R,HIGH) ;
  delay(time) ;
}
void GoLeft(int speed_L, int speed_R){
  //For Turning LEFT
digitalWrite(in_1L,LOW) ;
digitalWrite(in_2L,HIGH) ;
analogWrite(pwmL,speed_L) ;
digitalWrite(in_1R,HIGH) ;
digitalWrite(in_2R,LOW) ;
analogWrite(pwmR,speed_R) ;
}
void GoRight(int speed_L, int speed_R){
  //For Turning LEFT
digitalWrite(in_1L,HIGH) ;
digitalWrite(in_2L,LOW) ;
analogWrite(pwmL,speed_L) ;
digitalWrite(in_1R,LOW) ;
digitalWrite(in_2R,HIGH) ;
analogWrite(pwmR,speed_R) ;
}
void TurnLeft(int speed_L, int speed_R, int time){
  //For Turning LEFT
digitalWrite(in_1L,LOW) ;
digitalWrite(in_2L,HIGH) ;
analogWrite(pwmL,speed_L) ;
digitalWrite(in_1R,LOW) ;
digitalWrite(in_2R,HIGH) ;
delay(200);
digitalWrite(in_1L,LOW) ;
digitalWrite(in_2L,HIGH) ;
analogWrite(pwmL,speed_L) ;
digitalWrite(in_1R,HIGH) ;
digitalWrite(in_2R,LOW) ;
analogWrite(pwmR,speed_R) ;
delay(time);
}

void loop() {
if (Serial.available() > 0){
    while(Serial.available() > 0){
      inDigit = Serial.read();
    }
}

if(inDigit==1){
  GoLeft(50,50);
  }
  else if(inDigit==2){
  GoForward(50,50);
  }
  else if(inDigit==3){
  GoRight(50,50);
  }
  else if(inDigit==4){
    GoBackward(50,50);
  }
  else{
    brake(1000);
  }


}
