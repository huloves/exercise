#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int lengthOfLongestSubstring(char * s) {
    int hash[128] = {0};
    int max = 0;

    // 统计字符出现的次数
    for (int i = 0; i < strlen(s); i++) {
        memset(hash, 0, sizeof(int) * 126);
        int cnt = 1;
        hash[s[i]] = 1;
        for (int j = i + 1; j < strlen(s); j++) {
            if (hash[s[j]] != 1) {
                cnt++;
                hash[s[j]] = 1;
            } else {
                break;
            }
        }
        if(max < cnt) {
            max = cnt;
        }
    }
    return max;
}

int main(int argc, char** argv)
{
    char* str = "dvdf";
    printf("strlen(str) = %d\n", strlen(str));
    printf("%d\n", lengthOfLongestSubstring(str));
    return 0;
}
