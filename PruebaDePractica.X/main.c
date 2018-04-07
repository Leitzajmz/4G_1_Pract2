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
    }
}
