#include <iostream>
#include <queue>

int N;
int miro[1001];
int visited[1001];

#define INF 210000000

int BFS(int start)
{
	if (start == N)
	{
		return 0;
	}

	int cnt = INF;

	std::queue<std::pair<int, int>> queue;
	queue.push(std::make_pair(start, 0));

	visited[start] = true;

	while (!queue.empty())
	{
		std::pair<int, int> curr = queue.front();
		queue.pop();

		int maxJump = miro[curr.first];
		
		int currPos = curr.first;
		int currCnt = curr.second;

		for (int i = 1; i <= maxJump; i++)
		{
			const int nextPos = currPos + i;

			if ( N == nextPos)
			{
				cnt = std::min(cnt, currCnt + 1);
				continue;
			}

			if ( 0 <= nextPos && nextPos < N && false == visited[nextPos] )
			{
				queue.push(std::make_pair(nextPos, currCnt + 1));
				visited[nextPos] = true;
			}
		}
	}
	
	return cnt;
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &miro[i]);
	}

	const int result = BFS(1);

	if (INF != result)
	{
		std::cout << result;
	}
	else
	{
		std::cout << -1;
	}

	return 0;
}