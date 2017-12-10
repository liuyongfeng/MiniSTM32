#include "led.h"
#include "stm32f10x.h"

void LED_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
	
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//GPIOA
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);//GPIOD
	//LED0 PA8
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);
	
	//LED1 PD2
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOD,&GPIO_InitStructure);
	GPIO_SetBits(GPIOD,GPIO_Pin_2);
}

void LED0_OFF(void){
	GPIO_SetBits(GPIOA,GPIO_Pin_8);
}

//blue led
void LED0_ON(void){
	GPIO_ResetBits(GPIOA,GPIO_Pin_8);
}

//red led
void LED1_OFF(void){

	GPIO_SetBits(GPIOD,GPIO_Pin_2);
}

void LED1_ON(){

	GPIO_ResetBits(GPIOD,GPIO_Pin_2);

}


