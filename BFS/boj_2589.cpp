#include <stdio.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

char map[50][50];
int distance[50][50];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int N, M;

int BFS(int i, int j)
{
	memset(distance, 0, sizeof(distance));

	std::queue<std::pair<int, int>> queue;
	queue.push(std::make_pair(i, j));

	distance[i][j] = 1;
	int maxDistance = distance[i][j];

	while (!queue.empty())
	{
		auto curr = queue.front();
		queue.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = curr.first + dx[i];
			int ny = curr.second + dy[i];

			if ( ( 0 <= nx ) &&
				 ( 0 <= ny ) &&
				 ( nx < N ) &&
				 ( ny < M ) &&
				 ( 'L' == map[nx][ny]) &&
				 ( 0 == distance[nx][ny] ) )
			{
				queue.push(std::make_pair(nx, ny));
				distance[nx][ny] = distance[curr.first][curr.second] + 1;

				if (maxDistance < distance[nx][ny])
				{
					maxDistance = distance[nx][ny];
				}
			}
		}
	}

	return maxDistance;
}

int main()
{
	scanf("%d %d ", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M + 1; j++)
		{
			char temp;
			scanf("%c", &temp);

			if ('\n' == temp)
			{
				break;
			}

			map[i][j] = temp;
		}
	}

	int maxValue = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if ( 'L' == map[i][j] )
			{
				maxValue = std::max(maxValue, BFS(i, j));
			}
		}
	}

	printf("%d", maxValue - 1);

	return 0;
}