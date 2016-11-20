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
    /*
         Joint1_Angle_PID(Joint1_Object_Angle,Joint1_AD_Data);
         Joint2_Angle_PID(Joint2_Object_Angle,Joint2_AD_Data);
         Joint3_Angle_PID(Joint3_Object_Angle,Joint3_AD_Data);
    */
    // pc104 directly control

    DA_Control(Joint1_Object_Angle,1);
    DA_Control(Joint2_Object_Angle,2);
    DA_Control(Joint3_Object_Angle,3);

}















void EW_IntHandler_RX_CAN2( void )

{



        CAN_MSG RxMsg2;
        int16u_t PP1;
        int16u_t PP2;
        int16u_t force_temp;

          EW_ReceiveData_CAN(CAN2,&RxMsg2);




#ifdef Board_QY

        switch(RxMsg2.ID)
      {
      case FORCE:
         PP1=(RxMsg2.Data1&0x000000FF)<<8;
         PP2=(RxMsg2.Data1&0x0000FF00)>>8;
         pc104para=PP1+PP2;
         fdata[2]=Force_Fliter(PORT0);
         force_temp=fdata[2];
         Force_Send(0,0,force_temp,Force_Leg_QY);

          break;

      case PIDPARA:
         PP1=(RxMsg2.Data1&0x000000FF)<<8;
         PP2=(RxMsg2.Data1&0x0000FF00)>>8;
         pc104para=PP1+PP2;
          break;

      case ADRANGE:
         PP1=(RxMsg2.Data1&0x000000FF)<<8;
         PP2=(RxMsg2.Data1&0x0000FF00)>>8;
         pc104para=PP1+PP2;
         break;
      default :
        break;
    }



#endif

#ifdef Board_QZ


      switch(RxMsg2.ID)
    {
         case Force_Leg_QY:
      fdata[2]=Force_Fliter(PORT0);
         force_temp=fdata[2];
         Force_Send(0,0,force_temp,Force_Leg_QZ);
         break;

    case PIDPARA:
          PP1=(RxMsg2.Data1&0x00FF0000)>>8;
          PP2=(RxMsg2.Data1&0xFF000000)>>24;
          pc104para=PP1+PP2;
      break;

    case ADRANGE:
       PP1=(RxMsg2.Data1&0x00FF0000)>>8;
       PP2=(RxMsg2.Data1&0xFF000000)>>24;
       pc104para=PP1+PP2;
      break;
    default:
      break;
    }

#endif

#ifdef Board_HY

      switch(RxMsg2.ID)
    {
         case Force_Leg_QZ:
      fdata[2]=Force_Fliter(PORT0);
         force_temp=fdata[2];
         Force_Send(0,0,force_temp,Force_Leg_HY);

        break;

    case PIDPARA:
       PP1=(RxMsg2.Data2&0x000000FF)<<8;
       PP2=(RxMsg2.Data2&0x0000FF00)>>8;
       pc104para=PP1+PP2;
        break;

    case ADRANGE:
       PP1=(RxMsg2.Data2&0x000000FF)<<8;
       PP2=(RxMsg2.Data2&0x0000FF00)>>8;
       pc104para=PP1+PP2;
        break;
    default:
      break;
    }

#endif

#ifdef Board_HZ


      switch(RxMsg2.ID)
    {
        case Force_Leg_HY:
      fdata[2]=Force_Fliter(PORT0);
         force_temp=fdata[2];
         Force_Send(0,0,force_temp,Force_Leg_HZ);

        break;
    case PIDPARA:
        PP1=(RxMsg2.Data2&0x00FF0000)>>8;
        PP2=(RxMsg2.Data2&0xFF000000)>>24;
        pc104para=PP1+PP2;
        break;

    case ADRANGE:
       PP1=(RxMsg2.Data2&0x00FF0000)>>8;
       PP2=(RxMsg2.Data2&0xFF000000)>>24;
       pc104para=PP1+PP2;
        break;
    default:
    break;
    }
#endif
    /*
         Joint1_Angle_PID(Joint1_Object_Angle,Joint1_AD_Data);
         Joint2_Angle_PID(Joint2_Object_Angle,Joint2_AD_Data);
         Joint3_Angle_PID(Joint3_Object_Angle,Joint3_AD_Data);
    */
    // pc104 directly control





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
