#include <stdio.h>
#include <queue>
#include <algorithm>

int V, E;
std::vector<std::vector<int>> graph;
bool visited[1001];

void BFS(int v)
{
	std::queue<int> queue;
	queue.push(v);

	visited[v] = true;

	while (!queue.empty())
	{
		int currV = queue.front();
		queue.pop();

		for (int nextV : graph[currV])
		{
			if (false == visited[nextV])
			{
				visited[nextV] = true;
				queue.push(nextV);
			}
		}
	}
}

int main()
{	
	scanf("%d %d", &V, &E);

	graph.resize(V + 1);

	for (int i = 0; i < E; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	int ccCnt = 0;
	for (int i = 1; i <= V; i++)
	{
		if (false == visited[i])
		{
			BFS(i);
			ccCnt++;
		}
	}

	printf("%d", ccCnt);

	return 0;
}