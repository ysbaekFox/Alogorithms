#include <stdio.h>
#include <vector>

bool isMatched = false;

std::vector<std::vector<int>> family;
bool isVisited[101];

int n, m;
int count = 0;
void dfs(int p1, int p2)
{
	count++;

	isVisited[p1] = true;

	for (int i = 0 ; i < family[p1].size(); i++)
	{
		if (family[p1][i] == p2)
		{
			isMatched = true;
			return;
		}

		if (false == isVisited[family[p1][i]])
		{
			dfs(family[p1][i], p2);
		}

		if (true == isMatched)
		{
			return;
		}
	}

	count--;
}


int main()
{
	int n = 0;
	scanf("%d", &n);
	family.resize(1 + n);

	int p1 = 0, p2 = 0;
	scanf("%d %d", &p1, &p2);

	int m = 0;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int p = 0, c = 0;
		scanf("%d %d", &p, &c);

		family[p].push_back(c);
		family[c].push_back(p);
	}

	dfs(p1, p2);

	isMatched ? printf("%d", count) : printf("-1");

	return 0;
}