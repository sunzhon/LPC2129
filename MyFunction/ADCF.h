#ifndef ADCF_H
#define ADCF_H
extern void delay(void);
extern int16u_t AD_Filter(int8u_t AD);//AD是AD采集通道，count是中值滤波次数，建议取偶数
extern void AD_Send(int16u_t Joint_AD1,int16u_t Joint_AD2,int16u_t Joint_AD3,int8u_t Leg_Number);
#endif