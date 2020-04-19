// ※押している間、Unity側では常にInput.GetKeyDown/GetKeyUpが trueになります。
// 処理には、1フレーム分バッファして工夫するなどが必要です。 
#include "DigiKeyboard.h"

// ボタンを押した瞬間のみ処理したい場合はコチラ
#define INPUT_DOWN_ONLY

const int LED_PIN = 0;
const int LED_PIN2 = 1;
const int BTN_PIN = 2;

void setup() {
    // don't need to set anything up to use DigiKeyboard
    pinMode(LED_PIN, OUTPUT);
    pinMode(LED_PIN2, OUTPUT);
    pinMode(BTN_PIN, INPUT);
    DigiKeyboard.sendKeyStroke(0);
}
#ifdef INPUT_DOWN_ONLY
int previewVal = HIGH;
#endif

void loop() {
    int val = 0;

    val = digitalRead(BTN_PIN);
    if (val != HIGH) {
#ifdef  INPUT_DOWN_ONLY
        if (previewVal != val) {
            DigiKeyboard.sendKeyStroke(KEY_ENTER);
        }
#else
        DigiKeyboard.sendKeyStroke(KEY_ENTER);
#endif
        digitalWrite(LED_PIN, HIGH);
        digitalWrite(LED_PIN2, HIGH);
    }
    else {
        digitalWrite(LED_PIN, LOW);
        digitalWrite(LED_PIN2, LOW);
        DigiKeyboard.delay(8);
    }
#ifdef INPUT_DOWN_ONLY
    previewVal = val;
#endif
    DigiKeyboard.delay(2);
}
