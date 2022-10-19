#include <iostream>
#include <queue>
#include <algorithm>

int F, S, G, U, D;

int move[2] = {0, 0};
bool visited[1000001];

int minCnt = 2100000000;

bool BFS(int S, int G)
{
	if (S == G)
	{
		minCnt = 0;
		return true;
	}

	bool isArrived = false;

	std::queue<std::pair<int,int>> queue;
	queue.push(std::make_pair(S, 1));

	visited[S] = true;

	while (!queue.empty())
	{
		std::pair<int, int> curr = queue.front();
		queue.pop();

		for (int i = 0; i < 2; i++)
		{
			const int next = curr.first + move[i];
			const int cnt = curr.second;

			if (G == next)
			{
				isArrived = true;
				visited[next] = true;
				minCnt = std::min(minCnt, cnt);
				continue;
			}

			if ( 0 < next && next <= F && false == visited[next] )
			{
				queue.push(std::make_pair(next, cnt + 1));
				visited[next] = true;
			}
		}
	}

	return isArrived;
}

int main()
{
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);

	move[0] = U;
	move[1] = -D;

	bool result = BFS(S, G);

	if (result)
	{
		std::cout << minCnt;
	}
	else
	{
		std::cout << "use the stairs";
	}

	return 0;
}