#ifndef _UART_H
#define _UART_H

#define UART0  0
#define UART1  1

extern void Data_Control(int8u_t UART,int16u_t baud,int8u_t data_bit,int8u_t parity_bit,int8u_t stop_bit);
extern void Putchar(int8u_t UART,int8u_t *data);
extern void Getchar(int8u_t UART,int8u_t *data);


#endif
