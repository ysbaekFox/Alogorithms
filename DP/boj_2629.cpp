#include <iostream>
#include <algorithm>
#include <math.h>

int N, M;
int weight[31];

bool dp[31][40001];

void checkAvailable(int i, int w)
{
	if ( i > N || dp[i][w] ) 
		return;
	
	dp[i][w] = true;

	checkAvailable(i + 1, w + weight[i]);
	checkAvailable(i + 1, abs(w - weight[i]));
	checkAvailable(i + 1, w);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		int n;
		scanf("%d", &n);
		weight[i] = n;
	}

	checkAvailable(0, 0);

	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int m;
		scanf("%d", &m);

		if (dp[N][m])
		{
			std::cout << "Y ";
		}
		else
		{
			std::cout << "N ";
		}
	}

	return 0;
}