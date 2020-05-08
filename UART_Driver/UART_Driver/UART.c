/*
 * UART.c
 *
 * Created: 5/7/2020 11:39:14 PM
 *  Author: Lina
 */ 
#include <avr/io.h>

#include "Bit_Math.h"
#include "UART_CFG.h"
#include "UART.h"


/* inti UART module */

void Init_UART(void)
 {   uint8 counter ;
	  UBRRL = 103;
	 for (counter= 0; counter<NUMBER_OFUART_MODULE ;counter++)
	 {
	   if ((UART_config[NUMBER_OFUART_MODULE].parity_cfg==NoParity) &&(UART_config[NUMBER_OFUART_MODULE].size_cfg==Bits_8) && (UART_config[NUMBER_OFUART_MODULE].stopBit_cfg==stopBit_1))             
		 {
		 //8 bit char size, 1 stop_BIT , NO parity
		 UCSRC = (1<<URSEL)|(1<<UCSZ1)|(1<<UCSZ0);
		 // enable full duplex
		 UCSRB =(1<<TXEN)|(1<<RXEN);  //transmitte and reciver
	   } 
 } 
 	 // ENABLE FULL DEPLUX TRANSMIITER
 	 Set_Bit(UCSRB,3); // ENABLR TX
 	 Set_Bit(UCSRB,4)  ;// ENABLE RX
}
/* send char bu UART module */
void UART_TransmitteChar( uint8 data )
 {    
	   while(!(UCSRA&(1<<UDRE)));
		UDR = data;
}
/* Receive by UART module */
uint8 UART_Recive(void)
{
	 while(!(UCSRA&(1<<RXC)));
	 return UDR;
}
/* send string of char bu UART_module*/
void UART_TransmitteString(uint8 *s)
{
	 uint8 i=0;
	while (s[i]!='/0'){
	UART_TransmitteChar(s[i]);
	i++;
	}// end while
}
