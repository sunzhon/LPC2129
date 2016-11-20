#include"headers.h"



/*******************************************************************************
* 函数名称：PIT_Init
* 描    述：设置定时器时间
*******************************************************************************/
void PIT_Init(void)
	{
	 PIT_setTime(Timer1,1000,3);     //1s定时器中断

	}
/*******************************************************************************
* 函数名称：GPIO_Init
* 描    述：初始化引脚功能
*******************************************************************************/
void GPIO_Init(void)
	{
	GPIO_SetPinMod (PORT0,13,0);
        GPIO_SetPinDir (PORT0,13,1);
        GPIO_SetPinMod (PORT0, 2, 0);       //选择P0.0为TXD0功能
        GPIO_SetPinDir (PORT0, 2, 1);
	}
/*******************************************************************************
* 函数名称：PWM_Init
* 描    述：初始化引脚功能
*******************************************************************************/
void PWM_Init(void)
	{
	GPIO_SetPinMod (PORT0,21,1);      //配置相应端口为PWM功能
        PWM_Control(10,10000);               //配置PWM周期 对VPB时钟进行4*1000分频
        }
/*******************************************************************************
* 函数名称：UART_Init
* 描    述：串口初始化
*******************************************************************************/
void UART_Init(void)
	{
        GPIO_SetPinMod (PORT0, 0, 1);       //选择P0.0为TXD0功能
        GPIO_SetPinMod (PORT0, 1, 1);       //选择P0.1为RXD0功能
        GPIO_SetPinStat(PORT0, 2,0);
	Data_Control(UART0,9600,8,0,1);   //UART0 9600波特率 8位数据位 无奇偶校验 1位停止位
	}
/*******************************************************************************
* 函数名称： SPI_Init
* 描    述：串口初始化
*******************************************************************************/
void SPI_Init(void)
{
  GPIO_SetPinMod (PORT0, 6, 1);    //选择SPI主机发送数据发送端口
  GPIO_SetPinMod (PORT0, 5, 1);    //选择SPI主机发送数据接收端口
  GPIO_SetPinMod (PORT0, 4, 1);    //传送时钟端口选择

  GPIO_SetPinMod (PORT0, 11,0);    //右侧片选控制端
  GPIO_SetPinDir (PORT0,11,1);     //设置为输出
   GPIO_SetPinMod (PORT0, 7,0);    //左侧片选控制端
  GPIO_SetPinDir (PORT0,7,1);      //设置为输出
   GPIO_SetPinMod (PORT0, 10,0);   //中间片选控制端
  GPIO_SetPinDir (PORT0,10,1);     //设置为输出
  SPI_Control(SPI0,240,1,0);     //VPB时钟240分频 主机模式 高位先传
}
/*******************************************************************************
* 函数名称：CAN_Init
* 描    述：设置定时器时间
*******************************************************************************/
void CAN_Init()
{
  int8u_t Filter_Count=0;

  GPIO_SetPinMod (PORT0, 23,1);    //CAN2接口功能号使能
  GPIO_SetPinMod (PORT0, 24,1);
  GPIO_SetPinMod (PORT0, 25,1);    //CAN1接口输出是默认的

  AFMR = 0x01;      // 忽略总线上接收到的信息

    /*---       进入复位模式          ---*/
  C1MOD |= 0x01;
  C2MOD |= 0x01;

  Open_CAN_Interrupt(CAN1,0,2);     //使能 CAN1接收中断 优先级为2
  Open_CAN_Interrupt(CAN2,0,3);     //使能 CAN2接收中断 优先级为3
  //为解决CAN2不进接收中断的问题，将CAN2 接收滤波器type 改为EW_CAN_STD.
  /**************关于CAN总线的设置*************************/
  //step1:滤波器
  // step2:分频系数，2是1M,4是500k,....,both of them have to same
  // step3:can1 and can2 ,both of them open interrupt, the pir have to be different


  C1GSR = 0;                        //清全局状态寄存器
  C2GSR = 0;

  CAN_Clk(CAN1,2,1);               //CAN位时间为100usec
  CAN_Clk(CAN2,2,1);

   SFF_sa     = 0;                //标准帧起始地址寄存器
   SFF_GRP_sa = 0;                //标准帧组起始地址寄存器
   EFF_sa     = 0;                //扩展帧起始地址寄存器
   EFF_GRP_sa = 0;                //扩展帧组起始地址寄存器
   ENDofTable = 0;                //AF表格终止寄存器

   AFMR = 0x04;          //启用FULLCAN模式，由验收滤波器自身来处理CAN总线上指定标准ID值的信息的接收和保存


   C1MOD = ( EW_C1MOD_CAN | 0x01 );      //复位模式下设置模式寄存器
   C2MOD = ( EW_C2MOD_CAN | 0x01 );      //发送优先级由Tx优先级域决定,且为正常工作模式

   C1MOD = ( C1MOD & ~0x01 );            //退出复位状态
   C2MOD = ( C2MOD & ~0x01 );

   Filter_Count=0;
   while ( CAN1Filter[Filter_Count].FilterType )         //加载CAN验收滤波器表格 最多有5种不同的标识符
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
* 函数名称：AD_Init
* 描    述：串口初始化
* 备    注：端口功能为默认值
*******************************************************************************/
void AD_Init(void)
	{

	  ADC_ClockCtrl(8);                 //对VPB时钟进行8分频

	}
/*******************************************************************************
* 函数名称：SetPLL
* 描    述：设置系统工作总线时钟
* 备    注：最大工作频率为60MHZ 外部晶振使用范围：10~25MHZ
*******************************************************************************/
void SetPLL(void)
	{
         int8u_t DIV_BusClk;                    //总线时钟分频数

	 PLLCFG_bit.MSEL= CORE_CLK/REF_CLK-1;
         PLLCFG_bit.PSEL= DIV_CCO_Clk;
         PLLFEED=0xAA;
         PLLFEED=0x55;
         PLLCON_bit.PLLE = 1;               // Enable the PLL
         PLLFEED=0xAA;
         PLLFEED=0x55;
         while(!(PLLSTAT & 0x0400));      //等待锁相环稳定
         PLLCON_bit.PLLC=1;               //连接锁相环作为系统时钟
         PLLFEED=0xAA;
         PLLFEED=0x55;
         DIV_BusClk=CORE_CLK/VPB_CLK;
         switch(DIV_BusClk)
         {
         case 1:
             APBDIV_bit.APBDIV = 0x01;	  //等于总线时钟
             break;
         case 2:
             APBDIV_bit.APBDIV = 0x02;    //总线时钟2分频
             break;
         case 4:
             APBDIV_bit.APBDIV = 0x00;    //总线时钟4分频
         default:
             break;                       //执行默认值总线时钟4分频
         }
        }

void System_Init(void)
    {
      SetPLL();                           //设置系统总线时钟和外围时钟
      GPIO_Init();
      CAN_Init();
      //PIT_Init();                     //定时器初始化
      AD_Init();
      SPI_Init();
      UART_Init();

    }
