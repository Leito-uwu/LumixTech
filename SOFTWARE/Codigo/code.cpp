#include "functions.h"

LiquidCrystal_I2C lcd(0x27, 16,2);

void init_elements(){
  lcd.init();
  lcd.init();
  lcd.backlight();
  pinMode(LED, OUTPUT);
  pinMode(BUTTON1, INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3, INPUT);
  pinMode(BUTTON4, INPUT);
  pinMode(BUTTON5, INPUT);

  
}/*
  //Messagea
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.print("LUMIXTECH  BOX");
  lcd.setCursor(0, 1);
  lcd.print("INICIALIZANDO...");*/