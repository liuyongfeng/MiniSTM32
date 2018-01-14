#ifndef __LED_H
#define __LED_H

#define LED0 PAout(8)	// PA8 RED DS0
#define LED1 PDout(2)	// PD2 GREEN DS1
void LED_Init(void);

void LED0_ON(void);
void LED0_OFF(void);	
void LED1_ON(void);
void LED1_OFF(void);	
#endif


