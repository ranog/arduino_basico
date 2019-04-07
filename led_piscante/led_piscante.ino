// Projeto 1 - LED piscante

byte led = 10;

void setup(){
  pinMode(led, OUTPUT);
}

void loop(){
  digitalWrite(led, HIGH);
  delay(1000);
  
  digitalWrite(led, LOW);
  delay(1000);
}
