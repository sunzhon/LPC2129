#include"headers.h"

void delay(int16u_t flag)
{
  int32u_t temp;
  temp=100*flag;
 while(temp!=0)
 {
 temp--;
 }

}

int16u_t AD_Filter(int8u_t AD)
    {
int16u_t AD_flag=0;
int32u_t count = 0;                      //��ʱ���ж�1��������
int16u_t AD_Data;                      //�ǶȲɼ�����PID����
int16u_t AD_Data_Temp[Filter_COUNT];               //�ɼ�50�νǶ�ֵ������ֵ�˲�
int16u_t AD_Data_Change_Temp;                   //�������ݽ�����ʱ����

              if(AD_flag==0)
              {
              AD_flag=1;
             for(count=0;count<Filter_COUNT;count++)
              {
                ADC_readResult(AD,&AD_Data_Temp[count]);
              }
              for(int i=0;i<Filter_COUNT;i++)                               //ð������
                {
                  for(int j=0;j<Filter_COUNT-i;j++)
                    {
                      if(AD_Data_Temp[j]<=AD_Data_Temp[j+1])
                        {
                          AD_Data_Change_Temp=AD_Data_Temp[j];
                          AD_Data_Temp[j]=AD_Data_Temp[j+1];
                          AD_Data_Temp[j+1]=AD_Data_Change_Temp;
                        }
                    }
                }
                AD_Data=AD_Data_Temp[Filter_COUNT/2];     //ȡ��ֵ
              }
  return AD_Data;

    }
int8u_t Force_Fliter(int8u_t PORT){

  int8u_t fdata;
  int8u_t temp;
  int8u_t i;
  int16u_t sum=0;

  for(i=0;i<10;i++){

     Getchar(PORT,&temp) ;
     sum+=temp;

  }
   fdata=(int8u_t)((sum/10)&0x00FF);

   return fdata;

}


/*=============================================================================
��������AD_Send
����  �����ɼ�����ADͨ��CAN���߷��ͳ�ȥ��ʹ��CAN2 �˿�
��ע  ��һ֡�����а�������һ�����������ؽڵĽǶ�ֵ��
===============================================================================*/
void AD_Send(int16u_t Joint1_AD_Data,int16u_t Joint2_AD_Data,int16u_t Joint3_AD_Data,int8u_t Leg_Number){
 CAN_MSG TxMsg_temp;

  int32u_t temp1,temp2,temp3;
  TxMsg_temp.CTRL=Can1Test[0].CTRL;
  TxMsg_temp.ID=Leg_Number;
  temp1=(int32u_t)Joint1_AD_Data;
  temp2=(int32u_t)Joint2_AD_Data;
  temp3=(int32u_t)Joint3_AD_Data;
  temp1=(temp1<<16)&0xFFFF0000;
  TxMsg_temp.Data1=temp1+temp2;
  TxMsg_temp.Data2=temp3;
  EW_SendData_CAN(CAN1,&TxMsg_temp);
}
void Force_Send(int16u_t Force_X,int16u_t Force_Y,int16u_t Force_Z,int8u_t Leg_Number){

     CAN_MSG TxMsg_temp;

  int32u_t temp1,temp2,temp3;
  TxMsg_temp.CTRL=Can1Test[0].CTRL;
  TxMsg_temp.ID=Leg_Number;
  temp1=(int32u_t)Force_X;
  temp2=(int32u_t)Force_Y;
  temp3=(int32u_t)Force_Z;
  temp1=(temp1<<16)&0xFFFF0000;
  TxMsg_temp.Data1=temp1+temp2;
  TxMsg_temp.Data2=temp3;
  EW_SendData_CAN(CAN2,&TxMsg_temp);

}