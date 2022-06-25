#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 2000000000

int item[101];
int dist[101];

bool visited[101];

int N, M;

std::vector<std::vector<std::pair<int, int>>> field;

int Dijkstra(int start)
{
	using P = std::pair<int, int>;

	std::fill(dist, dist + 101, INF);
	std::fill(visited, visited + 101, false);

	std::priority_queue<P, std::vector<P>, std::greater<P>> queue;
	queue.push({ 0, start });
	dist[start] = 0;

	while (!queue.empty())
	{
		int curr = queue.top().second;
		int currCost = queue.top().first;
		
		queue.pop();

		if(visited[curr])
			continue;

		visited[curr] = true;

		for ( auto area : field[curr] )
		{
			int next = area.first;
			int nextCost = area.second;

			dist[next] = std::min(dist[next], dist[curr] + nextCost);
			queue.push({ dist[next], next });
		}
	}

	int sumItemCnt = 0;
	for (int i = 1; i <= N; i++)
	{
		if (M >= dist[i])
		{
			sumItemCnt += item[i];
		}
	}

	return sumItemCnt;
}

int main()
{
	int r;
	scanf("%d %d %d", &N, &M, &r);

	field.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &item[i]);
	}

	for (int i = 0; i < r; i++)
	{
		int a, b, l;
		scanf("%d %d %d", &a, &b, &l);

		field[a].push_back(std::make_pair(b, l));
		field[b].push_back(std::make_pair(a, l));
	}

	int maxItemCnt = -1;
	for (int i = 1; i <= N ; i++)
	{
		maxItemCnt = std::max(maxItemCnt, Dijkstra(i));
	}

	std::cout << maxItemCnt;

	return 0;
}