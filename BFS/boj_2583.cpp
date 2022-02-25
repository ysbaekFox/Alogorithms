#include "stdio.h"
#include <vector>
#include <queue>
#include <algorithm>

int paper[100][100];
int visited[100][100];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0 , 0 };

int M, N, K;

int BFS(int i, int j)
{
	int areaSize = 0;

	std::queue<std::pair<int, int>> queue;
	queue.push(std::make_pair(i, j));

	visited[i][j] = true;
	areaSize++;

	while (!queue.empty())
	{
		std::pair<int, int> curr = queue.front();
		queue.pop();


		for (int i = 0; i < 4; i++)
		{
			int nx = curr.second + dx[i];
			int ny = curr.first + dy[i];

			if ( ( 0 <= nx ) &&
				 ( 0 <= ny ) &&
				 ( ny < M  ) &&
				 ( nx < N  ) &&
				 ( !visited[ny][nx] && !paper[ny][nx]) )
			{
				queue.push(std::make_pair(ny, nx));
				visited[ny][nx] = true;
				areaSize++;
			}
		}
	}

	return areaSize;
}

int main()
{
	scanf("%d %d %d", &M, &N, &K);

	for (int k = 0; k < K; k++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);

		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				paper[j][i] = 1;
			}
		}
	}

	int count = 0;
	std::vector<int> areaList;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j] && !paper[i][j] )
			{
				areaList.push_back(BFS(i, j));
				count++;
			}
		}
	}

	printf("%d\n", count);
	std::sort(areaList.begin(), areaList.end());

	for (int area : areaList)
	{
		printf("%d ", area);
	}

	return 0;
}