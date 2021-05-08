#include <Servo.h>
Servo servoMotor;
const int TMP36 = A0;
const int dc_motor = 2;
const int ldr = A2;
const int servo = 3;
int Temperatura = 0;
int ldr_deger =0;

void setup()
{
  servoMotor.attach(3);
  Serial.begin(9600);
  pinMode(TMP36, INPUT);
  pinMode(dc_motor, OUTPUT);
}

void loop()
{
  //sıcaklık_dcmotor//
  Temperatura = -40 + 0.488155 * (analogRead(TMP36) - 20);
  if (Temperatura >= 25) {
    digitalWrite(dc_motor, HIGH);
  }
  if (Temperatura <= 20) {
    digitalWrite(dc_motor, LOW);
  }
  delay(150); 
  //LDR_Servo//
  
  ldr_deger= analogRead(ldr);
  
  Serial.println(ldr_deger);
  if (ldr_deger < 1000)
  {
    servoMotor.write(0);
  }else if (ldr_deger > 500){
    servoMotor.write(180);
  }
  delay(150);
  
  
  
  
  
  
  
  
  
}
