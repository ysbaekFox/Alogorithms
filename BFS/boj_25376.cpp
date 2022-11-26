#include <vector>
#include <math.h>
#include <queue>
#include <iostream>

int N, startState;
bool visited[1 << 20]; 
int switches[20];

int BFS(int startState)
{
	int result = -1;

	std::queue<std::pair<int, int>> queue;
	queue.push(std::make_pair(startState, 0));

	visited[startState] = true;

	while (!queue.empty())
	{
		const auto curr = queue.front();
		queue.pop();

		const int currState = curr.first;
		const int currCnt = curr.second;

		if ( ( (1 << N) - 1 ) == currState )
		{
			result = currCnt;
			break;
		}

		for (int i = 0; i < N; i++)
		{
			if ( 0 == (currState & (1 << i) ) )
			{
				int nextState = currState ^ switches[i];

				if (false == visited[nextState])
				{
					visited[nextState] = true;
					queue.push(std::make_pair(nextState, currCnt + 1));
				}
			}
		}
	}

	return result;
}

int main()
{
	std::cin >> N;

	for (int i = 0; i < N ; i++)
	{
		int temp;
		std::cin >> temp;

		if (1 == temp)
		{
			startState |= (1 << i);
		}
	}

	for (int i = 0; i < N; i++)
	{
		int n;
		std::cin >> n;

		switches[i] |= (1 << i);
		for (int j = 0; j < n; j++)
		{
			int temp;
			std::cin >> temp;

			switches[i] |= (1 << (temp - 1));
		}
	}
	
	std::cout << BFS(startState);

	return 0;
}