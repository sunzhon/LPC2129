#include"headers.h"


/*******************************************************************************
* 函数名称：PWM_Control
* 入口参数： div      选择时钟分频数
             period   满占空比计数值
* 功    能： 对VPB时钟进行div*period 分频
                    
* 描    述：所有通道均设置为单边沿输出 若设置为双边沿输出使用2，4，6通道
*******************************************************************************/
void PWM_Control(int32u_t div,int32u_t period)
    {
     
     PWMTCR_bit.PWMEN=0;       //关闭PWM模式
     PWMTCR_bit.CE=0;          //禁止定时器计数器计数
     PWMPR = div-1;           //对VPB时钟进行div分频
     PWMMR0 = period;          //设置满占空比计数值
     PWMMCR = 0x02;            //匹配时不对定时器计数器值进行任何操作 满占空比匹配时清0
     PWMTCR_bit.CE=1;       //启动定时计数器计数
     PWMTCR_bit.PWMEN=1;    //开启PWM模式        
     PWMPCR = 0x7E00;       //选择但边沿模式并使能PWM输出 
       
    }

/*******************************************************************************
* 函数名称：PWM_Set
* 入口参数： channel     选择PWM通道

             dty         设置相应通道占空比
        
                    
* 备注：新设置的dty将在PWMLER对应位置位和匹配0（即定时器计数器清零）发生时写入对应匹配寄存器
        PWMLER自动清零
*******************************************************************************/
void PWM_Set(int8u_t channel,int32u_t dty)
    {
    switch(channel)           //设置相应通道占空比
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


