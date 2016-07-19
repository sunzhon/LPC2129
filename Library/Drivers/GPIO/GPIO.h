#ifndef _GPIO_H
#define _GPIO_H

#define PORT0   0
#define PORT1   1



extern void GPIO_SetPinMod(int16u_t gpio, int16u_t pin, int16u_t mux);
extern void GPIO_SetPinDir(int16u_t gpio,int16u_t pin,int16u_t dir);
extern void GPIO_SetPinStat(int16u_t gpio,int16u_t pin,int16u_t state);




#endif
