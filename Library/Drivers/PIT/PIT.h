#ifndef _PIT_H
#define _PIT_H

#define Timer0    0
#define Timer1    1

#define VIC_TIMER0_bit (1 << VIC_TIMER0)
#define VIC_TIMER1_bit (1 << VIC_TIMER1)



extern void PIT_setTime(int8u_t timer, int32u_t time, int8u_t prio);



#endif
