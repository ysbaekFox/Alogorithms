#include <stdio.h>
#include <queue>
#include <cstring>
#include <algorithm>

int lab[8][8];
int templab[8][8];
bool visited[8][8];

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int X, Y;

int GetSafeAreaSize(int y, int x)
{
	bool isSpread = false;
	int safeAreaSize = 0;

	std::queue<std::pair<int, int>> queue;
	queue.push(std::make_pair(y, x));

	visited[y][x] = true;
	safeAreaSize++;

	while (!queue.empty())
	{
		std::pair<int, int> curr = queue.front();
		queue.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = curr.first + dy[i];
			int nx = curr.second + dx[i];

			if ((0 <= nx) &&
				(0 <= ny) &&
				(nx < X) &&
				(ny < Y) &&
				(false == visited[ny][nx]) &&
				(1 != lab[ny][nx]))
			{
				if (2 == lab[ny][nx])
				{
					isSpread = true;
				}

				queue.push(std::make_pair(ny, nx));
				visited[ny][nx] = true;
				safeAreaSize++;
			}
		}
	}

	if (true == isSpread)
	{
		safeAreaSize = 0;
	}

	return safeAreaSize;
}

int main()
{
	scanf("%d %d", &Y, &X);

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			scanf("%d", &lab[y][x]);
		}
	}

	int safeArea = 0;
	int nodeSize = (X * Y);
	for (int i = 0; i < nodeSize; i++)
	{
		int firstWall_y = i / X;
		int firstWall_x = i % X;

		if (0 != lab[firstWall_y][firstWall_x]) continue;
		lab[firstWall_y][firstWall_x] = 1;

		for (int j = 0; j < nodeSize; j++)
		{
			int secondWall_y = j / X;
			int secondWall_x = j % X;

			if ((0 != lab[secondWall_y][secondWall_x]) ||
				( (secondWall_x == firstWall_x) &&
				  (secondWall_y == firstWall_y)) ) continue;
			lab[secondWall_y][secondWall_x] = 1;

			for (int k = 0; k < nodeSize; k++)
			{
				int thirdWall_y = k / X;
				int thirdWall_x = k % X;

				if ( (0 != lab[thirdWall_y][thirdWall_x]) ||
				     ( (thirdWall_x == secondWall_x) &&
					   (thirdWall_y == secondWall_y) ) ||
					 ( (thirdWall_y == firstWall_y) &&
					   (thirdWall_x == firstWall_x) ) ) continue;
				lab[thirdWall_y][thirdWall_x] = 1;

				int tempSafeArea = 0;
				for (int y = 0; y < Y; y++)
				{
					for (int x = 0; x < X; x++)
					{
						if ((false == visited[y][x]) && (0 == lab[y][x]))
						{
							tempSafeArea += GetSafeAreaSize(y, x);
						}
					}
				}

				safeArea = std::max(tempSafeArea, safeArea);
				lab[thirdWall_y][thirdWall_x] = 0;
				memset(visited, false, sizeof(visited));
			}

			lab[secondWall_y][secondWall_x] = 0;
		}

		lab[firstWall_y][firstWall_x] = 0;
	}

	printf("%d", safeArea);

	return 0;
}