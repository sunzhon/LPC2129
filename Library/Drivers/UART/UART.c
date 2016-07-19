#include"headers.h"

/*******************************************************************************
* �������ƣ�Data_Control
* ��ڲ�����UART    ����ѡ��
            baud    ���Ͳ���������
            data_bit    ����λѡ�񣬿�ѡ����λΪ5,6,7,8                    
            parity  ��żУ��λ
                    0������żУ��λ
                    1����У��
                    2��żУ��
                    3��ǿ��Ϊ1
                    4��ǿ��Ϊ0
            stop_bit ֹͣλѡ��
                    0��1��ֹͣλ
                    1��2��ֹͣλ,5����λʱΪ1.5��ֹͣλ
            
                          
* ��    �������ô���ͨ�ŵ����ݷ���ģʽ
*******************************************************************************/
void Data_Control(int8u_t UART,int16u_t baud,int8u_t data_bit,int8u_t parity_bit,int8u_t stop_bit)
    {
     switch(UART)
     {
     case 0:
            U0LCR_bit.DLAB = 1;              //ʹ�ܷ��ʳ�������Ĵ���
            U0DLL = VPB_CLK*1000000/(baud*16);       //ȡ��8λ
            U0DLM = VPB_CLK*1000000/(baud*16)>>8;    //ȡ��8λ
            U0LCR_bit.DLAB = 0;              //������ɽ�ֹ���ʳ�������Ĵ���
            U0LCR_bit.WLS = data_bit-5;      //��������λ
            if(parity_bit==0)                //��ֹ��żУ��
               U0LCR_bit.PE = 0;
            else                           
            { 
              U0LCR_bit.PE = 1;              //ʹ����żУ��  
              U0LCR_bit.PS = parity_bit-1;   //����У��ģʽ            
            }
            U0LCR_bit.SBS = stop_bit;       //����ֹͣλ
            break;
      case 1:
            U1LCR_bit.DLAB = 1;              //ʹ�ܷ��ʳ�������Ĵ���
            U1DLL = VPB_CLK*1000000/(baud*16);       //ȡ��8λ
            U1DLM = VPB_CLK*1000000/(baud*16)>>8;    //ȡ��8λ
            U1LCR_bit.DLAB = 0;              //������ɽ�ֹ���ʳ�������Ĵ���
            U1LCR_bit.WLS = data_bit-5;      //��������λ
            if(parity_bit==0)                //��ֹ��żУ��
               U1LCR_bit.PE = 0;
            else                           
            { 
              U1LCR_bit.PE = 1;              //ʹ����żУ��  
              U1LCR_bit.PS = parity_bit-1;   //����У��ģʽ            
            }
            U1LCR_bit.SBS = stop_bit;       //����ֹͣλ
            break;
             


    }
 }

/*******************************************************************************
* �������ƣ�putchar
* ��ڲ�����UART    ����ѡ��
            data    �����͵����ݿ�ѡ��λ��5,6,7,8
                          
* ��    ����ͨ��UART��������
*******************************************************************************/
void Putchar(int8u_t UART,int8u_t *data)
{
  switch(UART)
  {
  case 0:
    U0FCR_bit.FCRFE = 1;             //�ߵ�ƽʹ�ܶ� UART0 Rx ��Tx FIFO �Լ�U0FCR[7:1]�ķ���
    U0THR = *data;                   //�������͵�����д�뷢�ͱ��ּĴ���
    while(!U0LSR_bit.THRE);          //�ȴ��������
    break;
  case 1:
    U1FCR_bit.FCRFE = 1;             //�ߵ�ƽʹ�ܶ� UART1 Rx ��Tx FIFO �Լ�U1FCR[7:1]�ķ���
    U1THR = *data;                   //�������͵�����д�뷢�ͱ��ּĴ���
    while(!U1LSR_bit.THRE);          //�ȴ��������
    break;
  }
 
}
/*******************************************************************************
* �������ƣ�Getchar
* ��ڲ�����UART    ����ѡ��
            data    ���մ���ȡ������
                          
* ��    ����ͨ��UART��������
*******************************************************************************/
void Getchar(int8u_t UART,int8u_t *data)
{
  switch(UART)
  {
  case 0:
    U0FCR_bit.FCRFE = 1;             //�ߵ�ƽʹ�ܶ� UART0 Rx ��Tx FIFO �Լ�U0FCR[7:1]�ķ���
    if(U0LSR_bit.RDR==1)             //�������ݾ���          
    *data = U0RBR;                   //��ȡ����������Ĵ���
   break;
   case 1:
    U1FCR_bit.FCRFE = 1;             //�ߵ�ƽʹ�ܶ� UART0 Rx ��Tx FIFO �Լ�U0FCR[7:1]�ķ���
    if(U1LSR_bit.RDR==1)             //�������ݾ���          
    *data = U1RBR;                   //��ȡ����������Ĵ���
   break;
  }
 
}