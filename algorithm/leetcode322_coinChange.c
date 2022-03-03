#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    if(a < b) {
        return a;
    } else {
        return b;
    }
}

int coinChange_baoli(int* coins, int coinsSize, int amount){
    if(amount == 0) { return 0; }
    if(amount < 0) { return -1; }
    int res = INT_MAX;
    for(int i = 0; i < coinsSize; i++) {
        int subProblem = coinChange_baoli(coins, coinsSize, amount - coins[i]);
        if(subProblem == -1) { continue; }
        res = min(res, subProblem + 1);
    }
    return res == INT_MAX ? -1 : res;
}

int dp(int *coins, int coinsSize, int amount, int *memo) {
    if(amount == 0) { return 0; }
    if(amount < 0) { return -1; }
    if(memo[amount] != -666) {
        return memo[amount];
    }
    int res = INT_MAX;
    for (int i = 0; i < coinsSize; i++) {
        int subProblem = dp(coins, coinsSize, amount - coins[i], memo);
        if(subProblem == -1) { continue; }
        res = min(res, subProblem + 1);
    }
    memo[amount] = (res == INT_MAX) ? -1 : res;
    return memo[amount];
}

int coinChange_dp_digui(int *coins, int coinsSize, int amount) {
    int memo[amount + 1];
    for(int i = 0; i < amount + 1; i++) {
        memo[i] = -666;
    }
    dp(coins, coinsSize, amount, memo);
    return memo[amount];
}

int coinChange_dp(int* coins, int coinsSize, int amount){
    int dp[amount + 1];
    for(int i = 0; i < amount + 1; i++) {
        dp[i] = amount + 1;
    }
    // base case
    dp[0] = 0;
    for(int i = 0; i < amount + 1; i++) {
        for(int j = 0; j < coinsSize; j++) {
            if(i - coins[j] < 0) { continue; }
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}

int main()
{
	int coins[3] = {1, 2, 5};
	int res = coinChange_dp_digui(coins, 3, 100);
	printf("%d\n", res);
	return 0;
}
