#include <iostream>

int N;

int dp[16];
int t[16];
int p[16];

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d %d", &t[i], &p[i]);
	}

	for (int i = 1; i <= N ;i++)
	{
		for (int j = i; j <= N + 1; j++)
		{
			if (j - i >= t[i])
			{
				dp[j] = std::max(dp[j], dp[i] + p[i]);
			}
		}
	}

	int maxCost = -1;
	for (int i = 1; i <= N + 1; i++)
	{
		maxCost = std::max(maxCost, dp[i]);
	}

	std::cout << maxCost;

	return 0;
}