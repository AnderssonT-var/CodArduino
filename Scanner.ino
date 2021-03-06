#include <Wire.h>


void setup(){ 
  
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);
  Serial.println("\nI2C Escneo ");

}


void loop()
{
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0){
      Serial.print("Dispositivo I2C encontrado en la dirección 0x");
      if (address<16) 
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error==4) {
      Serial.print("Error desconocido en la dirección 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0){
    Serial.println("No se encontraron dispositivos I2C\n");
  }else{
   Serial.println("!!!!!!HECHO\n"); 
  }
  delay(5000);
}
