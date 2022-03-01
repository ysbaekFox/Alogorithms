#include <stdio.h>
#include <cstring>
#include <queue>

int dy[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int dx[8] = { -2, -2, -1, -1, 1, 1, 2 ,2 };

int testCase;
int N;

bool visited[300][300];


int BFS(int startY, int startX, int endY, int endX)
{
	if ( ( startX == endX ) && 
		 ( startY == endY ) )
	{
		return 0;
	}

	int count = 0;
	std::queue<std::pair<int, int>> queue;
	queue.push(std::make_pair(startY, startX));

	visited[startY][startX] = true;

	bool isFound = false;
	while (!queue.empty())
	{
		int qSize = queue.size();
		for (int qIdx = 0; qIdx < qSize; qIdx++)
		{
			auto curr = queue.front();
			queue.pop();

			for (int i = 0; i < 8; i++)
			{
				int ny = curr.first + dy[i];
				int nx = curr.second + dx[i];

				if ((ny == endY) &&
					(nx == endX))
				{
					isFound = true;
					break;
				}

				if ((0 <= nx) &&
					(0 <= ny) &&
					(nx < N) &&
					(ny < N) &&
					(false == visited[ny][nx]))
				{
					visited[ny][nx] = true;
					queue.push(std::make_pair(ny, nx));
				}
			}

			if (true == isFound)
			{
				break;
			}
		}

		count++;

		if (true == isFound)
		{
			break;
		}
	}

	return count;
}

int main()
{
	scanf("%d", &testCase);

	for (int tIdx = 0; tIdx < testCase; tIdx++)
	{
		scanf("%d", &N);

		int startX, startY;
		scanf("%d %d", &startX, &startY);

		int endX, endY;
		scanf("%d %d", &endX, &endY);

		int cnt = BFS(startY, startX, endY, endX);
		printf("%d\n", cnt);

		memset(visited, 0, sizeof(visited));
	}

	return 0;
}