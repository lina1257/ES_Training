/*
 * 7segment.c
 *
 * Created: 5/4/2020 11:32:22 PM
 * Author : Lina
 */ 

#include <avr/io.h>
#include "STD_TYPES.h"
#include <util/delay.h>

#define E1                         1
#define E2                         2
#define  seven_segment_Direction   DDRA
#define Enable_Pins_DIR            DDRB
#define Highr_Nibble               0xf0
#define Enable_Pins_output         PORTB
#define seven_segmant_Dispaly      PORTA
#define FOR_LOOP_Programe          1
#define Switch_CASE_Progrma        2
#define Config_paramter           FOR_LOOP_Programe
#define F_CPU   1600000
/*** programe print number from  to 9 at 7 segemnt ********/
int main(void)
{   // configure high nibble to output
	seven_segment_Direction|=Highr_Nibble;
	//configure Enable pin Direction  E1,E2
	Enable_Pins_DIR|=(1<<E1)|(1<<E2);
	//configure Enable pin Output  E1,E2
    uint8 count =0;
	
    while (1) 
    {   
		Enable_Pins_output|=(1<<E1)|(1<<E2);
		#if   Config_paramter   == FOR_LOOP_Programe
		 uint8 seve_segment_arr[]={0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90};
	     for (count=0 ;count<10;count++ )
		 {
		   seven_segmant_Dispaly=seve_segment_arr[count];
		   _delay_ms(10000);
		 }
		 
		#elif  Config_paramter   == Switch_CASE_Progrma
		
		switch(count)
		{
		case 0 :
		    seven_segmant_Dispaly =0x00;
			_delay_ms(10000);
			count=1;
			 break;
		case 1  :
		    seven_segmant_Dispaly=0x10;
		    _delay_ms(10000);
		     count=2;
		     break;
		case 2  :
		    seven_segmant_Dispaly=0x20;
		    _delay_ms(10000);
		    count=3;
		      break;
		case 3  :
		   seven_segmant_Dispaly=0x30;
		   _delay_ms(10000);
		    count=4;
		      break;
		 case 4 :
		    seven_segmant_Dispaly=0x40;
		    _delay_ms(10000);
		    count=5;
		    break;
			
		case 5 :
		     seven_segmant_Dispaly=0x50;
		     _delay_ms(10000);
		      count=6;
		 break;
		
		case 6 :
		   seven_segmant_Dispaly =0x60;
		   _delay_ms(10000);
		    count=7;
		      break;
		case 7  :
		    seven_segmant_Dispaly=0x70;
		    _delay_ms(10000);
		     count=8;
		     break;
		case 8  :
		      seven_segmant_Dispaly=0x80;
		      _delay_ms(10000);
		      count=9;
		     break;
		case 9  :
		      seven_segmant_Dispaly=0x90;
		      _delay_ms(10000);
		      count=0;
		      break;
		default :
		
		break;	
		}	
		#endif
    }
}

