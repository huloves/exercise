#include <stdio.h>
#include <stdlib.h>

void dfs(int **grid, int gridSize, int *gridColSize, int i, int j, int *size) {
    if(i < 0 || j < 0 || i >= gridSize || j >= *gridColSize) {
        return;
    }
    if(grid[i][j] == 0) {
        return;
    }
    grid[i][j] = 0;
    (*size)++;
    dfs(grid, gridSize, gridColSize, i + 1, j, size);
    dfs(grid, gridSize, gridColSize, i, j + 1, size);
    dfs(grid, gridSize, gridColSize, i - 1, j, size);
    dfs(grid, gridSize, gridColSize, i, j - 1, size);
    return;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int max = 0;
    for(int i = 0; i < gridSize; i++) {
        for(int j = 0; j < *gridColSize; j++) {
            int size = 0;
            if(grid[i][j] == 1) {
                dfs(grid, gridSize, gridColSize, i, j, &size);
                if(max < size)  {
                    max = size;
                }
            }
        }
    }
    return max;
}

int main()
{
	return 0;
}