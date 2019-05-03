void CheckState() {
  switch (robotState){
    case 1:
      LCD_Eat();
      Eyes_Sum();
      break;
    case 2:
      LCD_Sum();
      Eyes_Sum();
      break;
    case 3:
      LCD_AcceptCode();
      OpenLock();
      Eyes_Accept();
      break;
    case 4:
      LCD_RejectCode();
      Eyes_Error();
      break;
    case 5:
      LCD_CancelCode();
      Eyes_Iddle();
      break;
    case 6:
      LCD_NotLocking();
      Eyes_Warning();
      break;
    case 7:
      LCD_Locking();
      CloseLock();
      Eyes_Iddle();
      break;
    default:
      LCD_Iddle();
      Eyes_Iddle();
      break;
  }
}
