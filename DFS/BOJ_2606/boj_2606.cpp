#include <stdio.h>
#include <vector>

bool visited[101];
std::vector<std::vector<int>> computers;

void dfs(int start)
{
	visited[start] = true;

	for (int i = 0; i < computers[start].size(); i++)
	{
		if (false == visited[computers[start][i]])
		{
			dfs(computers[start][i]);
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	computers.resize(n + 1);

	int num;
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		computers[n].push_back(m);
		computers[m].push_back(n);
	}

	dfs(1);

	int count = 0;
	for (int i = 2; i <= n; i++)
	{
		if (true == visited[i])
		{
			count++;
		}
	}

	printf("%d", count);

	return 0;
}