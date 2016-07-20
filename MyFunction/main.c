#include"headers.h"

 int16u_t Joint1_AD_Data;
 int16u_t Joint2_AD_Data;
 int16u_t Joint3_AD_Data;
 int16u_t Joint3_Object_Angle;
 int16u_t Joint2_Object_Angle;
 int16u_t Joint1_Object_Angle;

void main(void)
    {

          __disable_interrupt();           //intrinsics.h中定义的函数

         System_Init();

          __enable_interrupt();
         Joint1_AD_Data=AD_Filter(AD1);
         Joint2_AD_Data=AD_Filter(AD2);
         Joint3_AD_Data=AD_Filter(AD3);
         Joint1_Angle_PID(300,Joint3_AD_Data);
         Joint2_Angle_PID(300,Joint3_AD_Data);
         Joint3_Angle_PID(300,Joint3_AD_Data);
#ifdef Board_QY
        AD_Send(Joint1_AD_Data,Joint2_AD_Data,Joint3_AD_Data,Leg_QY);
#endif
         for(;;)
         {
           GPIO_SetPinStat(PORT0,13,1);
           /*
          GPIO_SetPinStat(PORT0,13,0);
          delay(1000);
          GPIO_SetPinStat(PORT0,13,1);
          delay(1000);
             */
         }

    }
