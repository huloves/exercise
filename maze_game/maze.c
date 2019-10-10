#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#define ROW_MAX 50
#define COL_MAX 50

typedef struct node{
    int x;
    int y;
}Item;

typedef struct stack_node{
    Item item;
    struct stack_node *next;
}stack_t;

int maze[ROW_MAX][COL_MAX];
int flag[ROW_MAX][COL_MAX] = {0};
//int row, col; //行列数

void stack_push(stack_t **stack_head, int x, int y);
int stack_pop(stack_t **stack_head, int *x, int *y);
//int stack_pop_print(stack_t **stack_head, int *x, int *y);
int stack_empty(stack_t **stack_head);
int stack_size(stack_t *stack_head){
    int tmp = 0;
    stack_t *current = NULL;
    current = stack_head;
    while(current != NULL) {
        tmp++;
        current = current->next;
    }

    return tmp;
}

void user_maze(); //自定义迷宫
void print_maze(int row, int col); //输出迷宫
void maze_run(int row, int col);   //迷宫求解
void maze_answer(int row, int col);   //迷宫答案
void print_answer(stack_t **stack_head);
int maze_direction(int x, int y, int row, int col);
void default_maze(); //默认迷宫

int main()
{
    char choice[10];

    while(1){
        system("clear");
        printf("------------------------\n");
        printf("|     [1]自定义迷宫    |\n");
        printf("------------------------\n");
        printf("|     [2]默认迷宫      |\n");
        printf("------------------------\n");
        printf("|     [0]退出          |\n");
        printf("------------------------\n");

        while(1) {
            printf("请输入你的选择：");
            scanf("%s", choice);
            while(getchar() != '\n')
                continue;
            if(strcmp(choice, "1")==0 || strcmp(choice, "2")==0 ||strcmp(choice, "0")==0) {
                break;
            }
            else {
                printf("请按照提示输入!!!\n");
            }
        }

        if(choice[0] == '0') { break; } //退出

        switch(choice[0]) {
        case '1':
            user_maze();
            break;
        case '2':
            default_maze();
            break;
        }
    }

    return 0;
}

void stack_push(stack_t **stack_head, int x, int y){
    stack_t *current;
    
    current = (stack_t*)malloc(sizeof(stack_t));
    if(current == NULL) {
        printf("line: %d malloc error\n", __LINE__);
    }
    
    current->item.x = x;
    current->item.y = y;
    current->next = NULL;

    if(*(stack_head) == NULL) {
        *(stack_head) = current;
    }
    else {
        current->next = *(stack_head);
        *(stack_head) = current;
    }
}

int stack_pop(stack_t **stack_head, int *x, int *y){
    stack_t *current;
    
    if(*(stack_head) == NULL) { //栈空
        return 1;
    }
    
    //出栈
    current = *(stack_head);
    *(stack_head) = current->next;

    if(*stack_head == NULL) {
        //*x = current->item.x;
        //*y = current->item.y;
        free(current);
        return 0;
    }
    
    *x = (*stack_head)->item.x;
    *y = (*stack_head)->item.y;
    

    free(current);
}

int stack_pop_print(stack_t **stack_head, int *x, int *y){
    stack_t *current;

    current = *stack_head;
    *stack_head = current->next;

    *x = current->item.x;
    *y = current->item.y;

    free(current);
}

int stack_empty(stack_t **stack_head){
    if(*(stack_head) == NULL)
        return 1;
    else
        return 0;
}

void user_maze(){
    system("clear");
    int row, col;

    printf("请输入行数，列数：");
    scanf("%d %d", &row, &col);
    while(getchar() != '\n')
        continue;

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            maze[i][j] = 0;
            flag[i][j] = 0;
        }
    }

    //输入迷宫数据
    for(int i=0; i<row; i++) {
        printf("请输入第%d行数据(0表示通路，1表示墙壁)：", i+1);
        for(int j=0; j<col; j++) {
            scanf("%d", &maze[i][j]);
        }   
    }

    printf("迷宫：\n");
    print_maze(row, col); //打印迷宫
    maze_run(row, col);   //迷宫求解
}

