#include "wwdg.h"
#include "led.h"

/*

 使能看门狗时钟：
     RCC_APB1PeriphClockCmd();
②  设置分频系数：
     WWDG_SetPrescaler();
③ 设置上窗口值：
     WWDG_SetWindowValue();
④ 开启提前唤醒中断并分组(可选)：
     WWDG_EnableIT();   
     NVIC_Init();
⑤ 使能看门狗：
     WWDG_Enable();
⑥ 喂狗:
    WWDG_SetCounter();
⑦编写中断服务函数
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
	
	WWDG_EnableIT(); //开启窗口看门狗中断
	WWDG_Enable(WWDG_CNT);//使能窗口看门狗
}

void WWDG_IRQHandler(void){

	WWDG_SetCounter(WWDG_CNT);
	WWDG_ClearFlag();
	LED1 = !LED1;

}
