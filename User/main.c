#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"

uint8_t keyNum;

int main(void)
{
	LED_Init();
	Key_Init();
	
	
	
	uint8_t num=0;  //真实计数
	uint8_t subnum=0; /*第二盏灯计数，我知道总共只有3盏灯，我这样写可能比较麻烦
					但是我不想只是枚举计数，那样加一盏灯就不行了,我就是想用规律写  (*^__^*)   */
	uint8_t thirdnum=0;  //第三盏灯
	uint8_t maintain=0;
	
	
	
	while (1)
	{
		keyNum = Key_GetNum();
		if (keyNum ==2 ||  keyNum==3 )
		{
			maintain =keyNum;
		}
		if (keyNum==1 )   //实现按键递增
		{
			num+=1;
			subnum+=1;
			thirdnum+=1;
			if (num==8)
			{
				num=0;
			}
			LED0_Turn();
			if (subnum==2)
			{
				LED1_Turn();
				subnum=0;
			}
			if (thirdnum==4)
			{
				LED2_Turn();
				thirdnum=0;
			}
			
			
		
		}
		
			if (maintain==2)    //实现按键切换
			{
				for (uint8_t i=0;i<8;i++)
				{
					num+=1;
					subnum+=1;
					thirdnum+=1;
					if (num==8)
					{
						num=0;
					}
					LED0_Turn();
					if (subnum==2)
					{
						LED1_Turn();
						subnum=0;
					}
					if (thirdnum==4)
					{
						LED2_Turn();
						thirdnum=0;
					}
					for (uint8_t j=0;j<50;j++ )
					{
						if(Key_GetNum()==3)
						{
							maintain =3;
							break;
						}
						Delay_ms(10);
					}
					if (maintain ==3)
					{
						break;
					}
				}
			}
		
		
		}
		
		
}
