/*
 * UART_Driver.c
 *
 * Created: 5/7/2020 6:24:23 AM
 * Author : Lina
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <avr/delay.h>

int main(void)
{       DDRA|=(1<<0);
		Init_UART();
    /* Replace with your application code */
	/* Test Driver when receive char  apply led functionality */
    while (1) 
    {    
		/*  unsigned char CMD =UART_Recive();
		  if (CMD =='f')
		  {
			  PORTA|=(1<<0);
			  _delay_ms(1000);
		  }
		  else if (CMD== 'r'){
			  PORTA^=(1<<0);
			  _delay_ms(1000);
		  }*/
		
		 // UART_TransmitteString(" HEllo UART module \n \r");
          //_delay_ms(1000);
		  UART_TransmitteChar('t');
		    _delay_ms(1000);
    }
}
