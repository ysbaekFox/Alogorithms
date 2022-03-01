#include <stdio.h>
#include <queue>
#include <set>
#include <cstring>
#include <algorithm>

int area[100][100];
int visited[100][100];

int N;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void BFS(int y, int x)
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
			int ny = curr.first + dy[i];
			int nx = curr.second + dx[i];

			if ((0 <= ny) &&
				(0 <= nx) &&
				(nx < N) &&
				(ny < N) &&
				(false == visited[ny][nx]))
			{
				queue.push(std::make_pair(ny, nx));
				visited[ny][nx] = true;
			}
		}
	}

}

int main()
{
	scanf("%d", &N);

	std::set<int> heightList;
	heightList.insert(0);
	for (int y = 0; y < N ; y++)
	{
		for (int x = 0; x < N ; x++)
		{
			scanf("%d", &area[y][x]);
			heightList.insert(area[y][x]);
		}
	}

	int safeArea = 0;
	for (int height : heightList)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (area[y][x] <= height)
				{
					visited[y][x] = true;
				}
			}
		}

		int tempSafeArea = 0;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (false == visited[y][x])
				{
					BFS(y, x);
					tempSafeArea++;
				}
			}
		}

		safeArea = std::max(safeArea, tempSafeArea);
		memset(visited, false, sizeof(visited));
	}

	printf("%d", safeArea);
	return 0;
}