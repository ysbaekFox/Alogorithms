#include <vector>
#include <iostream>
#include <tuple>
#include <queue>
#include <string.h>

bool visited[50][50];
char forest[50][50];

int Y, X;

std::pair<int, int> D_Position;
std::pair<int, int> S_Position;
std::vector<std::pair<int, int>> water;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

int timer = 0;
bool isSuccess = false;

void MoveWater()
{
	bool waterVisited[50][50];
	memset(waterVisited, false, sizeof(waterVisited));

	std::vector<std::pair<int, int>> nextWater;
	
	for (auto pos : water)
	{
		waterVisited[pos.first][pos.second] = true;

		for (int i = 0; i < 4 ; i++)
		{
			int nextY = pos.first + dy[i];
			int nextX = pos.second + dx[i];

			if ( 0 <= nextY && 
				 0 <= nextX &&
				 nextY < Y && 
				nextX < X &&
				'*' != forest[nextY][nextX] &&
				 'X' != forest[nextY][nextX] &&
				 'D' != forest[nextY][nextX] &&
				 false == waterVisited[nextY][nextX])
			{
				forest[nextY][nextX] = '*';
				waterVisited[nextY][nextX] = true;
				nextWater.push_back(std::make_pair(nextY, nextX));
			}
		}
	}

	water.clear();
	water = nextWater;
	timer++;
}

int BFS()
{

	std::queue<std::tuple<int, int, int>> queue;
	queue.push({ S_Position.first, S_Position.second, 1 });

	visited[S_Position.first][S_Position.second] = true;

	while (!queue.empty())
	{
		auto curr = queue.front();
		queue.pop();

		if (timer < std::get<2>(curr) )
		{
			MoveWater();
		}

		for (int i = 0; i < 4 ; i++)
		{
			int nextY = std::get<0>(curr) + dy[i];
			int nextX = std::get<1>(curr) + dx[i];
			int count = std::get<2>(curr);

			if (0 <= nextY && nextY < Y && 0 <= nextX && nextX < X && 'X' != forest[nextY][nextX] && '*' != forest[nextY][nextX] && false == visited[nextY][nextX])
			{
				if ('D' == forest[nextY][nextX])
				{
					isSuccess = true;
					return count;
				}

				queue.push({ nextY, nextX, count + 1 });
				visited[nextY][nextX] = true;
			}
		}
	}

	return 0;
}

int main()
{
	scanf("%d %d\n", &Y, &X);

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X + 1 ; x++)
		{
			char temp;
			scanf("%c", &temp);

			switch (temp)
			{
			case 'D':
				D_Position = std::make_pair(y, x);
				forest[y][x] = 'D';
				break;
			case 'S':
				S_Position = std::make_pair(y, x);
				forest[y][x] = 'S';
				break;
			case 'X':
				forest[y][x] = 'X';
				break;
			case '*':
				forest[y][x] = '*';
				water.push_back(std::make_pair(y, x));
				break;
			case '.':
				forest[y][x] = '.';
				break;
			default:
				break;
			}

			if ('\n' == temp)
			{
				continue;
			}
		}
	}

	int count = BFS();

	if ( true == isSuccess)
	{
		std::cout << count;
	}
	else
	{
		std::cout << "KAKTUS";
	}

	return 0;
}