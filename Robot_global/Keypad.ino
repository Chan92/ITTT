void Key(){
  customKey = customKeypad.getKey();
  if (customKey){
    lastKey = customKey;

    if(robotState == 0 && customKey == '*'){
      if (lcdChrono.hasPassed(500)){
        lcdChrono.restart();
        robotState = 2;
        CheckState();
      }
    }

    if(robotState == 2 && customKey == '*'){
      Debugging2();
      if (lcdChrono.hasPassed(500)){
        lcdChrono.restart();
        robotState = 5;
        CheckState();
      }
    }

    if(robotState == 2 && customKey == lockCodeChr){
      Debugging2();
      if (lcdChrono.hasPassed(500)){
        lcdChrono.restart();
        robotState = 3;
        CheckState();
      }
    }

    if(robotState == 2 && customKey != lockCodeChr){
      Debugging2();
      if (lcdChrono.hasPassed(500)){
        lcdChrono.restart();
        robotState = 4;
        CheckState();
      }
    }

    if(robotState == 3 && customKey == '#'){
      if (lcdChrono.hasPassed(500)){
        lcdChrono.restart();
        robotState = 7;
        CheckState();
      }
    }
  }
  //DebuggingKeys();
}

void DebuggingKeys(){
  if (customKey){
    Serial.print("Pressed key: \t");
    Serial.println(customKey);
  }

  Serial.print("Last key: \t");
  Serial.println(lastKey);
}

void Debugging2(){
  Serial.print(":lastKey: \t:");
  Serial.print(lastKey);
  Serial.print(":lockcode: \t:");
  Serial.print(lockCodeChr);
  Serial.println(":");
}