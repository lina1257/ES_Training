/*
 * UART.h
 *
 * Created: 5/7/2020 11:39:36 PM
 *  Author: Lina
 */ 


#ifndef UART_H_
#define UART_H_
#include "STD_TYPES.h"

/* inti UART module */
void Init_UART(void);
/* send char bu UART module */
void UART_TransmitteChar( uint8 data );
/* Receive by UART module */
uint8 UART_Recive(void);
/* send string of char bu UART_module*/
void UART_TransmitteString(uint8 *s);
#endif /* UART_H_ */