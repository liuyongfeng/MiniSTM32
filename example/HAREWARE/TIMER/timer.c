#include "timer.h"
#include "led.h"
/*

1�� �ܶ�ʱ��ʱ�ӡ�
       RCC_APB1PeriphClockCmd();
2�� ��ʼ����ʱ��������ARR,PSC��
      TIM_TimeBaseInit();
3��������ʱ���жϣ�����NVIC��
      void TIM_ITConfig();
      NVIC_Init();
4��  ʹ�ܶ�ʱ����
      TIM_Cmd();
5�� ��д�жϷ�������
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
