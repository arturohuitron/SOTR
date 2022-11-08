#ifdef ESP32
#include <WiFi.h> 
#else
#include <ESP6266WiFi.h>
#endif
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
const char* ssid = "REPLACE WITH YOUR SSID"; 
const char* password = "REPLACE_WITH_YOUR_PASWWORD";
#define BOTtoken "XXXXXXXXXX:2XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"
#define CHAT_ID "XXXXXXXXXX"
#ifdef ESP8266
X509List cert(TELEGRAM_CERTIFICATE_ROOT);
#endif

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

const int ledPin = 2;
bool ledState = LOW;

void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages");
  Serial.println(String(newNewMessages));

  for (int i=0; i<numNewMessages; i++) {

    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage (
      }
  }
  
  }
  }
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
