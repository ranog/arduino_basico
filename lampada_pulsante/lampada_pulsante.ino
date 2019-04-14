// Projeto 7 - Lampada pulsante

int ledPin = 11;
float sinVal;
int ledVal;

void setup(){
  pinMode(ledPin, OUTPUT);
}

void loop(){
  
  for(int i = 0; i < 180; i++){
    // converte graus para radianos, e obtem o valor do seno
    sinVal = (sin(i * (PI / 180)));
    ledVal = int(sinVal * 255);
    analogWrite(ledPin, ledVal);
    delay(25);
  }
}
