#include "headers.h"

/*******************************************************************************
* �������ƣ�GPIO_SetPinMod
* ��ڲ�����gpio   GPIO��
            pin    gpio�ڵ����ź�
            mux    �����ŵĹ��ܺ�
* ��    ��������GPIO�е� pin �����ŵĹ��ܺ�
*******************************************************************************/
void GPIO_SetPinMod (int16u_t gpio, int16u_t pin, int16u_t mux)
   {  
     
     int16u_t i=0x03;                  //ȡ�Ĵ����е���λ   
     int16u_t j=0x00;
      switch(gpio)
      {
      case 0:
        
             if(pin<=15)
	        {
	        j = i<<(pin*2);                  
            	PINSEL0 &= ~j;			 //ÿ�ζ���ǰ����Ӧλ����
	        PINSEL0 |=(mux<<(pin*2));

	        }
	      else
	          {
		    j = i<<((pin-16)*2);
            	    PINSEL1 &= ~j;			 //ÿ�ζ���ǰ����Ӧλ����
	            PINSEL1 |=(mux<<((pin-16)*2));
		  }
			 break;
        
              case 1:
	         PINSEL2=mux;              //PORT1ֻ������ͨIO��
			 break;
	      default:
                         break;	
      
      }
    }
/*******************************************************************************
* �������ƣ�GPIO_SetPinDir
* ��ڲ�����gpio   GPIO��
            pin    gpio�ڵ����ź�
            dir    gpio�ڵ��������ģʽ
                    0������
                    1�����  
* ��    ��������GPIO�е� pin λ���������ģʽ
*******************************************************************************/
void GPIO_SetPinDir(int16u_t gpio,int16u_t pin,int16u_t dir)
    {
     switch(gpio)
	  {
	    case 0:
			   if(dir==1)    				//����Ϊ���
				 IO0DIR|=1<<pin;
			   else
				 IO0DIR&=~(1<<pin);
				 break;
		case 1:
			   if(dir==1)    				//����Ϊ���
				 IO1DIR|=1<<pin;
			   else
				 IO1DIR&=~(1<<pin);
				 break;
		default:
             break;
	  
	  } 
    }
/*******************************************************************************
* �������ƣ�GPIO_SetPinStat
* ��ڲ�����gpio   GPIO��ָ��
            pin    gpio�ڵ����ź�
            state  gpio�ڵ������ƽ
			     1:�ߵ�ƽ
			     0:�͵�ƽ
* ��    ��������GPIO�е� pin λ�ĵ�ƽ
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
