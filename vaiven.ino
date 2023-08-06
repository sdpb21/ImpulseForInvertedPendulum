byte duty=224, i;
//volatile unsigned long contador=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  while(!Serial){
    ;
  }
  //attachInterrupt(0,f1,RISING);
  Serial.print(millis());
  for(i=0;i<90;i++){
    analogWrite(5,duty*sin(2*i*3.1416/180));
    delayMicroseconds(6750);
  }
  for(i=0;i<90;i++){
    analogWrite(6,duty*sin(2*i*3.1416/180));
    delayMicroseconds(6750);
  }
  Serial.write("\r\n");
  Serial.print(millis());
  Serial.write("\r\n");
  Serial.print(millis());
  analogWrite(6,0);
  analogWrite(5,0);

}

void loop() {
  // put your main code here, to run repeatedly:
  /*Serial.write("0,0\r\n");
  for(i=0;i<90;i++){
    analogWrite(5,duty*sin(2*i*3.1416/180));
    Serial.print(millis());
    Serial.write(',');
    Serial.print(contador);
    Serial.write("\r\n");
    delay(10);
  }//fin for
  analogWrite(5,0);
  for(i=0;i<90;i++){
    analogWrite(6,duty*sin(2*i*3.1416/180));
    Serial.print(millis());
    Serial.write(',');
    Serial.print(contador);
    Serial.write("\r\n");
    delay(10);
    //delayMicroseconds(8500);
  }//fin for
  analogWrite(6,0);*/
}
/*void f1(){
  contador++;
}*/

