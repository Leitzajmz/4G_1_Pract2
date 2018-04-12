#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
#use fast_io(e)

#define SUMA 0x01
#define RESTA 0x02
#define MULTI 0X03
#define DIVISION 0X04
//#define __DEBUG_SERIAL__ //Si comentas esta linea se deshabilita el debug por serial y el PIN_C6 puede ser usado en forma digital I/O

#ifdef __DEBUG_SERIAL__
   #define TX_232        PIN_C6
   #use RS232(BAUD=9600, XMIT=TX_232, BITS=8,PARITY=N, STOP=1)
   #use fast_io(c)
#endif

void main (void){
   setup_oscillator(OSC_16MHZ);
#ifdef __DEBUG_SERIAL__ //Deberiamos de proteger nuestras depuraciones de esta forma o usar una macro ya protegida.
   printf("Hola Mundo\n");//Puedes usar putc o printf. Revisa la documentación de CCS para ver que mas puedes hacer.
#endif
   int opcion = 0x00;
   while(1){
      if(input(PIN_B4)== 0x01){
         opcion = 0x01;
      }
      else if (input(PIN_B5) == 0x01){
         opcion = 0x02;
      }
      else if (input(PIN_B6) == 0x01){
         opcion = 0x03;
      } 
      else if (input(PIN_B7) == 0x01){
         opcion = 0x04;
      } 
      
   }
}	
