void Key(){
  customKey = customKeypad.getKey();
  if (customKey){
    String customKeyStr(customKey);

    //start math sum
    if(robotState == 0 && customKeyStr == "*"){
      if (lcdChrono.hasPassed(500)){
        lcdChrono.restart();
        delay(500);
        robotState = 2;
        CheckState();
        Serial.println("Keypad_ state = 2");
      }
    }

    //cancel code
    if(robotState == 2 && customKeyStr == "*"){
      Serial.print("Keypad_CancelCode__");
      Debugging2();
      if (lcdChrono.hasPassed(500)){
        lcdChrono.restart();
        robotState = 5;
        CheckState();
        Serial.println("Keypad_ state = 5");
       
        delay(2000);
        robotState = 0;
        CheckState();
        Serial.println("Keypad_ state = 0");
      }
    }
    
    //right code
    String newtest(customKey);
    if(robotState == 2 && newtest == lockStr){
      Serial.print("Keypad_RightCodeNEW__");
      Debugging2();
      if (lcdChrono.hasPassed(500)){
        lcdChrono.restart();
        robotState = 3;
        CheckState();
        Serial.println("Keypad_ state = 3");
      }
    }

    //wrong code
    if(robotState == 2 && customKeyStr != lockStr){
      Serial.print("Keypad_WrongCode__");
      Debugging2();
      if (lcdChrono.hasPassed(500)){
        lcdChrono.restart();
        robotState = 4;
        CheckState();
        Serial.println("Keypad_ state = 4");
        
        delay(2000);
        robotState = 2;
        CheckState();
        Serial.println("Keypad_ state = 2");
      }
    }

    //locking the robot
    if(robotState == 3 && customKeyStr == "#"){
      if (lcdChrono.hasPassed(500)){
        lcdChrono.restart();
        robotState = 7;
        CheckState();
        Serial.println("Keypad_ state = 7");
        
        delay(2000);
        robotState = 0;
        CheckState();
        Serial.println("Keypad_ state = 0");
      }
    }
  }
  //DebuggingKeys();
}

void DebuggingKeys(){
  if (customKey){
    Serial.print("Keypad_Pressed key: \t");
    Serial.println(customKey);
  }
}

void Debugging2(){
  Serial.print("customKey:");
  Serial.print(customKey);
  Serial.print(": \tlockStr:");
  Serial.print(lockStr);
  Serial.println(":");
}
