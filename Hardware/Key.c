#include "stm32f10x.h"                  // Device header

#include "Delay.h"

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU ;
	GPIO_InitStructure.GPIO_Pin= GPIO_Pin_1 | GPIO_Pin_11 ;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz ;
	GPIO_Init(GPIOB,&GPIO_InitStructure);

}


uint8_t Key_GetNum(void)
{
	uint8_t KeyNum =0 ;
	static uint8_t temp=0;
	
	if ( GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) ==0  )   //递增键
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1) ==0);
		Delay_ms(20);
		KeyNum =1;
		
	}
	
	if ( GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) ==0  )     //切换键
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11) ==0);
		Delay_ms(20);
		if (KeyNum ==2  || temp ==2 )
		{
			KeyNum =3;   //关闭自动递增
			temp=KeyNum;
		}
		else 
		{
			KeyNum=2; //开启自动递增
			temp = KeyNum;
		}
		
		
	}
	
	return KeyNum;
}
