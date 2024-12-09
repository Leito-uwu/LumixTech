#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LED 13
#define BUTTON1 2 // STOP
#define BUTTON2 3 // START
#define BUTTON3 4 // ENTER
#define BUTTON4 5 // UP
#define BUTTON5 7 // DOWN

#define UV      6

typedef enum {
  ESTADO_INICIAL,      // Muestra el mensaje de inicio
  CONFIGURAR_TIEMPO,   // Configura el tiempo con UP/DOWN
  CONFIGURAR_INTENSIDAD, // Configura la intensidad con UP/DOWN
  LISTO_PARA_INICIAR,  // Espera que se presione START
  PROCESO_EN_CURSO,    // Cuenta regresiva
  PROCESO_DETENIDO     // Detenido por STOP
} Estado;


void init_elements();



#endif