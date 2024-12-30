// Encender y apagar un LED con rele 5V cada 2 segundos

#define RELE_ON 0              // Activar RELE, como los reles se activan con nivel bajo o 0 por la lógica inversa 
#define RELE_OFF 1             // Desactivar RELE, como los reles se desactivan con nivel alto o 1 por la lógica inversa

int rele = 2;                  // Definimos el número de pin digital de entrada del rele

void setup() {
    pinMode(rele, OUTPUT);     // Configuramos el pin del rele como salida
    Serial.begin(9600);        // Inicia la comunicación serial
}

void loop() {
    digitalWrite(rele, RELE_ON);         // Encendemos el rele
    Serial.println("Rele encendido");    // Imprimimos en el monitor serial
    delay(2000);                         // Esperamos 2 segundos

    digitalWrite(rele, RELE_OFF);        // Apagamos el rele
    Serial.println("Rele apagado");      // Imprimimos en el monitor serial
    delay(2000);                         // Esperamos 2 segundos
}