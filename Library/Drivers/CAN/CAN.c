#include"headers.h"


/**----------------------------------------------------------------------------------------
描述：定义CAN1和CAN2的全局验收滤波器表格，共包含8个FULLCAN模式标准标识符，2个标准标识符，
      2个标准标识符组，2个扩展标识符1个扩展标识符组
      通过调用EW_AddFilter_CAN（）将其顺序的放到验收滤波器RAM中
**----------------------------------------------------------------------------------------*/
#ifdef Board_QY
CAN_Filter CAN1Filter[] = {
/* Filter         Controller, Disable,  ID,        ID       */
/*  Type           1  2        1  2     1          2        */
{ EW_CAN_STD,     0, 0,       0, 0,     0x10,      0x11  },    /* Standard ID 0x10, 0x11 */
{ EW_CAN_STD,     0, 0,       0, 0,     0x12,      0x13  },    /* Standard ID 0x12, 0x17 */
{ EW_CAN_STD,     0, 0,       0, 0,     0x14,      0x15  },    /* Standard ID 0x18, 0x1E */
{ EW_CAN_STD,      0, 0,       0, 0,    0x26,      0x27 },    /* Standard ID 0x500-0x580 */
{ EW_CAN_EXT,      0, 0,       0, 0,    0x123456,  0 },        /* Extended ID 0x123456 */
{ EW_CAN_EXT,      0, 0,       0, 0,    0x222333,  0 },        /* Extended ID 0x222333 */
{ EW_CAN_EXT_GRP,  0, 0,       0, 0,    0x300000,  0x400000 }, /* Extended ID 0x300000-0x400000 */
{ 0,               0, 0,       0, 0,    0,         0 },        /* End of table */
};


#endif

#ifdef Board_QZ
CAN_Filter CAN1Filter[] = {
/* Filter         Controller, Disable,  ID,        ID       */
/*  Type           1  2        1  2     1          2        */
{ EW_CAN_STD,     0, 0,       0, 0,     0x10,      0x11  },    /* Standard ID 0x10, 0x11 */
{ EW_CAN_STD,     0, 0,       0, 0,     0x12,      0x13  },    /* Standard ID 0x12, 0x17 */
{ EW_CAN_STD,     0, 0,       0, 0,     0x14,      0x15  },    /* Standard ID 0x18, 0x1E */
{ EW_CAN_STD,      0, 0,       0, 0,    0x20,      0x27 },    /* Standard ID 0x500-0x580 */
{ EW_CAN_EXT,      0, 0,       0, 0,    0x123456,  0 },        /* Extended ID 0x123456 */
{ EW_CAN_EXT,      0, 0,       0, 0,    0x222333,  0 },        /* Extended ID 0x222333 */
{ EW_CAN_EXT_GRP,  0, 0,       0, 0,    0x300000,  0x400000 }, /* Extended ID 0x300000-0x400000 */
{ 0,               0, 0,       0, 0,    0,         0 },        /* End of table */
};

#endif

#ifdef Board_HY
CAN_Filter CAN1Filter[] = {
/* Filter         Controller, Disable,  ID,        ID       */
/*  Type           1  2        1  2     1          2        */
{ EW_CAN_STD,     0, 0,       0, 0,     0x10,      0x11  },    /* Standard ID 0x10, 0x11 */
{ EW_CAN_STD,     0, 0,       0, 0,     0x12,      0x13  },    /* Standard ID 0x12, 0x17 */
{ EW_CAN_STD,      0, 0,       0, 0,    0x21,      0x25 },    /* Standard ID 0x203-0x206 */
{ EW_CAN_STD,      0, 0,       0, 0,    0x26,      0x27 },    /* Standard ID 0x500-0x580 */
{ EW_CAN_EXT,      0, 0,       0, 0,    0x123456,  0 },        /* Extended ID 0x123456 */
{ EW_CAN_EXT,      0, 0,       0, 0,    0x222333,  0 },        /* Extended ID 0x222333 */
{ EW_CAN_EXT_GRP,  0, 0,       0, 0,    0x300000,  0x400000 }, /* Extended ID 0x300000-0x400000 */
{ 0,               0, 0,       0, 0,    0,         0 },        /* End of table */
};


#endif

#ifdef Board_HZ

