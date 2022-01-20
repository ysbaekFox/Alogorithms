#include <stdio.h>
#include <vector>

int main()
{
	int n = 0;
	scanf("%d", &n);

	std::vector<std::vector<int>> family;
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
	}

	return 0;
}