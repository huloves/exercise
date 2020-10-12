#include <stdio.h>

struct queue
{
    char a[100];
    int head;
    int tail;
};

void queue_init(struct queue* queue)
{
    // queue->a = {0};
    for(int i=0; i<100; i++) {
        queue->a[i] = '\0';
    }
    queue->head = 0;
    queue->tail = 0;
}

void queue_add(struct queue* queue, char var)
{
    queue->a[queue->tail++] = var;
}

char queue_del(struct queue* queue)
{

    return queue->a[queue->head++];
}

int main()
{
    // char a[100] = {'6', '3', '1', '7', '5', '8', '9', '2', '4'};
    struct queue q;
    // int head, tail;
    // int temp;

    // head = 0;
    // int i=0;
    // for(tail=0; a[tail+1] != '\0'; tail++);
    // while(a[head] != '\0') {
    //     ans[i++] = a[head];
    //     a[tail+1] = a[head+1];
    //     head += 2;
    //     tail += 1;
    // }
    queue_init(&q);
    char temp;
    for(int i=0; i<9; i++) {
        scanf("%c", &temp);
        queue_add(&q, temp);
    }

    while(q.head < q.tail) {
        printf("%c ", queue_del(&q));
        temp = queue_del(&q);
        queue_add(&q, temp);
    }
    printf("\n");

    return 0;
}
