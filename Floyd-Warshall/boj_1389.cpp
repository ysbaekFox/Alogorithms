#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

#define INF 200000000

int N, M;
int users[101][101];

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			( i == j ) ? users[i][j] = 0 : users[i][j] = INF;
		}
	}

	for (int i = 0; i < M; i++)
	{
		int A, B;
		scanf("%d %d", &A, &B);

		users[A][B] = 1;
		users[B][A] = 1;
	}

	for (int k = 1; k <= N ; k++)
	{
		for (int i = 1; i <= N ; i++)
		{
			for (int j = 1; j <= N ; j++)
			{
				if( k== i || j == i)
					continue;

				users[i][j] = std::min(users[i][j], users[i][k] + users[k][j]);
				users[j][i] = users[i][j];
			}
		}
	}
	
	std::vector<int> kebinBaconList;
	for (int i = 1; i <= N; i++)
	{
		int kebinBacon = 0;
		for (int j = 1; j <= N; j++)
		{
			if (i != j)
			{
				kebinBacon += users[i][j];
			}
		}

		kebinBaconList.push_back(kebinBacon);
	}

	std::cout << std::min_element(kebinBaconList.begin(), kebinBaconList.end()) - kebinBaconList.begin()  + 1;

	return 0;
}