#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 2000000000

//std::vector<std::vector<int>> maze;
char maze[100][100];
int visited[100][100];

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

int main()
{
	int N, M;
	scanf("%d %d ", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M + 1; j++)
		{
			char temp;
			scanf("%c", &temp);

			if ('\n' == temp)
			{
				break;
			}

			maze[i][j] = temp;
			visited[i][j] = INF;
		}
	}

	std::queue<std::pair<int, int>> queue;
	queue.push(std::make_pair(0, 0));

	visited[0][0] = 1;

	while (!queue.empty())
	{
		std::pair<int, int> curr = queue.front();
		queue.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = curr.first + dx[i];
			int ny = curr.second + dy[i];

			if ( ( -1 < nx ) && 
				 ( -1 < ny ) &&
				 ( nx < N  ) &&
				 ( ny < M  ) )
			{
				if ( ( '1' == maze[nx][ny]    ) && 
					 ( INF == visited[nx][ny] ) )
				{
					queue.push(std::make_pair(nx, ny));
				}

				visited[nx][ny] = std::min(visited[nx][ny], visited[curr.first][curr.second] + 1);
			}
		}
	}

	printf("%d", visited[N - 1][M - 1]);

	return 0;
}