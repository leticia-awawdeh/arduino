int sensorLDR = A5;
int motor = 9;


void setup() {

  pinMode(motor, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int leitura = analogRead(sensorLDR);
  Serial.print("Leitura: ");
  
  int brilho = map (leitura, 400, 1000, 0, 255);
  Serial.println(brilho);

  if(brilho <= 120){
    digitalWrite(motor, HIGH);
  }
    if(brilho > 120){
    digitalWrite(motor, LOW);

  }

  delay(200);
}