void default_maze(){
    system("clear");
    int row, col;
    int fd;

    row = col = 10;

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            maze[i][j] = 0;
            flag[i][j] = 0;
        }
    }

    FILE *fp = fopen("default_maze", "r");

    char buf[256];
    for(int i=0; i<row; i++){
        fscanf(fp, "%s", buf);
        for(int j=0; j<strlen(buf); j++){
            maze[i][j] = buf[j]-48;
        }
    }

    printf("迷宫：\n");
    print_maze(row, col);
    maze_run(row, col);
}

void print_maze(int row, int col){
    int i, j;

    for(i=0; i<row; i++) {
        for(j=0; j<col; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

void maze_run(int row, int col){
    char choice[20];

    while(1){
        system("clear");
        print_maze(row, col);
        printf("======================\n");
        printf("======================\n");
        printf("----------------------\n");
        printf("|     [1]迷宫答案    |\n");
        printf("----------------------\n");
        printf("|     [0]返回上级    |\n");
        printf("----------------------\n");

        while(1) {
            printf("请输入你的选择：");
            scanf("%s", choice);
            while(getchar() != '\n')
                continue;
            if(strcmp(choice, "1")==0 || strcmp(choice, "0")==0) {
                break;
            }
            else {
                printf("请按照提示输入！！！\n");
            }
        }

        if(choice[0] == '0') { break; }

        switch(choice[0]) {
        case '1':
            maze_answer(row, col);
            break;
        }
    }
}

void maze_answer(int row, int col){
    system("clear");
    print_maze(row, col);
    printf("=====================\n");
    printf("=====================\n");
    stack_t *top = NULL;
    stack_push(&top, 0, 0);

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            flag[i][j] = 0;
        }
    }

    //int ret = stack_size(top);
    //printf("stack size = %d\n", ret);

    int current_x = 0, current_y = 0;
    flag[current_x][current_y] = 1;

    while(!stack_empty(&top)) {
        //printf("A\n");
        //printf("x = %d   y = %d stack_size = %d\n", current_x, current_y, stack_size(top));
        if(current_x == row-1 && current_y == col-1) {
            print_answer(&top);
            printf("按回车键返回\n");
            getchar();
            return;
        }

        if(maze_direction(current_x-1, current_y, row, col)) {
            current_x = current_x-1;
            stack_push(&top, current_x, current_y);
            flag[current_x][current_y] = 1;
        }
        else if(maze_direction(current_x, current_y+1, row, col)) {
            current_y = current_y+1;
            stack_push(&top, current_x, current_y);
            flag[current_x][current_y] = 1;
        }
        else if(maze_direction(current_x+1, current_y, row, col)) {
            current_x = current_x+1;
            stack_push(&top, current_x, current_y);
            flag[current_x][current_y] = 1;
        }
        else if(maze_direction(current_x, current_y-1, row, col)) {
            current_y = current_y-1;
            stack_push(&top, current_x, current_y);
            flag[current_x][current_y] = 1;
        }
        else {
            stack_pop(&top, &current_x, &current_y);
        }
    }

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            printf("%d ", flag[i][j]);
        }
        printf("\n");
    }

    printf("此迷宫没有通路\n\n");
    printf("按回车键返回菜单\n");
    getchar();
}

int maze_direction(int x, int y, int row, int col){
    if(x<0 || y<0 || x == row || y == col) {  //越界
        return 0;
    }
    if(flag[x][y] == 1) {   //走过
        return 0;
    }
    if(maze[x][y] == 1) {   //墙
        return 0;
    }
    return 1;
}

void print_answer(stack_t **stack_head){
    //printf("AAAAAAAAAAAAAAAAa\n");
    stack_t *temp = NULL;
    stack_t *current = NULL;
    
    //将路径正序输入到临时栈
    current = *stack_head;
    while(current != NULL) {
        stack_t *temp_p = (stack_t*)malloc(sizeof(stack_t));
        temp_p->item = current->item;
        temp_p->next = NULL;

        if(temp == NULL) {
            temp = temp_p;
        }
        else {
            temp_p->next = temp;
            temp = temp_p;
        }

        current = current->next;
    }

    //printf("%d\n", stack_size(temp));

    //输出路径
    current = temp;
    while(current != NULL) {
        printf("(%d,%d)\n", current->item.x+1, current->item.y+1);
        current = current->next;
    }

    //销毁临时栈
    current = temp;
    while(current != NULL) {
        stack_t *delete_ = current;
        current = current->next;
        free(delete_);
    }
}
