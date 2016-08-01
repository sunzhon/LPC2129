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
         Joint1_Object_Angle=300;
         Joint2_Object_Angle=300;
         Joint3_Object_Angle=300;
         Joint1_Angle_PID(Joint1_Object_Angle,Joint1_AD_Data);
         Joint2_Angle_PID(Joint2_Object_Angle,Joint2_AD_Data);
         Joint3_Angle_PID(Joint3_Object_Angle,Joint3_AD_Data);
#ifdef Board_QY
        AD_Send(Joint1_AD_Data,Joint2_AD_Data,Joint3_AD_Data,Leg_QY);
#endif
         for(;;)
         {

          GPIO_SetPinStat(PORT0,13,1);
        /* Joint1_AD_Data=AD_Filter(AD1);
         Joint2_AD_Data=AD_Filter(AD2);
         Joint3_AD_Data=AD_Filter(AD3);
         Joint1_Object_Angle=450;
         Joint2_Object_Angle=450;
         Joint3_Object_Angle=300;
         GPIO_SetPinStat(PORT0,13,0);
         Joint1_Angle_PID(Joint1_Object_Angle,Joint1_AD_Data);
         Joint2_Angle_PID(Joint2_Object_Angle,Joint2_AD_Data);
         Joint3_Angle_PID(Joint3_Object_Angle,Joint3_AD_Data);
         //  DA_Control(300,1);
         //  DA_Control(0,1);
         //  DA_Control(-300,1);

          AD_Send(4,5,6,Leg_QZ);
          AD_Send(7,8,9,Leg_HY);
          AD_Send(10,10,12,Leg_HZ);

         */
         }

    }
