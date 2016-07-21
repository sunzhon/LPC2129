#ifndef _Interrupt_H
#define _Interrupt_H



extern int16u_t Status;
extern int16u_t Joint1_AD_Data;
extern int16u_t Joint2_AD_Data;
extern int16u_t Joint3_AD_Data;

extern int16u_t Joint3_Object_Angle;
extern int16u_t Joint2_Object_Angle;
extern int16u_t Joint1_Object_Angle;

extern void Timer0Interrupt(void);
extern void Timer1Interrupt(void);
extern void EW_IntHandler_RX_CAN1(void);
extern void EW_IntHandler_RX_CAN2(void);
extern void EW_IntHandler_TX_CAN1(void);
extern void EW_IntHandler_TX_CAN2(void);
extern void EW_IntHandler_OTHER_CAN(void);


#endif