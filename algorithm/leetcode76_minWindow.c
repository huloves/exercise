#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char * minWindow(char * s, char * t){
    // 初始化 window 和 need 两个哈希表，记录窗口中字符和需要凑齐的字符情况
    int window[200], need[200];
    memset(window, 0, sizeof(window));
    memset(need, 0, sizeof(need));
    int t_len = strlen(t);
    int s_len = strlen(s);
    for(int i = 0; i < t_len; i++) {
        int index = t[i];
        need[index]++;
    }
    int need_size = 0;   // 需要的字符种类数
    for(int i = 0; i < 200; i++) {
        if(need[i] != 0) {
            need_size++;
        }
    }
    int left = 0, right = 0;   // 窗口：[left, right)
    int vaild = 0;   // 窗口中满足 need 条件的字符个数
    int start = 0, len = INT_MAX;
    while(right < s_len) {
        char c = s[right];
        right++;
        if(need[c]) {
            window[c]++;
            if(window[c] == need[c]) { vaild++; }
        }
        while(vaild == need_size) {
            if(right - left < len) {
                start = left;
                len = right - left;
            }
            char d = s[left];
            left++;
            if(need[d]) {
                if(window[d] == need[d]) { vaild--; }
                window[d]--;
            }
        }
    }
    char *res = "";
    if(len != INT_MAX) {
        res = (char*)malloc(sizeof(char) * len + 1);
        strncpy(res, s + start, len);
        res[len] = '\0';
    }
    return res;
}

int main()
{
    return 0;
}
