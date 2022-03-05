#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <tuple>
#include <queue>

bool visited[2][1000][1000];
int dist[2][1000][1000];
char miro[1000][1000];

int dy[4] = { -1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};


#define INF 200000000

int X, Y;

void BFS(int y, int x)
{
	std::queue<std::tuple<int, int, int>> queue;
	queue.push(std::make_tuple(0, y, x));

	visited[0][y][x] = true;
	visited[1][y][x] = true;

	dist[0][y][x] = 0;

	while (!queue.empty())
	{
		std::tuple<int, int, int> curr = queue.front();
		queue.pop();

		for (int i = 0; i < 4; i++)
		{
			int cz = std::get<0>(curr);
			int cy = std::get<1>(curr);
			int cx = std::get<2>(curr);

			int nz = cz;
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			
			if ( ( 0 <= nx ) &&
				 ( 0 <= ny ) &&
				 ( ny < Y  ) &&
				 ( nx < X  ) )
			{
				if ( ( '1' == miro[ny][nx] ) &&
					 ( 0 == nz ) )
				{
					visited[1][ny][nx] = true;
					queue.push(std::make_tuple(1, ny, nx));
					dist[1][ny][nx] = std::min(dist[1][ny][nx], dist[cz][cy][cx] + 1);
				}
				else if ( ( '0' == miro[ny][nx] ) &&
						  (false == visited[nz][ny][nx]) )
				{
					visited[nz][ny][nx] = true;
					queue.push(std::make_tuple(nz, ny, nx));
					dist[nz][ny][nx] = std::min(dist[nz][ny][nx], dist[cz][cy][cx] + 1);
				}
			}
		}
	}
}

int main()
{
	//char* fname = "input.txt";
	//FILE* fp = fopen(fname, "r");

	scanf("%d %d ", &Y, &X);
	//fscanf(fp, "%d %d ", &Y, &X);

	for (int z = 0; z < 2; z++)
	{
		for (int y = 0; y < Y; y++)
		{
			for (int x = 0; x < X; x++)
			{
				dist[z][y][x] = INF;
			}
		}
	}

	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X + 1; x++)
		{
			char temp;
			scanf("%c", &temp);
			//fscanf(fp, "%c", &temp);
			if ('\n' == temp)
			{
				break;
			}
			miro[y][x] = temp;
		}
	}

	BFS(0, 0);

	int result = std::min(dist[0][Y - 1][X - 1], dist[1][Y - 1][X - 1]);

	if (INF == result)
	{
		printf("%d", -1);
	}
	else
	{
		printf("%d", result + 1);
	}

	return 0;
}