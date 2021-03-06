#include <IRremote.h>
 
int IR_Recv = 11;   //IR Receiver Pin 3
int bluePin = 10;
int greenPin = 9;
int yellowPin = 8;
 
IRrecv irrecv(IR_Recv);
decode_results results;
 
void setup(){
  Serial.begin(9600); 
  irrecv.enableIRIn();
  pinMode(bluePin, OUTPUT);     
  pinMode(greenPin, OUTPUT);     
  pinMode(yellowPin, OUTPUT);     

}
 
void loop(){
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(results.value);
    switch (results.value){
      case 551520375: 
        digitalWrite(bluePin, HIGH);
        break;   
      case 551495895: 
        digitalWrite(bluePin, LOW);   
        break;
       case 551504055: 
        digitalWrite(greenPin, HIGH);
        break;           
       case 551528535: 
        digitalWrite(greenPin, LOW);
        break;       
       case 551536695: 
        digitalWrite(yellowPin, HIGH);
        break;       
       case 551512215: 
        digitalWrite(yellowPin, LOW);
        break;
    }
    irrecv.resume(); 
  }
  delay(10);
}
