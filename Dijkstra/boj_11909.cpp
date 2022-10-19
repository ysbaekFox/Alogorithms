#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#pragma warning(disable: 6385)

int N;
#define MAX 2222
int board[MAX][MAX];
int dist[MAX * MAX];
bool visited[MAX * MAX];

using P = std::pair<int, int>;

int Dijkstra(int y, int x)
{
	auto getIndex = [](int _y, int _x) { return (N * _y) + _x; };
	auto getPair = [](int index) { return std::make_pair(index / N, index % N); };

	std::priority_queue<P, std::vector<P>, std::greater<P>> pQueue;
	pQueue.push(std::make_pair(0, getIndex(y, x)));
	dist[getIndex(y, x)] = 0;

	while (!pQueue.empty())
	{
		auto curr = pQueue.top();
		pQueue.pop();

		const int currCost = curr.first;
		const int currIndex = curr.second;
		const int currY = curr.second / N;
		const int currX = curr.second % N;

		if(true == visited[currIndex])
			continue;

		visited[currIndex] = true;

		if ((0 <= currY) &&
			(0 <= currX) &&
			(currX < N - 1) &&
			(currY < N - 1) )
		{
			int nextIndex = getIndex(currY, currX + 1);

			// cost 비교하는거 잘못됨
			// board 비교를 if문으로 빼서 조건 처리 해야 됨.
			int nextCost = board[currY][currX] > board[currY][currX + 1] ? 0 : abs(board[currY][currX + 1] - board[currY][currX]);

			if (dist[nextIndex] > nextCost + currCost)
			{
				pQueue.push(std::make_pair(currCost + nextCost, nextIndex));
				dist[nextIndex] = nextCost + currCost;
			}

			nextIndex = getIndex(currY + 1, currX);
			nextCost = board[currY][currX] > board[currY + 1][currX] ? 0 : abs(board[currY + 1][currX] - board[currY][currX]);

			if (dist[nextIndex] > nextCost + currCost)
			{
				pQueue.push(std::make_pair(currCost + nextCost, nextIndex));
				dist[nextIndex] = nextCost + currCost;
			}
		}
		else if ( ( currY == N - 1) && 
				  ( 0 <= currX ) &&
				  ( currX < N - 1) )
		{
			int nextIndex = getIndex(currY, currX + 1);
			int nextCost = board[currY][currX] > board[currY][currX + 1] ? 0 : abs(board[currY][currX + 1] - board[currY][currX]);

			if (dist[nextIndex] > nextCost + currCost)
			{
				pQueue.push(std::make_pair(currCost + nextCost, nextIndex));
				dist[nextIndex] = nextCost + currCost;
			}
		}
		else if ( (currX == N - 1) &&
				  (0 <= currY) &&
				  (currY < N - 1) )
		{
			int nextIndex = getIndex(currY + 1, currX);
			int nextCost = board[currY][currX] > board[currY + 1][currX] ? 0 : abs(board[currY + 1][currX] - board[currY][currX]);

			if (dist[nextIndex] > nextCost + currCost)
			{
				pQueue.push(std::make_pair(currCost + nextCost, nextIndex));
				dist[nextIndex] = nextCost + currCost;
			}
		}
		else if ( ( currY == N - 1 ) &&
				  ( currX == N - 1 ) )

		{
			continue;
		}
	}

	return dist[N * N - 1];
}


int main()
{
	std::fill(dist, &dist[2222] + 1, 2000000000);

	scanf("%d", &N);

	for ( int y = 0; y < N; y++ )
	{
		for ( int x = 0; x < N; x++ )
		{
			scanf("%d", &board[y][x]);
		}
	}

	std::cout << Dijkstra(0, 0);

	return 0;
}