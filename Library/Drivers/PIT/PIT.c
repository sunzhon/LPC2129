#include"headers.h"

/*******************************************************************************
* 函数名称：PIT_setIntTime
* 入口参数：timer  PIT定时器器选择
                    TIMER0
                    TIMER1
                    
            time   定时时间,单位 us
            prio   中断优先级(取值0-15,值越小优先级越高)
* 描    述：设置定时器
*******************************************************************************/
void PIT_setTime(int8u_t timer, int32u_t time, int8u_t prio)
{
   int32u_t volatile *VIC_address;                              //存放中断函数入口地址
   int32u_t volatile *VIC_Cntl_address;                         //配置中断优先级寄存器地址
   VIC_address = &VICVectAddr0+prio;
   VIC_Cntl_address = &VICVectCntl0+ prio; 
	if(timer==0)			         		//配置定时器0
		  {
                   VICIntSelect &= ~VIC_TIMER0_bit;             //  选择对应位为IRQ
                   *VIC_address = (int32u_t)&Timer0Interrupt;   //写入中断入口地址
                   *VIC_Cntl_address = 0x20|VIC_TIMER0;
                   VICIntEnable |= VIC_TIMER0_bit;      // Enable timer 0 interrupt. 使能对应中断请求
                   
                   
                   T0TCR = 0;                           // Disable timer 0 (1 bit register!)
                   T0CCR = 0;                           // All Capture types disabled      禁止外部捕捉
                   T0EMR = 0;                           // All external match type disabled   禁止各种外部匹配
		   T0PR = VPB_CLK-1;                    //预分频 计数寄存器每1us加一
		   T0MR0= time;
		   T0MCR=0x03;	                        //MR0 与TC 值的匹配将产生中断 MR0 与TC 值的匹配将使TC 复位。
		   T0TCR=0x01;	                        //定时器计数器和预分频计数器使能计数

		
               }
		else						     		//配置定时器1
		 	{
                          
                          VICIntSelect &= ~VIC_TIMER1_bit;                      //  选择对应位为IRQ
                          *VIC_address = (int32u_t)&Timer1Interrupt;            //写入中断入口地址
                          *VIC_Cntl_address = 0x20|VIC_TIMER1;
                          VICIntEnable |= VIC_TIMER1_bit;                       // Enable timer 0 interrupt. 使能对应中断请求
                          T1TCR = 0;                                            // Disable timer 0 (1 bit register!)
                          T1CCR = 0;                                            // All Capture types disabled      禁止外部捕捉
                          T1EMR = 0;                                            // All external match type disabled   禁止各种外部匹配
			  T1PR = VPB_CLK-1;                                     //预分频 计数寄存器每1us加一
                          T1MR0= time;
		          T1MCR=0x03;				                //MR0 与TC 值的匹配将产生中断 MR0 与TC 值的匹配将使TC 复位。
			  T1TCR=0x01;	             		                //定时器计数器和预分频计数器使能计数
	
		 	}

}