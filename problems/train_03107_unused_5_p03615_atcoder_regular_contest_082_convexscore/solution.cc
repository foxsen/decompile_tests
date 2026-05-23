#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
const int N = 11111;
void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}
int pw(int a, int b) {
	int an = 1;
	for (; b; b >>= 1) {
		if (b & 1) an = 1ll * an * a % mod;
		a = 1ll * a * a % mod;
	}
	return an;
}
int ans, x[N], y[N], n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d%d", &x[i], &y[i]);
	add(ans, pw(2, n));
	add(ans, mod - 1);
	add(ans, mod - n);
	add(ans, mod - n * (n - 1) / 2);
	for (int i = 1; i <= n; ++i) 
		for (int j = i + 1; j <= n; ++j) {
			int dx = x[j] - x[i], dy = y[j] - y[i];
			int cnt = 2;
			for (int k = 1; k <= n; ++k) {
				if (i == k || j == k) continue;
				int dx2 = x[k] - x[j], dy2 = y[k] - y[j];
				if (dx2 * dy != dy2 * dx) continue;
				if (k < j) break;
				++cnt;
			}
			add(ans, mod - pw(2, cnt));
			add(ans, 1);
			add(ans, cnt);
			add(ans, cnt * (cnt - 1) / 2);
		}
	printf("%d\n", ans);
	return 0;
}