CAN_Filter CAN1Filter[] = {
/* Filter         Controller, Disable,  ID,        ID       */
/*  Type           1  2        1  2     1          2        */
{ EW_CAN_STD,     0, 0,       0, 0,     0x10,      0x11  },    /* Standard ID 0x10, 0x11 */
{ EW_CAN_STD,     0, 0,       0, 0,     0x12,      0x13  },    /* Standard ID 0x12, 0x17 */
{ EW_CAN_STD,      0, 0,       0, 0,    0x22,      0x25 },    /* Standard ID 0x203-0x206 */
{ EW_CAN_STD,      0, 0,       0, 0,    0x26,      0x27 },    /* Standard ID 0x500-0x580 */
{ EW_CAN_EXT,      0, 0,       0, 0,    0x123456,  0 },        /* Extended ID 0x123456 */
{ EW_CAN_EXT,      0, 0,       0, 0,    0x222333,  0 },        /* Extended ID 0x222333 */
{ EW_CAN_EXT_GRP,  0, 0,       0, 0,    0x300000,  0x400000 }, /* Extended ID 0x300000-0x400000 */
{ 0,               0, 0,       0, 0,    0,         0 },        /* End of table */
};


#endif

CAN_Filter CAN2Filter[] = {
/* Filter         Controller, Disable,  ID,        ID       */
/*  Type           1  2        1  2     1          2        */
{ EW_CAN_STD,     1, 1,       0, 0,    0x30,      0x31  },    /* Standard ID 0x10, 0x12 */
{ EW_CAN_STD,     1, 1,       0, 0,    0x32,      0x33  },    /* Standard ID 0x23, 0x24 */
{ EW_CAN_STD,     1, 1,       0, 0,    0x34,      0x35  },    /* Standard ID 0x26, 0x27 */
{ EW_CAN_STD,     1, 1,       0, 0,    0x50,      0x51  },    /* Standard ID 0x29, 0x2A */
{ EW_CAN_STD,      1, 1,       0, 0,    0x52,     0x53 },    /* Standard ID 0x150, 0x151 */
{ EW_CAN_STD_GRP,  1, 1,       0, 0,    0x600,     0x620 },    /* Standard ID 0x600-0x620 */
{ EW_CAN_STD_GRP,  1, 1,       0, 0,    0x700,     0x780 },    /* Standard ID 0x700-0x780 */
{ EW_CAN_EXT,      1, 1,       0, 0,    0x334455,  0 },        /* Extended ID 0x334455 */
{ EW_CAN_EXT,      1, 1,       0, 0,    0x444666,  0 },        /* Extended ID 0x444555 */
{ EW_CAN_EXT_GRP,  1, 1,       0, 0,    0x500000,  0x600000 }, /* Extended ID 0x500000-0x600000 */
{ 0,               0, 0,       0, 0,    0,         0 },        /* End of table */
};

/**----------------------------------------------------------------------------------------
描述：定义CAN1和CAN2要发送的数据帧信息，注意要和对应的验收滤波器标识符对应
**----------------------------------------------------------------------------------------*/
CAN_MSG Can1Test[] = {
/* CTRL                                                   | ID         | Data1      | Data2       */
/* Priority,0-255, DLC bits, RTR,     Frame format        | ID         | Data1      | Data2       */
{   1            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x10,        0x11111111L, 0x22222222L },  // 0
{   2            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x11,        0x33333333L, 0x44444444L },  // 1
{   3            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x12,        0x11111111L, 0x22222222L },  // 2
{   4            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x13,        0x11111111L, 0x22222222L },  // 3
{   5            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x14,        0x33333333L, 0x44444444L },  // 4
{   6            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x15,        0x33333333L, 0x44444444L },  // 5
{   7            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x16,        0x33333333L, 0x44444444L },  // 6
{   0            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x17,        0x33333333L, 0x44444444L },  // 7
{   8            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x151,       0x88888888L, 0x09999999L },  // 8
{   8            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x600,       0x33333333L, 0x44444444L },  // 9
{   8            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x620,       0x33333333L, 0x44444444L },  // 10
{   8            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x700,       0x33333333L, 0x44444444L },  // 11
{   8            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x780,       0x33333333L, 0x44444444L },  // 12
{   8            + (8<<16) +  0  +EW_CAN_CTRL_EXTENDED_ID, 0x334455L,   0x12345678L, 0x12345678L },  // 13
{   8            + (8<<16) +  0  +EW_CAN_CTRL_EXTENDED_ID, 0x444666L,   0x12345678L, 0x12345678L },  // 14
{   8            + (8<<16) +  0  +EW_CAN_CTRL_EXTENDED_ID, 0x500000L,   0x12345678L, 0x12345678L },  // 15
};

