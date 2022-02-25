#include <stdio.h>
#include <queue>
#include <algorithm>
#include <tuple>
#include <cstring>

int X, Y, Z;
int box[100][100][100];
bool visited[100][100][100];

int dx[6] = { 0, 0, 0, 0, -1, 1 };
int dy[6] = { -1, 1, 0 ,0, 0, 0 };
int dz[6] = { 0, 0, -1, 1, 0, 0 };

bool IsAllRipe(void)
{
	bool isAllRipe = true;
	for (int z = 0; z < Z; z++)
	{
		for (int y = 0; y < Y; y++)
		{
			for (int x = 0; x < X; x++)
			{
				if (0 == box[z][y][x])
				{
					isAllRipe = false;
					break;
				}
			}

			if (false == isAllRipe)
			{
				break;
			}
		}

		if (false == isAllRipe)
		{
			break;
		}
	}

	return isAllRipe;
}

int BFS(std::vector<std::tuple<int,int,int>>& tomatoes)
{
	if (tomatoes.empty())
	{
		return -1;
	}

	int day = 0;

	std::queue<std::tuple<int, int, int>> queue;

	for (auto tomato : tomatoes)
	{
		int z = std::get<0>(tomato);
		int y = std::get<1>(tomato);
		int x = std::get<2>(tomato);

		queue.push(std::make_tuple(z, y, x));
		visited[z][y][x] = true;
	}

	while (!queue.empty())
	{
		const int qSize = queue.size();

		for (int qIdx = 0 ; qIdx < qSize; qIdx++)
		{
			auto curr = queue.front();
			queue.pop();

			for (int i = 0; i < 6; i++)
			{
				int nz = std::get<0>(curr) + dz[i];
				int ny = std::get<1>(curr) + dy[i];
				int nx = std::get<2>(curr) + dx[i];

				if ((0 <= nz) && (0 <= ny) && (0 <= nx) &&
					(nz < Z) && (ny < Y) && (nx < X) &&
					(false == visited[nz][ny][nx]) && (0 == box[nz][ny][nx]))
				{
					queue.push(std::make_tuple(nz, ny, nx));
					box[nz][ny][nx] = 1;
					visited[nz][ny][nx] = true;
				}
			}
		}

		if (0 == queue.size())
		{
			if (true == IsAllRipe())
			{
				return day;
			}
			else
			{
				return -1;
			}
		}

		day++;
	}

	return day;
}

int main()
{
	scanf("%d %d %d", &X, &Y, &Z);

	std::vector<std::tuple<int, int, int>> ripedTamatos;

	for (int z = 0; z < Z; z++)
	{
		for (int y = 0; y < Y; y++)
		{
			for (int x = 0; x < X; x++)
			{
				scanf("%d", &box[z][y][x]);

				if (1 == box[z][y][x])
				{
					ripedTamatos.push_back(std::make_tuple(z, y, x));
				}
			}
		}
	}

	if (true == IsAllRipe())
	{
		printf("%d", 0);
	}
	else
	{
		printf("%d", BFS(ripedTamatos));
	}
	
	return 0;
}