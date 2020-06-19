#ifndef __LED_THREAD_H__
#define __LED_THREAD_H__

#include "main.h"

#define   LEDB_OFF     SET_BIT(GPIOD->BSRR,  1<<12)      //PD12
#define   LEDY_OFF     SET_BIT(GPIOG->BSRR, 1<<7)        //PG7
#define   LEDB_ON      SET_BIT(GPIOD->BSRR,  1<<(12+16))
#define   LEDY_ON      SET_BIT(GPIOG->BSRR, 1<<(7+16))
#define   LEDB_REV     REVERSE_BIT(GPIOD->ODR, 1<<12)
#define   LEDY_REV     REVERSE_BIT(GPIOG->ODR, 1<<7)

extern osThreadId_t  led_Thread_ID;            //任务ID
extern const osThreadAttr_t  led_thread_attr;  //任务控制块
void led_thread (void *argument);              //任务

#endif /** __LED_THREAD_H__ **/
