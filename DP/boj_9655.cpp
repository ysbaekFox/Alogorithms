#include <iostream>
#include <algorithm>

int dp[1001];

int main()
{
	int rockCnt = 0;
	scanf("%d", &rockCnt);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 1;

	for (int i = 4; i <= 1000; i++)
	{
		dp[i] = std::min(dp[i - 1], dp[i - 3]) + 1;
	}

	if (0 == dp[rockCnt] % 2)
	{
		std::cout << "CY";
	}
	else
	{
		std::cout << "SK";
	}

	return 0;
}