#include "wwdg.h"
#include "led.h"

/*

 ʹ�ܿ��Ź�ʱ�ӣ�
     RCC_APB1PeriphClockCmd();
��  ���÷�Ƶϵ����
     WWDG_SetPrescaler();
�� �����ϴ���ֵ��
     WWDG_SetWindowValue();
�� ������ǰ�����жϲ�����(��ѡ)��
     WWDG_EnableIT();   
     NVIC_Init();
�� ʹ�ܿ��Ź���
     WWDG_Enable();
�� ι��:
    WWDG_SetCounter();
�߱�д�жϷ�����
   WWDG_IRQHandler();


*/

u8 WWDG_CNT = 0x7f;

void WWDG_NVIC_Init(void){
	
	NVIC_InitTypeDef NVIC_InitStruct;
	
	NVIC_InitStruct.NVIC_IRQChannel = WWDG_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority = 2;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority = 2;
	NVIC_Init(&NVIC_InitStruct);	
}



void WWDG_Init(u8 tr,u8 wr,u32 fprer){
	
	WWDG_CNT &= tr;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG,ENABLE);
	WWDG_SetPrescaler(fprer);
	WWDG_SetWindowValue(wr);
		
	WWDG_ClearFlag();
	WWDG_NVIC_Init();
	
	WWDG_EnableIT(); //�������ڿ��Ź��ж�
	WWDG_Enable(WWDG_CNT);//ʹ�ܴ��ڿ��Ź�
}

void WWDG_IRQHandler(void){

	WWDG_SetCounter(WWDG_CNT);
	WWDG_ClearFlag();
	LED1 = !LED1;

}
