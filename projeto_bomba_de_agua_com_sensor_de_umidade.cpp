#define LDRpin A1
int LDRvalue = 0;
int qq = 10;
int umidadeAnalogica = A0;
int umidadeDigital = 9;

int valorumidade;
int valorumidadeDigital;
void setup() {
  Serial.begin(9600); 
  pinMode(qq, OUTPUT);
  pinMode(umidadeAnalogica, INPUT); 
  pinMode(umidadeDigital, INPUT); 
}
void loop() {
  LDRvalue = analogRead(LDRpin);

  valorumidade = analogRead(umidadeAnalogica); 
  valorumidade = map(valorumidade, 1023, 315, 0, 100); 
  Serial.print(valorumidade); 
  Serial.println(" % " );
  Serial.println(LDRvalue);
  valorumidadeDigital = digitalRead(umidadeDigital);

  if (LDRvalue < 85 && valorumidade < 10){
    digitalWrite(qq, HIGH);
    //delay(500);
    
  } 
  if ((LDRvalue > 85) && (valorumidade > 10)){
    digitalWrite(qq, LOW);
  } else {
    digitalWrite(qq, LOW);
  }
  delay(500);
}
