# Documento Técnico - Máquina de Insolado

## Introducción
Este documento contiene información técnica y específica relacionada con la máquina de insolado, un dispositivo diseñado para procesos de exposición controlada a luz ultravioleta (UV) u otras fuentes lumínicas. Este equipo es esencial para aplicaciones industriales como la fabricación de circuitos impresos (PCB), el curado de resinas o la impresión serigráfica.

## Hardware

### **Componentes Principales**

#### **1. Controlador Principal**
- **Microcontrolador Atmega:** El cerebro del sistema.
- **Cristal Oscilador:** Para garantizar el correcto funcionamiento del Atmega (por ejemplo, 16 MHz con sus condensadores asociados de 22 pF).
- **Resistencias de Pull-up:** Para el botón de reset del Atmega (10 kΩ típicamente).

#### **2. Accionadores**
- **LEDs UV:** Fuente de luz para el insolado. Estos estarán organizados en matriz o arreglos.
- **Resistencias Limitadoras:** Calculadas según las especificaciones de los LEDs UV (generalmente entre 220 Ω y 1 kΩ).
- **Transistor o MOSFET:** Para controlar la corriente hacia los LEDs UV desde el microcontrolador (como un IRF540N para aplicaciones de mayor corriente).

#### **3. Pantalla LCD**
- **Pantalla LCD (por ejemplo, 16x2):** Interfaz de usuario para mostrar información como tiempo de exposición.
- **Resistor para Contraste:** Conectado al pin de contraste (generalmente de 10 kΩ, o un potenciómetro ajustable).

#### **4. Botones de Control**
- **Botones Pulsadores:** Usados para:
  - Iniciar o detener el proceso de insolado.
  - Ajustar el tiempo de exposición.
- **Resistencias Pull-up o Pull-down:** Para estabilizar las señales de los botones (típicamente de 10 kΩ).