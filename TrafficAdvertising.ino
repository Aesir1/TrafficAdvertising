#include "SR04.h"
#include <LiquidCrystal.h>
#define TRIG_PIN 12
#define ECHO_PIN 11
#define PIR_PIN 3

SR04 sr04 = SR04(ECHO_PIN, TRIG_PIN);
long a;
bool motionState = false;  //no motion detected
int val = 0;
LiquidCrystal lcd(4, 5, 6, 7, 8, 9);

// setting traaffic lights pin
int tDelay = 1000;
int latchPin = 13;      // (11) ST_CP [RCK] on 74HC595
int clockPin = 10;      // (9) SH_CP [SCK] on 74HC595
int dataPin = 2;     // (12) DS [S1] on 74HC595

byte leds = 0;
unsigned long millisecondLights = 0;
bool checkForLights = true;
bool readyForYellow = true;
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}

void setup() {
  pinMode(PIR_PIN, INPUT);
  
  // put your setup code here, to run once:
  Serial.begin(9600);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("Advertising.de!");
  Serial.println("Indicate wich advertising should be displayed:");
  Serial.println("Press 1 to => 'Drink water'.");
  Serial.println("Press 2 to => 'Drive safely'.");
  
  // traffic lights setup
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  a = sr04.Distance();
  if(a > 10 && a < 100){
    Serial.println(a);  
  }
   
  // Read out the PIR_PIN and store as val
  val = digitalRead(PIR_PIN);

  // if Motion is detected (PIR_PIN = HIGH)
  if(val == HIGH){
    Serial.print("Auto_detected\n");
  }

   // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);

  // checking serial
  if(Serial.available()){
    char advertising1[] = {"Drink water!!!"};
    char advertising2[] = "Drive safely";
    
    char advOnSelect = Serial.read();
    if(advOnSelect == '1'){
        lcd.print(advertising1);
    }
    if(advOnSelect == '2'){
        lcd.print(advertising2);
    }
  }

  if((millis() > (millisecondLights + 2000)) && checkForLights && readyForYellow){
    millisecondLights = millis();
    trafficLights1();
    checkForLights = false;
  }
  else if(((millis() > (millisecondLights + 10000)) && !checkForLights && readyForYellow)){
    millisecondLights = millis();
    trafficLightYellow();
    readyForYellow = false;
  }
  else if((millis() > (millisecondLights + 2000)) && !checkForLights && !readyForYellow){
    millisecondLights = millis();
    trafficLights2();
    checkForLights = true;
  }
   else if(((millis() > (millisecondLights + 10000)) && checkForLights && !readyForYellow)){
    millisecondLights = millis();
    trafficLightYellow();
    readyForYellow = true;
  }
  
  delay(1000);
}

void trafficLights1 (){
  leds = 0;
  updateShiftRegister();
  bitSet(leds,1);
  bitSet(leds, 4);
  bitClear(leds, 0);
  bitClear(leds, 2);
  bitClear(leds, 3);
  bitClear(leds, 5);
  bitClear(leds, 6);
  bitClear(leds, 7);
  updateShiftRegister();
}

void trafficLights2 (){
  leds = 0;
  updateShiftRegister();
  bitSet(leds, 3);
  bitSet(leds, 6);
  bitClear(leds, 0);
  bitClear(leds, 1);
  bitClear(leds, 2);
  bitClear(leds, 4);
  bitClear(leds, 5);
  bitClear(leds, 7);
  updateShiftRegister();
}

void trafficLightYellow (){
  //yellows leds
  leds = 0;
  updateShiftRegister();
  bitSet(leds, 2);
  bitSet(leds, 5);
  bitClear(leds, 0);
  bitClear(leds, 1);
  bitClear(leds, 3);
  bitClear(leds, 4);
  bitClear(leds, 6);
  bitClear(leds, 7);
  updateShiftRegister();
}
