#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define ELEM_SIZE 101

struct max_pq {
	// 存储元素的数组
	int elem[ELEM_SIZE];
	// 当前priority queue中的元素个数
	int n;
};

// 返回当前队列中最大元素
int top(const struct max_pq *pq) {
	return pq->elem[1];
}

// 插入元素e
void push(struct max_pq *pq, int e);

// 删除最大元素
void pop(struct max_pq *pq);

// 上浮第k个元素，以维护最大堆性质
void swim(struct max_pq *pq, int k);

// 下沉第k个元素，以维护最大堆性质
void sink(struct max_pq *pq, int k);

// 交换数组的两个元素
void exchange(struct max_pq *pq, int i, int j) {
	int temp = pq->elem[i];
	pq->elem[i] = pq->elem[j];
	pq->elem[j] = temp;
}

// pq->elem[i] < pq->elem[j]
bool less(const struct max_pq *pq, int i, int j) {
	return pq->elem[i] < pq->elem[j] ? true : false;
}

int parent(int root) {
	return root / 2;
}

int left(int root) {
	return root * 2;
}

int right(int root) {
	return root * 2 + 1;
}

int main()
{
	struct max_pq *pq;
	pq = (struct max_pq*)malloc(sizeof(struct max_pq));
	pq->n = 0;
	push(pq, 2);
	push(pq, 5);
	push(pq, 3);
	for(int i = 1; i <= 3; i++) {
		printf("%d ", pq->elem[i]);
	}
	printf("\n");
	for(int i = 0; i < 3; i++) {
		printf("%d ", top(pq));
		pop(pq);
	}
	printf("\n");
	return 0;
}

// 上浮第k个元素，以维护最大堆性质
void swim(struct max_pq *pq, int k) {
	// 如果上浮到堆顶，就不再上浮
	while(k > 1 && less(pq, parent(k), k) == true) {
		exchange(pq, parent(k), k);
		k = parent(k);
	}
}

// 下沉第k个元素，以维护最大堆性质
void sink(struct max_pq *pq, int k) {
	while(left(k) <= pq->n) {
		int older = left(k);
		if(right(k) <= pq->n && less(pq, older, right(k) == true)) {
			older = right(k);
		}
		if(less(pq, older, k)) {
			break;
		}
		exchange(pq, k, older);
		k = older;
	}
}

void push(struct max_pq *pq, int e) {
	assert(pq->n < ELEM_SIZE);
	pq->n++;
	pq->elem[pq->n] = e;
	swim(pq, pq->n);
	return;
}

void pop(struct max_pq *pq) {
	exchange(pq, 1, pq->n);
	assert(pq->n >= 1);	
	pq->n--;
	sink(pq, 1);
	return;
}
