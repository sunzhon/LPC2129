#ifndef _ADC_H
#define _ADC_H

#define AD0  0
#define AD1  1
#define AD2  2
#define AD3  3


extern void ADC_ClockCtrl(int8u_t adiv);
extern void ADC_readResult(int8u_t channel, int16u_t *result);





#endif
