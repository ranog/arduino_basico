// Projeto 4 - Semaforo interativo

// semaforo para carros
byte car_red = 12;
byte car_yellow = 11;
byte car_green = 10;

// semaforo para pedestres
byte pedestre_red = 9;
byte pedestre_green = 8;

// pino do botao
byte button = 2;

// tempo para que os pedestres atravessem
int cross_time = 5000;

// tempo desde que o botão foi pressionado
unsigned long change_time;

// prototipos
void change_lights();

void setup(){
  pinMode(car_red, OUTPUT);
  pinMode(car_yellow, OUTPUT);
  pinMode(car_green, OUTPUT);
  
  pinMode(pedestre_red, OUTPUT);
  pinMode(pedestre_green, OUTPUT);
  
  pinMode(button, INPUT);
  
  digitalWrite(car_green, HIGH);
  digitalWrite(pedestre_red, HIGH);
}

void loop(){
  /* verifica se o botão foi pressionado e se transcorreram 
  5 segundos desde a última vez que isso ocorreu */
  boolean state = digitalRead(button);
  
  if(state == HIGH && (millis() - change_time) > 5000){
    // chama a funçao para alterar as luzes
    change_lights();
  }
}

void change_lights(){
  digitalWrite(car_green, LOW);
  digitalWrite(car_yellow, HIGH);
  delay(2000);
  
  digitalWrite(car_yellow, LOW);
  digitalWrite(car_red, HIGH);
  delay(1000);
  
  digitalWrite(pedestre_red,LOW);
  digitalWrite(pedestre_green, HIGH);
  delay(cross_time);
  
  // pisca o verde dos pedestres
  for(byte i = 0; i < 10; i++){
    digitalWrite(pedestre_green, HIGH);
    delay(250);
    
    digitalWrite(pedestre_green, LOW);
    delay(250);   
  }
  
  // acende o vermelho dos pedestres
  digitalWrite(pedestre_red, HIGH);
  delay(250);
  
  digitalWrite(car_yellow, HIGH);
  digitalWrite(car_red, LOW);
  delay(1000);
  
  digitalWrite(car_green, HIGH);
  digitalWrite(car_yellow, LOW);
  
  // registra o tempo desde a última alteração no semáforo
  change_time = millis();
}
