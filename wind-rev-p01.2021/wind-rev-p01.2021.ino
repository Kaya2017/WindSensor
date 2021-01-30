/* 
* Ground     Ground
* +10-12V      Vin
* Out          A0
* TMP          A2
*/

const int OutPin  = A0;   // wind sensor analog pin  hooked up to Wind P sensor "OUT" pin
const int TempPin = A2;   // temp sesnsor analog pin hooked up to Wind P sensor "TMP" pin


void setup() {
    Serial.begin(9600);
}

void loop() {

   
    int windADunits = analogRead(OutPin);
    Serial.print("RW ");   // print raw A/D for debug
    Serial.print(windADunits);
    Serial.print("\t");
    
    
    float windMPH =  pow((((float)windADunits - 264.0) / 85.6814), 3.36814);
    Serial.print(windMPH*1609);
    Serial.print(" m/h");
    Serial.print("        ");

  
    int tempRawAD = analogRead(TempPin);  
    Serial.print("RT ");    // print raw A/D for debug
    Serial.print(tempRawAD);
    Serial.print("\t");
       
    
    float tempC = ((((float)tempRawAD * 5.0) / 1024.0) - 0.400) / .0195; 
    Serial.print(tempC);
    Serial.println(" C");
    delay(1000);
    
}
