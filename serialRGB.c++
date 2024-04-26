

// Definindo os pinos para os LEDs
const int redLED = 11;
const int blueLED = 9;
const int greenLED = 10;

void setup() {
  // Inicializando a comunicação serial
  Serial.begin(9600);
  
  // Configurando os pinos dos LEDs como saída
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    // Lendo o valor recebido pela porta serial
    char receivedChar = Serial.read();
    
    // Verificando qual cor deve ser acionada
    if (receivedChar == 'R') {
      // Acendendo o LED vermelho
      digitalWrite(redLED, HIGH);
      digitalWrite(blueLED, LOW);
      digitalWrite(greenLED, LOW);
    } else if (receivedChar == 'B') {
      // Acendendo o LED azul
      digitalWrite(redLED, LOW);
      digitalWrite(blueLED, HIGH);
      digitalWrite(greenLED, LOW);
    } else if (receivedChar == 'C') {
      // Acendendo o LED ciano (mistura de azul e verde)
      digitalWrite(redLED, LOW);
      digitalWrite(blueLED, HIGH);
      digitalWrite(greenLED, HIGH);
    } else {
      // Desligando todos os LEDs se uma entrada inválida for recebida
      digitalWrite(redLED, LOW);
      digitalWrite(blueLED, LOW);
      digitalWrite(greenLED, LOW);
    }
  }
}
