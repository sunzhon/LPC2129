#include"headers.h"



/*******************************************************************************
* �������ƣ�PIT_Init
* ��    �������ö�ʱ��ʱ��
*******************************************************************************/
void PIT_Init(void)
	{
	 PIT_setTime(Timer1,1000,3);     //1s��ʱ���ж�

	}
/*******************************************************************************
* �������ƣ�GPIO_Init
* ��    ������ʼ�����Ź���
*******************************************************************************/
void GPIO_Init(void)
	{
	GPIO_SetPinMod (PORT0,13,0);
        GPIO_SetPinDir (PORT0,13,1);
        GPIO_SetPinMod (PORT0, 2, 0);       //ѡ��P0.0ΪTXD0����
        GPIO_SetPinDir (PORT0, 2, 1);
	}
/*******************************************************************************
* �������ƣ�PWM_Init
* ��    ������ʼ�����Ź���
*******************************************************************************/
void PWM_Init(void)
	{
	GPIO_SetPinMod (PORT0,21,1);      //������Ӧ�˿�ΪPWM����
        PWM_Control(10,10000);               //����PWM���� ��VPBʱ�ӽ���4*1000��Ƶ
        }
/*******************************************************************************
* �������ƣ�UART_Init
* ��    �������ڳ�ʼ��
*******************************************************************************/
void UART_Init(void)
	{
        GPIO_SetPinMod (PORT0, 0, 1);       //ѡ��P0.0ΪTXD0����
        GPIO_SetPinMod (PORT0, 1, 1);       //ѡ��P0.1ΪRXD0����
        GPIO_SetPinStat(PORT0, 2,0);
	Data_Control(UART0,9600,8,0,1);   //UART0 9600������ 8λ����λ ����żУ�� 1λֹͣλ
	}
/*******************************************************************************
* �������ƣ� SPI_Init
* ��    �������ڳ�ʼ��
*******************************************************************************/
void SPI_Init(void)
{
  GPIO_SetPinMod (PORT0, 6, 1);    //ѡ��SPI�����������ݷ��Ͷ˿�
  GPIO_SetPinMod (PORT0, 5, 1);    //ѡ��SPI�����������ݽ��ն˿�
  GPIO_SetPinMod (PORT0, 4, 1);    //����ʱ�Ӷ˿�ѡ��

  GPIO_SetPinMod (PORT0, 11,0);    //�Ҳ�Ƭѡ���ƶ�
  GPIO_SetPinDir (PORT0,11,1);     //����Ϊ���
   GPIO_SetPinMod (PORT0, 7,0);    //���Ƭѡ���ƶ�
  GPIO_SetPinDir (PORT0,7,1);      //����Ϊ���
   GPIO_SetPinMod (PORT0, 10,0);   //�м�Ƭѡ���ƶ�
  GPIO_SetPinDir (PORT0,10,1);     //����Ϊ���
  SPI_Control(SPI0,240,1,0);     //VPBʱ��240��Ƶ ����ģʽ ��λ�ȴ�
}
/*******************************************************************************
* �������ƣ�CAN_Init
* ��    �������ö�ʱ��ʱ��
*******************************************************************************/
void CAN_Init()
{
  int8u_t Filter_Count=0;

  GPIO_SetPinMod (PORT0, 23,1);    //CAN2�ӿڹ��ܺ�ʹ��
  GPIO_SetPinMod (PORT0, 24,1);
  GPIO_SetPinMod (PORT0, 25,1);    //CAN1�ӿ������Ĭ�ϵ�

  AFMR = 0x01;      // ���������Ͻ��յ�����Ϣ

    /*---       ���븴λģʽ          ---*/
  C1MOD |= 0x01;
  C2MOD |= 0x01;

  Open_CAN_Interrupt(CAN1,0,2);     //ʹ�� CAN1�����ж� ���ȼ�Ϊ2
  Open_CAN_Interrupt(CAN2,0,3);     //ʹ�� CAN2�����ж� ���ȼ�Ϊ3
  //Ϊ���CAN2���������жϵ����⣬��CAN2 �����˲���type ��ΪEW_CAN_STD.
  /**************����CAN���ߵ�����*************************/
  //step1:�˲���
  // step2:��Ƶϵ����2��1M,4��500k,....,both of them have to same
  // step3:can1 and can2 ,both of them open interrupt, the pir have to be different


  C1GSR = 0;                        //��ȫ��״̬�Ĵ���
  C2GSR = 0;

  CAN_Clk(CAN1,2,1);               //CANλʱ��Ϊ100usec
  CAN_Clk(CAN2,2,1);

   SFF_sa     = 0;                //��׼֡��ʼ��ַ�Ĵ���
   SFF_GRP_sa = 0;                //��׼֡����ʼ��ַ�Ĵ���
   EFF_sa     = 0;                //��չ֡��ʼ��ַ�Ĵ���
   EFF_GRP_sa = 0;                //��չ֡����ʼ��ַ�Ĵ���
   ENDofTable = 0;                //AF�����ֹ�Ĵ���

   AFMR = 0x04;          //����FULLCANģʽ���������˲�������������CAN������ָ����׼IDֵ����Ϣ�Ľ��պͱ���


   C1MOD = ( EW_C1MOD_CAN | 0x01 );      //��λģʽ������ģʽ�Ĵ���
   C2MOD = ( EW_C2MOD_CAN | 0x01 );      //�������ȼ���Tx���ȼ������,��Ϊ��������ģʽ

   C1MOD = ( C1MOD & ~0x01 );            //�˳���λ״̬
   C2MOD = ( C2MOD & ~0x01 );

   Filter_Count=0;
   while ( CAN1Filter[Filter_Count].FilterType )         //����CAN�����˲������ �����5�ֲ�ͬ�ı�ʶ��
    {

        EW_AddFilter_CAN( &CAN1Filter[Filter_Count] );
        Filter_Count++;
    }
    Filter_Count= 0;
    while ( CAN2Filter[Filter_Count].FilterType )
    {
        EW_AddFilter_CAN( &CAN2Filter[ Filter_Count] );
        Filter_Count++;
    }


}
/*******************************************************************************
* �������ƣ�AD_Init
* ��    �������ڳ�ʼ��
* ��    ע���˿ڹ���ΪĬ��ֵ
*******************************************************************************/
void AD_Init(void)
	{

	  ADC_ClockCtrl(8);                 //��VPBʱ�ӽ���8��Ƶ

	}
