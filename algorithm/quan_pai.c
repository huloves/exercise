#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

int main(int argc, char** argv)
{
	int numsSize;
	int* nums;
	scanf("%d", &numsSize);
	nums = (int*)malloc(sizeof(int) * numsSize);
	for(int i = 0; i < numsSize; i++) {
		scanf("%d", (nums + i));
	}
	int returnSize;
	int* returnColumnSizes;
	int** ret;
	ret = permute(nums, numsSize, &returnSize, &returnColumnSizes);
	for(int i = 0; i < returnSize; i++) {
		for(int j = 0; j < *(returnColumnSizes + i); j++) {
			printf("%d", ret[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void dfs(int* nums, int numsSize,int depth,int* path,bool *used,int **ret, int *retSize, int **retColSize)
{
    if(depth == numsSize) {
        ret[*retSize] = (int *)calloc(numsSize, sizeof(int));
        for (int i = 0; i < numsSize; i++) {
            ret[*retSize][i] = path[i];
        }
        (*retColSize)[*retSize] = numsSize;
        (*retSize)++;
        return;
    }
    for (int i = 0; i < numsSize; i++) {
        if (used[i] == true) continue;
        path[depth] = nums[i];
        used[i] = true;
        dfs(nums,numsSize,depth + 1,path,used,ret,retSize,retColSize);
        used[i] = false;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    int **ret = calloc(10000,sizeof(int *));
    *returnColumnSizes = (int *)calloc(10000,sizeof(int));
    *returnSize = 0;
    if (numsSize == 0) {
        return ret;
    }
    int *path = (int *)calloc(numsSize,sizeof(int));
    bool *used = (bool *)calloc(numsSize,sizeof(bool));
    dfs(nums, numsSize, 0, path, used, ret, returnSize, returnColumnSizes);
    return ret; 
}
