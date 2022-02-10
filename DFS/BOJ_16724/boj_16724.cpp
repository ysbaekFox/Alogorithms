#include <stdio.h>

int parent[1000001];
char field[1001][1001];

int find(int x)
{
	if (parent[x] == x)
	{
		return x;
	}

	return parent[x] = find(parent[x]);
}

void _union(int x, int y)
{
	x = find(x);
	y = find(y);
	parent[y] = x;
}

int main()
{
	int N, M;
	scanf("%d %d ", &N, &M);

	for (int i = 0; i < N * M; i++)
	{
		parent[i] = i;
	}

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

			field[i][j] = direction;
		}
	}

	for (int i = 0; i < N * M; i++)
	{
		int y = i / M;
		int x = i % M;

		int Idx = (y * M) + x;
		int nextIdx = 0;

		switch (field[y][x])
		{
		case 'U':
			nextIdx = ((y - 1) * M) + x;
			break;
		case 'D':
			nextIdx = ((y + 1) * M) + x;
			break;
		case 'L':
			nextIdx = (y * M) + x - 1;
			break;
		case 'R':
			nextIdx = (y * M) + x + 1;
			break;
		}

		_union(nextIdx, Idx);
	}

	int count = 0;
	for (int i = 0; i < N * M; i++)
	{
		if (parent[i] == i)
		{
			count++;
		}
	}

	printf("%d", count);
	
	return 0;
}