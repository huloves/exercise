#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <ucontext.h>

#include "act.h"

#define act_access_procs_begin() do { \
    pthread_mutex_lock(&act_procs_mutex); \
} while(0)

#define act_access_procs_end() do { \
    pthread_mutex_unlock(&act_procs_mutex); \
} while(0)

static pthread_mutex_t act_procs_mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct act_procs act_proc_t;

struct act_procs {
    act_pid pid;
    ucontext_t* ctx;
    act_status status;

    act_proc_t* prev;
    act_proc_t* next;
};

static act_pid act_max_pid;
static act_proc_t* act_procs;

typedef struct act_sche {
    pthread_t tid;
    ucontext_t* ctx;
    act_proc_t* running_proc;
} act_sche_t;

static int act_sche_num;
static act_sche_t** act_sches;

static void* act_scheduler(void* data)
{
    int sche_id = (int)data;
    act_sche_t sche;
    ucontext_t main_ctx;

    act_proc_t* proc = NULL;
    act_proc_t* next_proc = act_procs;

    sche.ctx = &main_ctx;
    sche.tid = pthread_self();
    sche.running_proc = NULL;

    act_sches[sche_id] = &sche;

    for(;;) {
        for(;;) {
            act_access_procs_begin();

            if(proc == NULL) {
                proc = act_procs;
            } else {
                proc = proc->next;
            }

            if(ACT_RUNABLE == proc->status) {
                proc->status = ACT_RUNNING;
                act_access_procs_end();
                break;
            }

            act_access_procs_end();
        }

        sche.running_proc = proc;

        swapcontext(&main_ctx, proc->ctx);
    }
}
