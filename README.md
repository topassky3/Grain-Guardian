☕ Sistema de Monitoreo de Fermentación de Café (SMFC)
Este proyecto es un prototipo para monitorear las variables clave en el proceso de fermentación del café, utilizando un microcontrolador ESP32. El sistema mide la temperatura real y simula la lectura del pH para determinar el punto óptimo de fermentación y alertar al usuario.

📝 Descripción del Proyecto
El objetivo es crear un dispositivo de bajo costo que ayude a los caficultores a estandarizar la calidad de su café. El código monitorea dos condiciones críticas para la fermentación:

Temperatura: Leída a través de un sensor DHT22.

pH: Simulado mediante un potenciómetro. Esto permite probar la lógica del sistema sin necesidad de un sensor de pH real, que es más costoso y complejo de manejar.

Cuando la temperatura supera los 18°C y el pH (simulado) desciende por debajo de 4.5, el sistema imprime una alerta, indicando que la fermentación ha alcanzado su punto ideal y es momento de proceder con el lavado del lote.

⚙️ Hardware Necesario
Microcontrolador (se recomienda ESP32 por su ADC de 12 bits).

Sensor de temperatura y humedad DHT22.

Potenciómetro (cualquier valor, como 10KΩ, funciona bien).

Protoboard y cables de conexión (jumpers).

🚀 Cómo Funciona
El código está estructurado en el entorno de Arduino y realiza las siguientes tareas en un bucle (loop):

Espera 2 segundos entre cada medición para no saturar el sistema.

Lee la temperatura en grados Celsius desde el pin 15 usando el sensor DHT22.

Lee el valor analógico del potenciómetro (conectado al pin 34). Este valor va de 0 a 4095.

Mapea (convierte) el valor del potenciómetro a un rango de pH realista (de 8.0 a 3.0). Girar la perilla simula el descenso del pH durante la fermentación.

Imprime los valores de temperatura y pH simulado en el Monitor Serial.

Evalúa la condición de alerta: Si temperatura > 18.0 Y phSimulado < 4.5, muestra un mensaje destacado indicando que el proceso ha finalizado.

🛠️ Instalación y Uso
Conecta los componentes según los pines definidos en el código:

Sensor DHT22 al pin 15.

Potenciómetro al pin 34.

Abre el archivo .ino en el Arduino IDE.

Instala la librería DHT: Ve a Herramientas > Administrar Bibliotecas... y busca e instala "DHT sensor library" by Adafruit.

Selecciona la placa correcta (ej. "ESP32 Dev Module") y el puerto COM en el menú Herramientas.

Sube el código a tu microcontrolador.

Abre el Monitor Serial (Herramientas > Monitor Serie) y configúralo a una velocidad de 115200 baudios para ver los datos en tiempo real.

Al girar el potenciómetro y calentar ligeramente el sensor, podrás simular las condiciones y ver cómo se dispara la alerta.