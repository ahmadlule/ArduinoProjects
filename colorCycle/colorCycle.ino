//library of IR Connectivity code 
#include <IRremote.h> 
//gives each pin a name
int redPin= 7;
int greenPin = 6;
int bluePin = 5;

const int RECV_PIN = 4;
IRrecv irrecv(RECV_PIN);//??
decode_results results;

//It gives code a command
void setup() {
  //it sets up what pins is going to do
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  irrecv.enableIRIn();
  irrecv.blink13(true);

  Serial.begin(9600);
  
}
//it gives loop to the code u have writen
void loop() {
  //hexToRgb("FFFFFF");
  //setColor(0, 0, 0);
  decodeIR();
}
// ??
void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
//its function is to decode the IR button code
void decodeIR(){
    if (irrecv.decode(&results)){
        //Serial.println(results.value, HEX);
        irrecv.resume();
        Serial.println("Value is");
        Serial.println(results.value);
        Serial.println();
        if(results.value == 16724175){ //1 on the remote is pressed
          setColor(255,0,0);
          Serial.println("Red Light on");
        }
        if(results.value == 16718055){ //2 on the remote is pressed
          setColor(0,255,0);
          Serial.println("Green Light on");
        }
        if(results.value == 16726215){ //5 on the remote is pressed
          setColor(0,0,0);
          Serial.println("Light off");
        }
        if(results.value == 16743045){ //3 on the remote is pressed
          setColor(0,0,255);
          Serial.println("Blue Light on");
        }
        }
        if(results.value == 16730805){ //8 on the remote is pressed
          setColor(255,255,255);
          Serial.println("White Light on");
        }
  }


//used to change hex to RGB
void hexToRgb(char hex[]){
    Serial.print(hex);
    int bigint = atoi(hex);
    //Serial.print(bigint);
    int r = (bigint >> 16) & 255;
    int g = (bigint >> 8) & 255;
    int b = bigint & 255;

    setColor(r,g,b);

    Serial.print("\n");
    //return r + "," + g + "," + b;
}
