#include <iostream>
#include <stdlib.h>
#include <functional>
#include <algorithm>

int board[100001][3];
int dp[3];

#define MAX_VALUE 2100000000
#define MIN_VALUE -1

int main()
{
	int N = 0;
	scanf("%d", &N);

	for (int y = 1; y <= N; y++)
	{
		int a, b, c;
		scanf("%d %d %d", &board[y][0], &board[y][1], &board[y][2]);
	}

	std::fill(&dp[0], &dp[3], MIN_VALUE);

	dp[0] = board[1][0];
	dp[1] = board[1][1];
	dp[2] = board[1][2];

	for (int y = 2; y <= N; y++)
	{
		int temp1 = dp[0];
		int temp2 = dp[1];
		int temp3 = dp[2];

		dp[0] = std::max(temp1, temp2) + board[y][0];
		dp[1] = std::max({ temp1, temp2, temp3 }) + board[y][1];
		dp[2] = std::max(temp2, temp3) + board[y][2];
	}

	std::cout << std::max({ dp[0], dp[1], dp[2] }) << " ";

	std::fill(&dp[0], &dp[3], MAX_VALUE);

	dp[0] = board[1][0];
	dp[1] = board[1][1];
	dp[2] = board[1][2];

	for (int y = 2; y <= N; y++)
	{
		int temp1 = dp[0];
		int temp2 = dp[1];
		int temp3 = dp[2];

		dp[0] = std::min(temp1, temp2) + board[y][0];
		dp[1] = std::min({ temp1, temp2, temp3 }) + board[y][1];
		dp[2] = std::min(temp2, temp3) + board[y][2];
	}

	std::cout << std::min({ dp[0], dp[1], dp[2] });

	return 0;
}