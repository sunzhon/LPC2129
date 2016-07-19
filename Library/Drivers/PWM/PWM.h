#ifndef _PWM_H
#define _PWM_H

#define PWM1 1
#define PWM2 2
#define PWM3 3
#define PWM4 4
#define PWM5 5
#define PWM6 6

extern void PWM_Control(int32u_t div,int32u_t period);
extern void PWM_Set(int8u_t channel,int32u_t dty);



#endif