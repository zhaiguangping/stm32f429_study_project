#include "led_thread.h"

//任务优先级
#define   led_thread_priority   osPriorityLow7

//任务ID
osThreadId_t   led_Thread_ID  = NULL;

//任务控制块
uint64_t led_thread_stk[256];
const osThreadAttr_t led_thread_attr =
{
    .name = "osRtxLedThread",
    .stack_mem  = &led_thread_stk[0],
    .attr_bits = osThreadDetached, 
    .stack_size = 256U,
    .priority = led_thread_priority,
};

void led_thread (void *argument)
{
    while (1)
    {
        LEDY_REV;
        osDelay(500);
    }
}

