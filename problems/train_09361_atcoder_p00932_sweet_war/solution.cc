#include <cstdio>
#include <algorithm>
#define N_MAX 150
#define S_MAX 150
#define lld "%lld"
typedef long long lnt;
const lnt LNF = 0x3F3F3F3F3F3F3FLL;
int n, o, i, k, a, b, r[N_MAX], s[N_MAX + 1];
lnt f[2][S_MAX + 2];
int main()
{
	scanf("%d %d %d", &n, &a, &b);
	for (i = 0; i < n; ++i)
		scanf("%d %d", &r[i], &s[i]);
	for (i = n - 1; i >= 0; --i)
		s[i] += s[i + 1];
	f[o][0] = -LNF;
	for (i = n - 1; i >= 0; --i)
	{
		for (k = s[i + 1] + 1; k <= s[i] + 1; ++k)
			f[o][k] = LNF;
		o ^= 1;
		for (k = 0; k <= s[i]; ++k)
			f[o][k] = std::min(1 - f[o ^ 1][s[i] - k + 1] - r[i], std::max(1LL, f[o ^ 1][k] + r[i] + 1));
	}
	for (k = s[0]; f[o][k] > a - b; --k);
	printf("%d %d\n", k, s[0] - k);
	return 0;
}