#include <stdio.h>
#include <algorithm>
#include <functional>
#include <vector>

//std::vector<std::vector<int>> tree;
std::vector<std::pair<int, int>> tree[100001];

int v;
int n, m, dist;
int totaldist = 0;

bool visited[100001];

#define INF 100001

//int dfs(int start)
//{
//	visited[start] = true;
//
//	int dist = 0;
//	const int size = tree[start].size() - 1;
//
//	for (int i = 1; i <= size; i++)
//	{
//		if ( ( tree[start][i]  < INF ) && ( false == visited[i] ) )
//		{
//			dist = std::max(dist, dfs(i) + tree[start][i]);
//		}
//	}
//
//	return dist;
//}

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
		}
	}

	//printf("%d", dfs(1));

	return 0;
}