CAN_MSG Can2Test[] = {
/* CTRL                                               | ID         | Data1      | Data2       */
/* Priority,0-255, DLC bits, RTR, Frame format        | ID         | Data1      | Data2       */
{   0            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x21,        0x55555555L, 0x66666666L },  // 0
{   1            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x22,        0x77777777L, 0x88888888L },  // 1
{   2            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x23,        0x77777777L, 0x88888888L },  // 2
{   3            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x24,        0x77777777L, 0x88888888L },  // 3
{   4            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x25,        0x77777777L, 0x88888888L },  // 4
{   5            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x26,        0x77777777L, 0x88888888L },  // 5
{   6            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x27,        0x77777777L, 0x88888888L },  // 6
{   7            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x28,        0x77777777L, 0x88888888L },  // 7
{   8            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x140,       0x77777777L, 0x88888888L },  // 8
{   8            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x142,       0x77777777L, 0x88888888L },  // 9
{   8            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x204,       0x77777777L, 0x88888888L },  // 10
{   8            + (8<<16) +  0  +EW_CAN_CTRL_STANDARD_ID, 0x500,       0x77777777L, 0x88888888L },  // 11
{   8            + (8<<16) +  0  +EW_CAN_CTRL_EXTENDED_ID, 0x123456L,   0x12345678L, 0x12345678L },  // 12
{   8            + (8<<16) +  0  +EW_CAN_CTRL_EXTENDED_ID, 0x222333L,   0x12345678L, 0x12345678L },  // 13
{   8            + (8<<16) +  0  +EW_CAN_CTRL_EXTENDED_ID, 0x300000L,   0x77777777L, 0x88888888L },  // 14
{   8            + (8<<16) +  0  +EW_CAN_CTRL_EXTENDED_ID, 0x400000L,   0x77777777L, 0x88888888L },  // 15
};

/*******************************************************************************
* 函数名称：Open_CAN_Interrupt
* 入口参数：channel         CAN模块选择
            number          中断号
            priority        中断优先级
           number           名称
             0               RX
             1               TX1
             9               TX2
             10              TX3
* 描    述：CAN模块可以产生三种类型的中断，接收中断、发送中断和其他类型中断
            接收中断：共有RX1和RX2两个中断通道中断向量号分别为26和27
            发送中断：共有TX1和TX2两个中断通道中断向量号分别为20和21
            其他类型：这部分主要是发生错误时的中断和验收滤波器LUTerr条件相或产生一个中断，中断向量号为

*******************************************************************************/
void Open_CAN_Interrupt(int8u_t channel,int16u_t number,int8u_t prio)
    {
     int32u_t volatile *VIC_Cntl_address;
     int32u_t volatile *VIC_address;
     VIC_Cntl_address = &VICVectCntl0+ prio;     //中断优先级设置寄存器地址
     VIC_address = &VICVectAddr0+prio;           //向量中断函数入口地址 ，该VICVectAddr0地址内已经写好了个向量服务函数的地址
     switch(channel)
     {
     case 1:

           C1IER |=(1<<number);
           if(number==0)
           {
             VICIntSelect &= ~VIC_CAN1RX_bit;              //选择对应中断为IRQ中断类型
             *VIC_Cntl_address = 0x20|VIC_CAN1RX;          //接收中断
             *VIC_address = (int32u_t)&EW_IntHandler_RX_CAN1;   //服务函数地址写到向量地址中
              VICIntEnable |= VIC_CAN1RX_bit;
           }
           else if(number==1|number==9|number==10)        //三个发送中断
           {
             VICIntSelect &= ~VIC_CAN1TX_bit;
             *VIC_Cntl_address = 0x20|VIC_CAN1TX;
             *VIC_address = (int32u_t)&EW_IntHandler_TX_CAN1;
              VICIntEnable |= VIC_CAN1TX_bit;
           }
           else
           {
             VICIntSelect &= ~VIC_CAN_AF_bit;
             *VIC_Cntl_address = 0x20|VIC_CAN_AF;           //其他中断
             *VIC_address = (int32u_t)&EW_IntHandler_OTHER_CAN;
             VICIntEnable |= VIC_CAN_AF_bit;

           }
           break;
      case 2:
           C2IER |=(1<<number);
           if(number==0)
           {
             VICIntSelect &= ~VIC_CAN2RX_bit;
             *VIC_Cntl_address = 0x20|VIC_CAN2RX;               //接收中断
             *VIC_address = (int32u_t)&EW_IntHandler_RX_CAN2;
             VICIntEnable |= VIC_CAN2RX_bit;
           }
           else if(number==1|number==9|number==10)        //三个发送中断
           {
             VICIntSelect &= ~VIC_CAN2TX_bit;             //对应的中断请求分配为IRQ
             *VIC_Cntl_address = 0x20|VIC_CAN2TX;
             *VIC_address = (int32u_t)&EW_IntHandler_TX_CAN2;
              VICIntEnable |= VIC_CAN2TX_bit;
           }
           else
           {
             VICIntSelect &= ~VIC_CAN_AF_bit;
             *VIC_Cntl_address = 0x20|VIC_CAN_AF;         //其他中断
             *VIC_address = (int32u_t)&EW_IntHandler_OTHER_CAN;
             VICIntEnable |= VIC_CAN_AF_bit;
           }
           break;
     default:
           break;
      }

    }
