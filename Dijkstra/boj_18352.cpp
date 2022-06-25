#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <functional>
#include <algorithm>

int dist[300001];
bool visited[300001];

#define INF 2000000000

std::vector<std::vector<int>> city;
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pQueue;

void Dijkstra(int X)
{
	memset(visited, false, sizeof(visited));
	
	for (int i = 0; i < 300001; i++)
	{
		dist[i] = INF;
	}

	pQueue.push(std::make_pair(0, X));
	dist[X] = 0;

	while (!pQueue.empty())
	{
		auto curr = pQueue.top();
		pQueue.pop();

		if(visited[curr.second])
			continue;

		visited[curr.second] = true;

		for ( auto next : city[curr.second] )
		{
			dist[next] = std::min(dist[next], dist[curr.second] + 1);
			pQueue.push(std::make_pair(dist[next], next));
		}
	}
}

int main()
{
	int N, M, K, X;
	scanf("%d %d %d %d", &N, &M, &K, &X);

	city.resize(N + 1);

	for (int i = 0; i < M; i++)
	{
		int A, B;
		scanf("%d %d", &A, &B);

		city[A].push_back(B);
	}

	Dijkstra(X);

	bool isExist = false;
	for (int i = 1; i <= N; i++)
	{
		if (K == dist[i])
		{
			std::cout << i << std::endl;
			isExist = true;
		}
	}

	if (false == isExist)
	{
		std::cout << -1;
	}

	return 0;
}