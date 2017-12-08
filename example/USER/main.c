#include "stm32f10x.h"
#include  "led.h"
#include "delay.h"
#include "key.h"
#include "usart.h"

int main(void)
{
 
	delay_init();
	LED_Init();
	KEY_init();		
	uart_init(9600);
	while(1){

		u8 key_status = key_scan(0);
		printf("key_status: %d\n",key_status);
		switch(key_status){
		
			case KEY0_DOWN: 
				LED0_ON();
				break;
			case KEY1_DOWN:
				LED1_ON();
				break;
			case WAKE_UP_DOWN:
				LED0_ON();
				LED1_ON();
				break;
			default:
				LED0_OFF();
				LED1_OFF();
		}
	}
}

