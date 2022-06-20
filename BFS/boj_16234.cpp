#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
#include <math.h>
#include <functional>
#include <algorithm>

int N, L, R;
int A[50][50];
int visited[2500];

int dx[4] = { 0 , 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int BFS()
{
	int count = 0;

	while (true)
	{
		std::vector<std::vector<int>> country;
		country.resize(N * N);
		
		memset(visited, false, sizeof(visited));

		for (int y = 0; y < N ; y++)
		{
			for (int x = 0; x < N; x++)
			{
				const int curr = ( N * y ) + x;
				
				visited[curr] = true;

				for (int i = 0; i < 4; i++)
				{
					const int nextY = y + dy[i];
					const int nextX = x + dx[i];
					const int next = (N * nextY) + nextX;
				
					if( nextX < 0 || nextY < 0 || N <= nextX || N <= nextY || true == visited[next]  )
						continue;

					const int diffNum = abs(A[y][x] - A[nextY][nextX]);

					if ( L <= diffNum && diffNum <= R )
					{
						country[curr].push_back(next);
						country[next].push_back(curr);
					}
				}
			}
		}
		
		if (country.end() == std::find_if(country.begin(), country.end(),
			[](auto& value) { return 0 < value.size(); }) )
		{
			break;
		}

		memset(visited, false, sizeof(visited));

		for ( int cIdx = 0; cIdx < N * N; cIdx++ )
		{
			int peopleSum = 0;
			std::vector<int> list;
			
			if (true == visited[cIdx])
				continue;

			std::queue<int> queue;
			queue.push(cIdx);

			visited[cIdx] = true;
			peopleSum += A[cIdx / N][cIdx % N];
			list.push_back(cIdx);

			while (!queue.empty())
			{
				int curr = queue.front();
				queue.pop();

				const int currSize = country[curr].size();

				for (int currIdx = 0; currIdx < currSize; currIdx++)
				{
					const int next = country[curr][currIdx];
					if ( true == visited[next] )
						continue;

					peopleSum += A[next / N][next % N];
					visited[next] = true;
					list.push_back(next);
					queue.push(next);
				}
			}

			int average = peopleSum / list.size();
			for (int pos : list)
			{
				A[pos / N][pos % N] = average;
			}
		}

		count++;
	}

	return count;
}

int main()
{
	scanf("%d %d %d", &N, &L, &R);

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int num;
			scanf("%d", &A[y][x]);
		}
	}

	std::cout << BFS();

	return 0;
}