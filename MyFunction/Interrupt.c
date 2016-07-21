#include"headers.h"


/*******************************************************************************
描述：定时器中断函数定义
备注：均定义为1ms中断
*******************************************************************************/
void Timer0Interrupt(void)
{
  T0IR = 0xff; // 清中断标志


}

void Timer1Interrupt(void)
{
 T1IR = 0xff; // 清中断标志

}


void EW_IntHandler_RX_CAN1( void )

{       CAN_MSG RxMsg1;
        int16u_t TT1;
        int16u_t TT2;

  EW_ReceiveData_CAN(CAN1,&RxMsg1);
  Joint1_AD_Data=AD_Filter(AD1);
  Joint2_AD_Data=AD_Filter(AD2);
  Joint3_AD_Data=AD_Filter(AD3);


#ifdef Board_QY

        switch(RxMsg1.ID)
      {
      case joint1:
         TT1=(RxMsg1.Data1&0x000000FF)<<8;
         TT2=(RxMsg1.Data1&0x0000FF00)>>8;
         Joint1_Object_Angle=TT1+TT2;
          break;

      case joint2:
         TT1=(RxMsg1.Data1&0x000000FF)<<8;
         TT2=(RxMsg1.Data1&0x0000FF00)>>8;
         Joint2_Object_Angle=TT1+TT2;
          break;

      case joint3:
         TT1=(RxMsg1.Data1&0x000000FF)<<8;
         TT2=(RxMsg1.Data1&0x0000FF00)>>8;
         Joint3_Object_Angle=TT1+TT2;
         AD_Send(Joint1_AD_Data,Joint2_AD_Data,Joint3_AD_Data,Leg_QY);
          GPIO_SetPinStat(PORT0,13,0);
         break;
      default :
        break;
    }



#endif

#ifdef Board_QZ


      switch(RxMsg1.ID)
    {
    case joint1:
       TT1=(RxMsg1.Data1&0x00FF0000)>>8;
       TT2=(RxMsg1.Data1&0xFF000000)>>24;
       Joint1_Object_Angle=TT1+TT2;
        break;

    case joint2:
          TT1=(RxMsg1.Data1&0x00FF0000)>>8;
          TT2=(RxMsg1.Data1&0xFF000000)>>24;
          Joint2_Object_Angle=TT1+TT2;
      break;

    case joint3:
       TT1=(RxMsg1.Data1&0x00FF0000)>>8;
       TT2=(RxMsg1.Data1&0xFF000000)>>24;
       Joint3_Object_Angle=TT1+TT2;
      break;
    case Leg_QY:
      AD_Send(Joint1_AD_Data,Joint2_AD_Data,Joint3_AD_Data,Leg_QZ);
      GPIO_SetPinStat(PORT0,13,0);
      break;
    default:
      break;
    }

#endif

#ifdef Board_HY

      switch(RxMsg1.ID)
    {
    case joint1:
       TT1=(RxMsg1.Data2&0x000000FF)<<8;
       TT2=(RxMsg1.Data2&0x0000FF00)>>8;
       Joint1_Object_Angle=TT1+TT2;
        break;

    case joint2:
       TT1=(RxMsg1.Data2&0x000000FF)<<8;
       TT2=(RxMsg1.Data2&0x0000FF00)>>8;
       Joint2_Object_Angle=TT1+TT2;
        break;

    case joint3:
       TT1=(RxMsg1.Data2&0x000000FF)<<8;
       TT2=(RxMsg1.Data2&0x0000FF00)>>8;
       Joint3_Object_Angle=TT1+TT2;
        break;
    case Leg_QZ:
           AD_Send(Joint1_AD_Data,Joint2_AD_Data,Joint3_AD_Data,Leg_HY);
           GPIO_SetPinStat(PORT0,13,0);
           break;
    default:
      break;
    }

#endif

#ifdef Board_HZ


      switch(RxMsg1.ID)
    {
    case joint1:
       TT1=(RxMsg1.Data2&0x00FF0000)>>8;
       TT2=(RxMsg1.Data2&0xFF000000)>>24;
       Joint1_Object_Angle=TT1+TT2;
        break;
    case joint2:
        TT1=(RxMsg1.Data2&0x00FF0000)>>8;
        TT2=(RxMsg1.Data2&0xFF000000)>>24;
        Joint2_Object_Angle=TT1+TT2;
        break;

    case joint3:
       TT1=(RxMsg1.Data2&0x00FF0000)>>8;
       TT2=(RxMsg1.Data2&0xFF000000)>>24;
       Joint3_Object_Angle=TT1+TT2;
        break;
    case Leg_HY:
           AD_Send(Joint1_AD_Data,Joint2_AD_Data,Joint3_AD_Data,Leg_HZ);
           GPIO_SetPinStat(PORT0,13,0);
           break;
    default:
    break;
    }
#endif
         Joint1_Angle_PID(Joint1_Object_Angle,Joint3_AD_Data);
         Joint2_Angle_PID(Joint2_Object_Angle,Joint3_AD_Data);
         Joint3_Angle_PID(Joint3_Object_Angle,Joint3_AD_Data);

}












void EW_IntHandler_RX_CAN2( void )

{
   //GPIO_SetPinStat(PORT0,13,0);
}


void EW_IntHandler_TX_CAN1( void )

{
  ;
}

void EW_IntHandler_TX_CAN2( void )

{
  ;
}


void EW_IntHandler_OTHER_CAN( void )

{
   ;
}
