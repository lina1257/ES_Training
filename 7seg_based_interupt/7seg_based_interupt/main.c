/*
 * 7seg_based_interupt.c
 *
 * Created: 5/5/2020 1:07:46 AM
 * Author : Lina
 */ 

#include <avr/io.h>
#include "STD_TYPES.h"
#include <avr/interrupt.h>
#include <avr/delay.h>
#define F_CPU   1600000

#define E1                         1
#define E2                         2
#define  seven_segment_Direction   DDRA
#define Enable_Pins_DIR            DDRB
#define Highr_Nibble               0xf0
#define Enable_Pins_output         PORTB
#define seven_segmant_Dispaly      PORTA

void  INT0_init();
 uint8 count =0;
  volatile uint8 falg=0;
int main(void)
{
 // configure high nibble to output
 seven_segment_Direction|=Highr_Nibble;
 //configure Enable pin Direction  E1,E2
 Enable_Pins_DIR|=(1<<E1)|(1<<E2);
 //configure Enable pin Output  E1,E2
   
    while (1) 
    {   
	    INT0_init();
		Enable_Pins_output|=(1<<E1)|(1<<E2);
		uint8 seve_segment_arr[]={0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90};
		if(falg==1){
			seven_segmant_Dispaly=seve_segment_arr[count];
			_delay_ms(1000);
			falg=0;
			//clear interrupt
			cli();
		   }
    }
}
void  INT0_init()
{
	//  configure interrupt at Rising Edge 
	MCUCR=(1<<ISC10)|(1<<ISC00);
	// Enable  external interrupt INT0 
	GICR|=(1<<INT0);
	// Enable Global interrupt 
	sei();
}
ISR(INT0_vect)
{  	
	
	falg=1;
	if(count<9)
	{count++;}
		
	else{count=0;}
    _delay_ms(1000);
}
