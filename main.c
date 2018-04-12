#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)
#use fast_io(a)
#use fast_io(b)
#use fast_io(c)
#use fast_io(d)
#use fast_io(e)

<<<<<<< HEAD
#define SUMA 0x01
#define RESTA 0x02
#define MULTI 0X03
#define DIVISION 0X04
=======
>>>>>>> 256bcdc5616b037e7f60038e26ef40d022a470ca
//#define __DEBUG_SERIAL__ //Si comentas esta linea se deshabilita el debug por serial y el PIN_C6 puede ser usado en forma digital I/O

#ifdef __DEBUG_SERIAL__
   #define TX_232        PIN_C6
   #use RS232(BAUD=9600, XMIT=TX_232, BITS=8,PARITY=N, STOP=1)
   #use fast_io(c)
#endif

void rutinaDeError();
void main (void){
   setup_oscillator(OSC_16MHZ);
#ifdef __DEBUG_SERIAL__ //Deberiamos de proteger nuestras depuraciones de esta forma o usar una macro ya protegida.
   printf("Hola Mundo\n");//Puedes usar putc o printf. Revisa la documentación de CCS para ver que mas puedes hacer.
#endif
<<<<<<< HEAD
   int opcion = 0x00;
=======
   set_tris_a(0xC0);
   set_tris_b(0xF0);
   set_tris_c(0xFF);
   set_tris_d(0xFF);
   set_tris_e(0x08);
   int opcion;
>>>>>>> 256bcdc5616b037e7f60038e26ef40d022a470ca
   signed long resultado = 0x00;
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
      
      switch(opcion){
         case 0x01:
            resultado = (long)input_c() + (long)input_d();
            opcion = 0x00;
            break;
         case RESTA:
            resultado = (long)input_c() - (long)input_d();
            opcion = 0x00;
            break; 
         case MULTI: 
            resultado = (long)input_c() * (long)input_d();
            if (resultado > 0x1FFF){
               rutinaDeError();
               opcion = 0x00;
               break;
            }
            else
               opcion = 0x00;
               break;
         case DIVISION:
            if((long)input_d() == 0){
               rutinaDeError();
               opcion = 0x00;
               break;
            }
            else{
               resultado = (long)input_c() / (long)input_d();
               opcion = 0x00;
               break;
           }
       }
      
       output_a(resultado);
       output_b(resultado >> 6 );
       output_e(resultado >> 10);
   }
}	
void rutinaDeError(){
    for(int i = 0 ; i < 5 ; i++){
        output_a(0xFF);
        output_b(0x0F);
        output_e(0x07);
        delay_ms(150);
        output_a(0x00);
        output_b(0x00);
        output_e(0x00);
        delay_ms(150);
    }
}

