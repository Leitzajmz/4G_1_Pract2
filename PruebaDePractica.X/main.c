/* 
 * File:   Calculadora 8 bits
 * Author: Equipo 1 4G
 *
 * Created on 27 de marzo de 2018, 07:36 PM
 */

#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)

void rutinaDeError();

void main (void){
   setup_oscillator(OSC_16MHZ);
   set_tris_a(0x00);
   set_tris_b(0xF0);
   set_tris_c(0xFF);
   set_tris_d(0xFF);
   set_tris_e(0x00);
   
   unsigned int resultado = 0x00, opcion, complemento1;

   while(1){
      opcion = (long)input_b();
         switch(opcion){
            case 0x10: //Suma
               resultado = (long)input_c() + (long)input_d();
               break;
            case 0x20://Resta
               if ((long)input_d() > (long)input_c()){
                 complemento1 = ~(long)input_d();
                 resultado = complemento1;
                 /*complemento1 += 1; 
                  resultado = (long)input_c() + complemento1;*/
               }
               else{
                  resultado = (long)input_c() - (long)input_d();
               }
               break; 
            case 0x40: //Multiplicacion
               resultado = (long)input_c() * (long)input_d();
               break;
            case 0x80: //Division
                if((long)input_d() == 0)
                    rutinaDeError();
                else
                   resultado = (long)input_c() / (long)input_d();
               break;
       }
            output_a(resultado & 0x3F);
            output_b(resultado & 0x3C0);
            output_e(resultado & 0x1C00);      
   }
}

void rutinaDeError(){
    for (int i = 0 ; i < 5 ; i++){
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
