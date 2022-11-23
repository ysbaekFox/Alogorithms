#include <iostream>

int N;

int hp[21];
int point[21];

int dp[21][101];

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &hp[i]);
	}

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &point[i]);
	}

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x < 100; x++)
		{
			if ( 0 <= x - hp[y] )
			{
				dp[y][x] = std::max(dp[y - 1][x - hp[y]] + point[y], dp[y - 1][x]);
			}
			else
			{
				dp[y][x] = dp[y - 1][x];
			}
		}
	}

	std::cout << dp[N][99] << std::endl;
}