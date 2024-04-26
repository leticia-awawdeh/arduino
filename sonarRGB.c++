// Definição dos pinos para o sensor ultrassônico 
const int trigPin = 2; 
const int echoPin = 3; // Adicionando o pino echo
// Definição dos pinos para os LEDs 
const int verdePin = 10; 
const int amareloPin = 9; 
const int vermelhoPin = 11; 

void setup() { 
    // Inicialização dos pinos 
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); // Configura o pino echo como entrada
    pinMode(verdePin, OUTPUT); 
    pinMode(amareloPin, OUTPUT); 
    pinMode(vermelhoPin, OUTPUT); 
    
    // Inicialização da porta serial para debug (opcional) 
    Serial.begin(9600); 
} 

void loop() { 
    // Limpar o pino do trigger 
    digitalWrite(trigPin, LOW); 
    delayMicroseconds(2); 
    
    // Envio de um pulso de 10 microssegundos para iniciar a medição 
    digitalWrite(trigPin, HIGH); 
    delayMicroseconds(10); // Espera 10 microssegundos
    digitalWrite(trigPin, LOW); 
    
    // Lê o tempo de retorno do pulso (em microssegundos)
    long duration = pulseIn(echoPin, HIGH); 
    
    // Convertendo o tempo de retorno em centímetros 
    float distance_cm = duration * 0.034 / 2; 
    
    // Imprime a distância na porta serial (opcional) 
    Serial.print("Distância: "); 
    Serial.print(distance_cm); 
    Serial.println(" cm"); 
    
    // Controle dos LEDs com base na distância medida 
  if (distance_cm > 45 && distance_cm < 60){// distância maior que 100cm (1 metro)
        // Distância acima de 1m, acender LED verde 
        digitalWrite(verdePin, HIGH); 
        digitalWrite(amareloPin, LOW); 
        digitalWrite(vermelhoPin, LOW); 
    } else if (distance_cm > 20 && distance_cm < 40 ){// distância maior que 50cm (0.5 metro)
        // Distância acima de 0,5m, acender LED amarelo 
        digitalWrite(verdePin, LOW);
        digitalWrite(amareloPin, HIGH);
        digitalWrite(vermelhoPin, LOW);
    } else if (distance_cm < 25 && distance_cm > 1){ 
      // distância menor que 40cm
        // Distância abaixo de 20cm, acender LED vermelho 
        digitalWrite(verdePin, LOW); 
        digitalWrite(amareloPin, LOW); 
        digitalWrite(vermelhoPin, HIGH); 
    }  else { 
        // Nenhuma condição atendida, todos os LEDs desligados 
        digitalWrite(verdePin, LOW); 
        digitalWrite(amareloPin, LOW); 
        digitalWrite(vermelhoPin, LOW); 
    } 
    // Aguarda um curto período antes de fazer a próxima medição 
    delay(100); 
}
