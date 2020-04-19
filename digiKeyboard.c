// �������Ă���ԁAUnity���ł͏��Input.GetKeyDown/GetKeyUp�� true�ɂȂ�܂��B
// �����ɂ́A1�t���[�����o�b�t�@���čH�v����Ȃǂ��K�v�ł��B 

#include "DigiKeyboard.h"
const int LED_PIN = 0;
const int LED_PIN2 = 1;
const int BTN_PIN = 2;

void setup() {
  // don't need to set anything up to use DigiKeyboard
  pinMode(LED_PIN,OUTPUT);  
  pinMode(LED_PIN2,OUTPUT);  
  pinMode(BTN_PIN,INPUT);
  DigiKeyboard.sendKeyStroke(0);  
}

void loop() {
  int val = 0;

  val = digitalRead( BTN_PIN);
  if( val != HIGH  ){
      DigiKeyboard.sendKeyStroke(KEY_ENTER);
      digitalWrite(LED_PIN , HIGH);
      digitalWrite(LED_PIN2 , HIGH);
  }else{
      digitalWrite(LED_PIN , LOW);
      digitalWrite(LED_PIN2 , LOW);
      DigiKeyboard.delay(8);
  }
  DigiKeyboard.delay(2);
}