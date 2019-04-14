// Projeto 6 – Efeito interativo de iluminação sequencial com LEDs

byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
int ledDelay;
int direction = 1;
int currentLED = 0;
unsigned long changeTime;

// pino de entrada para o potenciometro
int potPin = 2;

// prototipo
void changeLED();

void setup(){
  // define todos os pinos como saida  
  for(int i = 0; i < 10; i++){
    pinMode(ledPin[i], OUTPUT);
  }
  
  changeTime = millis();
}

void loop(){
  // le o valor do potenciometro
  ledDelay = analogRead(potPin);
  
  // verifica se transcorreram ledDelay ms desde a ultima alteracao
  if((millis() - changeTime) > ledDelay){
    changeLED();
    changeTime = millis();
  }
}

void changeLED(){
  // apaga todos os LEDs
  for(int i = 0; i < 10; i++){
    digitalWrite(ledPin[i], LOW);
  }
  
  // acende o LED atual
  digitalWrite(ledPin[currentLED], HIGH);
  
  // incrementa de acordo com o valor de direction
  currentLED += direction;
  
  // altera a direçao se tivermos atingido o fim
  if(currentLED == 9){
    direction = -1;
  }
  
  if(currentLED == 0){
    direction = 1;
  }
}

