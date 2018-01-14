#include "stm32f10x.h"
#include  "led.h"
#include "delay.h"
#include "key.h"
//#include "myusart.h"
#include "usart.h"
#include "exit.h"
#include "wwdg.h"
int main(void)
{
 	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	KEY_init();		
	uart_init(115200);
	LED0 = 1;
	LED1 = 1;
	delay_ms(200);
	WWDG_Init(0x7F,0x5F,WWDG_Prescaler_8);
	
	while(1){

		LED0 = 0;
	}
}


