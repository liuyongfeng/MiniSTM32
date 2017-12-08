#ifndef _KEY_H
#define _KEY_H

#include "sys.h"

#define KEY0_DOWN 1
#define KEY1_DOWN 2
#define WAKE_UP_DOWN 3

void KEY_init(void);

u8 key_scan(u8 mode);

#define KEY0 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)
#define KEY1 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)
#define WAKE_UP GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)

#endif
