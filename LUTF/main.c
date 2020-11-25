#include "task.h"
#include <stdio.h>

int main()
{
    task_init();
    print_task_info(current_task);
    return 0;
}
