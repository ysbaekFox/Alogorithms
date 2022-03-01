#include <stdio.h>
#include <queue>
#include <algorithm>
#include <cstring>

int X, Y;

std::queue<std::pair<int, int>> queue;

bool allTomatoRipe = true;
int tomatoCount = 0;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int tomatoBox[1000][1000];
bool visited[1000][1000];

int BFS()
{
	int day = 0;
	int initialTomatoCnt = queue.size();

	while (!queue.empty())
	{
		const int qSize = queue.size();
		for (int qIdx = 0; qIdx < qSize; qIdx++)
		{
			std::pair<int, int> curr = queue.front();
			queue.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = curr.first + dy[i];
				int nx = curr.second + dx[i];

				if ( ( 0 <= nx ) &&
					 ( 0 <= ny ) &&
					 ( nx < X ) &&
					 ( ny < Y ) &&
					 ( false == visited[ny][nx] ) &&
					 ( 0 == tomatoBox[ny][nx] ) )
				{
					tomatoBox[ny][nx] = 1;
					visited[ny][nx] = true;
					queue.push(std::make_pair(ny, nx));
				}
			}
		}

		day++;
	}

	int ripedTomatoCount = 0;
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if (1 == tomatoBox[y][x])
			{
				ripedTomatoCount++;
			}
		}
	}

	if (tomatoCount == ripedTomatoCount)
	{
		return (day - 1);
	}
	else
	{
		return -1;
	}
}

int main()
{
	scanf("%d %d", &X, &Y);

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			scanf("%d", &tomatoBox[y][x]);

			if (1 == tomatoBox[y][x])
			{
				visited[y][x] = true;
				queue.push(std::make_pair(y, x));
				tomatoCount++;
			}
			else if (0 == tomatoBox[y][x])
			{
				allTomatoRipe = false;
				tomatoCount++;
			}
		}
	}

	if (true == allTomatoRipe)
	{
		printf("%d", 0);
	}
	else
	{
		printf("%d", BFS());
	}

	return 0;
}