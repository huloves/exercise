#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int left_bound(int *nums, int nums_size, int target) {
	if(nums_size == 0) { return -1; }
	int left = 0;
	int right = nums_size - 1;   // notice
	while(left <= right) {   // notice
		int mid = left + (right - left) / 2;
		if(nums[mid] == target) {
			right = mid - 1;
		} else if(nums[mid] < target) {
			left = mid + 1;
		} else if(nums[mid] > target) {
			right = mid - 1;   // notice
		}
	}
	if(left >= nums_size || nums[left] != target) {
		return -1;
	}
	return left;
}

int right_bound(int *nums, int nums_size, int target) {
	int left = 0, right = nums_size - 1;
	while(left <= right) {
		int mid = left + (right - left) / 2;
		if(nums[mid] == target) {
			left = left + 1;
		} else if(nums[mid] < target) {
			left = left + 1;
		} else if(nums[mid] > target) {
			right = mid - 1;
		}
	}
	if(right < 0 || nums[right] != target) {
		return -1;
	}
	return right;
}

int main()
{
	return 0;
}
