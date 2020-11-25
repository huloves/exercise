#ifndef __TASK_H
#define __TASK_H

#include "stdint.h"

typedef int16_t tid_t;

enum task_status
{
    TASK_RUNNING,
    TASK_READY,
    TASK_BLOCKED
};

struct task_struct
{
    tid_t tid;   //任务id
    enum task_status status;   //任务状态
    char name[32];   //任务名
    uint8_t priority;   //任务优先级，通过优先级设置时间片
    uint8_t ticks;   //每次处理器上执行的时间嘀嗒数，任务的时间片
};

#endif
