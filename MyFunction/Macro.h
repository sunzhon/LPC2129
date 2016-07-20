#ifndef _Macro_H
#define _Macro_H
/*************************相关数据类型定义***************************************/
typedef unsigned char    int8u_t;     /* 8位无符号数据类型 */
typedef signed   char    int8s_t;     /* 8位有符号数据类型 */
typedef unsigned short   int16u_t;    /* 16位无符号数据类型 */
typedef signed   short   int16s_t;    /* 16位有符号数据类型 */
typedef unsigned long    int32u_t;    /* 32位无符号数据类型 */
typedef signed   long    int32s_t;    /* 32位有符号数据类型 */

typedef unsigned char byte;           /*定义字节型变量*/
typedef unsigned int  word;           /*定义字型变量*/
typedef unsigned long dword;          /*定义双字型变量*/

/*******************************系统时钟相关变量定义******************************/

#define REF_CLK         12      //外部基准振荡器(晶振)频率(单位MHz)使用锁相环时取值范围为10~25否则为1~30
#define CORE_CLK        60      //系统内核工作频率即总线时钟取值为晶振的整数倍！！！
#define VPB_CLK         30      //即pclk外围工作时钟，该值只能是内核时钟的1,2,4分频，默认值为总线时钟的4分频
#define DIV_CCO_Clk      2 	//锁相环电流振荡器频率 取值为0，1，2，3  保证   156<2^DIV_CCO_Clk*CORE_CLK<320


/******************* definen Board **************************************/
#define Board_QY


/******************* definen Leg **************************************/

#define Leg_QY 0x20
#define Leg_QZ 0x21
#define Leg_HY 0x22
#define Leg_HZ 0x23

/******************* 关节定义**************************************/
#define joint1 0x10
#define joint2 0x11
#define joint3 0x12

/******************* AD滤波**************************************/


#define Filter_COUNT 10
/******************* 后右1伺服阀相关变量定义**************************************/

#define Joint1_Zero        520           //后右1伺服阀零偏值

#define Joint1_PID_UP_Limit   510           //后右1 PID输出限幅
#define Joint1_PID_DOWN_Limit   -510           //后右1 PID输出限幅
/******************* 后右2伺服阀相关变量定义**************************************/

#define Joint2_Zero        537           //后右2伺服阀零偏值

#define Joint2_PID_UP_Limit   510           //后右3 PID输出限幅
#define Joint2_PID_DOWN_Limit   -510           //后右3 PID输出限幅
/******************* 后右3伺服阀相关变量定义**************************************/

#define Joint3_Zero        512           //后右3伺服阀零偏值

#define Joint3_PID_UP_Limit   400           //后右3 PID输出限幅
#define Joint3_PID_DOWN_Limit   -510           //后右3 PID输出限幅
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