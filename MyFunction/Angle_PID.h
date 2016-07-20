#ifndef _Angle_PID_H
#define _Angle_PID_H


 void Joint1_Angle_PID(int16u_t Object_Data,int16u_t AD_Data);
 void Joint2_Angle_PID(int16u_t Object_Data,int16u_t AD_Data);
 void Joint3_Angle_PID(int16u_t Object_Data,int16u_t AD_Data);

 void DA_Control(int16s_t Manipulate_Data,int8u_t Joint);


#endif
