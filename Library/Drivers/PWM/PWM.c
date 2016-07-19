#include"headers.h"


/*******************************************************************************
* �������ƣ�PWM_Control
* ��ڲ����� div      ѡ��ʱ�ӷ�Ƶ��
             period   ��ռ�ձȼ���ֵ
* ��    �ܣ� ��VPBʱ�ӽ���div*period ��Ƶ
                    
* ��    ��������ͨ��������Ϊ��������� ������Ϊ˫�������ʹ��2��4��6ͨ��
*******************************************************************************/
void PWM_Control(int32u_t div,int32u_t period)
    {
     
     PWMTCR_bit.PWMEN=0;       //�ر�PWMģʽ
     PWMTCR_bit.CE=0;          //��ֹ��ʱ������������
     PWMPR = div-1;           //��VPBʱ�ӽ���div��Ƶ
     PWMMR0 = period;          //������ռ�ձȼ���ֵ
     PWMMCR = 0x02;            //ƥ��ʱ���Զ�ʱ��������ֵ�����κβ��� ��ռ�ձ�ƥ��ʱ��0
     PWMTCR_bit.CE=1;       //������ʱ����������
     PWMTCR_bit.PWMEN=1;    //����PWMģʽ        
     PWMPCR = 0x7E00;       //ѡ�񵫱���ģʽ��ʹ��PWM��� 
       
    }

/*******************************************************************************
* �������ƣ�PWM_Set
* ��ڲ����� channel     ѡ��PWMͨ��

             dty         ������Ӧͨ��ռ�ձ�
        
                    
* ��ע�������õ�dty����PWMLER��Ӧλ��λ��ƥ��0������ʱ�����������㣩����ʱд���Ӧƥ��Ĵ���
        PWMLER�Զ�����
*******************************************************************************/
void PWM_Set(int8u_t channel,int32u_t dty)
    {
    switch(channel)           //������Ӧͨ��ռ�ձ�
     {
       case 1:
             PWMMR1 = dty;
             PWMLER_bit.EM1L=1;
             break;
       case 2:
             PWMMR2 = dty;
             PWMLER_bit.EM2L=1;
             break;
       case 3:
             PWMMR3 = dty;
             PWMLER_bit.EM3L=1;
             break;
       case 4:
             PWMMR4 = dty;
             PWMLER_bit.EM4L=1;
             break;
       case 5:
             PWMMR5 = dty;
             PWMLER_bit.EM5L=1;
             break;
       case 6:
             PWMMR6 = dty;
             PWMLER_bit.EM6L=1;
             break;
     default:
             break;
             
     }
       
    }


