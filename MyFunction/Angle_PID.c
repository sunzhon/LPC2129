#include"headers.h"



int16u_t Joint1_PI_Out;             //后右1 PID运算输出
int16u_t Joint2_PI_Out;             //后右2 PID运算输出
int16u_t Joint3_PI_Out;             //后右3 PID运算输出
int8u_t Joint1_Temp;
int8u_t Joint2_Temp;
int8u_t Joint3_Temp;
/*=============================================================================
函数名   ：Joint1_Angle_PID
入口参数 ：Object_Data   角度目标值
作    用 ：后右1伺服阀角度PID运算函数
备    注 ：后右1的目标角度值的范围为240~462
===============================================================================*/
void Joint1_Angle_PID(int16u_t Object_Data,int16u_t AD_Data)
{
 int16s_t nP;
 int16s_t nValue;

 //printf("Joint1 Object_Data is :%d\t;AD_Data is :%d\n",Object_Data,AD_Data);
 nValue=Object_Data-AD_Data;                                   //比例项偏差


 if(nValue > 50)  nValue = 50;        //用于比例部分的角度偏差限幅 50
 if(nValue < -50) nValue = -50;
 if(nValue>0)
      nP = Joint1_Extend_P*nValue;          //求比例
 else
      nP = Joint1_Shorten_P*nValue;          //求比例


 if(nP>Joint1_PID_UP_Limit)
 {
 nP=Joint1_PID_UP_Limit;
 }
  if(nP<Joint1_PID_DOWN_Limit)
 {
 nP=Joint1_PID_DOWN_Limit;
 }

 /**************************以下通过DA输出控制伺服阀****************************/
 Joint1_PI_Out=(int16u_t)(nP+Joint1_Zero);   //从[-512,512]平移到[0,1024]
 Joint1_PI_Out=Joint1_PI_Out<<2;   //低两位，高四位 无效

  GPIO_SetPinStat(PORT0,7,0);
  Joint1_Temp=Joint1_PI_Out>>8;      //取高八位数据
  SPI_Send_Data(SPI0,&Joint1_Temp);
  Joint1_Temp=Joint1_PI_Out&0xff;    //取低八位数据
  SPI_Send_Data(SPI0,&Joint1_Temp);
  GPIO_SetPinStat(PORT0,7,1);

}



/*=============================================================================
函数名：Joint2_Angle_PID
作用  ：后右2伺服阀角度PID运算函数
备注  ：无
===============================================================================*/
void Joint2_Angle_PID(int16u_t Object_Data,int16u_t AD_Data)
{

  int16s_t nP;
  int16s_t nValue;

 //printf("Joint1 Object_Data is :%d\t;AD_Data is :%d\n",Object_Data,AD_Data);
 nValue=Object_Data-AD_Data;                                   //比例项偏差


 if(nValue > 50)  nValue = 50;        //用于比例部分的角度偏差限幅 50
 if(nValue < -50) nValue = -50;


 if(nValue>0)
      nP = Joint2_Extend_P*nValue;          //求比例
 else
      nP = Joint2_Shorten_P*nValue;          //求比例



 if(nP>Joint2_PID_UP_Limit)
 {
 nP=Joint2_PID_UP_Limit;
 }
  if(nP<Joint2_PID_DOWN_Limit)
 {
 nP=Joint2_PID_DOWN_Limit;
 }
 /**************************以下通过DA输出控制伺服阀****************************/
 Joint2_PI_Out=(int16u_t)(nP+Joint1_Zero);  //从[-512,512]平移到[0,1024]
 Joint2_PI_Out=Joint2_PI_Out<<2;           //低两位，高四位 无效

  GPIO_SetPinStat(PORT0,10,0);
  Joint2_Temp=Joint2_PI_Out>>8;      //取高八位数据
  SPI_Send_Data(SPI0,&Joint2_Temp);
  Joint2_Temp=Joint2_PI_Out&0xff;    //取低八位数据
  SPI_Send_Data(SPI0,&Joint2_Temp);
  GPIO_SetPinStat(PORT0,10,1);
}

