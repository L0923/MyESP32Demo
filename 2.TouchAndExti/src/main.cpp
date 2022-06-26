#include <Arduino.h>
/*
  ESP32
  电容Touch简单使用
  外部中断简单使用
  外部中断Mode：
  0：无中断，读取Touch的值
  1：Touch中断 执行TouchEvent()
  2：外部IO口中断,下降沿触发
*/

#define EXT_ISR_MODE 1

void TouchEvent(){
  Serial.printf(" Touch Event.\r\n ");
}
void PinIntEvent(){
  Serial.printf(" PinIntE vent.\r\n ");
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); //UART Init

#if 1 == EXT_ISR_MODE
    touchAttachInterrupt(T0, TouchEvent, 40); //Touch超过40，运行该函数TouchEvent
#elif 2 == EXT_ISR_MODE
    pinMode(4, INPUT_PULLUP);   
    attachInterrupt(4, PinIntEvent, FALLING); //下降沿触发，触发一次输出 PinIntEvent 的数据
#endif
}

void loop() {
  // put your main code here, to run repeatedly:
#if 0 == EXT_ISR_MODE
    Serial.printf("Touch:%d\r\n",touchRead(T0));  //读取Touch的值
#endif
    delay(200);
}