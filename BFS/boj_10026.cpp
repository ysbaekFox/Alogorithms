#include <stdio.h>
#include <queue>
#include <cstring>

int N;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

char area[100][100];
bool visited[100][100];

void normal(int y, int x)
{
	char color = area[y][x];
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

			if ( (0 <= nx) &&
				 (0 <= ny) &&
				 (nx < N) &&
				 (ny < N) &&
				 (color == area[ny][nx]) &&
				 (false == visited[ny][nx]) )
			{
				visited[ny][nx] = true;
				queue.push(std::make_pair(ny, nx));
			}
		}
	}
}

void abnormal(int y, int x)
{
	char color = area[y][x];
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
				(nx < N) &&
				(ny < N) &&
				(false == visited[ny][nx]))
			{
				if ('G' == color || 'R' == color)
				{
					if ( ( 'G' == area[ny][nx] ) || ( 'R' == area[ny][nx] ) )
					{
						visited[ny][nx] = true;
						queue.push(std::make_pair(ny, nx));
					}
				}
				else
				{
					if (area[ny][nx] == color)
					{
						visited[ny][nx] = true;
						queue.push(std::make_pair(ny, nx));
					}
				}
			}
		}
	}
}


int main()
{
	scanf("%d ", &N);

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N + 1; x++)
		{
			char temp;
			scanf("%c", &temp);

			if ('\n' == temp)
			{
				break;
			}

			area[y][x] = temp;
		}
	}

	int normalCnt = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (false == visited[y][x])
			{
				normal(y, x);
				normalCnt++;
			}
		}
	}

	memset(visited, false, sizeof(visited));

	int abnormalCnt = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (false == visited[y][x])
			{
				abnormal(y, x);
				abnormalCnt++;
			}
		}
	}

	printf("%d %d", normalCnt, abnormalCnt);

	return 0;
}