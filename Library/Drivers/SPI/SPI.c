#include"headers.h"

/*******************************************************************************
* 函数名称：SPI_Control
* 入口参数： channel  SPI接口
             div      选择对VPB时钟的分频数，8位寄存器，该数值必须为大于等于8的偶数最大值为254
             model    主从工作模式选择
                  1： 主机工作模式
                  0： 从机工作模式
             data_model 选择数据传输的方向
                  0： MSB →LSB
                  1： LSB →MSB
* 功    能： 设置SPI的通信速率，数据传输模式
                    
* 备    注： 默认不开启SPI中断 注意当从机采样的第一个数据是上升沿时，
             主机驱动的第一个数据必须是在第一个上升沿之前。
*******************************************************************************/
void SPI_Control(int8u_t channel,int8u_t div,int8u_t model,int8u_t data_model)
{
  switch(channel)
  {
  case 0:                                    //设置SPI0的通信参数
        if(model==1)                         //主机工作模式
        {
          S0SPCCR_bit.COUNTER = div;         //设置主机时钟
        }
          S0SPCR_bit.MSTR = model;          
          S0SPCR_bit.CPHA = 0;              //CPOL=0, CPHA=1 驱动的第一个数据在第一个SCK上升沿之前
          S0SPCR_bit.CPOL = 0;              //驱动的其他数据在 SCK上升沿 采样的数据在SCK下降沿
          S0SPCR_bit.LSBF = data_model;     //设置数据传输方向
          break;
   case 1:                                  //设置SPI0的通信参数
        if(model==1)                       //主机工作模式
        {
          S1SPCCR_bit.COUNTER = div;         //设置主机时钟
        }
          S1SPCR_bit.MSTR = model;          
          S1SPCR_bit.CPHA = 1;              //CPOL=0, CPHA=1 驱动的第一个数据在第一个SCK上升沿
          S1SPCR_bit.CPOL = 0;              //驱动的其他数据在 SCK上升沿 采样的数据在SCK下降沿
          S1SPCR_bit.LSBF = data_model;     //设置数据传输方向
          break; 
  }


}
/*******************************************************************************
* 函数名称：SPI_Send_Data
* 入口参数： channel  SPI接口
             data     要发送数据的存储地址
             
* 功    能： 将数据通过相应的SPI接口发送出去
                    

*******************************************************************************/
void SPI_Send_Data(int8u_t channel,int8u_t *data)
{    
     switch(channel)
     {
     case 0:
      S0SPDR =*data;            //将要发送的数据写入数据寄存器 
      while(!S0SPSR_bit.SPIF);    //等待发送完成 防止传输过程中再次写入数据造成写冲突
      break;
      case 1:
      S1SPDR = *data;            //将要发送的数据写入数据寄存器 
      while(!S1SPSR_bit.SPIF);    //等待发送完成 
      break;
     }
     
}
/*******************************************************************************
* 函数名称：SPI_Get_Data
* 入口参数： channel  SPI接口
             result     要发送数据的存储地址
             
* 功    能： 将数据通过相应的SPI接口发送出去
                    

*******************************************************************************/
void SPI_Get_Data(int8u_t channel,int8u_t* result)
{
  switch(channel)
     {
     case 0:
      if(S0SPSR_bit.SPIF==1)     //读缓冲区有未读出的数据
      * result = S0SPDR;          //读出接收到的数据
      break;
     case 1:
      if(S1SPSR_bit.SPIF==1)     //读缓冲区有未读出的数据
      * result = S1SPDR;          //读出接收到的数据
      break;
     }
}