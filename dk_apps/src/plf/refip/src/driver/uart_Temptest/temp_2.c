
	#include <stdio.h>
	#include "temp_2.h"

	/*********************延时1us*******************************************************************************/
//	void bsp_DelayUS(uint32_t nof_us)
//{
//    while( nof_us-- ){
//        __nop();
//        __nop();
//        __nop();
//        __nop();
//        __nop();
//        __nop();
//        __nop();
//        __nop();
//        __nop();
//        __nop();
//        __nop();
//    }
//}
	/************************************************************************************************************/
	/*
	 * MY1605B read one bit
	 */
	static uint8 MY1605B_Read_Bit(void)
	{
		uint8_t dat;
		
		/* time slot of read 1 and read 0 need to be over 60us */	

		//MY1605B_Mode_Out_PP();  设定推挽输出
		GPIO_ConfigurePin(MY1605B_GPIO_PORT, MY1605B_PIN, OUTPUT, PID_GPIO, true);

		bsp_DelayUS(3);

		/* master drive bus low >1us <15us*/
	 //MY1605B_DATA_OUT(LOW);  拉低总线
		GPIO_SetInactive(MY1605B_GPIO_PORT,MY1605B_PIN);
		
		bsp_DelayUS(3);
		
		/* set pin to inputmode, release bus, then pull up by pull-up resistor*/
	 //	MY1605B_Mode_IPU();  设定上拉输入模式
		GPIO_ConfigurePin(MY1605B_GPIO_PORT, MY1605B_PIN, INPUT_PULLUP, PID_GPIO, true);
		
		bsp_DelayUS(5);
		
		//if( MY1605B_DATA_IN() == 1 ) 读引脚输入电平是否为高
		if(GPIO_GetPinStatus(MY1605B_GPIO_PORT, MY1605B_PIN)==1)
			dat = 1;
		else
			dat = 0;
		
		/* based on Time Slot Timing Diagram */
		bsp_DelayUS(60);
		
		return dat;
	}


	/************************************************************************************************************/
	/*
	 * MY1605B read one byte, LSB first
	 */
	uint8_t MY1605B_Read_Byte(void)
	{
		uint8_t i, j, dat = 0;	
		
		for(i=0; i<8; i++) 
		{
			j = MY1605B_Read_Bit();		
			dat = (dat) | (j<<i);
		}
		
		return dat;
	}
	/************************************************************************************************************/
	/*
	 * master send reset pulse to slave
	 */
	static void MY1605B_Rst(void)
	{
		/*set pin mode to push-pull out mode*/

		//MY1605B_Mode_Out_PP();  设定推挽输出
		GPIO_ConfigurePin(MY1605B_GPIO_PORT, MY1605B_PIN, OUTPUT, PID_GPIO, true);

	//		bsp_DelayUS(11750);
		bsp_DelayUS(3);
		
	 //MY1605B_DATA_OUT(LOW);  拉低总线
		GPIO_SetInactive(MY1605B_GPIO_PORT,MY1605B_PIN);

		/* master drive bus low at least 480us */
		bsp_DelayUS(600);

		/* set pin to inputmode, release bus, then pull up by pull-up resistor*/
	 //	MY1605B_Mode_IPU();  设定上拉输入模式
		GPIO_ConfigurePin(MY1605B_GPIO_PORT, MY1605B_PIN, INPUT_PULLUP, PID_GPIO, true);

		/* master release bus */
	//	MY1605B_DATA_OUT(HIGH);
		
		/*once slave receive reset signal, it will send presence pulse to master after 15~60us*/
		bsp_DelayUS(15);
	}


	/************************************************************************************************************/
	/*
	 * check presence pulse
	 * 0: success
	 * 1: failure
	 */
	static uint8_t MY1605B_Presence(void)
	{
		uint8_t pulse_time = 0;
		
		/* set pin to inputmode, release bus, then pull up by pull-up resistor*/
	 //	MY1605B_Mode_IPU();  设定上拉输入模式
		GPIO_ConfigurePin(MY1605B_GPIO_PORT, MY1605B_PIN, INPUT_PULLUP, PID_GPIO, true);

		bsp_DelayUS(3);
		
		/* wait for presence pulse, 60~240us low level signal
		 * if presence pulse does not come, then timeout; once slave receive reset signal, it will send presence pulse to master after 15~60us
		 */
	//	while( MY1605B_DATA_IN() && pulse_time<100 )
			while( GPIO_GetPinStatus(MY1605B_GPIO_PORT, MY1605B_PIN) && pulse_time<100 )

		{
			pulse_time++;
			bsp_DelayUS(1);
		}	
		/* after 100us, presence pulse does not come*/
		if( pulse_time >=100 )
			return 1;
		else
			pulse_time = 0;
		
		/* presence pulse comes and not sustain over 240us */
		//while( !MY1605B_DATA_IN() && pulse_time<240 )
		while( !GPIO_GetPinStatus(MY1605B_GPIO_PORT, MY1605B_PIN)  && pulse_time<240 )

		{
			pulse_time++;
			bsp_DelayUS(1);
		}	
		if( pulse_time >=240 )
			return 1;
		else
			return 0;
	}
	/************************************************************************************************************/
	/*
	 * MY1605B write one byte, LSB first
	 */
	void MY1605B_Write_Byte(uint8_t dat)
	{
		uint8_t i, testb;
		
		//MY1605B_Mode_Out_PP();  设定推挽输出
		GPIO_ConfigurePin(MY1605B_GPIO_PORT, MY1605B_PIN, OUTPUT, PID_GPIO, true);

		bsp_DelayUS(5);
		
		for( i=0; i<8; i++ )
		{
			testb = dat&0x01;
			dat = dat>>1;		
			/* time slot of write 1 and read 0 need to be over 60us */
			if (testb)
			{			
	 //MY1605B_DATA_OUT(LOW);  拉低总线
		GPIO_SetInactive(MY1605B_GPIO_PORT,MY1605B_PIN);
				/* 1us < this delay < 15us */
				bsp_DelayUS(5);
				
	 //MY1605B_DATA_OUT(HIGH);  拉高总线
		GPIO_SetActive(MY1605B_GPIO_PORT,MY1605B_PIN);
				bsp_DelayUS(70);
			}		
			else
			{			
	 //MY1605B_DATA_OUT(LOW);  拉低总线
		GPIO_SetInactive(MY1605B_GPIO_PORT,MY1605B_PIN);
				/* 60us < Tx 0 < 120us */
				bsp_DelayUS(70);
				
	 //MY1605B_DATA_OUT(HIGH);  拉高总线
		GPIO_SetActive(MY1605B_GPIO_PORT,MY1605B_PIN);

				/* 1us < Trec < 无穷大*/
				bsp_DelayUS(10);
			}
		}
	}


	/************************************************************************************************************/
	float MY1605B_Read_Temperaure(void) 
	{
		uint8_t tpmsb, tplsb;
		short s_tem;
		float f_tem;
		
			MY1605B_Rst();	   
			MY1605B_Presence();	 
			MY1605B_Write_Byte(SKIP_ROM);				
			MY1605B_Write_Byte(CONVERT_T);
			
			bsp_DelayUS(6000);  //For V1 Chip
		
			MY1605B_Rst();	   
			MY1605B_Presence();	 
			MY1605B_Write_Byte(SKIP_ROM);
			MY1605B_Write_Byte(READ_SCRATCHPAD);
	
  	  bsp_DelayUS(200);  //For V1 Chip

  		tplsb = MY1605B_Read_Byte();
			tpmsb = MY1605B_Read_Byte();
			
		s_tem = tpmsb<<8;
		s_tem = s_tem | tplsb;
		
		s_tem = s_tem & 4095;
		
		if( (s_tem & 2048) == 2048 )	{
			s_tem = (s_tem^4095) & 4095;
			f_tem = -1*(s_tem+1) * 0.0625;
		}	/* negative */
				
		else
			f_tem = s_tem * 0.0625;
		return f_tem; 	
	
			
	}
void MY1605B_RECALL(void)
{
			MY1605B_Rst();	   
			MY1605B_Presence();	 
			MY1605B_Write_Byte(SKIP_ROM);
			MY1605B_Write_Byte(RECALL_PAGE1);

}
