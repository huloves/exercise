#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int* nums3 = (int*)malloc(sizeof(int) * (nums1Size + nums2Size));
    int ptr1 = 0;
    int ptr2 = 0;
    int ptr3 = 0;
    double ans;
    while(ptr1 < nums1Size && ptr2 < nums2Size) {
        if(nums1[ptr1] < nums2[ptr2]) {
            nums3[ptr3] = nums1[ptr1];
            ptr1++;
        } else {
            nums3[ptr3] = nums2[ptr2];
            ptr2++;
        }
        ptr3++;
    }
    while(ptr1 < nums1Size) {
        nums3[ptr3] = nums1[ptr1];
        ptr1++;
        ptr3++;
    }
    while(ptr2 < nums2Size) {
        nums3[ptr3] = nums2[ptr2];
        ptr2++;
        ptr3++;
    }
    for(int i=0; i<ptr3; i++) {
        printf("%d ", nums3[i]);
    }
    printf("\n");
    if((ptr3 % 2) == 0) {
        ans = ( (nums3[ptr3 / 2] + nums3[ptr3 / 2 - 1]) ) / 2.0;
        printf("%f\n", ans);
    } else {
        ans = (nums3[(ptr3)/2]) * 1.0;
    }
    return ans;
}

int main()
{
    int a[2] = {1, 2};
    int b[2] = {3, 4};
    double ans = findMedianSortedArrays(a, sizeof(a) / sizeof(int), b, sizeof(b) / sizeof(int));
    printf("%f\n", ans);
    return 0;
}
