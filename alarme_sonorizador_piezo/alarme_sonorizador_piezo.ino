// Projeto 11 – Alarme com sonorizador piezo

float sinVal;
int toneVal;

void setup(){
  pinMode(8, OUTPUT);
}

void loop(){
  for(int i = 0; i < 180; i++){
    // converte graus para radianos, e depois obtem o valor do seno
    sinVal = (sin(i * (3.1416 / 180)));
    
    // gera uma frequencia a partir do valor do seno
    toneVal = 2000 + (int(sinVal * 1000));
    tone(8, toneVal);
    delay(2);
  }
}
