byte led = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // 3 pontos
  for(int i = 0; i < 3; i++){
    digitalWrite(led, HIGH);
    delay(150);
    digitalWrite(led, LOW);
    delay(100);  
  }

  // espera 100ms para marcar o intervalo entre as letras
  delay(100);

  // 3 traços
  for(int i = 0; i < 3; i++){
    digitalWrite(led, HIGH);
    delay(400);
    digitalWrite(led, LOW);
    delay(100);  
  }

  // intervalo entre as letras 100ms
  delay(100);

  // 3 pontos novamente
  for(int i = 0; i < 3; i++){
    digitalWrite(led, HIGH);
    delay(150);
    digitalWrite(led,LOW);
    delay(100);
  }

  // espera 5 segundos antes de repetir o sinal
  delay(5000);
}
