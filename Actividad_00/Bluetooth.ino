/* Este código enciende el bluetooth del ESP32 al presionar un botón,
muestra mensajes en el monitor serie, y se apaga al enviar un comando específico*/

#include <BluetoothSerial.h>
#define LED1_GPIO 5

BluetoothSerial SerialBT;

int btn =5; //Se escoge el pin5 del ESP32, y variables importantes para el código
bool control = true;
int estado = 0;

void ConfigbyBluetooth (void); //Se prototipa la función de configurar Bluetooth (en la que viene los mensajes del monit. serie)
 
void setup() {
  pinMode(LED1_GPIO, OUTPUT); //Se declara el GPIO el cual será para la entrada del botón para el inicio de configuración
  pinMode(btn, INPUT);
  pinMode(4, OUTPUT);

  Serial.begin(115200);
  Serial.println("inicio de codigo");
  digitalWrite(4,HIGH);
}

void loop() {
  control = true;
  if (btn == 0 && control == true && estado == 0){
    delay (20);
    estado = 1;
  }
  if (btn == 0 && control == true && estado == 1){
    estado = 2;
    digitalWrite(4, HIGH);
  }
  if (estado == 2 && btn == 1){
    ConfigbyBluetooth();
  }
}


void ConfigbyBluetooth(void){
  String message = "";
  String message2 = "";
  char incomingChar;
  char incomingChar2;
  bool BTHControl = true;
  SerialBT.begin("Bluetooth_ESP32_Priapo_SOTR\n"); //Venía "Sis.op.real"
  Serial.println("Bluetooth disponible");
  while(BTHControl==true){
    if(SerialBT.available()){
      char incomingChar = SerialBT.read();
      if (incomingChar != '\n'){
        message += String(incomingChar);
      }
      
      else{
        message ="";
      }
      
      Serial.write(incomingChar);
    } 
    if (message == "Reset"){
      BTHControl = false;
      control = false;
    }
    
    if(Serial.available()){
      char incomingChar2 = Serial.read();
      if(incomingChar2 != '\n'){
        message2 += String(incomingChar2);
      }
      else{
        message2 = "";
      }
      Serial.write(incomingChar2);
    }
  }
  SerialBT.end();
}
