int a;

bool b;


void setup() {
  

// put your setup code here, to run once:
  

	/*Serial.begin(115200);
  
	while(!Serial){
    
		;
  
	}*/
  

	pinMode(A0,INPUT_PULLUP);
  
	a=0;
  
	b=true;


}



void loop() {
  

// put your main code here, to run repeatedly:
  

	while(b){
    
		a=analogRead(A0);
    
		if(a<=900){
      
			analogWrite(6,0);
      
			analogWrite(5,85);
      
			delay(230);
      
			analogWrite(5,0);
      
			b=false;
    
		}else{
      
			analogWrite(6,85);
    
		}
  
	}


}
