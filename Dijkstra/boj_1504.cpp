#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#include <functional>

int N, E;

std::vector<std::vector<std::pair<int, int>>> graph;

bool visited[801];
int dist[801];

#define INF 2000000000

std::pair<int,int> Dijkstra(int v)
{
	std::priority_queue < std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pQueue;

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < 801 ; i++)
	{
		dist[i] = INF;
	}

	dist[v] = 0;
	pQueue.push(std::make_pair(0, v));

	while (!pQueue.empty())
	{
		auto curr = pQueue.top();
		pQueue.pop();

		if (false == visited[curr.second])
		{
			visited[curr.second] = true;

			for (auto next : graph[curr.second])
			{
				dist[next.first] = std::min(dist[next.first], dist[curr.second] + next.second);
				pQueue.push(std::make_pair(dist[next.first], next.first));
			}
		}
	}

	std::pair<int, int> minV = { 0, INF };
	for (int i = 1; i <= N; i++)
	{
		if(i == v)
			continue;

		if ( minV.second > dist[i] )
		{
			minV = { i, dist[i] };
		}
	}

	return minV;
}

int main()
{
	scanf("%d %d", &N, &E);

	graph.resize(N + 1);

	for (int i = 0; i < E; i++)
	{
		int u, v, d;
		scanf("%d %d %d", &u, &v, &d);

		graph[u].push_back(std::make_pair(v, d));
		graph[v].push_back(std::make_pair(u, d));
	}

	int v1, v2;
	scanf("%d %d", &v1, &v2);

	Dijkstra(1);
	int _1toA = dist[v1];
	int _1toB = dist[v2];

	Dijkstra(v1);
	int AtoB = dist[v2];
	int AtoN = dist[N];

	Dijkstra(v2);
	int BtoN = dist[N];

	if ((INF == _1toA) ||
		(INF == _1toB) ||
		(INF == AtoB) ||
		(INF == AtoN) ||
		(INF == BtoN))
	{
		std::cout << -1;
		return 0;
	}

	if ((_1toA + AtoB + BtoN) < (_1toB + AtoB + AtoN))
	{
		std::cout << _1toA + AtoB + BtoN;
	}
	else
	{
		std::cout << _1toB + AtoB + AtoN;
	}

	return 0;
}