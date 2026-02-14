#include <Wire.h>

#include <Servo.h>


Servo SV7;
Servo SV8;
Servo SV9;

//----Servo manos-----
#define Psv7 3
#define Psv8 5
//----servo puerta---
#define Psv9 6





int Pm = 500;  // pulso min en us
int Px = 2500;  // pulso max en us
int Es;
int x = 1;
int y = 1;
int z;
int a;
int b;
int c;
int d;
int e;
int f;
void setup() {

  Wire.begin(1);
  Wire.onReceive(receiveEvent);

  Serial.begin(9600);

  SV7.attach(Psv7,Pm,Px);  
  SV8.attach(Psv8,Pm,Px);
  SV9.attach(Psv9,Pm,Px);
}

void loop() {

}
void receiveEvent(){

  while (Wire.available()){

    Es = Wire.read();
    Serial.print("|");
    Serial.print(Es);
    Serial.print("|");

    //----------------------------Condicion para manos ----------------------------------
    /*if (Es == 1) {
      SV7.write(90);
      delay(20);
      Serial.println("----SM7---encendido");
    }
    else if (Es == 4) {
      SV7.write(0);
      delay(20);
      Serial.println("----SM7---apagado");
    }
    else if (Es == 2) {
      SV8.write(90);
      delay(20);
      Serial.println("----SM8---encendido");
    }
    else if (Es == 5) {
      SV8.write(0);
      delay(20);
      Serial.println("----SM8---apagado");
    }
    //-----------------------------------Condicion para puerta---------------------------
    else if (Es == 3) {
      SV9.write(90);
      delay(20);
      Serial.println("----SM9---encendido");
    }
    else if (Es == 6) {
      SV9.write(0);
      delay(20);
      Serial.println("----SM9---apagado");
    }*/
    switch (Es) {
      case 1:
        SV7.write(90);
        delay(20);
        Serial.println("----SM7---encendido");
        break;
      case 2:
        SV8.write(90);
        delay(20);
        Serial.println("----SM8---encendido");
        break;
      case 3:
        SV9.write(180);
        delay(20);
        Serial.println("----SM9---encendido");
        break;
      case 4:
        SV7.write(0);
        delay(20);
        Serial.println("----SM7---apagado");
        break;
      case 5:
        SV8.write(0);
        delay(20);
        Serial.println("----SM8---apagado");
       break;
      case 6:
        SV9.write(0);
        delay(20);
        Serial.println("----SM9---apagado");
        break;
       
        
}



    /*x = x + 1;
    if (x == 3){
      x =1;
    }
    Serial.print("(");
    Serial.print(x);
    Serial.print(")");
    if (Es >= 150){
      
    }
    else if (Es > 100) {

    }
    else if (Es > 50) {
      y = y + 1;
      if (y == 99){
        y = 1;
      }
      if (y % 2 == 0){
        c = map(Es, 50, 100, 0, 180);
        SV3.write(c);
        //Serial.println(c);
      }
      else {
        d = map(Es, 50, 100, 0, 180);
        //Serial.println(d);
        SV4.write(d);
      }

    }
    else if (Es >= 0) {
      
      if (x % 2 == 0){
        a = map(Es, 0, 50, 0, 180);
        Serial.print("--");
        SV3.write(a);
        Serial.print(a);
        Serial.print("-");
      }
      else {
        b = map(Es, 0, 50, 0, 180);
        Serial.print("--");
        Serial.print(b);
        Serial.println("-");
        SV4.write(b);
      }
      
    }*/
  }

}
