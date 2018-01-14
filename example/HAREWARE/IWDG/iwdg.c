#include "iwdg.h"

/*
 ȡ���Ĵ���д������
      IWDG_WriteAccessCmd();
��  ���ö������Ź���Ԥ��Ƶϵ����ȷ��ʱ��:
     IWDG_SetPrescaler();
��  ���ÿ��Ź���װ��ֵ��ȷ�����ʱ��:
    IWDG_SetReload();
��  ʹ�ܿ��Ź�
    IWDG_Enable();
��  Ӧ�ó���ι��:
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
