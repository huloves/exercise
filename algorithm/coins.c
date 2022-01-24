#include <stdio.h>
#include <stdlib.h>

int min(int a, int b);
int coinChange(int* coins, int coinsSize, int amount);
int dp(int *coins, int coinsSize, int amount, int* book);

int main(int argc, char **argv)
{
	int *coins;
	printf("enter how many type:");
	int n;
	scanf("%d", &n);
	coins = (int*)malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++) {
		scanf("%d", coins + i);
	}
	for(int i = 0; i < n; i++) {
		printf("%d ", *(coins + i));
	}
	printf("\n");
	printf("enter amount:");
	int amount;
	scanf("%d", &amount);
	printf("%d\n", coinChange(coins, n, amount));
	return 0;
}

int min(int a, int b) {
    if(a <= b) {
        return a;
    } else {
        return b;
    }
}

int coinChange(int* coins, int coinsSize, int amount) {
    int book[amount + 1];
    for(int i = 0; i < amount + 1; i++) {
        book[i] = -666;
    }
    return dp(coins, coinsSize, amount, book);
}

int dp(int *coins, int coinsSize, int amount, int* book) {
    if(amount == 0) return 0;
    if(amount < 0) return -1;
    if(book[amount] != -666) {
        return book[amount];
    }
    int ans = 99999;
    for(int i = 0; i < coinsSize; i++) {
        int sub_problem = dp(coins, coinsSize, amount - coins[i], book);
        if(sub_problem == -1) continue;
        ans = min(ans, sub_problem + 1);
    }
    book[amount] = (ans == 99999 ? -1 : ans);
    return book[amount];
}
