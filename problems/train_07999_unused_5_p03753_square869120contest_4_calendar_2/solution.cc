#include <cstdio>

#define maxn 2000010
int a[maxn];
bool col[maxn][7], vis[maxn][7];
typedef long long ll;
struct que {
	int x, y;
} qu[maxn];
const int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
int up[maxn], dw[maxn], Fa[maxn], fcol[maxn][7];
int Find(int x) {return Fa[x] == x ? x : Fa[x] = Find(Fa[x]);}
int main()
{
	ll n;
	int m, q; scanf("%lld%d%d", &n, &m, &q);
	for (int i = 1; i <= q; ++i) scanf("%d", &a[i]);
	if (m % 7)
	{
		int nq = q;
		for (int i = 1; i <= q; ++i)
			for (int j = 1; j < 7; ++j)
				a[++nq] = a[i] + j * m;
		m *= 7; q = nq;
	}
	int mm = m / 7, cnt = 0;

	for (int i = 1; i <= q; ++i)
	{
		col[a[i] / 7][a[i] % 7] = 1;
//		printf("%d %d\n", a[i] / 7, a[i] % 7);
	}

	for (int i = 0; i < mm; ++i)
		for (int j = 0; j < 7; ++j)
			if (!vis[i][j] && !col[i][j])
			{
				fcol[i][j] = ++cnt;
				int head = 0, tail = 1; qu[1] = (que) {i, j}; vis[i][j] = 1;
				while (head < tail)
				{
					que now = qu[++head];
					for (int k = 0, nx, ny; k < 4; ++k)
					{
						nx = now.x + dx[k]; ny = now.y + dy[k];
						if (nx >= 0 && nx < mm && ny >= 0 && ny < 7 && !vis[nx][ny] && !col[nx][ny])
						{
							qu[++tail] = (que) {nx, ny};
							fcol[nx][ny] = cnt;
							vis[nx][ny] = 1;
						}
					}
				}
			}
//	printf("%d\n", cnt);
	int cnt2 = 0;
	for (int i = 0; i < 7; ++i) up[i] = fcol[0][i];
	for (int i = 0; i < 7; ++i) !col[mm - 1][i] ? dw[i] = fcol[mm - 1][i] + cnt : 0;
	for (int i = 1; i <= cnt * 2; ++i) Fa[i] = i;

//	for (int i = 0; i < 7; ++i) printf("%d %d\n", up[i], dw[i]);
	for (int i = 0; i < 7; ++i)
	{
//		printf("%d %d\n", up[i], dw[i]);
		if (up[i] && dw[i] && Find(up[i]) != Find(dw[i]))
		{
			Fa[Find(up[i])] = Find(dw[i]);
			++cnt2;
		}
	}
//	printf("%d\n", cnt2);
//	while (n % mm) ;
	ll ans = 1ll * cnt * (n / mm) - 1ll * (n / mm - 1) * cnt2;

	printf("%lld\n", ans);
	return 0;
}
/*
1000000000000 28 20
3 4 5 6 7 8 10 11 12 13 17 18 19 20 22 23 24 25 26 27
*/