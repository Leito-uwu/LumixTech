#include <Arduino_FreeRTOS.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 20, 4);

#define LED_BLINK 12
#define BUTTON     2
#define LED_UV     3

TaskHandle_t BlinkHandle = NULL;
TaskHandle_t UvHandle = NULL;
TaskHandle_t ScreenHandle = NULL;

void TaskBlink(void *pvParameters);
void TaskUv(void *pvParameters);
void Screen(void *pvParameters);
void WaitForButton(void *pvParameters);

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(LED_BLINK, OUTPUT);
  pinMode(LED_UV, OUTPUT);
  pinMode(BUTTON, INPUT);

  xTaskCreate(WaitForButton, "WaitButton", 128, NULL, 4, NULL);
  xTaskCreate(TaskBlink, "Blink", 128, NULL, 1, &BlinkHandle);
  vTaskSuspend(BlinkHandle);
  xTaskCreate(TaskUv, "UV", 128, NULL, 2, &UvHandle);
  vTaskSuspend(UvHandle);
  xTaskCreate(Screen, "Show", 128, NULL, 1, &ScreenHandle);
  vTaskSuspend(ScreenHandle);
}

void loop() {
}

void WaitForButton(void *pvParameters) {
  (void)pvParameters;
  lcd.setCursor(0, 0);
  lcd.print("Presione boton");
  
  for (;;) {
    if (digitalRead(BUTTON) == HIGH) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Iniciando tareas");
      vTaskResume(BlinkHandle);
      vTaskResume(UvHandle);
      vTaskResume(ScreenHandle);
      vTaskDelete(NULL);
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
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