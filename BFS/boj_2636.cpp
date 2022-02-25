#include <stdio.h>
#include <queue>
#include <algorithm>
#include <cstring>

int X, Y;

int cheese[100][100];
int visited[100][100];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int IsAllMelt()
{
	int cheeseCnt = 0;
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if (1 == cheese[y][x])
			{
				cheeseCnt++;
			}
		}
	}

	return cheeseCnt;
}

void Melt(int y, int x)
{
	std::queue<std::pair<int, int>> queue;
	queue.push(std::make_pair(y, x));

	visited[y][x] = true;

	while (!queue.empty())
	{
		std::pair<int, int> curr = queue.front();
		queue.pop();

		for (int i = 0; i < 4; i++)
		{
			int currY = curr.first;
			int currX = curr.second;

			int ny = curr.first + dy[i];
			int nx = curr.second + dx[i];

			if ( ( 0 <= nx ) && ( 0 <= ny ) &&
				 ( nx < X ) && ( ny < Y ) &&
				 ( false == visited[ny][nx] ) )
			{
				if (0 == cheese[ny][nx])
				{
					visited[ny][nx] = 1;
					queue.push(std::make_pair(ny, nx));
				}
				else
				{
					cheese[ny][nx] = 0;
					visited[ny][nx] = 1;
				}
			}
		}
	}

	memset(visited, false, sizeof(visited));
}

int main()
{
	scanf("%d %d", &Y, &X);


	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			scanf("%d", &cheese[y][x]);
		}
	}

	int time = 0;
	int beforeHourCnt = 0;
	while (true)
	{
		const int remainCnt = IsAllMelt();
		if (0 == remainCnt)
		{
			break;
		}

		beforeHourCnt = remainCnt;

		Melt(0, 0);
		time++;
	}

	printf("%d\n", time);
	printf("%d", beforeHourCnt);

	return 0;
}