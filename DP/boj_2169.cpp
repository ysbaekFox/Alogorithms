#include <iostream>
#include <algorithm>

int mars[1000][1000];
int dp[1000][1000][2];

int Y = 1, X = 1;

#define NEGATIVE_INF -2000000000

int main()
{
	std::fill(&dp[0][0][0], &dp[999][999][2] + 1, NEGATIVE_INF);

	scanf("%d %d", &Y, &X);

	if (X < 1 || Y < 1)
		return 0;

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			int temp;
			scanf("%d", &mars[y][x]);
		}
	}

	dp[0][0][0] = mars[0][0];

	for (int x = 1; x < X; x++)
	{
		dp[0][x][0] = std::max(dp[0][x][0], dp[0][x - 1][0] + mars[0][x]);
	}

	for (int y = 1; y < Y - 1; y++)
	{
		dp[y][0][0] = mars[y][0] + std::max(dp[y - 1][0][0], dp[y - 1][0][1]);

		for (int x = 1; x < X; x++)
		{
			dp[y][x][0] = mars[y][x] + std::max(dp[y][x - 1][0], std::max(dp[y - 1][x][0], dp[y - 1][x][1]));
		}

		dp[y][X - 1][1] = mars[y][X - 1] + std::max(dp[y - 1][X - 1][0], dp[y - 1][X - 1][1]);

		for (int x = X - 2; 0 <= x; x--)
		{
			dp[y][x][1] = mars[y][x] + std::max(dp[y][x + 1][1], std::max(dp[y - 1][x][0], dp[y - 1][x][1]));
		}
	}

	if ( 1 < Y )
	{
		dp[Y - 1][0][0] = mars[Y - 1][0] + std::max(dp[Y - 2][0][0], dp[Y - 2][0][1]);

		for (int x = 1; x < X; x++)
		{
			dp[Y - 1][x][0] = mars[Y - 1][x] + std::max(dp[Y - 1][x - 1][0], std::max(dp[Y - 2][x][0], dp[Y - 2][x][1]));
		}
	}

	std::cout << dp[Y - 1][X - 1][0];

	return 0;
}