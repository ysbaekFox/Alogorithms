#include <stdio.h>
#include <queue>
#include <cstring>
#include <algorithm>

int visited[50][50];
int island[50][50];

int dy[8] = { -1 , -1, -1, 0, 1, 1,  1, 0 };
int dx[8] = { -1 ,  0,  1, 1, 1, 0, -1,-1 };

int N, M;

void BFS(int i, int j)
{
	std::queue<std::pair<int, int>> queue;
	queue.push(std::make_pair(i, j));

	while (!queue.empty())
	{
		std::pair<int, int> curr = queue.front();
		queue.pop();

		visited[curr.second][curr.first] = true;

		for (int i = 0; i < 8; i++)
		{
			int nx = curr.first   + dx[i];
			int ny = curr.second  + dy[i];

			if ( ( 0 <= nx ) &&
				 ( 0 <= ny ) &&
				 ( nx < M  ) &&
				 ( ny < N  ) &&
				 ( 1 == island[ny][nx]) &&
				 ( false == visited[ny][nx]) )
			{
				visited[ny][nx] = true;
				queue.push(std::make_pair(nx, ny));
			}
		}
	}
}

int main()
{
	std::vector<int> result;

	while (true)
	{
		scanf("%d %d", &M, &N);

		if ( ( 0 == N ) &&
			 ( 0 == M ) )
		{
			break;
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				scanf("%d", &island[i][j]);
			}
		}

		int count = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if ( ( false == visited[i][j] ) &&
					 ( 1 == island[i][j]) )
				{
					BFS(j, i);
					count++;
				}
			}
		}

		result.push_back(count);

		memset(island, 0, sizeof(island));
		memset(visited, false, sizeof(visited));
	}

	for (int i = 0; i < result.size(); i++)
	{
		printf("%d\n", result[i]);
	}

	return 0;
}