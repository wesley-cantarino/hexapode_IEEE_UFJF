// portas usadas
//OE - GND
//SLC - D1
//SDA - D2
//VVC - 3V3
// INCLUSÃO DE BIBLIOTECAS
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#define Frequencia 50 // VALOR DA FREQUENCIA DO SERVO 

// INSTANCIANDO OBJETOS
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// DECLARAÇÃO DE FUNÇÕES
void writeServos(int posicao, int tempo);

void setup() {

  Serial.begin(115200);
  
  pwm.begin(); // INICIA O OBJETO PWM
  pwm.setPWMFreq(Frequencia); // DEFINE A FREQUENCIA DE TRABALHO DO SERVO
  delay(300);
}

void loop() {
     int valor = analogRead(A0);
     //Serial.println(valor);

     //writeServos(1, map(valor, 0, 1024, 0, 180));


    
     if(Serial.available() > 0)
     {
      int inByte = Serial.read();
      Serial.print(inByte, DEC);

      if(inByte == '0'){
        writeServos(0, map(valor, 0, 1024, 0, 180));
      }

      if(inByte == '1'){
        writeServos(1, map(valor, 0, 1024, 0, 180));
      }

      if(inByte == '2'){
        writeServos(2, map(valor, 0, 1024, 0, 180));
      }
      
     }
}
// IMPLEMENTO DE FUNÇÕES

void exemplo_motor (){
      writeServos(0, 10);
      delay(1000);
      writeServos(1, 10);
      delay(1000);
       writeServos(0, 50);
      delay(1000);
      writeServos(1, 100);
      delay(1000);
      writeServos(0, 100);
      delay(1000);
      writeServos(1, 150);
      delay(1000);
}

void writeServos(int nServo, int posicao) {
#define SERVOMIN  205 // VALOR PARA UM PULSO MAIOR QUE 1 mS/// testar isso
#define SERVOMAX  409 // VALOR PARA UM PULSO MENOR QUE 2 mS/// testar isso

  int pos = map ( posicao , 0 , 180 , SERVOMIN, SERVOMAX);
  pwm.setPWM(nServo , 0, pos);

}
