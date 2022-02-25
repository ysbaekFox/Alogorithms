#include <stdio.h>
#include <queue>
#include <cstring>
#include <algorithm>

int N;

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int visited[25][25];
char houseMap[25][25];

int BFS(int y, int x)
{
	int houseCount = 0;

	std::queue<std::pair<int, int>> queue;
	queue.push(std::make_pair(y, x));

	visited[y][x] = true;
	houseCount++;

	while (!queue.empty())
	{
		std::pair<int,int> curr = queue.front();
		queue.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = curr.first + dy[i];
			int nx = curr.second + dx[i];

			if( ( 0 <= nx ) &&
				( 0 <= ny ) &&
				( nx < N  ) &&
				( ny < N  ) &&
				( false == visited[ny][nx] )&&
				( '1' == houseMap[ny][nx] ) )
			{
				visited[ny][nx] = true;
				queue.push(std::make_pair(ny, nx));
				houseCount++;
			}
		}
	}

	return houseCount;
}

int main()
{
	scanf("%d ", &N);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N + 1; j++)
		{
			char temp;
			scanf("%c", &temp);

			if ('\n' == temp)
			{
				break;
			}

			houseMap[i][j] = temp;
		}
	}
	
	std::vector<int> result;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if ( ( false == visited[i][j] ) && ( '1' == houseMap[i][j] ) ) 
			{
				result.push_back(BFS(i, j));
			}
		}
	}

	std::sort(result.begin(), result.end());

	printf("%d\n", result.size());
	for (auto ret : result)
	{
		printf("%d\n", ret);
	}

	return 0;
}