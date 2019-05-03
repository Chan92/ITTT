/*
This code is to Remove ambience noise from sensor data.
IR LED connected to Digital pin: irLed
IR diode connected to analog input: irDio

by-Abhilash Patel
-------------------------------
Modified:
-the pins to have variable names
-ensure the stable(denoised)value to be positive
-split the check and the debugging prints
*/

void IrCheck(){
  if (robotState == 0 && irChrono.hasPassed(500)){
    irChrono.restart();
    digitalWrite(irLed,HIGH);    //Turning ON IR-LED
    delayMicroseconds(500);      //wait
    raw=analogRead(irDio);       //take reading from photodiode :noise+signal
    digitalWrite(irLed,LOW);     //turn Off IR-LED
    delayMicroseconds(500);      //wait
    noice=analogRead(irDio);     //again take reading from photodiode :noise
    stable=raw-noice;            //taking differnce:[ (noise+signal)-(noise)] just signal
    stable = abs(stable);        //Ensures the value to be positive
  
    IrDetected();
    //DebuggingPrint();
  }
}

void IrDetected(){
  if (stable < 10) {
    robotState = 1;
    CheckState();
    if (lcdChrono.hasPassed(1000)){
      lcdChrono.restart();
      robotState = 2;
      CheckState();
    }
  }
}

void DebuggingPrint(){
  Serial.print(raw);           //noise+signal/Serial.print("\t");
  Serial.print("\t");
  Serial.print(noice);         //noise
  Serial.print("\t");
  Serial.println(stable);      //denoised signal
}
