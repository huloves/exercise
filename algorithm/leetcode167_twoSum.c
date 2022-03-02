#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize){
    int left = 0, right = numbersSize - 1;
    int *res = (int*)malloc(sizeof(int) * 2);
    *returnSize = 0;
    while(left <= right) {
        // int mid = left + (right - left) / 2;
        int sum = numbers[left] + numbers[right];
        if(sum == target) {
            res[(*returnSize)++] = left + 1;
            res[(*returnSize)++] = right + 1;
            return res;
        } else if(sum < target) {
            left++;
        } else if(sum > target) {
            right--;
        }
    }
    return NULL;
}

int main()
{
	int numbers[] = {2, 7, 11, 15};
	int returnSize;
	int *res = twoSum(numbers, 4, 9, &returnSize);
	for(int i = 0; i < returnSize; i++) {
		printf("%d ", res[i]);
	}
	printf("\n");
	return 0;
}
