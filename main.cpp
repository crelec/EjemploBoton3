#include "mbed.h"

int volatile contador=0;

DigitalOut myled1(PA_10);//D2 = MSB
DigitalOut myled2(PB_5);//D4 
DigitalOut myled3(PB_4);//D5
DigitalOut myled4(PB_10);//D6 = LSB

InterruptIn myBoton(PC_13); //Uso pin PC_13 Boton tarjeta  
//InterruptIn myBoton(PB_3,PullUp);  // Uso otro pin PB_3=D3 con PullUp 
//InterruptIn myBoton(PB_3);  // Uso otro pin PB_3=D3 sin PullUp

void Funcion_interrupcion(){
    myled4 = (contador & 0x01);
    myled3 = (contador & 0x02)>>1;
    myled2 = (contador & 0x04)>>2;
    contador++;
}

int main()
{
 myBoton.fall(&Funcion_interrupcion);

    while(1) {
        myled1 = !myled1;
        ThisThread::sleep_for(500ms);
    }
}

