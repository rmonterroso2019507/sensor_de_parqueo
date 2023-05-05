



/*
 * 
 Fundacion Kinal
 Centro Educativo Tecnico Laboral KINAL
 Electronica
 Grado:5to A
 Nombre:Roberto Monterroso
 Carne :2019507
 */
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define trigger A2
#define echo A3
#define buzzer A0
int a;
int distancia;
int Fre=260;
long tiempo;
LiquidCrystal_I2C LCD_Roberto(direccion_lcd, columnas, filas);
byte bloque[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};
void setup()
{
Serial.begin(9600);
for(int i=2; i<=11;i++){
pinMode(i, OUTPUT);
}
  pinMode(buzzer ,OUTPUT);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  LCD_Roberto.init();
  LCD_Roberto.backlight();
  LCD_Roberto.createChar(1, bloque);
}
void loop()
{
  Serial.println(a);
  medicion();
  distancia = a;
  alerta();
}
int medicion(){
 
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigger, LOW);
  tiempo = pulseIn(echo, HIGH);
  a = tiempo/59;
  delay(50);
  return a;
}
void alerta(){
    if (distancia > 21 && distancia <= 50) {
    LCD_Roberto.setCursor(0,0);
    LCD_Roberto.print("                ");
    LCD_Roberto.setCursor(0,0);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.setCursor(7,0);
    LCD_Roberto.print("50");
    LCD_Roberto.setCursor(13,0);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.setCursor(0,1);
    LCD_Roberto.print("     libre   ");
    tone(buzzer, Fre, 260);
    delay(500);
    noTone(buzzer);
  }

  
    if (distancia > 11 && distancia <= 30) {
    LCD_Roberto.setCursor(0,0);
    LCD_Roberto.print("                ");
    LCD_Roberto.setCursor(0,0);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.setCursor(7,0);
    LCD_Roberto.print("30");
    LCD_Roberto.setCursor(11,0);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.setCursor(0,1);
    LCD_Roberto.print("    cuidado");
    tone(buzzer, Fre, 1000);
    delay(500);
    noTone(buzzer);
  }
    if (distancia > 0 && distancia <= 10) {
    LCD_Roberto.setCursor(0,0);
    LCD_Roberto.print("                ");
    LCD_Roberto.setCursor(0,0);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.setCursor(7,0);
    LCD_Roberto.print("10");
    LCD_Roberto.setCursor(9,0);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.write(1);
    LCD_Roberto.setCursor(0,1);
    LCD_Roberto.print("      alto         ");
    tone(buzzer, Fre, 4000);
    delay(500);
    noTone(buzzer);
  }
  }
  
 
