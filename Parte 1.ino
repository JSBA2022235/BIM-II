/*
Fundacion Kinal
Centro Educativo Tecnico Laboral
Electronica
Grado: Quinto
Seccion: A
Cuerso: Taller de Electronica Digital y Reparacion de
Computadoras I
Nombre: Jose Sebastian Bocaletti Aguilar
Carnet: 2022235
Proyecto: INTERRUPCIONES POR MEDIO DE SOFTWARE
*/
#define btn_rising 2
#define btn_falling 3 
#define a1 4
#define b1 5
#define c1 6
#define d1 7
#define e1 8
#define f1 9
#define g1 10
#define A2 11
#define B2 12
#define C2 13
#define D2 14
#define E2 15
#define F2 16
#define G2 17

void funcion_ISR_rising(void);
void funcion_ISR_falling(void);
int suma_unidad();
int resta_unidad();

int contador();
void display_izq();
void display_der();

volatile static bool f_print = false;
volatile static bool r_print = false;
volatile static byte i = 0;
int unidad = 0;
int decena = 0;
int num = 0;
bool estado;
void setup() {
Serial.begin(19200);
pinMode(btn_rising, INPUT); 
pinMode(btn_falling, INPUT);
attachInterrupt(digitalPinToInterrupt(btn_rising),funcion_ISR_rising,RISING); 
attachInterrupt(digitalPinToInterrupt(btn_falling),funcion_ISR_falling,FALLING); 
pinMode(a1, OUTPUT);
pinMode(b1, OUTPUT);
pinMode(c1, OUTPUT);
pinMode(d1, OUTPUT);
pinMode(e1, OUTPUT);
pinMode(f1, OUTPUT);
pinMode(g1, OUTPUT);
pinMode(A2, OUTPUT);
pinMode(B2, OUTPUT);
pinMode(C2, OUTPUT);
pinMode(D2, OUTPUT);
pinMode(E2, OUTPUT);
pinMode(F2, OUTPUT);
pinMode(G2, OUTPUT);
}
void loop() {
     if( unidad > 50){
      unidad = 0;
      }
      if( unidad < 0){
      unidad = 50;
      }
   display_izq();
   display_der();
  r_print = false;
  f_print = false;
}
void funcion_ISR_rising(){
    suma_unidad();
}
void funcion_ISR_falling(){ 
  resta_unidad();
}
int suma_unidad(){ 
  unidad++;
  Serial.println(unidad);
}
int resta_unidad(){
  unidad--;
  Serial.println(unidad);
  }

 void display_der(){
   if(unidad == 0 ||unidad == 10||unidad == 20||unidad == 30||unidad == 40||unidad == 50){  
      digitalWrite(a1, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, HIGH);
      digitalWrite(e1, HIGH);
      digitalWrite(f1, HIGH);
      digitalWrite(g1, LOW);
   }
   if( unidad == 1||unidad == 11||unidad == 21||unidad == 31||unidad == 41){   
      digitalWrite(a1, LOW);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, LOW);
      digitalWrite(e1, LOW);
      digitalWrite(f1, LOW);
      digitalWrite(g1, LOW);
   }
   if( unidad == 2||unidad == 12||unidad == 22||unidad == 32||unidad == 42){  
      digitalWrite(a1, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, LOW);
      digitalWrite(d1, HIGH);
      digitalWrite(e1, HIGH);
      digitalWrite(f1, LOW);
      digitalWrite(g1, HIGH);
   }
   if( unidad == 3||unidad == 13||unidad == 23||unidad == 33||unidad == 43){  
      digitalWrite(a1, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, HIGH);
      digitalWrite(e1, LOW);
      digitalWrite(f1, LOW);
      digitalWrite(g1, HIGH);
   }
    if( unidad == 4||unidad == 14||unidad == 24||unidad == 34||unidad == 44){ 
      digitalWrite(a1, LOW);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, LOW);
      digitalWrite(e1, LOW);
      digitalWrite(f1, HIGH);
      digitalWrite(g1, HIGH);
   }
   if( unidad == 5||unidad == 15||unidad == 25||unidad == 35||unidad == 45){
      digitalWrite(a1, HIGH);
      digitalWrite(b1, LOW);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, HIGH);
      digitalWrite(e1, LOW);
      digitalWrite(f1, HIGH);
      digitalWrite(g1, HIGH);
   }
   if( unidad == 6||unidad == 16||unidad == 26||unidad == 36||unidad == 46){
      digitalWrite(a1, HIGH);
      digitalWrite(b1, LOW);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, HIGH);
      digitalWrite(e1, HIGH);
      digitalWrite(f1, HIGH);
      digitalWrite(g1, HIGH);
   }
   if( unidad == 7||unidad == 17||unidad == 27||unidad == 37||unidad == 47){
      digitalWrite(a1, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, LOW);
      digitalWrite(e1, LOW);
      digitalWrite(f1, LOW);
      digitalWrite(g1, LOW);
   }
   if( unidad == 8||unidad == 18||unidad == 28||unidad == 38||unidad == 48){
      digitalWrite(a1, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, HIGH);
      digitalWrite(e1, HIGH);
      digitalWrite(f1, HIGH);
      digitalWrite(g1, HIGH);
   }
   if( unidad == 9||unidad == 19||unidad == 29||unidad == 39||unidad == 49){  
      digitalWrite(a1, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(c1, HIGH);
      digitalWrite(d1, HIGH);
      digitalWrite(e1, LOW);
      digitalWrite(f1, HIGH);
      digitalWrite(g1, HIGH);
 }
}
    void display_izq(){ 
   if(unidad == 0 || unidad == 9){
      digitalWrite(A2, HIGH);
      digitalWrite(B2, HIGH);
      digitalWrite(C2, HIGH);
      digitalWrite(D2, HIGH);
      digitalWrite(E2, HIGH);
      digitalWrite(F2, HIGH);
      digitalWrite(G2, LOW);
    }
      if(unidad == 10 || unidad == 19){
      digitalWrite(A2, LOW);
      digitalWrite(B2, HIGH);
      digitalWrite(C2, HIGH);
      digitalWrite(D2, LOW);
      digitalWrite(E2, LOW);
      digitalWrite(F2, LOW);
      digitalWrite(G2, LOW);
    }
    if(unidad == 20 || unidad == 29){
      digitalWrite(A2, HIGH);
      digitalWrite(B2, HIGH);
      digitalWrite(C2, LOW);
      digitalWrite(D2, HIGH);
      digitalWrite(E2, HIGH);
      digitalWrite(F2, LOW);
      digitalWrite(G2, HIGH);
    }
    if(unidad == 30 || unidad == 39){
      digitalWrite(A2, HIGH);
      digitalWrite(B2, HIGH);
      digitalWrite(C2, HIGH);
      digitalWrite(D2, HIGH);
      digitalWrite(E2, LOW);
      digitalWrite(F2, LOW);
      digitalWrite(G2, HIGH);
    }
    if(unidad == 40 || unidad == 49){
      digitalWrite(A2, LOW);
      digitalWrite(B2, HIGH);
      digitalWrite(C2, HIGH);
      digitalWrite(D2, LOW);
      digitalWrite(E2, LOW);
      digitalWrite(F2, HIGH);
      digitalWrite(G2, HIGH);
    }
    if(unidad == 50){
      digitalWrite(A2, HIGH);
      digitalWrite(B2, LOW);
      digitalWrite(C2, HIGH);
      digitalWrite(D2, HIGH);
      digitalWrite(E2, LOW);
      digitalWrite(F2, HIGH);
      digitalWrite(G2, HIGH);
 }
}
