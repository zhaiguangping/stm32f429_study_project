#include "init.h"

//任务优先级
#define   app_main_priority   osPriorityHigh

//任务控制块
uint64_t app_main_stk[256];
const osThreadAttr_t app_main_attr = {
  .stack_mem  = &app_main_stk[0],
  .stack_size = sizeof(app_main_stk),
  .priority = app_main_priority,
};

static void AppTaskCreate(void)
{
    //创建LED任务
    led_Thread_ID = osThreadNew(led_thread, NULL, &led_thread_attr);
    if(led_Thread_ID==NULL)  Error_Handler();


}

static void ObjCreate(void)
{

}

void app_main(void *argument)
{
    uint32_t tick = 0;

    /* 初始化 */


    /* 创建任务和通讯机制 */
    AppTaskCreate();
    ObjCreate();

    tick = osKernelGetTickCount(); 
    while(1)
    {
        tick += 1;
        osDelayUntil (tick);

        /* 1ms进入一次，可在此设置相应功能 */
        uwTick += uwTickFreq;

    }
}

