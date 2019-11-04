#include <Servo.h> 

#define LINEAR100PIN 9        //Linear Actuator Digital Pin

#define input 10           //Input pin
#define input2 11           // I



//max/min pulse values in microseconds for the linear actuators
#define LINEAR100_MIN      1000  
#define LINEAR100_MAX      2000 



Servo LINEAR100;

int linear100Value = 10;   //current positional value being sent to the linear actuator. (Assuming actuator is 10mm extended initially. Adjust accordingly. 

int button = 0;
int buttonstate1=0;
int buttonstate2=0;
void setup() 
{ Serial.begin(9600);
  pinMode(input,INPUT);
  pinMode(input2,INPUT);
  //initialize servos
  LINEAR100.attach(LINEAR100PIN, LINEAR100_MIN, LINEAR100_MAX);      // attaches/activates the linear actuator as a servo object 

 
  LINEAR100.writeMicroseconds(linear100Value); 
} 

void loop() 
{ // pinMode(input,LOW);
  buttonstate1=digitalRead(input);
   if(buttonstate1==HIGH)
   {
   Serial.print(button);
  Serial.print('\n');
  while(button!=100)
  {  
     //Serial.print(input);
   button++; //max extraction in mm
  
  linear100Value = map(button, 0, 100, LINEAR100_MIN, LINEAR100_MAX); 
  LINEAR100.writeMicroseconds(linear100Value); 

  }
   }
  //use the writeMicroseconds to set the servos to their new positions
 // pinMode(input2,HIGH);
 buttonstate2=digitalRead(input2);
  if(buttonstate2==HIGH){
 
  while(button!=0) {
     button--;

     
  linear100Value = map(button, 0, 100, LINEAR100_MIN, LINEAR100_MAX); 
   Serial.print(button);
  Serial.print('\n');
 
  LINEAR100.writeMicroseconds(linear100Value); 
  
  }
   }
    
     

} 
