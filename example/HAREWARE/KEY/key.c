#include "key.h"
#include "stm32f10x.h"
#include "delay.h"

void KEY_init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//GPIOA
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);//GPIOC

	//KEY0 PC5 输入上拉
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);

	
	//KEY1 PA15 输入上拉
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	//WAKE_UP PA0 输入下拉
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
}

//单次触发模式：mode = 0; 持续触发模式：mode = 1;
u8 key_scan(u8 mode)
{
	static u8 key_up = 1;
	
	if(mode) key_up = 1;

	if(key_up && (KEY0 == 0|| KEY1 == 0 || WAKE_UP == 1)){
		//上次抬起，现在按下；如果一直按下则只算按了一次
		key_up = 0;
		
		delay_ms(100);//按键去抖100ms
		
		if(KEY0 == 0)
			return KEY0_DOWN;
		else if(KEY1 == 0)
			return KEY1_DOWN;
		else if(WAKE_UP ==1)
			return WAKE_UP_DOWN;
		
	}else if(KEY0 == 1 && KEY1 == 1 && WAKE_UP == 0){
		//无按键按下
		key_up = 1;
	}
	
	return 0;
}
