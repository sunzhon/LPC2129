#ifndef _Angle_PID_H
#define _Angle_PID_H


 
extern int16s_t Joint1_PI_Out;             //后右1 PID运算输出
extern int16s_t Joint2_PI_Out;             //后右2 PID运算输出
extern int16s_t Joint3_PI_Out;             //后右3 PID运算输出

extern void Joint1_Angle_PID(int16u_t Object_Data,int16u_t AD_Data);
extern void Joint2_Angle_PID(int16u_t Object_Data,int16u_t AD_Data);
extern void Joint3_Angle_PID(int16u_t Object_Data,int16u_t AD_Data);

extern void DA_Control(int16s_t Manipulate_Data,int8u_t Joint);


#endif
