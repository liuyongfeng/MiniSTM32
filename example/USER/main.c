#include "stm32f10x.h"
#include  "led.h"
#include "delay.h"
#include "key.h"
//#include "myusart.h"
#include "usart.h"
#include "exit.h"
#include "iwdg.h"
int main(void)
{
 	delay_init();
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	LED_Init();
	KEY_init();		
	//my_uart_init(115200);
	uart_init(115200);
	//EXTIX_Init();
	IWDG_Init(4,625); //1S
	delay_ms(200);
	LED0_ON();
	printf("system RESET\n");
	while(1){
		printf("system is Alive\n");
		if(key_scan(1) != 0){
			IWDG_ReloadCounter();//如果有按键按下，喂狗
			printf("feed watchdog\n");
		}
	}
}

