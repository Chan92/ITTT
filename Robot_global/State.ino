void CheckState() {
  switch (robotState){
    case 1:
      LCD_Eat();
      Eyes_Sum();
      Serial.println("State_Case1");
      break;
    case 2:
      LCD_Sum();
      Eyes_Sum();
      Serial.println("State_Case2");
      break;
    case 3:
      LCD_AcceptCode();
      OpenLock();
      Eyes_Accept();
      Serial.println("State_Case3");
      break;
    case 4:
      LCD_RejectCode();
      Eyes_Error();
      Serial.println("State_Case4");
      break;
    case 5:
      LCD_CancelCode();
      Eyes_Iddle();
      Serial.println("State_Case5");
      break;
    case 6:
      LCD_NotLocking();
      Eyes_Warning();
      Serial.println("State_Case6");
      break;
    case 7:
      LCD_Locking();
      CloseLock();
      Eyes_Iddle();
      Serial.println("State_Case7");
      break;
    default:
      LCD_Iddle();
      Eyes_Iddle();
      Serial.println("State_Case default");
      break;
  }
}
