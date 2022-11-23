#include <iostream>

int N;
int gameBoard[100][100];
long long int dp[100][100];

int main()
{
	scanf("%d", &N);

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			scanf("%d", &gameBoard[y][x]);
		}
	}

	dp[0][0] = 1;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int next = gameBoard[y][x];

			if (next == 0)
				continue;
			dp[y + next][x] += dp[y][x];
			dp[y][x + next] += dp[y][x];
		}
	}

	std::cout << dp[N - 1][N - 1] << '\n';

	return 0;
}