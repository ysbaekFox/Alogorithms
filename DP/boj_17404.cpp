#include <iostream>
#include <algorithm>

int rgb[1000][3];
int dp[1000][3];

int N;
#define INF 210000000

int result = INF;

int calculateMinCost(int startColor /*r:0 g:1 b:2 */)
{
	int result = INF;

	for (int i = 0; i < 1000; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			dp[i][j] = INF;
		}
	}

	dp[0][startColor] = rgb[0][startColor];

	for (int i = 1; i < N; i++)
	{
		dp[i][0] = rgb[i][0] + std::min(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = rgb[i][1] + std::min(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = rgb[i][2] + std::min(dp[i - 1][0], dp[i - 1][1]);
	}

	for (int i = 0; i < 3; i++)
	{
		if (i != startColor)
		{
			result = std::min(result, dp[N - 1][i]);
		}
	}

	return result;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d %d", &rgb[i][0], &rgb[i][1], &rgb[i][2]);
	}

	std::cout << std::min({ calculateMinCost(0), calculateMinCost(1), calculateMinCost(2) }) << std::endl;

	return 0;
}