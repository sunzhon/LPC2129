#include "headers.h"

/*******************************************************************************
* 函数名称：GPIO_SetPinMod
* 入口参数：gpio   GPIO口
            pin    gpio口的引脚号
            mux    该引脚的功能号
* 描    述：设置GPIO中第 pin 个引脚的功能号
*******************************************************************************/
void GPIO_SetPinMod (int16u_t gpio, int16u_t pin, int16u_t mux)
   {  
     
     int16u_t i=0x03;                  //取寄存器中的两位   
     int16u_t j=0x00;
      switch(gpio)
      {
      case 0:
        
             if(pin<=15)
	        {
	        j = i<<(pin*2);                  
            	PINSEL0 &= ~j;			 //每次定义前将相应位清零
	        PINSEL0 |=(mux<<(pin*2));

	        }
	      else
	          {
		    j = i<<((pin-16)*2);
            	    PINSEL1 &= ~j;			 //每次定义前将相应位清零
	            PINSEL1 |=(mux<<((pin-16)*2));
		  }
			 break;
        
              case 1:
	         PINSEL2=mux;              //PORT1只用于普通IO口
			 break;
	      default:
                         break;	
      
      }
    }
/*******************************************************************************
* 函数名称：GPIO_SetPinDir
* 入口参数：gpio   GPIO口
            pin    gpio口的引脚号
            dir    gpio口的输入输出模式
                    0：输入
                    1：输出  
* 描    述：设置GPIO中第 pin 位的输入输出模式
*******************************************************************************/
void GPIO_SetPinDir(int16u_t gpio,int16u_t pin,int16u_t dir)
    {
     switch(gpio)
	  {
	    case 0:
			   if(dir==1)    				//设置为输出
				 IO0DIR|=1<<pin;
			   else
				 IO0DIR&=~(1<<pin);
				 break;
		case 1:
			   if(dir==1)    				//设置为输出
				 IO1DIR|=1<<pin;
			   else
				 IO1DIR&=~(1<<pin);
				 break;
		default:
             break;
	  
	  } 
    }
/*******************************************************************************
* 函数名称：GPIO_SetPinStat
* 入口参数：gpio   GPIO口指针
            pin    gpio口的引脚号
            state  gpio口的输出电平
			     1:高电平
			     0:低电平
* 描    述：设置GPIO中第 pin 位的电平
*******************************************************************************/
void GPIO_SetPinStat(int16u_t gpio,int16u_t pin,int16u_t state)
    {
    switch(gpio)
	 		{
	   			case 0:
	          			if(state==1)
  							{
    				 		IO0SET|=1<<pin;
  							}
						else 
				     		IO0CLR|=1<<pin;
							break; 
				case 1:
						if(state==1)
  							{
    				 		IO1SET|=1<<pin;
  							}
						else 
				     		IO1CLR|=1<<pin;
							break;
				default:
             			break;    	
	 		}	
    }