/*******************************************************************************
* 函数名称：CAN_Clk
* 入口参数：channel     CAN通道选择
            div         CAN时间份额=VPB时钟/div
            High_Speed  1：总线采样3次，用于中低速总线
                        0：总线采样1次，用于高速总线


* 描    述：设置CAN总线的位传播速率
*******************************************************************************/
void CAN_Clk(int8u_t channel,int16u_t div,int8u_t High_Speed)
    {
     switch(channel)
     {
     case 1:
            C1BTR_bit.BRP = div-1;
            C1BTR_bit.SAM = High_Speed;
            C1BTR_bit.SJW = 0;               //同步跳转宽度，规定了每次矫正相位误差的最大值
            C1BTR_bit.TSEG1 = 11;
            C1BTR_bit.TSEG2 = 1;
            break;
     case 2:
            C2BTR_bit.BRP = div-1;
            C2BTR_bit.SAM = High_Speed;
            C2BTR_bit.SJW = 0;               //同步跳转宽度，规定了每次矫正相位误差的最大值
            C2BTR_bit.TSEG1 = 11;
            C2BTR_bit.TSEG2 = 1;
            break;
     default:
            break;


     }

    }


int16s_t EW_SendData_CAN( int8u_t Controller, CAN_MSG *pTxMsg )

{
    int16s_t  ErrorCode;

    int32u_t *pAddr;                      //地址寄存器
    int32u_t offset;
    int32u_t tx_buf;

    ErrorCode = EW_OK;                    //ErrorCode=1


/**********************找到可用的发送缓冲器************************************************/
    pAddr = (int32u_t *) &C1SR;
    offset = (Controller - 1) * 0x1000L;   //强制转换为32位寄存器后每次加一代表四个地址
    pAddr += offset;                       //偏移地址用于选择不同的CAN模块

    if( *pAddr & 0x4L )           //状态寄存器的2,10,18表示了三个发送缓冲区的状态，1代表可以写入数据
    {
        /*--- Buffer 0 ---*/
        tx_buf = 0;               //表示发送缓冲器Tx1可用
    }

    else
    {
        return EW_BUSY;           //发送寄存器都在忙
    }

    pAddr = (int32u_t *) &C1TFI1;    //强制类型转换，8位为一个地址
    pAddr += offset;                 //偏移地址
    pAddr += tx_buf;

    /*--- Write transmit frame - Priority, DLC bits, RTR, Frame format ---*/
    *pAddr = pTxMsg->CTRL;           //32位寄存器

    /*--- Write ID ---*/
    pAddr++;
    *pAddr = pTxMsg->ID;

    /*--- Write data ---*/
    pAddr++;
    *pAddr = pTxMsg->Data1;
    pAddr++;
    *pAddr = pTxMsg->Data2;

    /*--- Transmission Request Buffer x ---*/
    if( tx_buf == 0 )
    {
        tx_buf = 2;
    }

    /*--- Set the STPx bit (Tx buffer transmission bit for Buffer x) ---*/
    pAddr = (int32u_t *) &C1CMR;
    pAddr += offset;
    *pAddr = (tx_buf << 4)+1;     //选择发送Tx缓冲区1的内容并启动一次发送

    return ErrorCode;

}

