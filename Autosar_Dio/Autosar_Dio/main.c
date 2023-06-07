/**********************************************************************/
 /****************** SWC : main.c            **************************/
 /****************** Version: V00            **************************/
 /****************** Date: Sep 21, 2022      **************************/
 /****************** Author: ibrahim.saber   **************************/
 /*********************************************************************/
#include "Common_Macros.h"
#include "Dio.h"
#include "Dio_Regs.h"
void Init(void);

void Init(void)
{
	DDRC = 0xFF;
	DDRD = 0x00;
	CLEAR_BIT(DDRA, 0);
	CLEAR_BIT(DDRA, 5);
	CLEAR_BIT(DDRA, 7);
	SET_BIT(DDRB , 0);
	
}

int main(void)
{
	Init();
	Dio_LevelType ChannelValue = 0;
	while(1)
	{	
		ChannelValue = Dio_ReadChannel(CHANNEL2);
		if  (STD_LOW == ChannelValue)
		{
			Dio_WritePort(PORT_ID0, 0xFF);
		}
		else 
		{
			Dio_FlipChannel(CHANNEL1);
		}
	}
	return 0;
}
