// Incluimos las librerías necesarias para el sensor DHT
#include "DHT.h"

// --- PINES DE CONEXIÓN ---
// Definimos el pin donde conectamos el sensor de temperatura DHT22
#define DHTPIN 15
// Definimos el tipo de sensor DHT que estamos usando
#define DHTTYPE DHT22
// Definimos el pin donde conectamos el potenciómetro (nuestro simulador de pH)
const int pinPotenciometro = 34; // Usamos el pin 34 para la entrada analógica

// --- VARIABLES PARA LA LÓGICA ---
float temperatura = 0;
float phSimulado = 0;
int valorPotenciometro = 0;

// Inicializamos el sensor DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Iniciamos la comunicación serial para ver los mensajes en el monitor
  Serial.begin(115200);
  Serial.println("Iniciando Sistema de Monitoreo de Fermentación (SMFC)...");
  
  // Iniciamos el sensor de temperatura
  dht.begin();
}

void loop() {
  // Esperamos 2 segundos entre cada lectura para no saturar el monitor
  delay(2000);

  // --- LECTURA DE SENSORES ---
  
  // Leemos la temperatura del sensor DHT22
  temperatura = dht.readTemperature();

  // Leemos el valor del potenciómetro (de 0 a 4095 en el ESP32)
  valorPotenciometro = analogRead(pinPotenciometro);
  
  // Convertimos el valor analógico (0-4095) a un rango de pH realista (ej. 3.0 a 8.0)
  // Esta función 'map' es clave para la simulación
  phSimulado = map(valorPotenciometro, 0, 4095, 8.0, 3.0);

  // --- MUESTRA DE DATOS EN MONITOR ---
  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.print(" °C");
  Serial.print("  |  ");
  Serial.print("pH Simulado: ");
  Serial.println(phSimulado);

  // --- LÓGICA DE LA ALERTA ---
  // Revisamos si las condiciones óptimas se han cumplido
  // (Temperatura por encima de 18°C y pH por debajo de 4.5)
  if (temperatura > 18.0 && phSimulado < 4.5) {
    Serial.println("*************************************************");
    Serial.println("* ALERTA: ¡FERMENTACIÓN ÓPTIMA ALCANZADA!      *");
    Serial.println("* Por favor, proceda a lavar el lote de café.  *");
    Serial.println("*************************************************");
  }
}