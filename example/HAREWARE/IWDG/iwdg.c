#include "iwdg.h"

/*
 取消寄存器写保护：
      IWDG_WriteAccessCmd();
②  设置独立看门狗的预分频系数，确定时钟:
     IWDG_SetPrescaler();
③  设置看门狗重装载值，确定溢出时间:
    IWDG_SetReload();
④  使能看门狗
    IWDG_Enable();
⑤  应用程序喂狗:
   IWDG_ReloadCounter();
   
void IWDG_WriteAccessCmd(uint16_t IWDG_WriteAccess);
void IWDG_SetPrescaler(uint8_t IWDG_Prescaler);
void IWDG_SetReload(uint16_t Reload);
void IWDG_ReloadCounter(void);
void IWDG_Enable(void);
FlagStatus IWDG_GetFlagStatus(uint16_t IWDG_FLAG);

*/
void IWDG_Init(u8 prer,u16 rlr)
{
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(prer);
	IWDG_SetReload(rlr);//set rlr
	IWDG_ReloadCounter();//load rlr
	IWDG_Enable();	
}
