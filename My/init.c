#include "init.h"

//�������ȼ�
#define   app_main_priority   osPriorityHigh

//������ƿ�
uint64_t app_main_stk[256];
const osThreadAttr_t app_main_attr = {
  .stack_mem  = &app_main_stk[0],
  .stack_size = sizeof(app_main_stk),
  .priority = app_main_priority,
};

static void AppTaskCreate(void)
{
    //����LED����
    led_Thread_ID = osThreadNew(led_thread, NULL, &led_thread_attr);
    if(led_Thread_ID==NULL)  Error_Handler();


}

static void ObjCreate(void)
{

}

void app_main(void *argument)
{
    uint32_t tick = 0;

    /* ��ʼ�� */


    /* ���������ͨѶ���� */
    AppTaskCreate();
    ObjCreate();

    tick = osKernelGetTickCount(); 
    while(1)
    {
        tick += 1;
        osDelayUntil (tick);

        /* 1ms����һ�Σ����ڴ�������Ӧ���� */
        uwTick += uwTickFreq;

    }
}

