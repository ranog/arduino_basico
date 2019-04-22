// Projeto 13 – Sensor de batida piezo

int ledPin = 9;
int piezoPin = 5;
int threshold = 120;  // valor do sensor a ser atingido antes da ativaçao
int sensorValue = 0;  // para armazenar o valor lido do sensor
float ledValue = 0;   // brilho do LED

void setup(){
  pinMode(ledPin, OUTPUT);
  
  for(int i = 0; i < 2; i++){
    digitalWrite(ledPin, HIGH);
    delay(150);
    
    digitalWrite(ledPin, LOW);
    delay(150);
  }
}

void loop(){
  sensorValue = analogRead(piezoPin);  // Le o valor do sensor
  
  // se uma batida for detectada, defina o brilho como maximo
  if( sensorValue >= threshold){
    ledValue = 255;
  }
  
  // escreve o valor de brilho no LED
  analogWrite(ledPin, int(ledValue));
  
  // apaga o LED lentamente
  ledValue = ledValue - 0.05;
  
  if(ledValue){
    ledValue = 0;
  }
}
