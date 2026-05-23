#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int const N = 150, M = N >> 1;
int dp[N + 1][N + 1][N + 1], md, dp0[M + 1][M + 1];

inline void ad(int &x, int y) { if ((x += y) >= md)x -= md; }
inline void up(int i, int a, int b, int y) { ad(dp[i][a + M][b + M], y); }

int pw(int x, int p){
	if (p < 0)return 0;
	int an = 1;
	while (p){
		if (p & 1)an = (ll)an * x % md;
		x = (ll)x * x % md;
		p >>= 1;
	}
	return an;
}

int easy(int n, int k){
	dp0[0][0] = 1;
	f(i, 1, n + 1){
		dp0[i][0] = 0;
		f(j, 0, k + 1)ad(dp0[i][0], dp0[i - 1][j]);
		f(j, 1, k + 1)dp0[i][j] = dp0[i - 1][j - 1];
	}
	int an = 0;
	f(i, 0, k + 1)ad(an, dp0[n][i]);
	return an;
}

int main(){
	int n, k;
	scanf("%d%d%d", &n, &k, &md);
	if (k & 1){
		dp[0][M][M] = 1;
		int m = n - n / 2;
		f(i, 0, n + 1)f(f1, -M, m + 1)f(f2, -M, m + 1){
			int &d = dp[i][f1 + M][f2 + M];
			if (i & 1){
				if (-f1 >= k + 3 >> 1 && -f1 + abs(f2) >= k + 2)d = 0;
				if (f1 < 0 && i - (-f1 - 1) * 2 <= 0)d = 0;
				else if (f1 > 0 && i - k / 2 * 2 <= 0)d = 0;
			}
			else {
				if (-f2 >= k + 3 >> 1 && -f2 + abs(f1) >= k + 2)d = 0;
				if (f2 < 0 && i - (-f2 - 1) * 2 <= 0)d = 0;
				else if (f2 > 0 && i - k / 2 * 2 <= 0)d = 0;
			}
			if (d == 0 || i == n)continue;
			if (i & 1){
				if (f2 < 0){
					up(i + 1, f1, k / 2, d);
					up(i + 1, f1, max(f2 - 1, -(k + 1)), d);
				}
				else if (f2)up(i + 1, f1, f2 - 1, d);
				else {
					up(i + 1, f1, 0, d);
					f(j, 1, min(k / 2, m) + 1)up(i + 1, f1, j, d);
					up(i + 1, f1, -(k / 2 + 1), d);
				}
			}else {
				if (f1 < 0){
					up(i + 1, k / 2, f2, d);
					up(i + 1, max(f1 - 1, -(k + 1)), f2, d);
				}
				else if (f1)up(i + 1, f1 - 1, f2, d);
				else {
					up(i + 1, 0, f2, d);
					f(j, 1, min(k / 2, m) + 1)up(i + 1, j, f2, d);
					up(i + 1, -(k / 2 + 1), f2, d);
				}
			}
		}
		int an = 0;
		f(i, -M, M + 1)f(j, -M, M + 1){
			int z = dp[n][i + M][j + M];
			if (z == 0)continue;
			if (i >= 0)z = (ll)z * pw(2, k / 2 - i) % md;
			if (j >= 0)z = (ll)z * pw(2, k / 2 - j) % md;
			ad(an, z);
		}
		printf("%d\n", an);
	}else printf("%d\n", (int)((ll)easy(n >> 1, k >> 1) * easy(n - n / 2, k >> 1) % md));
}