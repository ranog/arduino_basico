// Projeto 14 – Sensor de luz

int piezoPin = 8;
int ldrPin = 0;
int ldrValue = 0;  // valor lido do LDR

void setup(){
  // nada a ser feito aqui
}

void loop(){
  // ler o LDR
  ldrValue = analogRead(ldrPin);
  
  // tocar um tom de 1000 Hz no piezo
  tone(piezoPin, 1000);
  delay(25);
  
  // interronper o tom
  noTone(piezoPin);
  
  // esperar a quantidade de milissegundos em ldrValue
  delay(ldrValue);
}
