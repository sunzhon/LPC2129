#ifndef ADCF_H
#define ADCF_H
extern void delay(int16u_t flag);
extern int16u_t AD_Filter(int8u_t AD);//AD��AD�ɼ�ͨ����count����ֵ�˲�����������ȡż��
extern void AD_Send(int16u_t Joint_AD1,int16u_t Joint_AD2,int16u_t Joint_AD3,int8u_t Leg_Number);
extern int8u_t Force_Fliter(int8u_t PORT);  //force fliter
extern void Force_Send(int16u_t Force_X,int16u_t Force_Y,int16u_t Force_Z,int8u_t Leg_Number);
#endif