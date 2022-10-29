#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

constexpr int Y = 5, X = 5;
char classRoom[Y][X];

#define MAX 25
bool checked[MAX];
int totalCnt = 0;

int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { -1, 1, 0, 0 };

bool BFS()
{
	int visitedCnt = 0;
	bool visited[MAX];
	std::fill(visited, visited + MAX, false);

	auto FindFirst = []() -> int
	{
		for (int i = 0; i < MAX; i++)
		{
			if (true == checked[i])
			{
				return i;
			}
		}
	};

	const int firstIdx = FindFirst();

	std::queue<int> queue;
	queue.push(firstIdx);

	visited[firstIdx] = true;
	visitedCnt++;

	while ( !queue.empty() )
	{
		int curr = queue.front();
		queue.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = (curr / 5) + dy[i];
			int nextX = (curr % 5) + dx[i];
			int nextIdx = (nextY * 5) + nextX;

			if ( ( 0 <= nextY ) && ( 0 <= nextX ) &&
				 ( 5 > nextY  ) && ( 5 > nextX  ) &&
				 ( false == visited[nextIdx] ) &&
				 ( true  == checked[nextIdx]  ) )
			{
				queue.push(nextIdx);
				visited[nextIdx] = true;
				visitedCnt++;
			}
		}
	}

	if ( 7 == visitedCnt )
	{
		return true;
	}

	return false;
}

void DFS(int idx, int cnt)
{
	auto isMoreThanFour = []() -> bool 
	{
		int somGirlsCnt = 0;
		for (int i = 0; i < MAX; i++)
		{
			if ( true == checked[i] )
			{
				if ('S' == classRoom[i / 5][i % 5])
				{
					somGirlsCnt++;
				}

				if ( 4 <= somGirlsCnt )
				{
					return true;
				}
			}
		}

		return false;
	};

	if (cnt == 7)
	{
		if ( true == isMoreThanFour() )
		{
			if ( true == BFS() )
			{
				totalCnt++;
			}
		}

		return;
	}

	for (int i = idx; i < MAX; i++)
	{
		if (checked[i] == true)
			continue;

		checked[i] = true;
		DFS(i, cnt + 1);
		checked[i] = false;
	}
}

int main()
{
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X + 1; x++)
		{
			char temp = '\0';
			scanf("%c", &temp);
			
			if ('\n' == temp)
			{
				break;
			}
			
			classRoom[y][x] = temp;
		}
	}

	DFS(0, 0);

	std::cout << totalCnt << std::endl;

	return 0;
}