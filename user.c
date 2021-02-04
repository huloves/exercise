#include <stdio.h>
#include <string.h>


#define MAX_TASK_NUM (10)
#define TASK_STACK_SIZE (4096)


#define DBG_PRINT(fmt, args...) \
do \
{ \
printf("DBG:%s(%d)-%s:\n"fmt"\n", __FILE__,__LINE__,__FUNCTION__,##args); \
} while (0)


typedef void * (*task_entry_ptr) (void *);
typedef struct
{
char name[64];
unsigned long state;
task_entry_ptr entry;
unsigned long ret;
unsigned long sp;
unsigned long pc;
unsigned long stack[TASK_STACK_SIZE/sizeof(unsigned long)];
} __attribute__((packed)) t_task;


#define STATE_INVALID (0)
#define STATE_SLEEPING (1)
#define STATE_RUNNING (2)
#define STATE_FINISHED (3)


t_task g_at_tasks[MAX_TASK_NUM];
int g_task_cnt = 0;


unsigned long process_main_thread_sp;
t_task *pt_cur_running_task;
unsigned long prev_task_sp, prev_task_pc;
unsigned long next_task_sp, next_task_pc;
#define save_main_thread_context() \
do { \
asm volatile("pushfq\n\t" /* save flags */ \
"pushq %%rax\n\t" \
"pushq %%rdi\n\t" \
"pushq %%rsi\n\t" \
"pushq %%rdx\n\t" \
"pushq %%rcx\n\t" \
"pushq %%rbx\n\t" \
"pushq %%rbp\n\t" \
"movq %%rsp,%[main_thread_sp]\n\t" \
: [main_thread_sp] "=m" (process_main_thread_sp)\
); \
} while (0)


#define restore_main_thread_context() \
do { \
asm volatile("movq %[main_thread_sp],%%rsp\n\t" \
"popq %%rbp\n\t" \
"popq %%rbx\n\t" \
"popq %%rcx\n\t" \
"popq %%rdx\n\t" \
"popq %%rsi\n\t" \
"popq %%rdi\n\t" \
"popq %%rax\n\t" \
"popfq\n\t" \
:: [main_thread_sp] "m" (process_main_thread_sp)\
); \
} while (0)


int i;
int task_scheduler()
{
unsigned long ret;
asm volatile("movq %%rax,%[task_ret]\n\t"
: [task_ret] "=m" (ret)
);


if (pt_cur_running_task)
{
pt_cur_running_task->state=STATE_FINISHED;
pt_cur_running_task->ret=ret;
DBG_PRINT("task %s exit with code %lu", pt_cur_running_task->name, pt_cur_running_task->ret);
}

restore_main_thread_context();


for (i=0;i<MAX_TASK_NUM;i++)
{
pt_cur_running_task = &(g_at_tasks[i]);
if (pt_cur_running_task->state==STATE_SLEEPING)
{
pt_cur_running_task->state=STATE_RUNNING;
next_task_sp = pt_cur_running_task->sp;
next_task_pc = pt_cur_running_task->pc;


/* 准备运行下一个可运行任务 */
save_main_thread_context();
asm volatile("movq %[next_sp],%%rsp\n\t"
/* "movq $0x0,%%rdi\n\t"
"pushq task_return\n\t" */
"popq %%rbp\n\t" \
"popq %%rbx\n\t" \
"popq %%rcx\n\t" \
"popq %%rdx\n\t" \
"popq %%rsi\n\t" \
"popq %%rdi\n\t" \
"popq %%rax\n\t" \
"popfq\n\t" \
"jmp *%[next_pc]\n\t"
:: [next_sp] "m" (next_task_sp), [next_pc] "m" (next_task_pc)
);




}
}


DBG_PRINT("==no task to run. so we exit");
return 0;
}


#define push_task_stack(sp, data) \
do \
{ \
sp--; \
*sp = data; \
} while (0)


int create_task(const char *name, void *task_entry, void *para)
{
unsigned long *sp;
t_task *pt_task = &(g_at_tasks[g_task_cnt]);
strncpy(pt_task->name, name, sizeof(pt_task->name));
pt_task->entry = task_entry;
pt_task->sp = (unsigned long)((void *)(pt_task + 1));
pt_task->state = STATE_SLEEPING;
sp = (void *)(pt_task->sp);
push_task_stack(sp, (unsigned long)(void *)&task_scheduler);
pt_task->pc = (unsigned long)task_entry;
push_task_stack(sp, 0);
push_task_stack(sp, 0);
push_task_stack(sp, (unsigned long)para);
push_task_stack(sp, 0);
push_task_stack(sp, 0);
push_task_stack(sp, 0);
push_task_stack(sp, 0);
push_task_stack(sp, pt_task->sp); /* push bp at last */
pt_task->sp = (unsigned long)(void *)sp;



g_task_cnt++;


return 0;
}




#define switch_to(prev, next) \
do { \
asm volatile("pushfq\n\t" \
"pushq %%rax\n\t" \
"pushq %%rdi\n\t" \
"pushq %%rsi\n\t" \
"pushq %%rdx\n\t" \
"pushq %%rcx\n\t" \
"pushq %%rbx\n\t" \
"pushq %%rbp\n\t" \
"movq %%rsp,%[prev_sp]\n\t" \
"movq $1f,%[prev_pc]\n\t" \
"movq %[next_sp],%%rsp\n\t" \
"popq %%rbp\n\t" /* restore EBP */ \
"popq %%rbx\n\t" \
"popq %%rcx\n\t" \
"popq %%rdx\n\t" \
"popq %%rsi\n\t" \
"popq %%rdi\n\t" \
"popq %%rax\n\t" \
"popfq\n\t" \
"jmp *%[next_pc]\n\t" \
"1:\t" \
"nop\n\t" \
: [prev_sp] "=m" (prev->sp),\
[prev_pc] "=m" (prev->pc)\
: [next_sp] "m" (next_task_sp), [next_pc] "m" (next_task_pc) \
); \
}while (0)


void schedule()
{
t_task *prev=pt_cur_running_task, *next=NULL;
for (i=0;i<MAX_TASK_NUM;i++)
{
next = &(g_at_tasks[i]);
if (next->state==STATE_SLEEPING)
{
pt_cur_running_task->state=STATE_SLEEPING;
prev_task_sp = pt_cur_running_task->sp;
prev_task_pc = pt_cur_running_task->pc;


pt_cur_running_task = next;
pt_cur_running_task->state=STATE_RUNNING;
next_task_sp = pt_cur_running_task->sp;
next_task_pc = pt_cur_running_task->pc;


break;
}
}


if (i==MAX_TASK_NUM) return;


switch_to(prev, next);
}


int start_sched()
{
/* 准备运行初始任务 father_of_all_task -- g_at_tasks[0] */
save_main_thread_context();
task_scheduler();
return 0;
}

/* 以上是调度功能的实现，下面是使用示例 */


void * usr_task1(void *para)
{
int i;
DBG_PRINT("==enter");
for (i=0; i<3; i++)
{
DBG_PRINT("==%d", i);
schedule();
}
DBG_PRINT("==exit");
return (void *)100UL;
}


void * usr_task2(void *para)
{
int i;
DBG_PRINT("==enter");
for (i=0; i<3; i++)
{
DBG_PRINT("==%d", i);
schedule();
}
DBG_PRINT("==exit");
return (void *)200UL;
}


void * father_of_all_task(void *para)
{
DBG_PRINT("==enter");
create_task("usr_task1", usr_task1, NULL);
create_task("usr_task2", usr_task2, NULL);
DBG_PRINT("==exit");
return (void *)2015UL;
}


int main(int argc, char *argv[])
{
DBG_PRINT("hello");
create_task("father_of_all_task", father_of_all_task, NULL);
start_sched();
DBG_PRINT("good bye");
return 0;
}