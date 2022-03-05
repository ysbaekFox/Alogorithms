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

#define INF 2000000000;

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
	arrayInit();

	while (true)
	{
		int minDist = INF;
		std::pair<int, int> target{-1,-1};
		for (std::pair<int, int> fish : fishPosList)
		{
			if (sharkSize > sea[fish.first][fish.second])
			{
				int currDist = ( abs(fish.first - sharkPos.first)
							     + abs(fish.second - sharkPos.second) );

				if (minDist > currDist)
				{
					target = fish;
					minDist = currDist;
				}
			}
		}

		if (target.first == -1)
		{
			break;
		}

		fishPosList.erase(std::find(fishPosList.begin(), fishPosList.end(), target));

		std::queue<std::pair<int, int>> queue;
		queue.push({ sharkPos.first, sharkPos.second });
		visited[sharkPos.first][sharkPos.second] = true;
		dist[sharkPos.first][sharkPos.second] = 0;

		while (!queue.empty())
		{
			std::pair<int, int> curr = queue.front();
			queue.pop();

			if ( ( target.first == curr.first ) &&
				 ( target.second == curr.second) )
			{
				sea[sharkPos.first][sharkPos.second] = 0;
				sharkPos.first = target.first;
				sharkPos.second = target.second;
				totalTime += dist[target.first][target.second];
				arrayInit();
				triedFish++;
				if (triedFish == sharkSize)
				{
					triedFish = 0;
					sharkSize++;
				}
				sea[sharkPos.first][sharkPos.second] = 9;
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				int ny = curr.first + dy[i];
				int nx = curr.second + dx[i];

				if ((0 <= nx) &&
					(0 <= ny) &&
					(nx < N) &&
					(ny < N) &&
					(false == visited[ny][nx]) &&
					(sharkSize >= sea[ny][nx]))
				{
					visited[ny][nx] = true;
					queue.push(std::make_pair(ny, nx));
					dist[ny][nx] = std::min(dist[ny][nx], dist[curr.first][curr.second] + 1);
				}
			}
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