/*******************************************************************************
* 函数名称：EW_AddFilter_CAN
* 入口参数：pNewFilter   LUT表格结构体指针变量
* 返回值  ：添加验收滤波器表格状态
            EW_FULL：验收滤波器表格已满
            EW_OK  ：添加新的验收滤波器标识符成功
            EW_ERROR：添加出错
* 描    述：执行函数后可以根据验收滤波器的类型将其按顺序添加的相应的位置并返回添加结果
*******************************************************************************/
int16s_t EW_AddFilter_CAN( CAN_Filter *pNewFilter )

{
    int32u_t ii, Size;                   //用于验证滤波器表格是否已满
    int32u_t FilterID;                   //滤波器表格的一行
    int32u_t Address;
    int32u_t *pFilter;                    //存放验收滤波器RAM基地址
    int32u_t id0, id1, id3, id4;


    /*---首先检验验收滤波器表格是否已经满了---*/
    Size = ENDofTable + 4;           //验收滤波器表格每一行占用4个地址值，添加完成后的起始地址为ENDofTable + 4
    Size += SFF_sa * 6;              //一共有1/2*SFF_sa个FULLCAN标准标识符，应该预留12*1/2*SFF_sa地址的自动接收空间
    if( Size > 0x7ff )               //验收滤波器最大的地址空间就是0x000~0x7ff
    {
        return EW_FULL;              // 验收滤波器表格已满
    }

    switch ( pNewFilter->FilterType )   //三个case做相同的处理时可以什么都不写，只在最后一个后面写上要进行的处理
    {
    case EW_CAN_FULL:         //case 1
    case EW_CAN_STD:          //case 2                 //标准帧
    case EW_CAN_STD_GRP:      //case 3                 //标准帧组
        /*--- Prepare new pair of IDs ---*/
        FilterID = pNewFilter->ID1;                    /* ID lower */
        FilterID |= ( pNewFilter->Disable1 << 12);     /* Disable bit */
        FilterID |= ( pNewFilter->Controller1 << 13);  /* Controller */
        FilterID <<= 16;                               /* shift to lower column */

        FilterID |= pNewFilter->ID2;                   /* ID upper */
        FilterID |= ( pNewFilter->Disable1 << 12);     /* Disable bit */
        FilterID |= ( pNewFilter->Controller2 << 13);  /* Controller */
        break;

    case EW_CAN_EXT:            //case 4
    case EW_CAN_EXT_GRP:        //case 5               //扩展帧组
        /*--- Prepare new extend ID ---*/
        FilterID = pNewFilter->ID1;                    /* ID */
        FilterID |= ( pNewFilter->Disable1 << 28);     /* Disable bit */
        FilterID |= ( pNewFilter->Controller1 << 29);  /* Controller */
        break;

    default:
        return EW_ERROR;
    }

    /*--- All Rx messages on all CAN buses are ignored ---*/
    AFMR = 0x01;

    /*--- Enter reset mode ---*/
    C1MOD |= 0x01;
    C2MOD |= 0x01;

    /*--- Set pointer to first location of filter ---*/
    pFilter = (int32u_t *) ACCEPTANCE_FILTER_RAM_BASE;    //强制类型转换为32位地址指针，每次都取出32位的数据


    switch ( pNewFilter->FilterType )
    {
    case EW_CAN_FULL:
        /*--- Find place to add new fullCAN filter ---*/
        ii = 0;

        /*--- Loop through all existing fullCAN filters ---*/
        while ( ii < SFF_sa )
        {
            /*--- New filter < Stored filter? ---*/
            if ( ( FilterID & 0xc7ffc7ff ) < ( *pFilter & 0xc7ffc7ff ) )
            {
                /*--- yes break ---*/
                break;
            }
            ii += 4;
            pFilter++;
        }

        /*--- Save current table ID ---*/
        id0 = *pFilter;

        /*--- Update start address registers   更新起始地址寄存器 ---*/
        SFF_sa += 4;
        SFF_GRP_sa += 4;
        EFF_sa += 4;
        EFF_GRP_sa += 4;
        break;

    case EW_CAN_STD:
        /*--- Find place to add new standard IDs filter ---*/
        ii = SFF_sa;
        pFilter += (ii / 4);

        /*--- Loop through all existing standard filters ---*/
        while ( ii < SFF_GRP_sa )
        {
            /*--- New filter < Stored filter? ---*/
            if ( ( FilterID & 0xc7ffc7ff ) < ( *pFilter & 0xc7ffc7ff ) )
            {
                /*--- yes break ---*/
                break;
            }
            ii += 4;
            pFilter++;
        }

        /*--- Save current table ID ---*/
        id0 = *pFilter;

        /*--- Add new Filter ID ---*/
        *pFilter = FilterID;

        /*--- Update start address registers ---*/
        SFF_GRP_sa += 4;
        EFF_sa += 4;
        EFF_GRP_sa += 4;
        break;

    case EW_CAN_STD_GRP:
        /*--- Find place to add new standard IDs group filter ---*/
        ii = SFF_GRP_sa;
        pFilter += (ii / 4);

        /*--- Loop through all existing standard filters ---*/
        while ( ii < EFF_sa )
        {

            if ( ( FilterID & 0xc7ffc7ff ) < ( *pFilter & 0xc7ffc7ff ) )
            {
                /*--- yes break ---*/
                break;
            }
            ii += 4;
            pFilter++;
        }

        /*--- Save current table ID ---*/
        id0 = *pFilter;

        /*--- Add new Filter ID ---*/
        *pFilter = FilterID;

        /*--- Update start address registers ---*/
        EFF_sa += 4;
        EFF_GRP_sa += 4;
        break;

    case EW_CAN_EXT:
        /*--- Find place to add new extended ID filter ---*/
        ii = EFF_sa;
        pFilter += (ii / 4);

        /*--- Loop through all existing standard filters ---*/
        while ( ii < EFF_GRP_sa )
        {
            /*--- New filter < Stored filter? ---*/
            if ( ( FilterID & 0xc7ffffff ) < ( *pFilter & 0xc7ffffff ) )
            {
                /*--- yes break ---*/
                break;
            }
            ii += 4;
            pFilter++;
        }

        /*--- Save current table ID ---*/
        id0 = *pFilter;

        /*--- Add new Filter ID ---*/
        *pFilter = FilterID;

        // Update start address registers
        EFF_GRP_sa += 4;
        break;

    case EW_CAN_EXT_GRP:
        ii = EFF_GRP_sa;
        pFilter += (ii / 4);

        while ( ii < ENDofTable )
        {
            if ( ( FilterID & 0xc7ffffff ) < ( *pFilter & 0xc7ffffff ) )
            {
                break;
            }
            ii += 8;
            pFilter += 2;
        }

        /*--- Save current table ID ---*/
        id0 = *pFilter;

        /*--- Add new Filter ID lower bound ---*/
        *pFilter = FilterID;

        /*--- Prepare new extend ID, higher bound ---*/
        FilterID = pNewFilter->ID2;                    /* ID */
        FilterID |= ( pNewFilter->Controller2 << 29);  /* Controller */
        pFilter++;

        /*--- Save current table ID ---*/
        id1 = *pFilter;

        /*--- Add new Filter ID higher bound ---*/
        *pFilter = FilterID;

        /*--- Move all existing filter bounds two steps forward ---*/
        pFilter++;
        while ( ii < ENDofTable )
        {
            /*--- lower bound ---*/
            id3 = *pFilter;  /* get filter */
            *pFilter = id0;  /* restore filter */
            id0 = id3;       /* move filter */
            pFilter++;

            /*--- higher bound ---*/
            id4 = *pFilter;  /* get filter */
            *pFilter = id1;  /* restore filter */
            id1 = id4;       /* move filter */
            pFilter++;
            ii += 8;
        }

        /*--- Update end of table register ---*/
        ENDofTable += 8;
        break;

    }

    if ( pNewFilter->FilterType != EW_CAN_EXT_GRP )    //不是扩展标识符组
    {
      /*--- Add new Filter ID ---*/
      *pFilter = FilterID;

      /*--- Move all existing filters one step forward ---*/
      pFilter++;
      while ( ii < ENDofTable )
      {
          id1 = *pFilter;  /* get filter */
          *pFilter = id0;  /* restore filter */
          id0 = id1;       /* move filter */
          pFilter++;
          ii += 4;
      }

        /*--- Update end of table register ---*/
      ENDofTable += 4;

    }

    /*--- Acceptance filter mode ----*/
    AFMR = 0x04;

    /*--- Release reset! ---*/
    C1MOD  = ( C1MOD & ~0x01 );
    C2MOD  = ( C2MOD & ~0x01 );

    /*--- List has been full? ---*/
    Address = ENDofTable;
    Address += ( SFF_sa * 6 );
    if( Address > 0x800 )
    {
        /*--- Acceptance filter table full after new entries ---*/
        return EW_FULL;
    }

    return EW_OK;

}
int16s_t EW_Manage_CAN( int8u_t Controller )
{
    int16s_t RetCode;
    int32u_t status;

    RetCode = 0;

    if( Controller == 1)
    {
        status = C1GSR;
    }
    else if( Controller == 2)
    {
        status = C2GSR;
    }

    if( status & 0x01 )
    {
        /*--- A message is available ---*/
        RetCode |= EW_CAN_RECEIVED;
    }

    return RetCode;

}


