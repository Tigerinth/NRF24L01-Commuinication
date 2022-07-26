#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>  
#include "RF24.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int pot = A0;
int potDeger = 0;

const int contbtn = 7;
const int okbtn = 8;
int okbtnState = 0;
int contbtnState = 0;


RF24 myRadio (9, 10);
byte addresses[][6] = {"0"};



char *kelime = new char[20];
int crs = 0;

void setup() {
pinMode(contbtn, INPUT);
pinMode(okbtn, INPUT);
Serial.begin(115200);
delay(1000);
  

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.clearDisplay();
  display.setTextColor(WHITE); 
  display.setCursor(0,0);
  display.println("HAZIR!   by Tigerinth"); //21 karakter max sigiyor
  display.display(); 
  
  myRadio.begin();  
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS );
  myRadio.openWritingPipe(addresses[0]);

}

void loop() {
okbtnState = digitalRead(okbtn);
contbtnState = digitalRead(contbtn);
potDeger = analogRead(pot);
//Serial.println(potDeger);

if(okbtnState==LOW){
  
  if(contbtnState==HIGH){
    // klavye
    if (potDeger <40) {
    kelime[crs] = 'A';
    crs++;
    Serial.println("A");
    delay(500);
    }
    else if (potDeger > 40 && potDeger <80) {
    kelime[crs] = 'B';
    crs++;
    Serial.println("B");
    delay(500);
    }
    else if (potDeger > 80 && potDeger <120) {
    kelime[crs] = 'C';
    crs++;
    Serial.println("C");
    delay(500);
    }
    else if (potDeger > 120 && potDeger <160) {
    kelime[crs] = 'D';
    crs++;
    Serial.println("D");
    delay(500);
    }
    else if (potDeger > 160 && potDeger <200) {
    kelime[crs] = 'E';
    crs++;
    Serial.println("E");
    delay(500);
    }
    else if (potDeger > 200 && potDeger <240) {
    kelime[crs] = 'F';
    crs++;
    Serial.println("F");
    delay(500);
    }
    else if (potDeger > 240 && potDeger <280) {
    kelime[crs] = 'G';
    crs++;
    Serial.println("G");
    delay(500);
    }
    else if (potDeger > 280 && potDeger <320) {
    kelime[crs] = 'H';
    crs++;
    Serial.println("H");
    delay(500);
    }
    else if (potDeger > 320 && potDeger <360) {
    kelime[crs] = 'I';
    crs++;
    Serial.println("I");
    delay(500);
    }
    else if (potDeger > 360 && potDeger <400) {
    kelime[crs] = 'J';
    crs++;
    Serial.println("J");
    delay(500);
    }
    else if (potDeger > 400 && potDeger <440) {
    kelime[crs] = 'K';
    crs++;
    Serial.println("K");
    delay(500);
    }
    else if (potDeger > 440 && potDeger <480) {
    kelime[crs] = 'L';
    crs++;
    Serial.println("L");
    delay(500);
    }
    else if (potDeger > 480 && potDeger <520) {
    kelime[crs] = 'M';
    crs++;
    Serial.println("M");
    delay(500);
    }
    else if (potDeger > 520 && potDeger <560) {
    kelime[crs] = 'N';
    crs++;
    Serial.println("N");
    delay(500);
    }
    else if (potDeger > 560 && potDeger <600) {
    kelime[crs] = 'O';
    crs++;
    Serial.println("O");
    delay(500);
    }
    else if (potDeger > 600 && potDeger <640) {
    kelime[crs] = 'P';
    crs++;
    Serial.println("P");
    delay(500);
    }
    else if (potDeger > 640 && potDeger <680) {
    kelime[crs] = 'R';
    crs++;
    Serial.println("R");
    delay(500);
    }
    else if (potDeger > 680 && potDeger <720) {
    kelime[crs] = 'S';
    crs++;
    Serial.println("S");
    delay(500);
    }
    else if (potDeger > 720 && potDeger <760) {
    kelime[crs] = 'T';
    crs++;
    Serial.println("T");
    delay(500);
    }
    else if (potDeger > 760 && potDeger <800) {
    kelime[crs] = 'U';
    crs++;
    Serial.println("U");
    delay(500);
    }
    else if (potDeger > 800 && potDeger <840) {
    kelime[crs] = 'V';
    crs++;
    Serial.println("V");
    delay(500);
    }
    else if (potDeger > 840 && potDeger <880) {
    kelime[crs] = 'Y';
    crs++;
    Serial.println("Y");
    delay(500);
    }
    else if (potDeger > 880 && potDeger <920) {
    kelime[crs] = 'X';
    crs++;
    Serial.println("X");
    delay(500);
    }
    else if (potDeger > 920) {
    kelime[crs] = 'Z';
    crs++;
    Serial.println("Z");
    delay(500);
    }
    // klavye
  }
  }else { // yazdirma kismi
    int x = -6;
    for (int i = 0; i < crs; i++){
    x = x + 6;
    Serial.print(kelime[i]);
    display.setCursor(x,20);
    display.print(kelime[i]);

    myRadio.write(&kelime[i], sizeof(kelime));

    
    
    display.setCursor(0,0);
    display.println("HAZIR!   by Tigerinth");
    
    display.display();
    }
    Serial.println();
    delay(1000);
    display.clearDisplay();
    
    crs = 0;
    for (int i = 0; i < crs; i++){
      delete[] kelime;
    }
    char *kelime = new char[20];
    delay(500); 
  }
}
