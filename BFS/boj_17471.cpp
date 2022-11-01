#include <iostream>
#include <vector>
#include <queue>
#define INF 2100000000

int N;
int peopleNumber[11];

bool visited[11];
bool selected[11];

std::vector<std::vector<int>> city;


int getFirstIdx(bool isArea_A)
{
	if (isArea_A)
	{
		for ( int idx = 1; idx <= N; idx++ )
		{
			if (true == selected[idx])
			{
				return idx;
			}
		}
	}
	else
	{
		for (int idx = 1; idx <= N; idx++)
		{
			if (false == selected[idx])
			{
				return idx;
			}
		}
	}

	return -1;
}

bool isCanDevide(bool isArea_A)
{
	if (isArea_A)
	{
		for (int idx = 1; idx <= N; idx++)
		{
			if (selected[idx] != visited[idx])
			{
				return false;
			}
		}
	}
	else
	{
		for (int idx = 1; idx <= N; idx++)
		{
			if (selected[idx] == visited[idx])
			{
				return false;
			}
		}
	}

	return true;
}

int BFS(int start, bool isArea_A)
{
	for (int i = 0; i <= N; i++)
	{
		visited[i] = false;
	}

	int totalCnt = 0;

	std::queue<int> queue;
	queue.push(start);

	visited[start] = true;
	totalCnt += peopleNumber[start];

	while (!queue.empty())
	{
		int curr = queue.front();
		queue.pop();

		for (int next : city[curr])
		{
			if ( false == visited[next] && isArea_A == selected[next] )
			{
				queue.push(next);
				visited[next] = true;
				totalCnt += peopleNumber[next];
			}
		}
	}

	return totalCnt;
}

int DFS(int idx, int count, int maxCnt)
{
	if ( count == maxCnt )
	{
		int areaA = BFS(getFirstIdx(true), true);
		if (!isCanDevide(true)) // 备开1
		{
			return INF;
		}

		int areaB = BFS(getFirstIdx(false), false);
		if (!isCanDevide(false)) // 备开2
		{
			return INF;
		}

		return std::abs(areaA - areaB);
	}

	int result = INF;
	for (int i = idx; i < N; i++)
	{
		if (selected[i] == true)
			continue;

		selected[i] = true;
		result = std::min(result, DFS(i, count + 1, maxCnt));
		selected[i] = false;
	}

	return result;
}

int main()
{
	std::cin >> N;
	city.resize(N + 1);

	for (int idx = 1; idx <= N; idx++)
	{
		std::cin >> peopleNumber[idx];
	}

	for (int idx = 1; idx <= N; idx++)
	{
		int siteCnt = 0;
		std::cin >> siteCnt;

		for (int jdx = 0; jdx < siteCnt; jdx++)
		{
			int neighbor;
			std::cin >> neighbor;

			city[idx].push_back(neighbor);
		}
	}

	int minValue = INF;
	for (int idx = 1; idx < N; idx++)
	{
		minValue = std::min(minValue, DFS(1, 0, idx));
	}

	if (INF == minValue)
	{
		minValue = -1;
	}

	std::cout << minValue << std::endl;

	return 0;
}