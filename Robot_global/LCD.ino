void LCD_Iddle(){
  if (lcdChrono.hasPassed(5000)){
    lcdChrono.restart();  
    String textArr0A = "You are"; 
    String textArr1A = "Lets play!";
    String textArr2A = "Dont forget"; 
    
    String textArrA[3] = {
      textArr0A,
      textArr1A,
      textArr2A
    };
  
    String textArr0B = "my best friend"; 
    String textArr1B = " ";
    String textArr2B = "to feed me"; 
  
    String textArrB[3] = {
      textArr0B,
      textArr1B,
      textArr2B
    };
  
    int randomText = random(0, 3);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(textArrA[randomText]);
    lcd.setCursor(0,1);
    lcd.print(textArrB[randomText]);
    
    //Serial.print(randomText);
    //Serial.print(">>  ");
    //Serial.print(textArrA[randomText]);
    //Serial.print("  -   ");
    //Serial.println(textArrB[randomText]);
    Serial.println("LCD_new iddle text");
  }
}

void LCD_Eat(){
  if (lcdChrono.hasPassed(500)){
    lcdChrono.restart();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Yum (:"));
    lcd.setCursor(0,1);
    lcd.print(F("Thank you <3"));
    Serial.println("LCD_eat text");
  }
}

void LCD_Sum(){
  if (lcdChrono.hasPassed(500)){
    lcdChrono.restart();
    RandomMath();
  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Answer the code:"));
    lcd.setCursor(0,1);
    lcd.print("x + " + sumStr + " = ?");
    Serial.println("LCD_sum text");
  }
}

void LCD_AcceptCode(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Look I kept your"));
    lcd.setCursor(0,1);
    lcd.print(F("treasure safe"));
    Serial.println("LCD_accept code text");

    lcdChrono2.restart();
    robotState = 6;
    CheckState();
}

void LCD_RejectCode(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Please try again"));
    lcd.setCursor(0,1);
    lcd.print(F(" "));
    Serial.println("LCD_reject code text");
}

void LCD_CancelCode(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("I see"));
    lcd.setCursor(0,1);
    lcd.print(F("until next time"));
    Serial.println("LCD_cancel code text");
}

void LCD_NotLocking(){
  if (lcdChrono2.hasPassed(5000)){
    lcdChrono2.restart();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Dont forget"));
    lcd.setCursor(0,1);
    lcd.print(F("to lock me"));
    Serial.println("LCD_not locking text");
  }
}

void LCD_Locking(){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("Ok I will"));
    lcd.setCursor(0,1);
    lcd.print(F("protect it"));
    Serial.println("LCD_locking text");
}
