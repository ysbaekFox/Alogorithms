#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>

//std::vector<std::vector<int>> tree;
std::vector<std::pair<int, int>> tree[100001];

int v;
int n, m, dist;

int lastNode;
int totaldist = 0;

bool visited[100001];

#define INF 100001

void dfs(int i, int dist)
{
	if (true == visited[i])
		return;
	if (totaldist < dist)
	{
		lastNode = i;
		totaldist = dist;
	}

	visited[i] = true;

	const int size = tree[i].size();

	for (int j = 0; j < size; j++)
	{
		int nextNode = tree[i][j].first;
		int nextDist = tree[i][j].second;
		dfs(nextNode, nextDist + dist);
	}
}

int main()
{
	scanf("%d", &v);

	for (int i = 1; i <= v; i++)
	{
		scanf("%d", &n);

		while (true)
		{
			scanf("%d", &m);

			if (-1 == m)
			{
				break;
			}
			else
			{
				scanf("%d", &dist);
			}

			tree[n].push_back(std::make_pair(m, dist));
			tree[m].push_back(std::make_pair(n, dist));
		}
	}

	dfs(1, 0);
	memset(visited, false, sizeof(visited));
	totaldist = 0;

	dfs(lastNode, 0);
	printf("%d", totaldist);

	return 0;
}