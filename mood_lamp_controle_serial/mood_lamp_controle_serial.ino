// Projeto 10 – Mood lamp com controle serial

char buffer[18];

int red, green, blue;

int redPin = 11;
int greenPin = 10;
int bluePin = 9;

// prototipo
void splitString(char* data);
void setLED(char* data);

void setup(){
  Serial.begin(9600);
  Serial.flush();
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop(){
  if(Serial.available() > 0){
    int index = 0;
    
    // deixe o buffer encher
    delay(100);
    
    int numChar = Serial.available();
    
    if(numChar > 15){
      numChar = 15;
    }
    
    while(numChar--){
      buffer[index++] = Serial.read();
    }
    
    splitString(buffer);
  }
}

void splitString(char* data){
  Serial.print("Data entered: ");
  Serial.println(data);
  
  char* parameter;
  
  parameter = strtok(data, " ,");
  
  while(parameter != NULL){
    setLED(parameter);
    parameter = strtok(NULL, " ,");
  }
  
  // limpa o texto e os buffers seriais
  for(int i = 0; i < 16; i++){
    buffer[i] = '\0';
  }
  
  Serial.flush();
}

void setLED(char* data) {
  if ((data[0] == 'r') || (data[0] == 'R')) {
    int ans = strtol(data+1, NULL, 10);
    
    ans = constrain(ans,0,255);
    
    analogWrite(redPin, ans);
    Serial.print("Red is set to: ");
    Serial.println(ans);
  }

  if ((data[0] == 'g') || (data[0] == 'G')) {
    int ans = strtol(data+1, NULL, 10);  
  
    ans = constrain(ans,0,255);
  
    analogWrite(greenPin, ans);
    Serial.print("Green is set to: ");
    Serial.println(ans);
  }

  if ((data[0] == 'b') || (data[0] == 'B')) {
    int ans = strtol(data+1, NULL, 10);

    ans = constrain(ans,0,255);
	
    analogWrite(bluePin, ans);
    Serial.print("Blue is set to: ");
    Serial.println(ans);
  }
}
