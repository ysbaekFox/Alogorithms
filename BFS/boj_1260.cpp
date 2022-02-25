#include <stdio.h>
#include <algorithm>

#include <vector>
#include <queue>

class Graph
{
public:
	Graph()
		: N(0)
	{

	}

	Graph(int n)
		: N(n)
	{
		graph.resize(n);
	}

	void addEdge(int u, int v)
	{
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	void sortList()
	{
		for (auto& list : graph)
		{
			std::sort(list.begin(), list.end());
		}
	}

	virtual void search(int start) = 0;

protected:
	int N; // 정점의 개수
	std::vector<std::vector<int>> graph; // 인접 리스트
};

class BFS : public Graph
{
public:
	BFS()
		: Graph(0)
	{ }

	BFS(int n)
		: Graph(n)
	{ }

	virtual void search(int start) override
	{
		std::vector<bool> visited(graph.size(), false); // 방문 여부를 저장하는 배열
		std::queue<int> queue;
		queue.push(start);
		visited[start] = true;

		while (!queue.empty())
		{
			int curr = queue.front();
			queue.pop();
			printf("%d ", curr);

			for (int next : graph[curr])
			{
				if (!visited[next])
				{
					visited[next] = true;
					queue.push(next);
				}
			}
		}

	}
};

class DFS : public Graph
{
public:
	DFS()
		: Graph(0)
	{ }

	DFS(int n)
		: Graph(n)
	{ 
		visited.resize(graph.size());
	}

	virtual void search(int start) override
	{
		std::fill(visited.begin(), visited.end(), false);
		dfs(start);
	}

private:
	void dfs(int curr)
	{
		printf("%d ", curr);
		visited[curr] = true;
		for (int next : graph[curr])
		{
			if (!visited[next])
			{
				dfs(next);
			}
		}
	}

	std::vector<bool> visited; // 방문 여부를 저장하는 배열
};

int main()
{
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);

	BFS bfs(N + 1);
	DFS dfs(N + 1);

	for (int i = 0; i < M; i++)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		bfs.addEdge(u, v);
		dfs.addEdge(u, v);
	}

	bfs.sortList();
	dfs.sortList();

	dfs.search(V);
	printf("\n");
	bfs.search(V);

	return 0;
}