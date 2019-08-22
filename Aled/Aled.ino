void setup() {
pinMode(13,OUTPUT);  //set digital pin 13 as OUTPUT pin
pinMode(8,OUTPUT);

}
void loop(){
// this loop runs continuously i.e, LED Blinks with a time period of 2 seconds

digitalWrite(13,HIGH); 
delay(100); 
tone(8, 5000, 200);
digitalWrite(13,LOW);
delay(100); 

digitalWrite(13,HIGH); 
delay(100); 
tone(8, 2000, 200);
digitalWrite(13,LOW);
delay(100); 

digitalWrite(13,HIGH); 
delay(100); 
tone(8, 200, 200);
digitalWrite(13,LOW);
delay(100); 

digitalWrite(13,HIGH); 
delay(100); 
tone(8, 1500, 200);
digitalWrite(13,LOW);
delay(100);
}
