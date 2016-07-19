#include"headers.h"



int16s_t Joint1_PI_Out;             //����1 PID�������
int16s_t Joint2_PI_Out;             //����2 PID�������
int16s_t Joint3_PI_Out;             //����3 PID�������
int8u_t Joint1_Temp;
int8u_t Joint2_Temp;
int8u_t Joint3_Temp;
/*=============================================================================
������   ��Joint1_Angle_PID
��ڲ��� ��Object_Data   �Ƕ�Ŀ��ֵ
��    �� ������1�ŷ����Ƕ�PID���㺯��
��    ע ������1��Ŀ��Ƕ�ֵ�ķ�ΧΪ240~462
===============================================================================*/
void Joint1_Angle_PID(int16u_t Object_Data,int16u_t AD_Data)
{
 int32s_t nP;
 int16s_t nValue;

 //printf("Joint1 Object_Data is :%d\t;AD_Data is :%d\n",Object_Data,AD_Data);
 nValue=Object_Data-AD_Data;                                   //������ƫ��


 if(nValue > 50)  nValue = 50;        //���ڱ������ֵĽǶ�ƫ���޷� 50
 if(nValue < -50) nValue = -50;



 nP = nValue * Joint1_Angle_P;          //�����

 Joint1_PI_Out=(int16u_t)(nP);


 if(Joint1_PI_Out>Joint1_PID_UP_Limit)
 {
 Joint1_PI_Out=Joint1_PID_UP_Limit;
 }
  if(Joint1_PI_Out<Joint1_PID_DOWN_Limit)
 {
 Joint1_PI_Out=Joint1_PID_DOWN_Limit;
 }

 /**************************����ͨ��DA��������ŷ���****************************/
 Joint1_PI_Out=Joint1_PI_Out+Joint1_Zero;
 Joint1_PI_Out=Joint1_PI_Out<<2;

  GPIO_SetPinStat(PORT0,7,0);
  Joint1_Temp=Joint1_PI_Out>>8;      //ȡ�߰�λ����
  SPI_Send_Data(SPI0,&Joint1_Temp);
  Joint1_Temp=Joint1_PI_Out&0xff;    //ȡ�Ͱ�λ����
  SPI_Send_Data(SPI0,&Joint1_Temp);
  GPIO_SetPinStat(PORT0,7,1);

}



/*=============================================================================
��������Joint2_Angle_PID
����  ������2�ŷ����Ƕ�PID���㺯��
��ע  ����
===============================================================================*/
void Joint2_Angle_PID(int16u_t Object_Data,int16u_t AD_Data)
{

  int32s_t nP;
  int16s_t nValue;

 //printf("Joint1 Object_Data is :%d\t;AD_Data is :%d\n",Object_Data,AD_Data);
 nValue=Object_Data-AD_Data;                                   //������ƫ��


 if(nValue > 50)  nValue = 50;        //���ڱ������ֵĽǶ�ƫ���޷� 50
 if(nValue < -50) nValue = -50;



 nP = nValue * (Joint2_Angle_P );          //�����
 Joint2_PI_Out=(int16u_t)(nP);


 if(Joint2_PI_Out>Joint2_PID_UP_Limit)
 {
 Joint2_PI_Out=Joint2_PID_UP_Limit;
 }
  if(Joint2_PI_Out<Joint2_PID_DOWN_Limit)
 {
 Joint2_PI_Out=Joint2_PID_DOWN_Limit;
 }

 /**************************����ͨ��DA��������ŷ���****************************/
 Joint2_PI_Out=Joint2_PI_Out+Joint2_Zero;
 Joint2_PI_Out=Joint2_PI_Out<<2;

  GPIO_SetPinStat(PORT0,10,0);
  Joint2_Temp=Joint2_PI_Out>>8;      //ȡ�߰�λ����
  SPI_Send_Data(SPI0,&Joint2_Temp);
  Joint2_Temp=Joint2_PI_Out&0xff;    //ȡ�Ͱ�λ����
  SPI_Send_Data(SPI0,&Joint2_Temp);
  GPIO_SetPinStat(PORT0,10,1);

}

/*=============================================================================
��������Joint2_Angle_PID
����  ������2�ŷ����Ƕ�PID���㺯��
��ע  ����
===============================================================================*/
void Joint3_Angle_PID(int16u_t Object_Data,int16u_t AD_Data)
{


    int32s_t nP;
    int16s_t nValue;

 //printf("Joint1 Object_Data is :%d\t;AD_Data is :%d\n",Object_Data,AD_Data);
 nValue=Object_Data-AD_Data;                                   //������ƫ��


 if(nValue > 50)  nValue = 50;        //���ڱ������ֵĽǶ�ƫ���޷� 50
 if(nValue < -50) nValue = -50;



 nP = nValue * (Joint3_Angle_P );          //�����

 Joint3_PI_Out=(int16u_t)(nP);

 if(Joint3_PI_Out>Joint3_PID_UP_Limit)
 {
 Joint3_PI_Out=Joint3_PID_UP_Limit;
 }
  if(Joint3_PI_Out<Joint3_PID_DOWN_Limit)
 {
 Joint3_PI_Out=Joint3_PID_DOWN_Limit;
 }

 /**************************����ͨ��DA��������ŷ���****************************/
 Joint3_PI_Out=Joint3_PI_Out+Joint3_Zero;
 Joint3_PI_Out=Joint3_PI_Out<<2;

  GPIO_SetPinStat(PORT0,11,0);
  Joint3_Temp=Joint3_PI_Out>>8;      //ȡ�߰�λ����
  SPI_Send_Data(SPI0,&Joint3_Temp);
  Joint3_Temp=Joint3_PI_Out&0xff;    //ȡ�Ͱ�λ����
  SPI_Send_Data(SPI0,&Joint3_Temp);
  GPIO_SetPinStat(PORT0,11,1);

}


/*=============================================================================
��������DA_control
����  ��������������ݱ���
��ע  ����
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
  Manipulate_Temp=Manipulate_Data>>8;      //ȡ�߰�λ����
  SPI_Send_Data(SPI0,&Manipulate_Temp);
  Manipulate_Temp=Manipulate_Data&0xff;    //ȡ�Ͱ�λ����
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
  Manipulate_Temp=Manipulate_Data>>8;      //ȡ�߰�λ����
  SPI_Send_Data(SPI0,&Manipulate_Temp);
  Manipulate_Temp=Manipulate_Data&0xff;    //ȡ�Ͱ�λ����
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
  Manipulate_Temp=Manipulate_Data>>8;      //ȡ�߰�λ����
  SPI_Send_Data(SPI0,&Manipulate_Temp);
  Manipulate_Temp=Manipulate_Data&0xff;    //ȡ�Ͱ�λ����
  SPI_Send_Data(SPI0,&Manipulate_Temp);
  GPIO_SetPinStat(PORT0,11,1);

   break;

 }


}