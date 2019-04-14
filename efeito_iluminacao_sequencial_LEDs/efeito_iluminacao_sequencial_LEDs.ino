// Projeto 5 - Efeito de iluminaçao sequencial com LEDs

// cria um array para os pinos dos LEDs
byte leds[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

// intervalo entre as alteraçoes
int ledDelay(65);
int direction = 1;
int currentLED = 0;
unsigned long changeTime;

// prototipos
void changeLED();

void setup(){
  
  // define todos os pinos como saida
  for(int i = 0; i < 10; i++){
    pinMode(leds[i], OUTPUT);
  }
  
  changeTime = millis();
}

void loop(){
  if((millis() - changeTime) > ledDelay){
    changeLED();
    changeTime = millis();
  }
}

void changeLED(){
  // apaga todos os LEDs
  for(int i = 0; i < 10; i++){
    digitalWrite(leds[i], LOW);
  }
  
  // acende o LED atual
  digitalWrite(leds[currentLED], HIGH);
  
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
