#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <string.h>
#include <algorithm>

#define INF 2000000000

int N;

int room[50][50];
int dist[2500];
bool visited[2500];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int BFS(int y, int x)
{
	auto getPair = [](int index) { return std::make_pair(index / N, index % N); };
	auto getIndex = [](int y, int x) { return (N * y) + x; };

	std::fill(dist, dist + 2501, INF);
	std::fill(visited, visited + 2501, false);

	std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, std::greater<std::pair<int,int>>> queue;

	const int start = getIndex(y, x);
	queue.push(std::make_pair(0, start));
	dist[start] = 0;

	while (!queue.empty())
	{
		const auto curr = queue.top();
		queue.pop();

		auto currPair = getPair(curr.second);
		int currY = currPair.first;
		int currX = currPair.second;

		if (true == visited[curr.second])
			continue;

		visited[curr.second] = true;

		for (int i = 0; i < 4; i++)
		{
			int nextY = currPair.first + dy[i];
			int nextX = currPair.second + dx[i];
			int next = getIndex(nextY, nextX);

			if ( 0 <= nextX && 0 <= nextY && nextX < N && nextY < N && false == visited[next] )
			{
				if (0 == room[nextY][nextX])
				{
					dist[next] = std::min(dist[next], dist[curr.second] + 1);
				}
				else
				{
					dist[next] = std::min(dist[next], dist[curr.second]);
				}

				queue.push(std::make_pair(dist[next], next));
			}
		}
	}

	return dist[getIndex(N - 1, N - 1)];
}

int main()
{
	scanf("%d", &N);

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int temp;
			scanf("%1d", &temp);

			room[y][x] = temp;
		}
	}

	std::cout << BFS(0, 0);

	return 0;
}