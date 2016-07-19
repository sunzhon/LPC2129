#include"headers.h"

/*******************************************************************************
* 函数名称：Data_Control
* 入口参数：UART    串口选择
            baud    发送波特率设置
            data_bit    数据位选择，可选数据位为5,6,7,8                    
            parity  奇偶校验位
                    0：无奇偶校验位
                    1：奇校验
                    2：偶校验
                    3：强制为1
                    4：强制为0
            stop_bit 停止位选择
                    0：1个停止位
                    1：2个停止位,5数据位时为1.5个停止位
            
                          
* 描    述：设置串口通信的数据发送模式
*******************************************************************************/
void Data_Control(int8u_t UART,int16u_t baud,int8u_t data_bit,int8u_t parity_bit,int8u_t stop_bit)
    {
     switch(UART)
     {
     case 0:
            U0LCR_bit.DLAB = 1;              //使能访问除数锁存寄存器
            U0DLL = VPB_CLK*1000000/(baud*16);       //取低8位
            U0DLM = VPB_CLK*1000000/(baud*16)>>8;    //取高8位
            U0LCR_bit.DLAB = 0;              //设置完成禁止访问除数锁存寄存器
            U0LCR_bit.WLS = data_bit-5;      //设置数据位
            if(parity_bit==0)                //禁止奇偶校验
               U0LCR_bit.PE = 0;
            else                           
            { 
              U0LCR_bit.PE = 1;              //使能奇偶校验  
              U0LCR_bit.PS = parity_bit-1;   //设置校验模式            
            }
            U0LCR_bit.SBS = stop_bit;       //设置停止位
            break;
      case 1:
            U1LCR_bit.DLAB = 1;              //使能访问除数锁存寄存器
            U1DLL = VPB_CLK*1000000/(baud*16);       //取低8位
            U1DLM = VPB_CLK*1000000/(baud*16)>>8;    //取高8位
            U1LCR_bit.DLAB = 0;              //设置完成禁止访问除数锁存寄存器
            U1LCR_bit.WLS = data_bit-5;      //设置数据位
            if(parity_bit==0)                //禁止奇偶校验
               U1LCR_bit.PE = 0;
            else                           
            { 
              U1LCR_bit.PE = 1;              //使能奇偶校验  
              U1LCR_bit.PS = parity_bit-1;   //设置校验模式            
            }
            U1LCR_bit.SBS = stop_bit;       //设置停止位
            break;
             


    }
 }

/*******************************************************************************
* 函数名称：putchar
* 入口参数：UART    串口选择
            data    待发送的数据可选的位数5,6,7,8
                          
* 描    述：通过UART发送数据
*******************************************************************************/
void Putchar(int8u_t UART,int8u_t *data)
{
  switch(UART)
  {
  case 0:
    U0FCR_bit.FCRFE = 1;             //高电平使能对 UART0 Rx 和Tx FIFO 以及U0FCR[7:1]的访问
    U0THR = *data;                   //将待发送的数据写入发送保持寄存器
    while(!U0LSR_bit.THRE);          //等待发送完成
    break;
  case 1:
    U1FCR_bit.FCRFE = 1;             //高电平使能对 UART1 Rx 和Tx FIFO 以及U1FCR[7:1]的访问
    U1THR = *data;                   //将待发送的数据写入发送保持寄存器
    while(!U1LSR_bit.THRE);          //等待发送完成
    break;
  }
 
}
/*******************************************************************************
* 函数名称：Getchar
* 入口参数：UART    串口选择
            data    接收待读取的数据
                          
* 描    述：通过UART发送数据
*******************************************************************************/
void Getchar(int8u_t UART,int8u_t *data)
{
  switch(UART)
  {
  case 0:
    U0FCR_bit.FCRFE = 1;             //高电平使能对 UART0 Rx 和Tx FIFO 以及U0FCR[7:1]的访问
    if(U0LSR_bit.RDR==1)             //接收数据就绪          
    *data = U0RBR;                   //读取接收器缓存寄存器
   break;
   case 1:
    U1FCR_bit.FCRFE = 1;             //高电平使能对 UART0 Rx 和Tx FIFO 以及U0FCR[7:1]的访问
    if(U1LSR_bit.RDR==1)             //接收数据就绪          
    *data = U1RBR;                   //读取接收器缓存寄存器
   break;
  }
 
}