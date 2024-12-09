#include <Arduino_FreeRTOS.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 20, 4);

#define LED_BLINK 12
#define BUTTON     2
#define LED_UV     3

void TaskBlink(void *pvParameters);
void TaskUv(void *pvParameters);
void Screen(void *pvParameters);

void setup() {
  lcd.init();lcd.init();
  lcd.backlight();
  pinMode(LED_BLINK, OUTPUT);
  pinMode(LED_UV, OUTPUT);
  pinMode(BUTTON, INPUT);

  xTaskCreate(TaskBlink, "Blink", 128, NULL, 1, NULL);
  xTaskCreate(TaskUv, "UV", 128, NULL, 2, NULL);
  xTaskCreate(Screen, "Show", 128, NULL, 1, NULL);
}

void loop() {
}

void TaskBlink(void *pvParameters) {
  (void) pvParameters;
  for (;;) {
    digitalWrite(LED_BLINK, HIGH);
    vTaskDelay(300 / portTICK_PERIOD_MS);
    digitalWrite(LED_BLINK, LOW);
    vTaskDelay(300 / portTICK_PERIOD_MS);
  }
}

void TaskUv(void *pvParameters) {
  (void) pvParameters;
  for (;;) {
    for (int i = 0; i < 256; i++) {
      analogWrite(LED_UV, i);
      vTaskDelay(10 / portTICK_PERIOD_MS);
    }
    for (int i = 255; i >= 0; i--) {
      analogWrite(LED_UV, i);
      vTaskDelay(10 / portTICK_PERIOD_MS);
    }
  }
}

void Screen(void *pvParameters) {
  (void) pvParameters;
  for (;;) {
    lcd.setCursor(0, 0);
    lcd.print("Hello, world!");
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}