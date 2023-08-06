byte duty=214, i;

volatile long angl=0;

volatile long pos=0;


void setup() {

// put your setup code here, to run once:

	Serial.begin(115200);

	while(!Serial){
    
		;
  
	}

	pinMode(4,INPUT_PULLUP);//angle

	pinMode(7,INPUT_PULLUP); //position

	attachInterrupt(0,f1,RISING);//angle pin 2

	attachInterrupt(1,f2,RISING);//position pin 3

	for(i=0;i<90;i++){

		analogWrite(5,duty*sin(2*i*3.1416/180));
		Serial.print(millis());
		Serial.write(' ');
		Serial.print(angl*0.35);

		Serial.write(' ');
		Serial.print(pos);
		Serial.write("\r\n");
		delayMicroseconds(4600);

	}//fin for

	analogWrite(5,0);

	for(i=0;i<90;i++){
		analogWrite(6,duty*sin(2*i*3.1416/180));
		Serial.print(millis());
		Serial.write(' ');
		Serial.print(angl*0.35);
		Serial.write(' ');
		Serial.print(pos);
		Serial.write("\r\n");
		delayMicroseconds(4600);
	}//fin for

	analogWrite(6,0);
	//Serial.print(millis());

}



void loop() {
  // put your main code here, to run repeatedly:
  

	Serial.print(millis());
    
	Serial.write(' ');
    
	Serial.print(angl*0.35);
    
	Serial.write(' ');
    
	Serial.print(pos);
    
	Serial.write("\r\n");

}


void f1(){//angle
  

	if(digitalRead(4)==LOW){
    
		angl--;
  
	}else{
    
		angl++;
  
	}

}


void f2(){//position
  

	if(digitalRead(7)==LOW){
    
		pos++;
  
	}else{
    
		pos--;
  
	}

}

