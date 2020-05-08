/*
 * UART_CFG.h
 *
 * Created: 5/7/2020 11:09:08 PM
 *  Author: Lina
 */ 


#ifndef UART_CFG_H_
#define UART_CFG_H_

#include  "STD_TYPES.h"

#define NUMBER_OFUART_MODULE 1

typedef enum {
	NoParity ,
	Even_Parity,
	Odd_parity
}Parity_Mode;

typedef enum {
	 syncronus,
	 As_syncronus,
  } syncronization_mode;

typedef enum {
	 stopBit_1,
	 StopBit_2
	}Stop_Bits;

typedef enum {
	  Bits_5,
	  Bits_6,
	  Bits_7,
	  Bits_8,
	  Bits_9,
	}Frame_Size;

typedef enum {
	Normal_Mode,
	Double_Speed
	}operation_Mode;
	
 typedef struct {
	 
	 Parity_Mode           parity_cfg;
	 Frame_Size            size_cfg;
	 Stop_Bits             stopBit_cfg;
 }UART_cfg;
 
extern const UART_cfg   UART_config[];

#endif /* UART_CFG_H_ */