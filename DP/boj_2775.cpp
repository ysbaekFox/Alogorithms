#include <iostream>

int dp[15][15];

int main()
{
	for (int i = 1; i <= 14; i++)
	{
		dp[0][i] = i;
	}

	for (int i = 1; i <= 14; i++)
	{
		dp[i][1] = 1;
	}

	for (int i = 1; i <= 14; i++)
	{
		for (int j = 2; j <= 14; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	int testCase = 0;
	scanf("%d", &testCase);

	for (int i = 0; i < testCase; i++)
	{
		int k = 0;
		scanf("%d", &k);

		int n = 0;
		scanf("%d", &n);

		std::cout << dp[k][n] << std::endl;
	}


	return 0;
}