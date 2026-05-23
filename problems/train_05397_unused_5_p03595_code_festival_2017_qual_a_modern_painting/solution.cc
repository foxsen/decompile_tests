#include <bits/stdc++.h>
using namespace std;

const int N = 301010;
const int MOD = 998244353;
const int INV = (MOD + 1) >> 1;
typedef long long ll;

char S[N];
int fac[N << 2], inv[N << 2];
int v[N][2], h[N][2];
int pre[N], suf[N], p2[N];
int n, m, lim, ans;

inline void Mod(int &x) {
	while (x >= MOD) x -= MOD;
}
inline int Pow(int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1) c = (ll)c * a % MOD;
		b >>= 1; a = (ll)a * a % MOD;
	}
	return c;
}
inline int Inv(int x) {
	return Pow(x, MOD - 2);
}
inline int C(int n, int m) {
	return (ll)fac[n] * inv[m] % MOD * inv[n - m] % MOD;
}
inline int Calc(int X, int Y, int Z) {
	if (X == 0) return (Y + Z) ? 0: 1;
	return C(X + Y + Z - 1, X - 1);
}
inline void Solve(void) {
	static int x, y, z;
	memset(p2, 0, sizeof p2);
	memset(suf, 0, sizeof suf);
	x = y = z = 0;
	for (int i = 1; i <= n; i++) x += h[i][1];
	p2[0] = 1;
	for (int i = 1; i <= m; i++)
		Mod(p2[i] = p2[i - 1] << (v[i][0] & v[i][1]));
	for (int i = m; i; i--) {
		if (!v[i][0] && !v[i][1]) {
			suf[i] = suf[i + 1];
			continue;
		}
		Mod(suf[i] = suf[i + 1] + (ll)Calc(x, y, z) * p2[i] % MOD);
		y += v[i][0]; z += v[i][1];
	}
	x = y = z = 0;
	for (int i = 1; i <= n; i++) x += h[i][0];
	for (int i = 1; i <= m; i++) {
		if (!v[i][0] && !v[i][1]) continue;
		pre[i] = (ll)Calc(x, y, z) * Inv(p2[i - 1]) % MOD;
		Mod(ans += (ll)pre[i] * suf[i] % MOD);
		y += v[i][0]; z += v[i][1];
	}
}


int main(void) {
	scanf("%d%d\n", &n, &m);
	lim = max(n, m) << 2;
	inv[1] = 1;
	for (int i = 2; i <= lim; i++)
		inv[i] = (ll)(MOD - MOD / i) * inv[MOD % i] % MOD;
	fac[0] = inv[0] = 1;
	for (int i = 1; i <= lim; i++) {
		fac[i] = (ll)fac[i - 1] * i % MOD;
		inv[i] = (ll)inv[i - 1] * inv[i] % MOD;
	}
	scanf("%s\n", S);
	for (int i = 1; i <= n; i++) h[i][0] = S[i - 1] - '0';
	scanf("%s\n", S);
	for (int i = 1; i <= n; i++) h[i][1] = S[i - 1] - '0';
	scanf("%s\n", S);
	for (int i = 1; i <= m; i++) v[i][0] = S[i - 1] - '0';
	scanf("%s\n", S);
	for (int i = 1; i <= m; i++) v[i][1] = S[i - 1] - '0';
	Solve(); lim >>= 2;
	for (int i = 1; i <= lim; i++) {
		swap(h[i][0], v[i][0]);
		swap(h[i][1], v[i][1]);
	}
	swap(n, m); Solve();
	cout << max(ans, 1) << endl;
}