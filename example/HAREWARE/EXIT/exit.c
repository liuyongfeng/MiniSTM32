#include "exit.h"
#include "key.h"
#include "led.h"
#include "delay.h"
void EXTIX_Init(void)
{
	EXTI_InitTypeDef EXTI_InitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	//1）初始化 IO 口为输入。
	KEY_init();
	
	//2）开启 IO 口复用时钟，设置 IO 口与中断线的映射关系。
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	//KEY0 PC5
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOC,GPIO_PinSource5);
	//KEY1 PA15
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource15);
	//WAKE_UP PA0
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA,GPIO_PinSource0);
	
	//3）初始化线上中断，设置触发条件等。
	
	//KEY0 PC5
	EXTI_InitStruct.EXTI_Line = EXTI_Line5;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	EXTI_Init(&EXTI_InitStruct);
	//KEY1 PA15
	EXTI_InitStruct.EXTI_Line = EXTI_Line15;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	EXTI_Init(&EXTI_InitStruct);
	//WAKE_UP PA0
	EXTI_InitStruct.EXTI_Line = EXTI_Line0;
	EXTI_InitStruct.EXTI_LineCmd = ENABLE;
	EXTI_InitStruct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStruct.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
	EXTI_Init(&EXTI_InitStruct);
		
		
	//4）配置中断分组（NVIC），并使能中断。
	
	NVIC_InitStruct.NVIC_IRQChannel = EXTI9_5_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStruct);
	
	NVIC_InitStruct.NVIC_IRQChannel = EXTI15_10_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStruct);
	
	NVIC_InitStruct.NVIC_IRQChannel = EXTI0_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStruct);
			
}


//5）编写中断服务函数。


//WAKE_UP PA0
void EXTI0_IRQHandler(void)
{
//	if(EXTI_GetITStatus(EXTI_Line0) != RESET){
		delay_ms(10);    //消抖	
		if(WAKE_UP){
			LED0_ON();
			LED1_ON();
		}else{
			LED0_OFF();
			LED1_OFF();
		}
		EXTI_ClearITPendingBit(EXTI_Line0);
//	}
}

//KEY0 PC5
void EXTI9_5_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line5) != RESET){
		delay_ms(10);    //消抖	
		if(!KEY0)
			LED0_ON();
		else
			LED0_OFF();

		EXTI_ClearITPendingBit(EXTI_Line5);
	}
}

	
//KEY1 PA15
void EXTI15_10_IRQHandler(void)
{
	if(EXTI_GetITStatus(EXTI_Line15) != RESET){
		delay_ms(10);    //消抖	
		if(!KEY1)
			LED1_ON();
		else
			LED1_OFF();

		EXTI_ClearITPendingBit(EXTI_Line15);
	}	
}	



