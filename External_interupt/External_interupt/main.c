/*
 * External_interupt.c
 *
 * Created: 5/4/2020 1:54:46 AM
 * Author : Lina
 */ 

#include <avr/io.h>
#include "avr/interrupt.h"
#include <util/delay.h>
#define F_CPU 1600000

#define Toggel_LED()         PORTC^=(1<<7)

volatile unsigned char flag =0;

void external_init();

int main(void)
{   
	DDRC|=(1<<7);
	DDRD|=(1<<3);
	external_init();
    /* Replace with your application code */
    while (1) 
    {   
		PORTD|=(1<<3);
		if(flag==1)
		{
			Toggel_LED();
			// clear interrupt 
			GICR=(1<<INT0);
			flag =0;
			_delay_ms(100);
		}
    }
}
void external_init(){
	MCUCR= (1<<ISC01)|(1<<ISC00);  // sense control
	GICR=(1<<INT0);   // enable for INTO 
	sei();
}
ISR(INT0_vect){
flag =1;
_delay_ms(1000);
}

