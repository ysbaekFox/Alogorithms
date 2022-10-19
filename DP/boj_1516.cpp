#include <iostream>
#include <vector>

#define INF 2100000000

int dp[501];
int buildings[501];
bool visited[501];

std::vector<std::vector<int>> required;

int GetCompleteTime(int idx)
{
	if ( true == visited[idx] )
	{
		return dp[idx];
	}

	visited[idx] = true;

	int result = 0;

	const size_t listSize = required[idx].size();
	for (int k = 0; k < listSize; k++)
	{
		result = std::max(result, GetCompleteTime(required[idx][k]));
	}

	result += buildings[idx];
	dp[idx] = std::min(result, dp[idx]);
	return result;
}

int main()
{
	std::fill(dp, dp + 501, INF);
	std::fill(buildings, buildings + 501, INF);

	int N = 0;
	scanf("%d", &N);

	required.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		int time;
		scanf("%d", &time);
		buildings[i] = time;

		while (true)
		{
			int r;
			scanf("%d", &r);

			if (-1 == r)
				break;

			required[i].push_back(r);
		}
	}

	for (int idx = 1; idx <= N; idx++)
	{
		std::cout << GetCompleteTime(idx) << std::endl;
	}

	return 0;
}