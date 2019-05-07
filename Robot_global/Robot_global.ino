//libraries
#include <Keypad.h>
#include <LCD.h>
#include <LiquidCrystal.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Chrono.h>
#include <LightChrono.h>

//general variables
int robotState = 0;
int secretCode = 0;
int randomCode = 0;
int lockCode = 0;
String lockStr;
char lockCodeChr[5];
String sumStr;
char sumChar[16];

//infrared variables
Chrono irChrono;
int raw,noice,stable;
int irDio = A2;
int irLed = A1;

//Keypad
const byte ROWS = 4; 
const byte COLS = 3; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3}; 
char customKey;
char lastKey;

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

//LCD variables
Chrono lcdChrono;
Chrono mathChrono;
//thris row can differ depending on which i2c you have, use a i2c scanner
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//Servo variables
Chrono servoChrono;
Servo servoMain; // Define our Servo

//Led variables
Chrono eyeChrono;
int rgbRed = 10;
int rgbGreen = 12;
int rgbBlue = 11;
int blueLed = 13;

//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE

void setup() {
  Serial.begin(9600);

  //infrared
  pinMode(irLed, OUTPUT);

  //lcd
  lcd.backlight();
  lcd.begin(16, 2);

  //start text
  lcd.setCursor(0,0);
  lcd.print("Hello <3");

  //servo
  servoMain.attach(2);
  CloseLock();
  
  //leds
  pinMode(rgbRed, OUTPUT);
  pinMode(rgbGreen, OUTPUT);
  pinMode(rgbBlue, OUTPUT); 
  pinMode(blueLed, OUTPUT);
}

void loop() {
 Key();
 IrCheck(); 
 BlueLeds();
 Serial.println("Global_Looping: Key(), IrCheck(), BlueLeds()");

 if (robotState == 0) { 
  CheckState();
   Serial.println("Global_State = 0");
 }
}
