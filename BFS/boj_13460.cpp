#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <tuple>

struct Pos
{
	int y = 0;
	int x = 0;
	int cnt = 0;
};

int X, Y;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

Pos redPos;
Pos bluePos;

char escape[10][10];
bool visited[10][10][10][10];

int BFS()
{
	int count = 2000000000;
	
	std::queue<Pos> queue;
	queue.push({ redPos.y, redPos.x, 0 });
	queue.push({ bluePos.y, bluePos.x, 0 });

	visited[redPos.y][redPos.x][bluePos.y][bluePos.x] = true;

	while (!queue.empty())
	{
		auto r_point = queue.front();
		queue.pop();

		auto b_point = queue.front();
		queue.pop();

		int cnt = r_point.cnt + 1;

		for ( int i = 0; i < 4; i++ )
		{
			int nextRedY = 0;
			int nextRedX = 0;

			int nextBlueY = 0;
			int nextBlueX = 0;

			bool isRedEnterHole = false;
			while (true)
			{
				if ('#' == escape[r_point.y + nextRedY][r_point.x + nextRedX])
				{
					nextRedY -= dy[i];
					nextRedX -= dx[i];
					break;
				}

				if ('O' == escape[r_point.y + nextRedY][r_point.x + nextRedX])
				{
					isRedEnterHole = true;
					break;
				}

				nextRedY += dy[i];
				nextRedX += dx[i];
			}

			bool isBlueEnterHole = false;
			while (true)
			{
				if ('#' == escape[b_point.y + nextBlueY][b_point.x + nextBlueX])
				{
					nextBlueY -= dy[i];
					nextBlueX -= dx[i];
					break;
				}

				if ('O' == escape[b_point.y + nextBlueY][b_point.x + nextBlueX])
				{
					isBlueEnterHole = true;
					break;
				}

				nextBlueY += dy[i];
				nextBlueX += dx[i];
			}

			if ((b_point.y + nextBlueY) == (r_point.y + nextRedY) && (b_point.x + nextBlueX) == (r_point.x + nextRedX))
			{
				if (true != isBlueEnterHole)
				{
					if (abs(nextBlueY) + abs(nextBlueX) < abs(nextRedY) + abs(nextRedX))
					{
						nextRedY -= dy[i];
						nextRedX -= dx[i];
					}
					else
					{
						nextBlueY -= dy[i];
						nextBlueX -= dx[i];
					}

					if (false == visited[r_point.y + nextRedY][r_point.x + nextRedX][b_point.y + nextBlueY][b_point.x + nextBlueX])
					{
						queue.push({ r_point.y + nextRedY, r_point.x + nextRedX, cnt});
						queue.push({ b_point.y + nextBlueY, b_point.x + nextBlueX, cnt});
						visited[r_point.y + nextRedY][r_point.x + nextRedX][b_point.y + nextBlueY][b_point.x + nextBlueX] = true;
					}
				}
			}
			else
			{
				if (true == isRedEnterHole)
				{
					count = std::min(cnt, count);
				}
				else
				{
					if (false == visited[r_point.y + nextRedY][r_point.x + nextRedX][b_point.y + nextBlueY][b_point.x + nextBlueX])
					{
						queue.push({ r_point.y + nextRedY, r_point.x + nextRedX, cnt});
						queue.push({ b_point.y + nextBlueY, b_point.x + nextBlueX, cnt});
						visited[r_point.y + nextRedY][r_point.x + nextRedX][b_point.y + nextBlueY][b_point.x + nextBlueX] = true;
					}
				}
			}
		}
	}

	return count;
}

int main()
{
	scanf("%d %d ", &Y, &X);

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x <= X; x++)
		{
			char temp;
			scanf("%c", &temp);

			if ('R' == temp)
			{
				redPos = { y, x, 0 };
				escape[y][x] = '.';
			}
			else if ('B' == temp)
			{
				bluePos = { y, x, 0 };
				escape[y][x] = '.';
			}
			else if ('\n' == temp)
			{
				break;
			}
			else
			{
				escape[y][x] = temp;
			}
		}
	}

	int count = BFS();

	if (10 < count)
	{
		count = -1;
	}

	printf("%d", count);

	return 0;
}