#include <Wire.h>

#include <Servo.h>

//---------------servomotor------------------------------
Servo SV1;
Servo SV2;

Servo SV3;
Servo SV4;

Servo SV5;
Servo SV6;

#define Psv1 10
#define Psv2 11

#define Psv3 3
#define Psv4 5

#define Psv5 6
#define Psv6 9

//-----------------motor----------------------------

#define STB 12  //antes pin 6    

// Motor A

//#define pwmA 3
#define in1A 4 // antes pin 5
#define in2A 2

//  Motor B


//#define pwmB 9
#define in1B 7
#define in2B 8

//--------------------Joystick -------------------------------

//--motores--
#define VRx1 A0   
#define VRy1 A1
//--servos--
#define VRx2 A2
#define VRy2 A3

//--------------------Inicialisacion-------------------
int X;          // variable para leer VRx1
int Y;          // variable para leer VRy1

int A;          // variable para leer VRx2
int B;          // variable para leer VRy2

int C;          // variable para leer VRy3      
int D;          // variable para leer VRy3

int E;          // variable para leer VRy4
int F;          // variable para leer VRy4

int Pm = 500;  // pulso min en us
int Px = 2500;  // pulso max en us

int m;          // valor del angulo del primer servomotor
int n;          // valor del angulo del segundo servomotor
int g;          // valor del angulo del tercer servomotor
int h;          // valor del angulo del cuarto servomotor
int j;          // valor del angulo del quinto servomotor
int k;          // valor del angulo del sexto servomotor

bool del = false;
//_______________________________INICIO_______________________________________________

void setup(){
  //-------------------libreria wire - master---------------------
  Wire.begin();
  //-------------------Comunicacion serie----------------
  Serial.begin(9600); 
  /*--------------------joystick-------------------------
  //--motores reductor--
  pinMode(VRx1,INPUT);
  pinMode(VRy1,INPUT);
  //--servo motores--
  pinMode(VRx2,INPUT);
  pinMode(VRy2,INPUT);
  */

  //---------------------Motores recuctores-------------------------------
  //pinMode(pwmA, OUTPUT);
 // pinMode(pwmB, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);
  pinMode(STB, OUTPUT);
  //analogWrite(pwmA, 255);
 // analogWrite(pwmB, 255);
  //------------------------Servo motores-------------------------------------
  SV1.attach(Psv1,Pm,Px);  
  SV2.attach(Psv2,Pm,Px);

  SV3.attach(Psv3,Pm,Px);  
  SV4.attach(Psv4,Pm,Px);

  SV5.attach(Psv5,Pm,Px);  
  SV6.attach(Psv6,Pm,Px);

}
//________________________________________LOOP___________________________________

