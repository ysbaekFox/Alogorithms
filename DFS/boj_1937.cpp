#include <stdio.h>
#include <string.h>
#include <algorithm>

int N = 0;

int forest[501][501];
int memoization[501][501];

int dx[4] = { -1, 1, 0, 0};
int dy[4] = { 0, 0, -1, 1};

int dfs(int x, int y)
{
	if (0 < memoization[x][y])
		return memoization[x][y];

    memoization[x][y] = 1;
    for (int i = 0; i< 4 ;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if ((1 <= nx) && (N >= nx) && (1 <= ny) && (N >= ny))
        {
            if (forest[x][y] < forest[nx][ny])
            {
                memoization[x][y] = std::max(memoization[x][y], dfs(nx, ny) + 1);
            }
        }
    }

    return memoization[x][y];
}

int main()
{
    scanf("%d\n", &N);

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            scanf("%d", &forest[i][j]);
        }
    }
    
    int maxValue = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
        {
            maxValue = std::max(maxValue, dfs(i, j));
        }
    }

    printf("%d", maxValue);
    return 0;
}