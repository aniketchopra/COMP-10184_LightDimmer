//I, Aniket CHopra, student number 000814313, certify that this material 
//is my original work. No other person's work has been used without
// due acknowledgment and I have not made my work available to anyone else.


#include <Arduino.h>

int ledDim = 0;
int led=0;
byte buttonState = HIGH;
byte ledState = HIGH;


void setup() {
// put your setup code here, to run once:
// configure the USB serial monitor
Serial.begin(115200);

// configure pin D5 as digital input - this is the pushbutton
pinMode(D5, INPUT_PULLUP);

// configure pin D4 as a digital output - this is the LED
pinMode(D4, OUTPUT);

digitalWrite(D4,HIGH);

}

void loop() {

// put your main code here, to run repeatedly:

  byte iButton = digitalRead(D5);
  if (iButton != buttonState) {
   buttonState = iButton;

    //when the button is not pressed
    if (iButton == HIGH) {
      ledState = (ledState == LOW) ? HIGH: LOW;
      digitalWrite(D4, ledState);
    }

  }

  if(ledState==LOW){

    // Reading the analog Value
    ledDim = analogRead(A0);
    // Maping in the analog value
    led = map(ledDim, 0, 1023, 0, 255);

    //put the analog valueinto the led
    analogWrite(D4, led);


  }
  //Delay for 1 ms
  delay(1);
}