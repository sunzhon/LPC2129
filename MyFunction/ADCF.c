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
int32u_t count = 0;                      //定时器中断1计数变量
int16u_t AD_Data;                      //角度采集用于PID运算
int16u_t AD_Data_Temp[Filter_COUNT];               //采集50次角度值用于中值滤波
int16u_t AD_Data_Change_Temp;                   //用于数据交换临时变量

              if(AD_flag==0)
              {
              AD_flag=1;
             for(count=0;count<Filter_COUNT;count++)
              {
                ADC_readResult(AD,&AD_Data_Temp[count]);
              }
              for(int i=0;i<Filter_COUNT;i++)                               //冒泡排序
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
                AD_Data=AD_Data_Temp[Filter_COUNT/2];     //取中值
              }
  return AD_Data;

    }


/*=============================================================================
函数名：AD_Send
作用  ：将采集到的AD通过CAN总线发送出去，使用CAN2 端口
备注  ：一帧数据中包含的是一条腿中三个关节的角度值，
===============================================================================*/
void AD_Send(int16u_t Joint1_AD_Data,int16u_t Joint2_AD_Data,int16u_t Joint3_AD_Data,int8u_t Leg_Number){
 CAN_MSG TxMsg2;

  int32u_t temp1,temp2,temp3;
  TxMsg2.CTRL=Can1Test[0].CTRL;
  TxMsg2.ID=Leg_Number;
  temp1=(int32u_t)Joint1_AD_Data;
  temp2=(int32u_t)Joint2_AD_Data;
  temp3=(int32u_t)Joint3_AD_Data;
  temp1=(temp1<<16)&0xFFFF0000;
  TxMsg2.Data1=temp1+temp2;
  TxMsg2.Data2=temp3;
  EW_SendData_CAN(CAN1,&TxMsg2);
}