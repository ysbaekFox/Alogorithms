#include <iostream>
#include <queue>
#include <algorithm>

int map[21][21];
int Y, X, K;

int d = 0; // 초기값 오른쪽 방향
int totalScore = 0;

std::pair<int, int> currPos = { 1, 1 };

bool visited[21][21];

int dice[4][3] = 
{
	{ 0, 2, 0 },
	{ 4, 1, 3 },
	{ 0, 5, 0 },
	{ 0, 6, 0 }
};

char direction[4] = { 'R', 'D', 'L', 'U' }; // +1 시계, +2 반대방향, +3 반시계
											// % 4
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};


void moveDice(char direction)
{
	if ('R' == direction)
	{
		int temp = dice[3][1];
		dice[3][1] = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = temp;

		currPos.first  += dy[0];
		currPos.second += dx[0];
	}
	else if ('L' == direction)
	{
		int temp = dice[3][1];
		dice[3][1] = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = temp;

		currPos.first  += dy[2];
		currPos.second += dx[2];
	}
	else if ('U' == direction)
	{
		int temp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = temp;

		currPos.first  += dy[3];
		currPos.second += dx[3];
	}
	else if ('D' == direction)
	{
		int temp = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = dice[0][1];
		dice[0][1] = temp;

		currPos.first  += dy[1];
		currPos.second += dx[1];
	}
}

int rotateDice(int A /* bottomNum */, int B /* mapNum */, int currDirection)
{
	if (A > B)
	{
		return (currDirection + 1) % 4;
	}
	else if (A < B)
	{
		return (currDirection + 3) % 4;
	}

	return currDirection;
}

int getDiceBottom()
{
	return dice[3][1];
}

bool checkOutOfRange(char direction)
{
	int dIndx = 0;
	switch (direction)
	{
	case 'R':
		dIndx = 0;
		break;
	case 'D':
		dIndx = 1;
		break;
	case 'L':
		dIndx = 2;
		break;
	case 'U':
		dIndx = 3;
		break;
	}

	if ( ( 1 <= currPos.first + dy[dIndx] ) &&
		 ( currPos.first + dy[dIndx] <= Y ) &&
		 ( 1 <= currPos.second + dx[dIndx]) &&
		 ( currPos.second + dx[dIndx] <= X) )
	{
		return false;
	}

	return true;
}

int BFS(int y, int x, int startBottomScore)
{
	int score = 0;
	std::fill(&visited[0][0], &visited[21][21], false);

	std::queue<std::pair<int, int>> queue;
	queue.push(std::make_pair(y, x));
	visited[y][x] = true;

	while (!queue.empty())
	{
		std::pair<int,int> curr = queue.front();
		queue.pop();

		score += startBottomScore;

		for (int i = 0; i < 4; i++)
		{
			int nextY = curr.first + dy[i];
			int nextX = curr.second + dx[i];

			if ( ( 1 <= nextY ) &&
				 ( 1 <= nextX ) &&
				 ( nextY <= Y ) &&
				 ( nextX <= X ) &&
				 ( false == visited[nextY][nextX] ) &&
				 ( startBottomScore == map[nextY][nextX]) )
			{
				queue.push(std::make_pair(nextY, nextX));
				visited[nextY][nextX] = true;
			}
		}
	}

	return score;
}

int main()
{
	scanf("%d %d %d", &Y, &X, &K);

	for (int y = 1; y <= Y; y++)
	{
		for (int x = 1; x <= X; x++)
		{
			scanf("%d", &map[y][x]);
		}
	}

	for (int cnt = 0; cnt < K; cnt++)
	{
		if ( true == checkOutOfRange(direction[d]) )
		{
			// 만약, 이동 방향에 칸이 없다면, 이동 방향을 반대로 한 다음 한 칸 굴러간다.
			d = (d + 2) % 4;
		}

		moveDice(direction[d]);

		// BFS로 점수 계산
		totalScore += BFS(currPos.first, currPos.second, map[currPos.first][currPos.second]);

		// 주사위 방향 회전.
		d = rotateDice(getDiceBottom(), map[currPos.first][currPos.second], d);
	}

	std::cout << totalScore << std::endl;

	return 0;
}