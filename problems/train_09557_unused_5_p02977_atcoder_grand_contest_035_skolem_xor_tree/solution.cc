#include <cstdio>
using namespace std;

namespace zyt
{
	int work()
	{
		int n, id = 0;
		scanf("%d", &n);
		while ((1 << id) <= n)
		{
			if (n == (1 << id))
			{
				puts("No");
				return 0;
			}
			++id;
		}
		--id;
		puts("Yes");
		printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n", n + 1, n + 1, n + 2, n + 2, n + 3);
		for (int i = 4; i + 1 <= n; i += 2)
		{
			printf("%d %d\n", i, n + 1);
			printf("%d %d\n", i + 1, i);
			printf("%d %d\n", n + 1, i + n + 1);
			printf("%d %d\n", i + n + 1, n + i);
		}
		if (!(n & 1))
		{
			printf("%d %d\n", n, 1 << id);
			printf("%d %d\n", n << 1, n - (1 << id) + 1 == 3 ? 3 : n * 2 - (1 << id) + 1);
		}
		return 0;
	}
}
int main()
{
	return zyt::work();
}