// Es necesario instalar la "librería DHT Sensor Library by Adafruit"

// Librerías
#include <DHT.h>


// Definiciones
#define DHTTYPE DHT22  // define lo que hace es que cada vez que se mencione DHTTYPE se reemplaza por DHT22 en la compilación, en un futuro si se cambia el sensor se cambia aquí y no en todo el código

const int DHTPin = 6;

DHT dht(DHTPin, DHTTYPE); // crea la instancia dth del objeto DHT con el pin 6 y el sensor tipo DHT22


void setup()
{
   Serial.begin(9600);  // Inicia la comunicación serial
   Serial.println("Probando DHT22!");  // Imprime en el monitor serial

   dht.begin();  // es necesario iniciar el sensor antes de tomar lecturas
}


void loop()
{
   delay(2000);

   float h = dht.readHumidity();  // lee la humedad
   float t = dht.readTemperature();  // lee la temperatura en grados Celsius

   if (isnan(h) || isnan(t))
   {
      Serial.println("No se pudo leer el sensor DHT!");
      return;
   }

   Serial.print("Humedad: ");
   Serial.print(h);
   Serial.print(" %\t");  // es un carácter de tabulación horizontal
   Serial.print("Temperatura: ");
   Serial.print(t);
   Serial.println(" *C "); // hace el salto de línea
}