#include <stdio.h>
#include <algorithm>
#include <queue>
#include <algorithm>
#include <cstring>

int X, Y, Cnt;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool visited[50][50];
int board[50][50];

void BFS(int y, int x)
{
	std::queue<std::pair<int, int>> queue;
	queue.push(std::make_pair(y, x));

	visited[y][x] = true;

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
				(1 == board[ny][nx]))
			{
				visited[ny][nx] = true;
				queue.push(std::make_pair(ny, nx));
			}
		}
	}
}

int main()
{
	int testCase;
	scanf("%d", &testCase);

	for (int test = 0; test < testCase; test++)
	{
		scanf("%d %d %d", &X, &Y, &Cnt);

		for (int i = 0; i < Cnt; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			board[y][x] = 1;
		}

		int larva = 0;
		for (int y = 0; y < Y; y++)
		{
			for (int x = 0; x < X; x++)
			{
				if ( (false == visited[y][x]) &&
					 (1 == board[y][x]) )
				{
					BFS(y, x);
					larva++;
				}
			}
		}

		memset(board, 0, sizeof(board));
		memset(visited, false, sizeof(visited));
		printf("%d\n", larva);
	}

	return 0;
}