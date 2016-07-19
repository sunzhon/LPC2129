#ifndef _SPI_H
#define _SPI_H

#define SPI0  0
#define SPI1  1


extern void SPI_Control(int8u_t channel,int8u_t div,int8u_t model,int8u_t data_model);
extern void SPI_Send_Data(int8u_t channel,int8u_t* data);
extern void SPI_Get_Data(int8u_t channel,int8u_t* result);


#endif
