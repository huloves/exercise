#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int **ans;
int path[15];
int path_size;

void traverse(int s, int **graph, int graphSize, int *graphColSize, int *returnSize, int **returnColumnSizes) {
    // 添加节点 s 到路径
    path[path_size++] = s;

    if(s == graphSize - 1) {
        // int *temp = (int*)malloc(sizeof(int) * path_size);
        // memcpy(temp, path, sizeof(int) * path_size);
        // ans[*returnSize] = temp;
        ans[*returnSize] = (int*)malloc(sizeof(int) * path_size);
        memcpy(ans[*returnSize], path, sizeof(int) * path_size);
        (*returnColumnSizes)[*returnSize] = path_size;
        (*returnSize)++;
        path_size--;
        return;
    }

    // 递归遍历每一个相邻节点
    for(int i = 0; i < graphColSize[s]; i++) {
        traverse(graph[s][i], graph, graphSize, graphColSize, returnSize, returnColumnSizes);
    }

    // 从路径中移除节点s
    path_size--;
}

int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes){
    path_size = 0;
    ans = (int**)malloc(sizeof(int*) * 20000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 20000);
    *returnSize = 0;
    traverse(0, graph, graphSize, graphColSize, returnSize, returnColumnSizes);
    return ans;
}

int main()
{
	return 0;
}
