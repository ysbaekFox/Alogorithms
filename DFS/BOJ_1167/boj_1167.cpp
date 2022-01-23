#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>

std::vector<std::vector<int>> tree;

int v;
int n, m, dist;
int totaldist = 0;

bool visited[1000001];

#define INF 100001

int dfs(int start)
{
	visited[start] = true;

	int dist = 0;
	const int size = tree[start].size() - 1;
	for (int i = 1; i <= size; i++)
	{
		if ( ( tree[start][i]  < INF ) && ( false == visited[i] ) )
		{
			dist = std::max(dist, dfs(i) + tree[start][i]);
		}
	}

	return dist;
}

int main()
{
	scanf("%d", &v);
	tree.resize(v + 1);
	for (int i = 1; i <= v; i++)
	{
		tree[i].resize(v + 1);
		std::fill(tree[i].begin(), tree[i].end(), INF);
	}

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

			tree[n][m] = dist;
		}
	}

	printf("%d", dfs(1));

	return 0;
}