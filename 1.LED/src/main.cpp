#include <Arduino.h>
/*
  LED REVERSE
*/
void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);   //LED Pin Init
  Serial.begin(115200); //UART Init
  Serial.printf("\r\n************************	 BEGIN	************************");

}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(2, HIGH);                       // turn the LED on (HIGH is the voltage level)
    delay(100);                                  // wait for a second
    Serial.printf("hello");
    digitalWrite(2, LOW);                        // turn the LED off by making the voltage LOW
    delay(100);
}