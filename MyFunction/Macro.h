#ifndef _Macro_H
#define _Macro_H
/*************************����������Ͷ���***************************************/
typedef unsigned char    int8u_t;     /* 8λ�޷����������� */
typedef signed   char    int8s_t;     /* 8λ�з����������� */
typedef unsigned short   int16u_t;    /* 16λ�޷����������� */
typedef signed   short   int16s_t;    /* 16λ�з����������� */
typedef unsigned long    int32u_t;    /* 32λ�޷����������� */
typedef signed   long    int32s_t;    /* 32λ�з����������� */

typedef unsigned char byte;           /*�����ֽ��ͱ���*/
typedef unsigned int  word;           /*�������ͱ���*/
typedef unsigned long dword;          /*����˫���ͱ���*/

/*******************************ϵͳʱ����ر�������******************************/

#define REF_CLK         12      //�ⲿ��׼����(����)Ƶ��(��λMHz)ʹ�����໷ʱȡֵ��ΧΪ10~25����Ϊ1~30
#define CORE_CLK        60      //ϵͳ�ں˹���Ƶ�ʼ�����ʱ��ȡֵΪ�����������������
#define VPB_CLK         30      //��pclk��Χ����ʱ�ӣ���ֵֻ�����ں�ʱ�ӵ�1,2,4��Ƶ��Ĭ��ֵΪ����ʱ�ӵ�4��Ƶ
#define DIV_CCO_Clk      2 	//���໷��������Ƶ�� ȡֵΪ0��1��2��3  ��֤   156<2^DIV_CCO_Clk*CORE_CLK<320


/******************* definen Board **************************************/
#define Board_QY


/******************* definen Leg **************************************/

#define Leg_QY 0x20
#define Leg_QZ 0x21
#define Leg_HY 0x22
#define Leg_HZ 0x23

/******************* �ؽڶ���**************************************/
#define joint1 0x10
#define joint2 0x11
#define joint3 0x12

/******************* AD�˲�**************************************/


#define Filter_COUNT 10
/******************* ����1�ŷ�����ر�������**************************************/

#define Joint1_Zero        520           //����1�ŷ�����ƫֵ

#define Joint1_PID_UP_Limit   510           //����1 PID����޷�
#define Joint1_PID_DOWN_Limit   -510           //����1 PID����޷�
/******************* ����2�ŷ�����ر�������**************************************/

#define Joint2_Zero        537           //����2�ŷ�����ƫֵ

#define Joint2_PID_UP_Limit   510           //����3 PID����޷�
#define Joint2_PID_DOWN_Limit   -510           //����3 PID����޷�
/******************* ����3�ŷ�����ر�������**************************************/

#define Joint3_Zero        512           //����3�ŷ�����ƫֵ

#define Joint3_PID_UP_Limit   400           //����3 PID����޷�
#define Joint3_PID_DOWN_Limit   -510           //����3 PID����޷�
/**********************PID parameter *****************************/
#ifdef Board_QY
#define Joint1_Angle_P   12
#define Joint2_Angle_P   12
#define Joint3_Angle_P   12
#endif

#ifdef Board_QZ
#define Joint1_Angle_P   12
#define Joint2_Angle_P   12
#define Joint3_Angle_P   12
#endif
#ifdef Board_HY

#define Joint1_Angle_P   12
#define Joint2_Angle_P   12
#define Joint3_Angle_P   12
#endif

#ifdef Board_HZ
#define Joint1_Angle_P   12
#define Joint2_Angle_P   12
#define Joint3_Angle_P   12
#endif


#endif