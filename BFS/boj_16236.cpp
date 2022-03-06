#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

int N = 0;
int sea[20][20];
int visited[20][20];
int dist[20][20];

int dx[4] = { 0 , 0 , -1, 1 };
int dy[4] = { -1 , 1 , 0, 0 };

int sharkSize = 2;
int triedFish = 0;

std::pair<int, int> sharkPos;
std::vector<std::pair<int, int>> fishPosList;

#define INF 200000000

int totalTime = 0;

void arrayInit()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			visited[y][x] = false;
			dist[y][x] = INF;
		}
	}
}

void BFS()
{
	while (true)
	{
		arrayInit();

		std::queue<std::pair<int, int>> queue;
		queue.push(std::make_pair(sharkPos.first, sharkPos.second));

		dist[sharkPos.first][sharkPos.second] = 0;
		visited[sharkPos.first][sharkPos.second] = true;

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
					(sharkSize >= sea[ny][nx]))
				{
					if (false == visited[ny][nx])
					{
						visited[ny][nx] = true;
						queue.push(std::make_pair(ny, nx));
						dist[ny][nx] = std::min(dist[ny][nx], dist[curr.first][curr.second] + 1);
					}
				}
			}
		}

		int minDist = INF;
		std::pair<int, int> target{ -1,-1 };
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if ( ( minDist > dist[y][x] ) &&
					 ( 0 < sea[y][x] ) &&
					 ( sharkSize > sea[y][x] ) 
					)
				{
					minDist = dist[y][x];
					target = std::make_pair(y, x);
				}
			}
		}

		if ( ( target.first == -1 ) &&
			 ( target.second == -1 ) )
		{
			break;
		}

		fishPosList.erase(std::find(fishPosList.begin(), fishPosList.end(), target));

		sea[target.first][target.second] = 9;
		sea[sharkPos.first][sharkPos.second] = 0;
		totalTime += dist[target.first][target.second];
		sharkPos = target;
		triedFish++;
		if (triedFish == sharkSize)
		{
			triedFish = 0;
			sharkSize++;
		}
	}
}

int main()
{
	scanf("%d", &N);

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			scanf("%d", &sea[y][x]);

			if (9 == sea[y][x])
			{
				sharkPos = std::make_pair(y, x);
			}
			else if (0 != sea[y][x])
			{
				fishPosList.push_back(std::make_pair(y, x));
			}
		}
	}

	BFS();
	printf("%d", totalTime);

	return 0;
}