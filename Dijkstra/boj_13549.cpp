#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 2000000000

int dist[100001];
bool visited[100001];

#if 0
// decltype + 积己磊俊 持绢林绢具窃.
auto compare = [](std::pair<int, int>& lhs, std::pair<int, int>& rhs)->bool { return lhs.first > rhs.first; };
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(compare)> pQueue(compare);
#else
class Compare
{
public:
	bool operator()(std::pair<int, int>& lhs, std::pair<int, int>& rhs)
	{
		return lhs.first > rhs.first;
	}
};
std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Compare> pQueue;
#endif

int N, K;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	if (N >= K)
	{
		std::cout << N - K;
		return 0;
	}

	int start = std::min(N, K);
	int size = std::max(N, K);

	for (int i = 0; i < 100001; i++)
	{
		dist[i] = INF;
	}

	dist[N] = 0;
	pQueue.push(std::make_pair(0, start));

	while (!pQueue.empty())
	{
		auto next = pQueue.top();
		pQueue.pop();

		if (100000 >= next.second * 2 && false == visited[next.second * 2])
		{
			dist[next.second * 2] = std::min(dist[next.second * 2], dist[next.second]);
			pQueue.push(std::make_pair(dist[next.second * 2], next.second * 2));
		}

		if (0 <= next.second - 1 && false == visited[next.second - 1])
		{
			dist[next.second - 1] = std::min(dist[next.second - 1], dist[next.second] + 1);
			pQueue.push(std::make_pair(dist[next.second - 1], next.second - 1));
		}

		if (100000 >= next.second + 1 && false == visited[next.second + 1])
		{
			dist[next.second + 1] = std::min(dist[next.second + 1], dist[next.second] + 1);
			pQueue.push(std::make_pair(dist[next.second + 1], next.second + 1));
		}

		visited[next.second] = true;
	}

	std::cout << dist[K];

	return 0;
}