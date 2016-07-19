#ifndef _CAN_H
#define _CAN_H

#define CAN1 1
#define CAN2 2

#define VIC_CAN1TX_bit (1 << VIC_CAN1TX)
#define VIC_CAN1RX_bit (1 << VIC_CAN1RX)

#define VIC_CAN2TX_bit (1 << VIC_CAN2TX)
#define VIC_CAN2RX_bit (1 << VIC_CAN2RX)

#define VIC_CAN_AF_bit (1 << VIC_CAN_AF)

/*
**===========================================================================
CAN模块寄存器地址定义，用于相对基址寻址
**===========================================================================
*/
#define CAN_REG_BASE                    (0xE0000000)
#define ACCEPTANCE_FILTER_RAM_BASE      (CAN_REG_BASE + 0x00038000)
#define ACCEPTANCE_FILTER_REGISTER_BASE (CAN_REG_BASE + 0x0003C000)
#define CENTRAL_CAN_REGISTER_BASE       (CAN_REG_BASE + 0x00040000)
#define CAN_1_BASE                      (CAN_REG_BASE + 0x00044000)
#define CAN_2_BASE                      (CAN_REG_BASE + 0x00048000)

/*--- 验收滤波器相关变量定义 ---*/
#define EW_CAN_FULL            1
#define EW_CAN_STD             2
#define EW_CAN_STD_GRP         3
#define EW_CAN_EXT             4
#define EW_CAN_EXT_GRP         5

/*--- Return codes ---*/
#define EW_OK            1
#define EW_DATA          2
#define EW_RTR           3

#define EW_ERROR        4
#define EW_FULL        5
#define EW_EMPTY        6
#define EW_BUSY        7

/*--- CAN status codes ---*/
#define EW_CAN_RECEIVED        1
#define EW_CAN_OVERRUN         2
#define EW_CAN_TRANSMITTED     4
#define EW_CAN_ERROR           8
#define EW_CAN_BUS_ERROR       16
#define EW_CAN_FILTER_ERROR    32

/*--- SFR register bits ---*/
#define C1GSR_RBS  0x01        /* Bit 0: RBS (接收缓冲器状态位)  */
#define C1CMR_RRB  0x04        /* Bit 2: RRB (释放接收缓冲器) */

/*--- Don't change these values as they maps into AFMR bits ---*/

#define AcceptanceFilterOn       0x00
#define AcceptanceFilterBypass   0x03

/*--- CAN message control information constants ---*/
#define EW_CAN_CTRL_STANDARD_ID  0             //标准帧ID
#define EW_CAN_CTRL_EXTENDED_ID  0x80000000L   //扩展帧ID
#define EW_CAN_CTRL_RTR          0x40000000L   //远程帧ID


#define EW_C1MOD_CAN  0x08  
#define EW_C2MOD_CAN  0x08 
/*
**===========================================================================
** 描述：接收和发送数据结构体定义
         CTRL：Tx帧信息寄存器
         ID  ：数据标识符
         Data：发送或者接收的数据，由数据寄存器A和B储存一次最多可以发送双字
**===========================================================================
*/
typedef struct
{
    int32u_t CTRL;                           /* bit 0-7 = PRIO bits  (Priority,0-255) */
                                             /* bit 16-19 = DLC bits (Datalength,1-8) */
                                             /* bit 24-26 = CAN Controller (1-4) only used when fullCAN message received */
                                             /* bit 30=RTR bit     (EW_CTRL_RTR) 远程请求位0代表一个数据帧 1代表一个远程帧此时DLC代表请求发送的数据字节数    */
                                             /* bit 31=FF bit      (EW_CTRL_FF) 0代表标准标识符 1代表扩展标识符     */
    int32u_t ID;                             /* Extended ID bits [28:0]             */
                                             /* Standard ID bits [10:0]             */
    int32u_t Data1;                          /* Message data A                      */
    int32u_t Data2;                          /* Message data B                      */
} CAN_MSG;

/*
**===========================================================================
** 描述：验收滤波器查询标识符表格（LUT）结构体定义
         Controller：CAN控制器选择
         Disable   ：验收禁能位
               0   ：使能相应标识符验收
               1   ：禁止相应标识符验收
         ID        ：标准或者扩展标识符
**===========================================================================
*/
typedef struct
{
    int8u_t FilterType;                    /* CAN_FULL, CAN_STD, CAN_STD_GRP, CAN_EXT, CAN_EXT_GRP */
    int8u_t Controller1;                   /* Controller ID1, 1=CAN1, 2=CAN2,3=CAN3,4=CAN4 */
    int8u_t Controller2;                   /* Controller ID2, 1=CAN1, 2=CAN2,3=CAN3,4=CAN4 */
    int8u_t Disable1;                      /* 0 = Enabled, 1 = Disabled */
    int8u_t Disable2;                      /* 0 = Enabled, 1 = Disabled */
    int32u_t ID1;                          /* ID 1 (lower bound for standard/extended id group)  */
    int32u_t ID2;                          /* ID 2 (upper bound for standard/extended id group)  */
} CAN_Filter;

extern CAN_Filter CAN1Filter[];
extern CAN_Filter CAN2Filter[];
extern CAN_MSG Can1Test[];
extern CAN_MSG Can2Test[];
extern int16s_t EW_AddFilter_CAN( CAN_Filter *pNewFilter);
extern void CAN_Clk(int8u_t channel,int16u_t div,int8u_t High_Speed);
extern void Open_CAN_Interrupt(int8u_t channel,int16u_t number,int8u_t prio);
extern int16s_t EW_SendData_CAN( int8u_t Controller, CAN_MSG *pTxMsg );
extern int16s_t EW_Manage_CAN( int8u_t Controller );
extern int16s_t EW_ReceiveData_CAN( int8u_t  Controller, CAN_MSG *pRxMsg );








#endif