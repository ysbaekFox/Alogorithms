#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int minIdx, maxIdx;
int N, K;

int map[100001];
bool visited[100001];

#define INF 2100000000

void BFS(int start, int end)
{
	if (start == end)
	{
		std::cout << 0 << std::endl;
		std::cout << start;
		return;
	}

	if (start > end)
	{
		std::cout << start - end << std::endl;
		for (int i = start; end <= i  ; i--)
		{
			std::cout << i << " ";
		}

		return;
	}

	bool isFound = false;
	int cnt = INF;
	std::vector<int> result;

	std::queue<std::pair<int, std::vector<int>>> queue;
	queue.push(std::make_pair(start, std::vector<int>{ start }));
	visited[start] = true;

	while (!queue.empty())
	{
		auto curr = queue.front();
		queue.pop();

		for (int i = 0; i < 3; i++)
		{
			int next = 0;
			switch (i)
			{
			case 0:
				next = curr.first + 1;
				break;
			case 1:
				next = curr.first - 1;
				break;
			case 2:
				next = curr.first * 2;
				break;
			}

			if (0 <= next && next <= 100000 && false == visited[next])
			{
				std::vector<int> history = curr.second;

				if (next == end)
				{
					cnt = history.size();
					result = history;
					isFound = true;
					break;
				}

				history.push_back(next);

				queue.push(std::make_pair(next, history));
				visited[next] = true;
			}
		}

		if (true == isFound)
			break;
	}

	std::cout << cnt << std::endl;

	for (auto idx : result)
	{
		std::cout << idx << " ";
	}

	std::cout << end;
}

int main()
{
	scanf("%d %d", &N, &K);
	BFS(N, K);

	return 0;
}