/*=============================================================================
函数名：Joint2_Angle_PID
作用  ：后右2伺服阀角度PID运算函数
备注  ：无
===============================================================================*/
void Joint3_Angle_PID(int16u_t Object_Data,int16u_t AD_Data)
{


    int16s_t nP;
    int16s_t nValue;

 //printf("Joint1 Object_Data is :%d\t;AD_Data is :%d\n",Object_Data,AD_Data);
 nValue=Object_Data-AD_Data;                                   //比例项偏差


 if(nValue > 50)  nValue = 50;        //用于比例部分的角度偏差限幅 50
 if(nValue < -50) nValue = -50;

 if(nValue>0)
      nP = Joint3_Extend_P*nValue;          //求比例
 else
      nP = Joint3_Shorten_P*nValue;          //求比例

 if(nP>Joint3_PID_UP_Limit)
 {
 nP=Joint3_PID_UP_Limit;
 }
  if(nP<Joint3_PID_DOWN_Limit)
 {
 nP=Joint3_PID_DOWN_Limit;
 }
 /**************************以下通过DA输出控制伺服阀****************************/
 Joint3_PI_Out=(int16u_t)(nP+Joint1_Zero);
 Joint3_PI_Out=Joint3_PI_Out<<2;             //低两位，高四位 无效

  GPIO_SetPinStat(PORT0,11,0);
  Joint3_Temp=Joint3_PI_Out>>8;      //取高八位数据
  SPI_Send_Data(SPI0,&Joint3_Temp);
  Joint3_Temp=Joint3_PI_Out&0xff;    //取低八位数据
  SPI_Send_Data(SPI0,&Joint3_Temp);
  GPIO_SetPinStat(PORT0,11,1);

}


/*=============================================================================
函数名：DA_control
作用  ：控制器输出操纵变量
备注  ：无
===============================================================================*/
void DA_Control(int16s_t Manipulate_Data,int8u_t Joint){

  int8u_t  Manipulate_Temp;

 switch(Joint){
 case 1:
      if(Manipulate_Data>Joint1_PID_UP_Limit)
 {
 Manipulate_Data=Joint1_PID_UP_Limit;
 }
  if(Manipulate_Data<Joint1_PID_DOWN_Limit)
 {
 Manipulate_Data=Joint1_PID_DOWN_Limit;
 }

  Manipulate_Data=Manipulate_Data+Joint1_Zero;
  Manipulate_Data=Manipulate_Data<<2;

  GPIO_SetPinStat(PORT0,7,0);
  Manipulate_Temp=Manipulate_Data>>8;      //取高八位数据
  SPI_Send_Data(SPI0,&Manipulate_Temp);
  Manipulate_Temp=Manipulate_Data&0xff;    //取低八位数据
  SPI_Send_Data(SPI0,&Manipulate_Temp);
  GPIO_SetPinStat(PORT0,7,1);

   break;
 case 2:
      if(Manipulate_Data>Joint2_PID_UP_Limit)
 {
 Manipulate_Data=Joint2_PID_UP_Limit;
 }
  if(Manipulate_Data<Joint2_PID_DOWN_Limit)
 {
 Manipulate_Data=Joint2_PID_DOWN_Limit;
 }

  Manipulate_Data=Manipulate_Data+Joint2_Zero;
   Manipulate_Data=Manipulate_Data<<2;


     GPIO_SetPinStat(PORT0,10,0);
  Manipulate_Temp=Manipulate_Data>>8;      //取高八位数据
  SPI_Send_Data(SPI0,&Manipulate_Temp);
  Manipulate_Temp=Manipulate_Data&0xff;    //取低八位数据
  SPI_Send_Data(SPI0,&Manipulate_Temp);
  GPIO_SetPinStat(PORT0,10,1);

   break;
 case 3:
      if(Manipulate_Data>Joint3_PID_UP_Limit)
 {
 Manipulate_Data=Joint3_PID_UP_Limit;
 }
  if(Manipulate_Data<Joint3_PID_DOWN_Limit)
 {
 Manipulate_Data=Joint3_PID_DOWN_Limit;
 }

  Manipulate_Data=Manipulate_Data+Joint3_Zero;
   Manipulate_Data=Manipulate_Data<<2;

     GPIO_SetPinStat(PORT0,11,0);
  Manipulate_Temp=Manipulate_Data>>8;      //取高八位数据
  SPI_Send_Data(SPI0,&Manipulate_Temp);
  Manipulate_Temp=Manipulate_Data&0xff;    //取低八位数据
  SPI_Send_Data(SPI0,&Manipulate_Temp);
  GPIO_SetPinStat(PORT0,11,1);

   break;

 }


}