/*******************************************************************************
* �������ƣ�SetPLL
* ��    ��������ϵͳ��������ʱ��
* ��    ע�������Ƶ��Ϊ60MHZ �ⲿ����ʹ�÷�Χ��10~25MHZ
*******************************************************************************/
void SetPLL(void)
	{
         int8u_t DIV_BusClk;                    //����ʱ�ӷ�Ƶ��

	 PLLCFG_bit.MSEL= CORE_CLK/REF_CLK-1;
         PLLCFG_bit.PSEL= DIV_CCO_Clk;
         PLLFEED=0xAA;
         PLLFEED=0x55;
         PLLCON_bit.PLLE = 1;               // Enable the PLL
         PLLFEED=0xAA;
         PLLFEED=0x55;
         while(!(PLLSTAT & 0x0400));      //�ȴ����໷�ȶ�
         PLLCON_bit.PLLC=1;               //�������໷��Ϊϵͳʱ��
         PLLFEED=0xAA;
         PLLFEED=0x55;
         DIV_BusClk=CORE_CLK/VPB_CLK;
         switch(DIV_BusClk)
         {
         case 1:
             APBDIV_bit.APBDIV = 0x01;	  //��������ʱ��
             break;
         case 2:
             APBDIV_bit.APBDIV = 0x02;    //����ʱ��2��Ƶ
             break;
         case 4:
             APBDIV_bit.APBDIV = 0x00;    //����ʱ��4��Ƶ
         default:
             break;                       //ִ��Ĭ��ֵ����ʱ��4��Ƶ
         }
        }

void System_Init(void)
    {
      SetPLL();                           //����ϵͳ����ʱ�Ӻ���Χʱ��
      GPIO_Init();
      CAN_Init();
      //PIT_Init();                     //��ʱ����ʼ��
      AD_Init();
      SPI_Init();
      UART_Init();

    }
