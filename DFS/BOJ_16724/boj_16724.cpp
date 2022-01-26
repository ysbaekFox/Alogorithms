#include <stdio.h>

bool isVisited = false;
char zone[1001][1001];
bool visited[1001][1001];

void dfs(int i, int j)
{
	if (visited[i][j])
	{
		isVisited = true;
		return;
	}

	visited[i][j] = true;

	switch (zone[i][j])
	{
	case 'U':
		dfs(i - 1, j);
		break;
	case 'D':
		dfs(i + 1, j);
		break;
	case 'L':
		dfs(i, j - 1);
		break;
	case 'R':
		dfs(i, j + 1);
		break;
	}
}

int main()
{
	int N, M;
	scanf("%d %d ", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M + 1; j++)
		{
			char direction = 0;
			scanf("%c", &direction);

			if ('\n' == direction)
			{
				break;
			}

			zone[i][j] = direction;
		}
	}

	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (false == visited[i][j])
			{
				dfs(i, j);

				if (true == isVisited)
				{
					count++;
				}
			}

			isVisited = false;
		}
	}

	printf("%d", count);
	return 0;
}