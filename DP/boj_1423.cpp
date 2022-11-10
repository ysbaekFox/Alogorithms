#include<iostream>
#include<algorithm>

long long int n, day, characters[51], powers[51];
long long initPowerPoints, dp[101];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &characters[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &powers[i]);
	}

	scanf("%d", &day);
	for (int i = 1; i <= n; i++)
	{
		initPowerPoints += characters[i] * powers[i];
		characters[i] = std::min(day, characters[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		for(int remainCharacCnt = characters[i] ; 0 < remainCharacCnt ; --remainCharacCnt)
		{
			for (int remainDays = day; 0 <= remainDays; remainDays--)
			{
				for (int k = i + 1; k <= n && (k - i) + remainDays <= day; k++)
				{
					dp[(k - i) + remainDays] = std::max(dp[(k - i) + remainDays], dp[remainDays] + powers[k] - powers[i]);
				}
			}
		}
	}
	printf("%lld", dp[day] + initPowerPoints);
	return 0;
}