int16s_t EW_ReceiveData_CAN( int8u_t  Controller, CAN_MSG *pRxMsg )

{
    int16s_t  ErrorCode;
    int32u_t  ii, jj;
    int32u_t  FilterID;
    int32u_t  volatile *pFilter;



    switch( Controller )
    {
    case 0:
        /*
        **------------------
        ** Full CAN message
        **------------------
        */

        if(( CANRxSR & 0x3 ) > 0 )                        //集中接收状态寄存器与全局状态寄存器中的RS位效果相同
        {
            /*--- Receiving CAN message ---*/
            ErrorCode = EW_BUSY;
        }

        else
        {
            /*--- Error code initialized ---*/
            ErrorCode = EW_ERROR;

            /*--- Test if new Full CAN message received ---*/

            /*--- Set pointer to first location of filter ---*/
            pFilter = (  int32u_t *) ( ACCEPTANCE_FILTER_RAM_BASE+ ENDofTable );

            /*--- Number of items in table ---*/
            jj = (SFF_sa >> 1);                  //一共有的信息个数

            for( ii = 0; ii < jj; ii++ )         //查询全部的FULLCAN标准标识符表格
            {
                if(( *pFilter & 0x3000000L ) == 0x1000000L )
                {
                    /*--- SEM == 1  表格内的信息正在更新---*/
                    /*
                    **-------------------------------------------------
                    ** Increment variable used only during driver test
                    ** SEM1count++;
                    **-------------------------------------------------
                    */
                }

                if(( *pFilter & 0x3000000L ) == 0x3000000L )
                {
                    /*--- SEM == 3, 信息更新结束读取信息 ---*/

                    /*--- Read FF, RTR, DLC info and ID ---*/
                    pRxMsg->CTRL = (*pFilter & 0xC00F0000L);
                    pRxMsg->ID = (*pFilter & 0x000007FFL);

                    /*--- 清0 SEM 回写第一个字 ---*/
                    *pFilter &= ~0x3000000L;
                    pFilter++;

                    /*--- Read Data 2 ---*/
                    pRxMsg->Data1= *pFilter;
                    pFilter++;

                    /*--- Read Data 3 ---*/
                    pRxMsg->Data2= *pFilter;

                    /*--- Message still OK? ---*/
                    pFilter -= 2;
                    if(( *pFilter & 0x3000000L ) == 0)
                    {
                        /*--- Yes OK ---*/

                        /*--- Get CAN controller # info - contained in filter table ---*/
                        pFilter = (  int32u_t *) ACCEPTANCE_FILTER_RAM_BASE;
                        pFilter += (ii>>1);
                        FilterID = *pFilter;

                        /*以下获取CAN控制器的信息即确定接收到的信息是通过CAN1还是CAN2模块接收的*/
                        if( ii&1 )              //ii是奇数
                        {
                            /*--- Get info from position 13-15 ---*/
                            FilterID &= 0xE000;
                            /*--- Store info in bit position 24-26 ---*/
                            FilterID <<= 11;
                        }
                        else
                        {
                            /*--- Get info from position 29-31 ---*/
                            FilterID &= 0xE0000000L;
                            /*--- Store info in bit position 24-26 ---*/
                            FilterID >>= 5;
                        }

                        /*--- Add CAN controller # info to bit position 24-26 ---*/
                        pRxMsg->CTRL |= FilterID;

                        if(( pRxMsg->CTRL & EW_CAN_CTRL_RTR ) != 0)   //判断是否接收到了远程帧
                        {
                            /*--- RTR message received ---*/
                            ErrorCode = EW_RTR;
                        }
                        else
                        {
                            /*--- Data message received ---*/
                            ErrorCode = EW_DATA;                    //接收到了数据帧跳出循环体
                        }
                        break;
                    }
                    else
                    {
                        /*--- Message has been updated during read ---*/
                        /*再次读第一个字SEM！=0说明在读信息的过程中信息被更新了
                        **-------------------------------------------------
                        ** Increment variable used only during driver test
                        ** SEM2count++;
                        **-------------------------------------------------
                        */
                        return EW_EMPTY;        //循环中的return跳出子函数直接返回结果
                    }
                }
                else
                {
                    /*--- Next message ---*/
                    pFilter += 3;              //查询下一个表格
                }
            }

            // Neee this test ????
            /*--- Any new message found? ---*/
            if( ii == jj )
            {
                /*--- Receive buffer is empty ---*/
                ErrorCode = EW_EMPTY;          //查询完成所有的位置没有可用信息
            }
        }
        break;

    case 1:
        /*
        **--------------------------
        ** CAN controller 1 message
        **--------------------------
        */
        if( C1GSR & C1GSR_RBS )
        {
            /*--- A received message is available ---*/

            /*--- Read FF, RTR, DLC info ---*/
            pRxMsg->CTRL = (C1RFS & 0xC00F0000L);

            /*--- Read ID ---*/
            pRxMsg->ID = C1RID;

            /*--- Read Data ---*/
            pRxMsg->Data1= C1RDA;
            pRxMsg->Data2= C1RDB;

            /*--- Bit 2: RRB (释放接收缓存器) ---*/
            C1CMR |= C1CMR_RRB;

            if(( pRxMsg->CTRL & EW_CAN_CTRL_RTR ) != 0)
            {
                /*--- RTR message received ---*/
                ErrorCode = EW_RTR;
            }
            else
            {
                /*--- Data message received ---*/
                ErrorCode = EW_DATA;
            }
            /*--- Data overrun? ---*/
            if( C1GSR & 0x02 )
            {
                /*--- A data overrun has occurred ---*/
                ErrorCode = EW_ERROR;      //上次传输到缓冲区的数据未被读出释放导致数据溢出
            }
        }
        else
        {
            /*--- Receive buffer is empty ---*/
            ErrorCode = EW_EMPTY;
        }
        break;

    case 2:
        /*
        **--------------------------
        ** CAN controller 2 message
        **--------------------------
        */
        if( C2GSR & C1GSR_RBS )
        {
            /*--- A received message is available ---*/
            pRxMsg->CTRL = (C2RFS & 0xC00F0000L);

            /*--- Read ID ---*/
            pRxMsg->ID = C2RID;

            /*--- Read Data ---*/
            pRxMsg->Data1= C2RDA;
            pRxMsg->Data2= C2RDB;

            /*--- Bit 2: RRB (Release receiver buffer) ---*/
            C2CMR |= C1CMR_RRB;

            if(( pRxMsg->CTRL & EW_CAN_CTRL_RTR ) != 0)
            {
                /*--- RTR message received ---*/
                ErrorCode = EW_RTR;
            }
            else
            {
                /*--- Data message received ---*/
                ErrorCode = EW_DATA;
            }
            /*--- Data overrun? ---*/
            if( C1GSR & 0x02 )
            {
                /*--- A data overrun has occurred ---*/
                ErrorCode = EW_ERROR;
            }
        }
        else
        {
            /*--- Receive buffer is empty ---*/
            ErrorCode = EW_EMPTY;
        }
        break;
    default:
        /*--- wrong controller parameter ---*/
        ErrorCode = EW_ERROR;
        break;
    }


    return ErrorCode;

}