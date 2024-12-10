# Documento Técnico - Máquina de Insolado

## Software

### **Descripción del Software**

El software de la máquina de insolado está diseñado para controlar los diferentes componentes electrónicos mediante un flujo de programación optimizado. Se encarga de gestionar el tiempo de exposición, las interacciones del usuario con los botones y la visualización de datos en la pantalla LCD. El sistema se basa en la arquitectura del microcontrolador Atmega.

### **Componentes Principales**

#### **1. Control del Proceso**
- **Gestión del Tiempo de Exposición:** 
  - Uso de temporizadores para controlar la duración de encendido de los LEDs UV.
  - Configuración del tiempo a través de los botones pulsadores.
- **Encendido y Apagado de LEDs UV:** 
  - Control mediante salidas digitales conectadas a un MOSFET para gestionar la intensidad de los LEDs UV.

#### **2. Interfaz de Usuario**
- **Pantalla LCD:**
  - Muestra información sobre:
    - El tiempo configurado por el usuario.
    - El estado actual del proceso (en ejecución, finalizado, en espera).
  - Actualización dinámica de los datos durante la ejecución del proceso.
- **Botones de Control:**
  - Botón para iniciar y detener el proceso de insolado.
  - Botones para aumentar y disminuir el tiempo de exposición, con validación para evitar valores inválidos (como tiempos negativos o excesivamente altos).
  
#### **4. Seguridad y Validación**
- **Validación de Entradas:** 
  - Verificación de que el tiempo configurado por el usuario esté dentro de un rango permitido.
  - Debounce para evitar activaciones accidentales en los botones.
- **Apagado Automático de LEDs:** 
  - Garantía de que los LEDs UV se apagan automáticamente al finalizar el proceso.

### **Flujo General del Software**
1. **Inicio:**
   - Inicialización de todos los componentes (pantalla LCD, pines de entrada/salida).
   - Presentación de un mensaje de bienvenida en la pantalla LCD.

2. **Configuración del Tiempo:**
   - Lectura de los botones para aumentar o disminuir el tiempo de exposición.
   - Visualización del tiempo configurado en la pantalla LCD.

3. **Ejecución del Proceso:**
   - Activación de los LEDs UV durante el tiempo configurado.
   - Contador descendente mostrado en la pantalla LCD.

4. **Finalización:**
   - Apagado de los LEDs UV.
   - Activación del buzzer para notificar al usuario.
   - Mensaje en la pantalla indicando que el proceso ha concluido.

5. **Reinicio:**
   - Espera de nuevas interacciones del usuario para configurar un nuevo tiempo o iniciar otro ciclo.

### **Lenguaje de Programación**
El software está escrito en **C/C++**, utilizando la plataforma Arduino IDE para facilitar la programación y depuración del microcontrolador Atmega.