void loop(){ 
  //------------Lectura de joystck para el control de motores reductores-----------
  //X = analogRead(VRx1);
  //Y = analogRead(VRy1);
  /*Serial.print(X);
  Serial.print(" ____ ");
  Serial.println(Y);
  delay(200);*/
  //------------Lectura de joystick para el control de servomotores---------------
  //A = analogRead(VRx2);
  //B = analogRead(VRy2);
  /*Serial.print(A);
  Serial.print(" ------ ");
  Serial.println(B);
  delay(200);*/
  //------------------control de servomotores--------------------------------------
  if (Serial.available()){

    String l = Serial.readStringUntil('S');         // leemos datos por bluetooth

    
    //----------------------------Condicion para los motores reductores---------------------

    if (l[0] == 'A') {
      //delay(200);
      Serial.println(l);
      X = (l[2] - '0')*100 + (l[3] - '0')*10 +(l[4] - '0');
      Y = (l[6] - '0')*100 + (l[7] - '0')*10 +(l[8] - '0');
      Serial.println(X);
      Serial.println(Y);

      if (Y >= 270) {
        digitalWrite(STB,HIGH);
        forward_A();
        forward_B();
        if (X >= 270){
          back_B();
          forward_A();
        }
        else if(X >= 230) {
          forward_A();
          forward_B();
        }
        else if(X >= 100){
          back_A();
          forward_B();
        }
        else {}
        
      
      }
      else if(Y >= 230) {
        digitalWrite(STB,LOW);
      }
      else if (Y >= 100){
        
        digitalWrite(STB,HIGH);
        back_A();
        back_B();
        if (X >= 270){
          back_A();
          forward_B();
        }
        else if(X >= 230) {
          back_A();
          back_B();
        }
        else if(X >= 100){
          back_B();
          forward_A();
        }
        else {} 
        
      }
      else {}
    }

    //---------------------------Condicion para los servomotores de la cabeza-----------------------------
    else if (l[0] == 'B'){                               
      //Serial.println(l);
      A = (l[2] - '0')*100 + (l[3] - '0')*10 +(l[4] - '0');
      B = (l[6] - '0')*100 + (l[7] - '0')*10 +(l[8] - '0');
      if (A >= 0 && B >= 0 ){
        //Serial.println(prueva);
        m = map(A, 400, 580, 0, 90);         // servo derecha izquierda pin 10
        n = map(B, 400, 580, 35, 105);      // servo arriba abajo pin 11     
        SV2.write(n);
        SV1.write(m);
        delay(20);
        
      }
   
    }
    //---------------------------Condicion para los servomotores del brazo izquierdo-----------------------------
    /*else if (l[0] == 'C') {
      Serial.println(l);
      
      C = (l[2] - '0')*100 + (l[3] - '0')*10 +(l[4] - '0');
      D = (l[6] - '0')*100 + (l[7] - '0')*10 +(l[8] - '0');
      Serial.println(C);
      Serial.println(D);
      g = map(C, 600, 780, 0, 50);
      h = map(D, 600, 780, 0, 50);
      if (C >= 0 && D >=0 && C >= 0 && D >=0) {
        Wire.beginTransmission(1);
        Wire.write(g);
        Wire.write(h);
        //Serial.println(g);
        //Serial.println(h);
        Wire.endTransmission();
        
      }
      /*if (C >= 0 ){
        //Serial.println(prueva);
        g = map(C, 400, 580, 0, 180);
        //Serial.println(m);
        SV1.write(g);
        delay(10);
      }
      if (D >= 0) {
        h = map(D, 400, 580, 0, 180);
        SV2.write(h);
        delay(10);
      }
    
    }*/
    else if (l[0] == 'C') {
      //Serial.println(l);
      C = (l[2] - '0')*100 + (l[3] - '0')*10 +(l[4] - '0');
      D = (l[6] - '0')*100 + (l[7] - '0')*10 +(l[8] - '0');
      if (C >= 0 && D >= 0 ){
        //Serial.println(prueva);
        g = map(C, 600, 780, 0, 180);        
        h = map(D, 600, 780, 0, 180);         
        SV4.write(g);
        SV3.write(h);
        delay(20);
        
      }

    }
    //---------------------------Condicion para los servomotores del brazo derecho----------------------
    else if (l[0] == 'D'){                               
      //Serial.println(l);
      E = (l[2] - '0')*100 + (l[3] - '0')*10 +(l[4] - '0');
      F = (l[6] - '0')*100 + (l[7] - '0')*10 +(l[8] - '0');
      if (E >= 0 && F >= 0 ){
        //Serial.println(prueva);
        j = map(E, 800, 980, 0, 180);         
        k = map(F, 800, 980, 0, 180);         
        SV5.write(j);
        SV6.write(k);
        delay(20);
        
      }
   
    }
    //----------------------------Condicion para manos ----------------------------------
    //char Bot = Serial.read();
    //Serial.println(Bot);

    else if (l[0] == 'M') {
      Serial.print(l);
      Serial.println(l[1]);
      Wire.beginTransmission(1);
      Wire.write(1);
      Wire.endTransmission();
    }
    else if (l[0] == 'm') {
      Wire.beginTransmission(1);
      Wire.write(4);
      Wire.endTransmission();
    }
    else if (l[0] == 'Q') {
      Wire.beginTransmission(1);
      Wire.write(2);
      Wire.endTransmission();
    }
    else if (l[0] == 'q') {
      Wire.beginTransmission(1);
      Wire.write(5);
      Wire.endTransmission();
    }
    //-----------------------------------Condicion para puerta-----------------------------------
    else if (l[0] == 'W') {
      Wire.beginTransmission(1);
      Wire.write(3);
      Wire.endTransmission();
    }
    else if (l[0] == 'w') {
      Wire.beginTransmission(1);
      Wire.write(6);
      Wire.endTransmission();
    }
    
  }

//-----------------------control de motores reductores--------------------------

  
}
  
  
//--------------------------FUNCIONES------------------------


//----------------------------------MOTOR-------------------------------

void forward_A(){
digitalWrite(in1A, HIGH);
digitalWrite(in2A, LOW);
}

void forward_B(){
digitalWrite(in1B, LOW);
digitalWrite(in2B, HIGH);
}

void back_A(){
digitalWrite(in1A, LOW);
digitalWrite(in2A, HIGH);
}
void back_B(){
digitalWrite(in1B, HIGH);
digitalWrite(in2B, LOW);
}

void search(){
digitalWrite(in1A, LOW);
digitalWrite(in2A, HIGH);

digitalWrite(in1B, LOW);
digitalWrite(in2B, HIGH);
}



