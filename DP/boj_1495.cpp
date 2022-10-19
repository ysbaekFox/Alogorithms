#include <iostream>

int N, S, M;

int volume[51];
int dp[51][2];

int main()
{
	scanf("%d %d %d", &N, &S, &M);

	for (int idx = 1; idx <= N; idx++)
	{
		int vol;
		scanf("%d", &vol);

		volume[idx] = vol;
	}

	if( 0 <= S + volume[0] && S + volume[0] <= M )
		dp[1][0] = S + volume[0];
	
	if (0 <= S - volume[0] && S - volume[0] <= M)
		dp[1][1] = S - volume[0];

	for (int idx = 2; idx <= N; idx++)
	{
		dp[idx][0];
		dp[idx][1];
	}

	return 0;
}