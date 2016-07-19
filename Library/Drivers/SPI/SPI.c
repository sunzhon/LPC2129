#include"headers.h"

/*******************************************************************************
* �������ƣ�SPI_Control
* ��ڲ����� channel  SPI�ӿ�
             div      ѡ���VPBʱ�ӵķ�Ƶ����8λ�Ĵ���������ֵ����Ϊ���ڵ���8��ż�����ֵΪ254
             model    ���ӹ���ģʽѡ��
                  1�� ��������ģʽ
                  0�� �ӻ�����ģʽ
             data_model ѡ�����ݴ���ķ���
                  0�� MSB ��LSB
                  1�� LSB ��MSB
* ��    �ܣ� ����SPI��ͨ�����ʣ����ݴ���ģʽ
                    
* ��    ע�� Ĭ�ϲ�����SPI�ж� ע�⵱�ӻ������ĵ�һ��������������ʱ��
             ���������ĵ�һ�����ݱ������ڵ�һ��������֮ǰ��
*******************************************************************************/
void SPI_Control(int8u_t channel,int8u_t div,int8u_t model,int8u_t data_model)
{
  switch(channel)
  {
  case 0:                                    //����SPI0��ͨ�Ų���
        if(model==1)                         //��������ģʽ
        {
          S0SPCCR_bit.COUNTER = div;         //��������ʱ��
        }
          S0SPCR_bit.MSTR = model;          
          S0SPCR_bit.CPHA = 0;              //CPOL=0, CPHA=1 �����ĵ�һ�������ڵ�һ��SCK������֮ǰ
          S0SPCR_bit.CPOL = 0;              //���������������� SCK������ ������������SCK�½���
          S0SPCR_bit.LSBF = data_model;     //�������ݴ��䷽��
          break;
   case 1:                                  //����SPI0��ͨ�Ų���
        if(model==1)                       //��������ģʽ
        {
          S1SPCCR_bit.COUNTER = div;         //��������ʱ��
        }
          S1SPCR_bit.MSTR = model;          
          S1SPCR_bit.CPHA = 1;              //CPOL=0, CPHA=1 �����ĵ�һ�������ڵ�һ��SCK������
          S1SPCR_bit.CPOL = 0;              //���������������� SCK������ ������������SCK�½���
          S1SPCR_bit.LSBF = data_model;     //�������ݴ��䷽��
          break; 
  }


}
/*******************************************************************************
* �������ƣ�SPI_Send_Data
* ��ڲ����� channel  SPI�ӿ�
             data     Ҫ�������ݵĴ洢��ַ
             
* ��    �ܣ� ������ͨ����Ӧ��SPI�ӿڷ��ͳ�ȥ
                    

*******************************************************************************/
void SPI_Send_Data(int8u_t channel,int8u_t *data)
{    
     switch(channel)
     {
     case 0:
      S0SPDR =*data;            //��Ҫ���͵�����д�����ݼĴ��� 
      while(!S0SPSR_bit.SPIF);    //�ȴ�������� ��ֹ����������ٴ�д���������д��ͻ
      break;
      case 1:
      S1SPDR = *data;            //��Ҫ���͵�����д�����ݼĴ��� 
      while(!S1SPSR_bit.SPIF);    //�ȴ�������� 
      break;
     }
     
}
/*******************************************************************************
* �������ƣ�SPI_Get_Data
* ��ڲ����� channel  SPI�ӿ�
             result     Ҫ�������ݵĴ洢��ַ
             
* ��    �ܣ� ������ͨ����Ӧ��SPI�ӿڷ��ͳ�ȥ
                    

*******************************************************************************/
void SPI_Get_Data(int8u_t channel,int8u_t* result)
{
  switch(channel)
     {
     case 0:
      if(S0SPSR_bit.SPIF==1)     //����������δ����������
      * result = S0SPDR;          //�������յ�������
      break;
     case 1:
      if(S1SPSR_bit.SPIF==1)     //����������δ����������
      * result = S1SPDR;          //�������յ�������
      break;
     }
}