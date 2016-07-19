#include"headers.h"

/*******************************************************************************
* 函数名称：IRQ_Handler
* 入口参数：无
* 描    述：中断入口函数——获取相应中断的入口地址并转向中断函数执行
*******************************************************************************/
__irq __arm void IRQ_Handler(void)          //__irq 是一个函数限定符 它影响函数的类型，确定其用于中断函数
{
  void (*interrupt_function)();             //返回值为void型的函数指针
  int16u_t vector;

  vector = VICVectAddr;                     // 从向量中断控制器获得中断地址信息返回最高优先级slot（最低编号）在向量地址寄存器中的地址
  interrupt_function = (void(*)())vector;   //(void(*)())这个表达式是一个类型表示指向返回值为void型的函数的指针
                                            //称为类型转换符
  (*interrupt_function)();                  // 此时将最高优先级中断函数的地址放到了interrupt_function中执行中断函数

  VICVectAddr = 0;
                                            // Clear interrupt in VIC.
}
