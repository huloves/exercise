#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* findAnagrams(char * s, char * p, int* returnSize){
    int window[200], need[200];
    memset(window, 0, sizeof(window));
    memset(need, 0, sizeof(need));
    int s_len = strlen(s), p_len = strlen(p);
    for(int i = 0; i < p_len; i++) {
        int index = p[i];
        need[index]++;
    }
    int need_size = 0;
    for(int i = 0; i < 200; i++) {
        if(need[i] != 0) {
            need_size++;
        }
    }
    int right = 0, left = 0;
    int vaild = 0;
    *returnSize = 0;
    int *res = (int*)malloc(sizeof(int) * 200);
    while(right < s_len) {
        char c = s[right];
        right++;
        if(need[c]) {
            window[c]++;
            if(window[c] == need[c]) { vaild++; }
        }
        while(right - left >= p_len) {
            if(vaild == need_size) {
                res[(*returnSize)] = left;
                (*returnSize)++;
            }
            char d = s[left];
            left++;
            if(need[d]) {
                if(window[d] == need[d]) { vaild--; }
                window[d]--;
            }
        }
    }
    return res;
}

int main()
{
    char *s = "cbaebabacd", *p = "abc";
    int returnSize;
    int *res = findAnagrams(s, p, &returnSize);
    for(int i = 0; i < returnSize; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    free(res);
	return 0;
}
