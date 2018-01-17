#include "timer.h"
#include "led.h"
/*

1、 能定时器时钟。
       RCC_APB1PeriphClockCmd();
2、 初始化定时器，配置ARR,PSC。
      TIM_TimeBaseInit();
3、开启定时器中断，配置NVIC。
      void TIM_ITConfig();
      NVIC_Init();
4、  使能定时器。
      TIM_Cmd();
5、 编写中断服务函数。
      TIMx_IRQHandler();

*/


void TIM3_Init(u16 arr, u16 psc ){

	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;
	NVIC_InitTypeDef NVIC_InitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	TIM_TimeBaseInitStruct.TIM_Period = arr;
	TIM_TimeBaseInitStruct.TIM_Prescaler = psc;
	TIM_TimeBaseInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
	
	NVIC_InitStruct.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 3;
	NVIC_Init(&NVIC_InitStruct);
	
	TIM_Cmd(TIM3,ENABLE);
}


void TIM3_IRQHandler(void){

	if(TIM_GetITStatus(TIM3,TIM_IT_Update) != RESET){
		LED0 = !LED0;
		TIM_ClearITPendingBit(TIM3,TIM_IT_Update);
	}

}
