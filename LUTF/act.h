#ifndef __ACT_H
#define __ACT_H

#include <stdint.h>

#define act_pid int

typedef enum {
    ACT_RUNABLE,
    ACT_RUNNING,
    ACT_WAITING,
    ACT_EXIT
} act_status;

typedef void (*act_func)(void*);

#endif