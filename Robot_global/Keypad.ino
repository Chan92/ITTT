void Key(){
  customKey = customKeypad.getKey();
  if (customKey){
    lastKey = customKey;

    //start math sum
    if(robotState == 0 && customKey == '*'){
      if (lcdChrono.hasPassed(500)){
        lcdChrono.restart();
        robotState = 2;
        CheckState();
        Serial.println("Keypad_ state = 2");
      }
    }

    //cancel code
    if(robotState == 2 && customKey == '*'){
      Debugging2();
      if (lcdChrono.hasPassed(500)){
        lcdChrono.restart();
        robotState = 5;
        CheckState();
        Serial.println("Keypad_ state = 5");

         if (lcdChrono.hasPassed(500)){
          lcdChrono.restart();
          robotState = 0;
          CheckState();
          Serial.println("Keypad_ state = 0");
         }
      }
    }

    //right code
    if(robotState == 2 && customKey == lockCodeChr){
      Debugging2();
      if (lcdChrono.hasPassed(500)){
        lcdChrono.restart();
        robotState = 3;
        CheckState();
        Serial.println("Keypad_ state = 3");
      }
    }

    //wrong code
    if(robotState == 2 && customKey != lockCodeChr){
      Debugging2();
      if (lcdChrono.hasPassed(500)){
        lcdChrono.restart();
        robotState = 4;
        CheckState();
        Serial.println("Keypad_ state = 4");

        if (lcdChrono.hasPassed(500)){
          lcdChrono.restart();
          robotState = 2;
          CheckState();
          Serial.println("Keypad_ state = 2");
         }
      }
    }

    //locking the robot
    if(robotState == 3 && customKey == '#'){
      if (lcdChrono.hasPassed(500)){
        lcdChrono.restart();
        robotState = 7;
        CheckState();
        Serial.println("Keypad_ state = 7");

        if (lcdChrono.hasPassed(500)){
          lcdChrono.restart();
          robotState = 0;
          CheckState();
          Serial.println("Keypad_ state = 0");
         }
      }
    }
  }
  DebuggingKeys();
}

void DebuggingKeys(){
  if (customKey){
    Serial.print("Keypad_Pressed key: \t");
    Serial.println(customKey);
  }

  Serial.print("Keypad_Last key: \t");
  Serial.println(lastKey);
}

void Debugging2(){
  Serial.print("Keypad_:lastKey: \t:");
  Serial.print(lastKey);
  Serial.print(":lockcode: \t:");
  Serial.print(lockCodeChr);
  Serial.println(":");
}
