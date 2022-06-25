#include <iostream>
#include <vector>
#include <string.h>

long long sum[1000001];

int main()
{
	int N;
	scanf("%d", &N);

	std::vector<int> input;
	for (int i = 0; i < N; i++)
	{
		int temp;
		scanf("%d", &temp);
		input.push_back(temp);
	}

	memset(sum, 0, sizeof(sum));

	sum[1] = 1;
	sum[2] = 2;
	sum[3] = 4;

	for (int i = 4; i < 1000001 ; i++)
	{
		sum[i] = (sum[i - 3] + sum[i - 2] + sum[i - 1]) % 1000000009;
	}

	for (int result : input)
	{
		std::cout << sum[result] << std::endl;
	}

	return 0;
}