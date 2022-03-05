#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>

int N = 0;

int parentNode[100001];
int visited[100001];
std::vector<std::vector<int>> tree;

void BFS(int i)
{
	std::queue<int> queue;
	queue.push(i);

	visited[i] = true;

	while (!queue.empty())
	{
		int curr = queue.front();
		queue.pop();

		for (int v : tree[curr])
		{
			if (false == visited[v])
			{
				parentNode[v] = curr;
				visited[v] = true;
				queue.push(v);
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	tree.resize(N + 1);

	for (int i = 1; i < N; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);

		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	BFS(1);
	
	for (int i = 2; i <= N; i++)
	{
		printf("%d\n", parentNode[i]);
	}

	return 0;
}