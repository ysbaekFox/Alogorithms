#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

int V, E;
int visited[20001];
std::vector<std::vector<int>> graph;

bool BFS()
{
	bool isSuccess = true;

	std::queue<int> queue;

	for (int i = 1; i <= V; i++)
	{
		if (0 == visited[i])
		{
			queue.push(i);
			visited[i] = 1;

			while (!queue.empty())
			{
				int vertex = queue.front();
				queue.pop();

				std::vector<int>::const_iterator iter = graph[vertex].begin();
				std::vector<int>::const_iterator endIter = graph[vertex].end();

				while (endIter != iter)
				{
					if (0 == visited[*iter])
					{
						if (1 == visited[vertex])
						{
							visited[*iter] = 2;
						}
						else if (2 == visited[vertex])
						{
							visited[*iter] = 1;
						}

						if (graph[*iter].end() != std::find_if(graph[*iter].begin(), graph[*iter].end(),
							[iter](int v) { return visited[v] == visited[*iter]; }))
						{
							isSuccess = false;
							break;
						}

						queue.push(*iter);
					}

					iter++;
				}

				if (false == isSuccess)
				{
					break;
				}
			}
		}

		if (false == isSuccess)
		{
			break;
		}
	}

	return isSuccess;
}

int main()
{
	int testCase = 0;
	scanf("%d", &testCase);
	
	while (testCase--)
	{
		scanf("%d %d", &V, &E);

		graph.clear();
		graph.resize(V + 1);
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < E; i++)
		{
			int u, v;
			scanf("%d %d", &u, &v);

			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		if (true == BFS())
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}

	}

	return 0;
}