#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Item{
	int id;
	int password;
}Item;

typedef struct Node{
	Item item;
	struct Node *next;
}Node, *link_list;

int number; //约瑟夫环中的人数

int empty_link_list(link_list *phead){
	if( !( (*phead)->next ) ) { return 1; }
	return 0;
}

void create_list(link_list *phead, int number);
void print_list(link_list *phead);
void Josephus_operate(link_list *phead, int password);

int main()
{
	int password = 0;
	link_list head = NULL;

	scanf("%d", &number);
	scanf("%d", &password);

	//创建链表，链表的节点数为number
	create_list(&head, number);

	//打印链表
	//print_list(&head);
    //printf("\n");

	//运行约瑟夫环，打印出队情况
	Josephus_operate(&head, password);

    printf("\n");

	return 0;
}

//创建链表，链表的节点数为number
void create_list(link_list *phead, int number){
	int i = 0;
	int password = 0;
	Node *current = NULL, *pre = NULL;

    //创建链表
	while( i < number ) {
		current = (link_list)malloc(sizeof(Node));
		
		if(*phead == NULL) { *phead = current; }
		else { pre->next = current; }
		current->next = *phead;
		pre = current;

		scanf("%d", &password);
        
		current->item.id = i+1;
		current->item.password = password;

		i++;
	}
}

void print_list(link_list *phead){
	Node *current = NULL;
	
	//判断链表是否为空，询问是否要输入密码。
	if(empty_link_list(phead)){
		printf("the link list is empty\n");
		return;
    }

	//打印链表中的密码
	printf("--id-- --PASSWORLD--\n");
	current = *phead;
    int i = 0;
	while(i<7) {
		printf("  %d      %d\n", current->item.id, current->item.password);
		current = current->next;
        i++;
	}
}

void Josephus_operate(link_list *phead, int password){
	Node *current = NULL;
	Node *pre = NULL;
	int flag = 1;

	current = *phead;
    pre = *phead;

	while( pre->next != (*phead)) { pre = pre->next; }

	while(flag == 1) {
		for( int i=0; i<password-1; i++) {
			pre = current;
			current = current->next;
		}
        
		if(pre == current) { flag = 0; }

		pre->next = current->next;
        password = current->item.password;
        printf("%d ", current->item.id);
        
        Node *del = current;
		current = current->next;

        free(del);
	}

	(*phead)->next = NULL;
}
