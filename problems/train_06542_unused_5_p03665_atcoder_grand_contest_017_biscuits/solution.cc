#include <cstdio>

#define R register
int main()
{
	R int n, p; scanf("%d%d", &n, &p);
	R int a0 = 0, a1 = 0;
	for (R int i = 1; i <= n; ++i)
	{
		R int a;
		scanf("%d", &a);
		a0 += a % 2 == 0;
		a1 += a % 2 == 1;
	}
	printf("%lld\n", a1 == 0 && p == 1 ? 0 : a1 == 0 && p == 0 ? 1ll << n : 1ll << (n - 1));
	return 0;
}