#include <stdio.h>
#include <string.h>
#include <algorithm>

int forest[501][501];
int memoization[501][501];

int dfs(int x, int y, int prevTree, int moveCount)
{
	if ((1 > x) || (500 < x) || (1 > y) || (500 < y))
	{
		return moveCount - 1;
	}

    if (prevTree >= forest[x][y])
    {
        return moveCount - 1;
    }

    return std::max({  dfs(x + 1, y, forest[x][y], moveCount + 1),
                       dfs(x - 1, y, forest[x][y], moveCount + 1),
                       dfs(x, y + 1, forest[x][y], moveCount + 1),
                       dfs(x, y - 1, forest[x][y], moveCount + 1) });
}

int main()
{
	int N = 0;
    scanf("%d\n", &N);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &forest[i][j]);
        }
    }
    
    int maxValue = 1;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
        {
            int result = dfs(i, j, 0, 1);
            memoization[i][j] = result;
            maxValue = std::max(maxValue, result);
        }
    }

    printf("%d", maxValue);
    return 0;
}