#include"headers.h"

/*******************************************************************************
* �������ƣ�PIT_setIntTime
* ��ڲ�����timer  PIT��ʱ����ѡ��
                    TIMER0
                    TIMER1
                    
            time   ��ʱʱ��,��λ us
            prio   �ж����ȼ�(ȡֵ0-15,ֵԽС���ȼ�Խ��)
* ��    �������ö�ʱ��
*******************************************************************************/
void PIT_setTime(int8u_t timer, int32u_t time, int8u_t prio)
{
   int32u_t volatile *VIC_address;                              //����жϺ�����ڵ�ַ
   int32u_t volatile *VIC_Cntl_address;                         //�����ж����ȼ��Ĵ�����ַ
   VIC_address = &VICVectAddr0+prio;
   VIC_Cntl_address = &VICVectCntl0+ prio; 
	if(timer==0)			         		//���ö�ʱ��0
		  {
                   VICIntSelect &= ~VIC_TIMER0_bit;             //  ѡ���ӦλΪIRQ
                   *VIC_address = (int32u_t)&Timer0Interrupt;   //д���ж���ڵ�ַ
                   *VIC_Cntl_address = 0x20|VIC_TIMER0;
                   VICIntEnable |= VIC_TIMER0_bit;      // Enable timer 0 interrupt. ʹ�ܶ�Ӧ�ж�����
                   
                   
                   T0TCR = 0;                           // Disable timer 0 (1 bit register!)
                   T0CCR = 0;                           // All Capture types disabled      ��ֹ�ⲿ��׽
                   T0EMR = 0;                           // All external match type disabled   ��ֹ�����ⲿƥ��
		   T0PR = VPB_CLK-1;                    //Ԥ��Ƶ �����Ĵ���ÿ1us��һ
		   T0MR0= time;
		   T0MCR=0x03;	                        //MR0 ��TC ֵ��ƥ�佫�����ж� MR0 ��TC ֵ��ƥ�佫ʹTC ��λ��
		   T0TCR=0x01;	                        //��ʱ����������Ԥ��Ƶ������ʹ�ܼ���

		
               }
		else						     		//���ö�ʱ��1
		 	{
                          
                          VICIntSelect &= ~VIC_TIMER1_bit;                      //  ѡ���ӦλΪIRQ
                          *VIC_address = (int32u_t)&Timer1Interrupt;            //д���ж���ڵ�ַ
                          *VIC_Cntl_address = 0x20|VIC_TIMER1;
                          VICIntEnable |= VIC_TIMER1_bit;                       // Enable timer 0 interrupt. ʹ�ܶ�Ӧ�ж�����
                          T1TCR = 0;                                            // Disable timer 0 (1 bit register!)
                          T1CCR = 0;                                            // All Capture types disabled      ��ֹ�ⲿ��׽
                          T1EMR = 0;                                            // All external match type disabled   ��ֹ�����ⲿƥ��
			  T1PR = VPB_CLK-1;                                     //Ԥ��Ƶ �����Ĵ���ÿ1us��һ
                          T1MR0= time;
		          T1MCR=0x03;				                //MR0 ��TC ֵ��ƥ�佫�����ж� MR0 ��TC ֵ��ƥ�佫ʹTC ��λ��
			  T1TCR=0x01;	             		                //��ʱ����������Ԥ��Ƶ������ʹ�ܼ���
	
		 	}

}