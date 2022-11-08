#define boton 15
void setup(){
  pinMode(boton,INPUT_PULLUP);
  Serial.begin(115200);
  
}

void loop(){
  if(digitalRead(boton) == 0){
    delay(500);
    if(digitalRead(boton) == 0){
      while(digitalRead(boton)== 1);
      Serial.println("boton pressionado");
      
    }
  }
  else{
    Serial.println("boton no presionado");
  }
  delay(1000);
}
