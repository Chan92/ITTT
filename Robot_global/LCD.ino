void LCD_Iddle(){
  if (lcdChrono.hasPassed(5000)){
    lcdChrono.restart();  
    char textArr0A[16] = "You are"; 
    char textArr1A[16] = "Lets play!";
    char textArr2A[16] = "Dont forget"; 
  
    char * textArrA[] = {
      textArr0A,
      textArr1A,
      textArr2A
    };
  
    char textArr0B[16] = "my best friend"; 
    char textArr1B[16] = " ";
    char textArr2B[16] = "to feed me"; 
  
     char * textArrB[] = {
      textArr0B,
      textArr1B,
      textArr2B
    };
  
    int randomText = random(0, 4);

    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(textArrA[randomText]);
    lcd.setCursor(0,1);
    lcd.print(textArrB[randomText]);
  }
}

void LCD_Eat(){
  if (lcdChrono.hasPassed(500)){
    lcdChrono.restart();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Yum (:");
    lcd.setCursor(0,1);
    lcd.print("Thank you <3");
  }
}

void LCD_Sum(){
  if (lcdChrono.hasPassed(500)){
    lcdChrono.restart();
    RandomMath();
  
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Answer the code:");
    lcd.setCursor(0,1);
    lcd.print("x + " + sumStr + " = ?");
  }
}

void LCD_AcceptCode(){
  if (lcdChrono.hasPassed(500)){
    lcdChrono.restart();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Look I kept your");
    lcd.setCursor(0,1);
    lcd.print("treasure safe");
  }
}

void LCD_RejectCode(){
  if (lcdChrono.hasPassed(500)){
    lcdChrono.restart();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Please try again");
    lcd.setCursor(0,1);
    lcd.print(" ");
  }
}

void LCD_CancelCode(){
  if (lcdChrono.hasPassed(5000)){
    lcdChrono.restart();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("I see");
    lcd.setCursor(0,1);
    lcd.print("until next time");
  }
}

void LCD_NotLocking(){
  if (lcdChrono.hasPassed(5000)){
    lcdChrono.restart();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Hello?");
    lcd.setCursor(0,1);
    lcd.print("Dont forget to lock me");
  }
}

void LCD_Locking(){
  if (lcdChrono.hasPassed(500)){
    lcdChrono.restart();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ok");
    lcd.setCursor(0,1);
    lcd.print("I will protect it");
  }
}
