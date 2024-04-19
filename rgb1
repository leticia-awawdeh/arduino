// Define os pinos dos botões
const int buttonYellow = 8; // Pino do botão amarelo
const int buttonPink = 7;   // Pino do botão rosa
const int buttonPurple = 6; // Pino do botão púrpur

// Define os pinos do LED RGB
const int redPin = 11;
const int greenPin = 9;
const int bluePin = 10;

void setup() {
  // Define os pinos dos botões como entrada com pull-up interno
  pinMode(buttonYellow, INPUT_PULLUP);
  pinMode(buttonPink, INPUT_PULLUP);
  pinMode(buttonPurple, INPUT_PULLUP);

  // Define os pinos do LED RGB como saída
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  //setColor(0, 0, 0);
}

void loop() {
  // Verifica se o botão amarelo foi pressionado
  if (digitalRead(buttonYellow) == HIGH) {
    setColor(255, 255, 0); // Amarelo (R, G, B)
  }
  // Verifica se o botão rosa foi pressionado
  if (digitalRead(buttonPink) == HIGH) {
    setColor(255, 0, 127); // Rosa (R, G, B)
  }
  // Verifica se o botão púrpura foi pressionado
  if (digitalRead(buttonPurple) == HIGH) {
    setColor(128, 0, 128); // Púrpura (R, G, B)
  }
}

// Função para definir a cor do LED RGB
void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin,blue);
}
