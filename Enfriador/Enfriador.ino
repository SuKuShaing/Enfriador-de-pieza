// Enfriador de pieza


// Librerías
#include <DHT.h> // Es necesario instalar la "librería DHT Sensor Library by Adafruit"


// Definiciones
#define DHTTYPE DHT22 // define lo que hace es que cada vez que se mencione DHTTYPE se reemplaza por DHT22 en la compilación, en un futuro si se cambia el sensor se cambia aquí y no en todo el código
#define RELE_ON 0     // Activar RELE, como los reles se activan con nivel bajo o 0 por la lógica inversa
#define RELE_OFF 1    // Desactivar RELE, como los reles se desactivan con nivel alto o 1 por la lógica inversa

const int rele = 2;               // Definimos el número de pin digital de entrada del rele
const int DHTPin = 6;             // define el pin digital 6 como el pin de datos de ingreso del sensor DHT22
bool funcionamiento = RELE_OFF;   // variable para saber si el enfriador está encendido o no
float temperatura_deseada = 17.0; // define la temperatura deseada en grados Celsius
float tolerancia = 0.8;           // define la tolerancia de temperatura en grados Celsius


// instancias
DHT dht(DHTPin, DHTTYPE); // crea la instancia dth del objeto DHT con el pin 6 y el sensor tipo DHT22


void setup() {
   pinMode(rele, OUTPUT); // Configuramos el pin del rele como salida

   Serial.begin(9600);                // Inicia la comunicación serial
   Serial.println("Probando DHT22!"); // Imprime en el monitor serial

   dht.begin(); // es necesario iniciar el sensor antes de tomar lecturas
}


void loop() {
   delay(2000);

   float humedad_pieza = dht.readHumidity();    // lee la humedad
   float temperatura_pieza = dht.readTemperature(); // lee la temperatura en grados Celsius

   if (isnan(humedad_pieza) || isnan(temperatura_pieza)) {
      Serial.println("No se pudo leer el sensor DHT!");
      return;
   }

   // Enciende el enfriador si la temperatura es mayor a la deseada más la tolerancia
   if (temperatura_pieza > (temperatura_deseada + tolerancia) && funcionamiento == RELE_OFF) {
      digitalWrite(rele, RELE_ON); // Enciende el enfriador
      funcionamiento = RELE_ON;    // Actualiza el estado del enfriador
      Serial.println("Enfriador encendido");
   }
   // Cuando llega o es menor a la temperatura deseada aparta el enfriador
   else if (temperatura_pieza <= temperatura_deseada && funcionamiento == RELE_ON) {
      digitalWrite(rele, RELE_OFF); // Apaga el enfriador
      funcionamiento = RELE_OFF;    // Actualiza el estado del enfriador
      Serial.println("Enfriador apagado");
   }

   Serial.print("Humedad: ");
   Serial.print(humedad_pieza);
   Serial.print(" %\t"); // es un carácter de tabulación horizontal
   Serial.print("Temperatura: ");
   Serial.print(temperatura_pieza);
   Serial.println(" *C "); // hace el salto de línea
}