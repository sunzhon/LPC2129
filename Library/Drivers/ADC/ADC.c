#include"headers.h"


/*******************************************************************************
* 函数名称：ADC_ClockCtrl
* 入口参数：adc_clkdiv    AD时钟分频选择
                    
* 描    述：设置AD时钟源 对VPB时钟进行分频 分频后的最大值为4.5MHZ
*******************************************************************************/
void ADC_ClockCtrl(int8u_t adiv)
{
      ADCR_bit.CLKDIV =   adiv-1;        //对VPB时钟进行adiv分频得到AD转换时钟
  
}

/*******************************************************************************
* 函数名称：ADC_readResult
* 入口参数：channel    AD转换通道选择
                    
* 描    述：读取相应通道的AD转换结果
*******************************************************************************/
void ADC_readResult(int8u_t channel, int16u_t *result)
    {  
            ADCR_bit.SEL = 0x01<<channel;
            ADCR_bit.PDN = 1;               //正常工作模式
            ADCR_bit.START = 1;             //启动AD转换
            while(!(ADDR_bit.DONE));        //等待AD转换结束
            *result = ADDR_bit.RESULT;       //读取AD转换结果
            
    }

