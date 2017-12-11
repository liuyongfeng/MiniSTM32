#include "stm32f10x.h"
#include  "led.h"
#include "delay.h"
#include "key.h"
//#include "myusart.h"
#include "usart.h"
#include "exit.h"
int main(void)
{
 
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	KEY_init();		
	//my_uart_init(115200);
	uart_init(115200);
	EXTIX_Init();
	
	
	while(1){
		delay_ms(1000);
		printf("system is runing\n");
	}
}

