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
#include <Ticker.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>

#define push 3

volatile static bool estado;
float temperatura;

void ISR_temp(void);
void ISR_deteccion_push(void);

Ticker isr_conseguir_temperatura(ISR_temp, 3000);
Ticker isr_valor_boton(ISR_deteccion_push, 6000);
OneWire ourWire(5);
DallasTemperature sensor(&ourWire);

void setup() {
Serial.begin(9600);
isr_conseguir_temperatura.start();
isr_valor_boton.start();
sensor.begin(); 
}
void loop() {
  isr_conseguir_temperatura.update();
  isr_valor_boton.update();
}
void medicion(){
  sensor.requestTemperatures();
  float temp = sensor.getTempCByIndex(0);
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.println("C");
  }
void ISR_temp(){
   medicion(); 
}
void ISR_deteccion_push(){
  bool estado_push = digitalRead(push);
  if(estado_push == 1){
  Serial.println("push activo");
}
if(estado_push == 0){
  Serial.println("push inactivo");
}}
