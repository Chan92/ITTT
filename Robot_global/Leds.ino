/*
Adafruit Arduino - Lesson 3. RGB LED
*/

void Eyes_Iddle(){
  setColor(0, 0, 255);  // blue
}

void Eyes_Sum() {
  blinkColor(155, 155, 155);  // white
}

void Eyes_Error(){
  blinkColor(255, 0, 0);  // red
}

void Eyes_Accept(){
  setColor(0, 255, 0);  // green
}

void Eyes_Warning(){
  blinkColor(80, 0, 80);  // purple
}


void setColor(int red, int green, int blue){
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(rgbRed, red);
  analogWrite(rgbGreen, green);
  analogWrite(rgbBlue, blue);  
}

void blinkColor(int red, int green, int blue){
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  if (eyeChrono.hasPassed(200)){
    eyeChrono.restart();
    analogWrite(rgbRed, red);
    analogWrite(rgbGreen, green);
    analogWrite(rgbBlue, blue);  
  }
  if (eyeChrono.hasPassed(200)){
    eyeChrono.restart();
    analogWrite(rgbRed, -red);
    analogWrite(rgbGreen, -green);
    analogWrite(rgbBlue, -blue);  
  }
}

void BlueLeds(){
  digitalWrite(blueLed, HIGH);
}
