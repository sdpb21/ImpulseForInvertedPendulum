byte duty=227, i;

volatile long contador=0;


void setup() {
  
// put your setup code here, to run once:
  
	Serial.begin(115200);
  
	while(!Serial){
    
		;
  
	}
  

	pinMode(3, INPUT_PULLUP); // internalเป็น pullup input pin 3
  
	attachInterrupt(0,f1,RISING);
  
	//Serial.write("0,0\r\n");
  

	for(i=0;i<90;i++){
    
		analogWrite(5,duty*sin(2*i*3.1416/180));
    
		Serial.print(millis());
    
		Serial.write(' ');
    
		Serial.print(contador*0.35);
    
		Serial.write("\r\n");
    
		delayMicroseconds(6020);
  
	}//fin for
  

	analogWrite(5,0);
  

	for(i=0;i<90;i++){
    
		analogWrite(6,duty*sin(2*i*3.1416/180));
    
		Serial.print(millis());
    
		Serial.write(' ');
    
		Serial.print(contador*0.35);
    
		Serial.write("\r\n");
    
		delayMicroseconds(6020);
  
	}//fin for
  

	analogWrite(6,0);
  

	/*Serial.print(millis());
  
	Serial.write("\r\n");*/

}



void loop() {
  
// put your main code here, to run repeatedly:
  

	Serial.print(millis());
  
	Serial.write(' ');
  
	Serial.print(contador*0.35);
  
	Serial.write("\r\n");

}


void f1(){
  

	if(digitalRead(3)==LOW){
    
		contador--;
  
	}else{
    
		contador++;
  
	}


}

