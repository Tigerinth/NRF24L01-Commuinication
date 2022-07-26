#include <LiquidCrystal_I2C.h>
#include <SPI.h>
#include <Wire.h>  
#include "RF24.h"

RF24 myRadio (9, 10);
byte addresses[][6] = {"0"};
int crs = 0;
int led = 6;
LiquidCrystal_I2C lcd(0x27, 16, 2); // 16x2 lcd ekleme
void setup() {
  Serial.begin(115200);
  delay(1000);
  
  pinMode(led , OUTPUT);
  
  lcd.init();
  
  lcd.backlight();
  lcd.clear();    
  
  myRadio.begin();  
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS );
  
  myRadio.openReadingPipe(1, addresses[0]);
  myRadio.startListening();  //dinlemeyi baslat
  
}

void loop() {
  if (myRadio.available()) {
    digitalWrite(led,HIGH);
    lcd.setCursor(0,0);
    lcd.print("Veri:");
    char text[20] = "";
    
    while (myRadio.available()){
      
      myRadio.read( &text, sizeof(text));
      
    //lcd.clear();
    lcd.setCursor(crs,1);
    lcd.print(text);
    crs++;
    }
    
  }
  
  delay(2000);
  digitalWrite(led,LOW);
  lcd.clear();
  crs = 0;
}
