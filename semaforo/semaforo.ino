// Projeto 3 - Semaforo

int led_delay = 10000; // espera entre as alteraçoes
byte green = 10;
byte yellow = 9;
byte red = 8;

void setup(){
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
}

void loop(){
  digitalWrite(red, HIGH);
  delay(led_delay);
  
  digitalWrite(yellow, HIGH);
  delay(2000);
  
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  delay(led_delay);
  
  digitalWrite(yellow, HIGH);
  digitalWrite(green, LOW);
  delay(2000);
  
  digitalWrite(yellow, LOW);
}
