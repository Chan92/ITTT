void RandomMath(){
  if (mathChrono.hasPassed(8000)){
    mathChrono.restart();
    randomCode = random(0, 10);
    lockCode = secretCode + randomCode;
    lockStr = String(lockCode);
    lockStr.toCharArray(lockCodeChr,5);
  
    sumStr = String(randomCode);
    sumStr.toCharArray(sumChar, 16);
  }
}
