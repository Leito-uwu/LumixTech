#include "functions.h"

byte arrow_char[8] = {
  0b11000,  
  0b11100,  
  0b11110,  
  0b11111,  
  0b11111,  
  0b11110,  
  0b11100,  
  0b11000  
};
uint8_t intensity=0;
uint8_t time_h=0;
uint8_t time_m=0;
uint8_t time_s=0;
int light=0;
unsigned int last_time=0;
int pos=0;
int level=0;
LiquidCrystal_I2C lcd(I2C_DIR, COLUMNS,ROWS);

void initializeComponents(){
  lcd.init();
  lcd.backlight();
  pinMode(BUTTON1 ,  INPUT); //stop
  pinMode(BUTTON2 ,  INPUT); //start
  pinMode(BUTTON3 ,  INPUT); //enter
  pinMode(BUTTON4 ,  INPUT); //up
  pinMode(BUTTON5 ,  INPUT); //down
  pinMode(LED     , OUTPUT);
  lcd.createChar(0, arrow_char);
}
void initState(){
  lcd.setCursor(0, 0);
  lcd.print("LumixTech    Box");
  lcd.setCursor(0, 1);
  lcd.print("Inicializando...");
  delay(WAIT1);
  lcd.clear();
}
void select(){
  level=0;
  while(1){
    if (up()==0){
      pos=0;
    }
    else if (down()==0){
      pos=1;
    }
    else if (start()==0){
      level=3;
      break;
    }
    lcd.setCursor(0,pos);
    lcd.write(byte(0));
    lcd.setCursor(2,0);
    lcd.print("Tiempo: ");
    lcd.setCursor(2,1);
    lcd.print("Intensidad: ");
    if (enter()==0){
      if(pos==0){
        level=1;
      }
      else if(pos==1){
        level=2;
      }
      break;
    }
    
    
    delay(100);
  }
}
void timeSet(){
  level=1;
  while(1){
    if (up()==0){
      if (time_s >= 59){
        time_s = 0;
        time_m ++;
      }
      else{
        time_s++;
      }
    }
    else if (down()==0){
      if (time_s <= 0){
        if (time_m > 0 ){
          time_s = 59;
          time_m --;
        }
      }
      else{
        time_s--;
      }
    }
    lcd.setCursor(5,0);
    lcd.print(time_m);
    lcd.setCursor(7,0);
    lcd.print(":");
    lcd.setCursor(9,0);
    lcd.print(time_s);
    if (enter()==0){
      level=0;
      break;
    }
  }
}
void intensitySet(){
  level=2;
  while(1){
    if (up()==0){
      if (intensity<100){
        intensity++;
      }
    }
    else if (down()==0){
      if (intensity>0){
        intensity--;
      }
    }
    light=map(intensity, 0, 100, 0, 255);
    lcd.setCursor(6,0);
    lcd.print(intensity);
    lcd.setCursor(10,0);
    lcd.print("%");
    if (enter()==0){
      level=0;
      break;
    }
  }
}
void counting(){
  level=3;
  analogWrite(UV, light);
  while(1){
    if (time_s <= 0){
        if (time_m > 0 ){
          time_s = 59;
          time_m --;
          if (time_m==0 && time_s==0){
          lcd.clear();
          analogWrite(UV,0);
          break;
    }
        }
      }
      else{
        time_s--;
        if (time_m==0 && time_s==0){
        lcd.clear();
        analogWrite(UV,0);
        break;
        }
      }
    lcd.clear();
    delay(50);
    lcd.setCursor(5,0);
    lcd.print(time_m);
    lcd.setCursor(7,0);
    lcd.print(":");
    lcd.setCursor(9,0);
    lcd.print(time_s);
    delay(950);
    
    if (stop()==0){
      level==4;
      break;
    }
  }
}

bool stop(){
  bool pulse=1;
  if (digitalRead(BUTTON1)==0){
    if((millis()-last_time) > DB ){
      pulse=0;
      last_time=millis();
      lcd.clear();
    }
  }
  return pulse;
}
bool start(){
  bool pulse=1;
  if (digitalRead(BUTTON2)==0){
    if((millis()-last_time) > DB ){
      pulse=0;
      last_time=millis();
      lcd.clear();
    }
  }
  return pulse;
}
bool up(){
  bool pulse=1;
  if (digitalRead(BUTTON4)==0){
    if((millis()-last_time) > DB ){
      pulse=0;
      last_time=millis();
      lcd.clear();
    }
  }
  return pulse;
}
bool down(){
  bool pulse=1;
  if (digitalRead(BUTTON5)==0){
    if((millis()-last_time) > DB ){
    pulse=0;
    last_time=millis();
    lcd.clear();
    }
  }
  return pulse;
}
bool enter(){
  bool pulse=1;
  if (digitalRead(BUTTON3)==0){
    if((millis()-last_time) > DB ){
    pulse=0;
    last_time=millis();
    lcd.clear();
    }
  }
  return pulse;
}