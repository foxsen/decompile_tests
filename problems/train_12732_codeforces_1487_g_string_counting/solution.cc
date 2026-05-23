#include <bits/stdc++.h>
using namespace std;

const int N = 405, mod = 998244353;

int n, mx[26], ans = 26*26, f[N][N][2][2], g[2][N][N][3][3], cnt[3], cur;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 26; i++)
		scanf("%d", &mx[i]);
	for (int i = 3; i <= n; i++)
		ans = 25ll*ans%mod;
	cnt[0] = 25, cnt[1] = 1;
	for (int x = 0; x <= 1; x++)
		for (int y = 0; y <= 1; y++)
			f[2][(x&1) + (y&1)][x][y] = cnt[x]*cnt[y];
	for (int i = 3; i <= n; i++)
		for (int x = 0; x <= 1; x++) for (int y = 0; y <= 1; y++)
			for (int j = (x&1) + (y&1); j <= i; j++)
				f[i][j][x][y] = (1ll*f[i - 1][j - (x&1)][y][x]*(cnt[x] - 1) + 1ll*f[i - 1][j - (x&1)][y][x^1]*cnt[x])%mod;
	for (int i = 0; i < 26; i++)
		for (int j = mx[i] + 1; j <= n; j++)
			for (int x = 0; x <= 1; x++) for (int y = 0; y <= 1; y++)
				ans = (ans - f[n][j][x][y])%mod;
	cnt[0] = 24, cnt[1] = 1, cnt[2] = 1, cur = 0;
	for (int x = 0; x <= 2; x++)
		for (int y = 0; y <= 2; y++)
			g[cur][(x&1) + (y&1)][x/2 + y/2][x][y] = cnt[x]*cnt[y];
	for (int i = 3; i <= n; i++) {
		cur ^= 1;
		memset(g[cur], 0, sizeof(g[cur]));
		for (int x = 0; x <= 2; x++) for (int y = 0; y <= 2; y++)
			for (int j = (x&1) + (y&1); j <= i; j++)
				for (int k = x/2 + y/2; j + k <= i; k++) {
					for (int z = 0; z <= 2; z++)
						g[cur][j][k][x][y] = (g[cur][j][k][x][y] + 1ll*g[cur^1][j - (x&1)][k - x/2][y][z]*cnt[x])%mod;
					g[cur][j][k][x][y] = (g[cur][j][k][x][y] - g[cur^1][j - (x&1)][k - x/2][y][x])%mod;					
				}
	}
	for (int i = 0; i < 25; i++)
		for (int j = i + 1; j < 26; j++)
			for (int x = 0; x <= 2; x++) for (int y = 0; y <= 2; y++)
				for (int s1 = mx[i] + 1; s1 <= n; s1++)
					for (int s2 = mx[j] + 1; s2 + s1 <= n; s2++)
						ans = (ans + g[cur][s1][s2][x][y])%mod;
	printf("%d\n", (ans%mod + mod)%mod);
}