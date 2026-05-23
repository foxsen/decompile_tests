#include <bits/stdc++.h>
#define ll long long
#define maxn 150005 /*rem*/
#define mod 65537
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
inline int add(int a, int b) {
	a += b;
	return (a < mod) ? a : (a - mod);
}
inline int sub (int a, int b) {
	a -= b;
	return (a < 0) ? a + mod : a;
}
inline int mul(int a, int b) {
	return (ll)a * b % mod;
}
int power(int a, int b) {
	if (!b) return 1;
	int u = power(a, b >> 1);
	u = mul(u, u);
	if (b & 1) u = mul(u, a);
	return u;
}
vi rev, roots;
int mx = -1;
void init() {
	mx = 16;
	roots.resize(1 << mx);
	for (int j = 1; j <= mx; j++) {
		int mn = power(3, (mod - 1) >> j);
		for (int i = 0; i < (1 << (j - 1)); i++) {
			int npl = (1 << (j - 1)) | i;
			if (i == 0) roots[npl] = 1;
			else roots[npl] = mul(mn, roots[npl - 1]); 
		}
	}
}
void calr(int m) {
	rev.resize(1 << m);
	if (mx == -1) init();
	rev[0] = 0;
	for (int j = 0; j < m; j++)
		for (int k = 0; k < (1 << j); k++) 
			rev[k | (1 << j)] = rev[k] + (1 << (m - j - 1));
}
void dft(vi& a) {
	int n = a.size(), r = 0; // 保证 a 是 2 幂 
	while ((1 << r) < n) r++;
	calr(r);
	for (int i = 0; i < n; i++)
		if (rev[i] > i)
			swap(a[rev[i]], a[i]);
	for (int i = 1; i < n; i <<= 1) {
		for (int j = 0; j < n; j += (i << 1)) {
			for (int k = 0; k < i; k++) {
				int mr = mul(a[i + j + k], roots[i + k]);
				a[i + j + k] = sub(a[j + k], mr);
				a[j + k] = add(a[j + k], mr);
			}
		}
	}
}
vi mul1(vi a, vi b) {
	int l = a.size() + b.size() - 1;
	int r = 0;
	while ((1 << r) < l) r++;
	a.resize(1 << r), b.resize(1 << r);
	dft(a);
	dft(b);
	int bk = power(1 << r, mod - 2);
	for (int i = 0; i < (1 << r); i++)
		a[i] = mul(mul(a[i], b[i]), bk);
	reverse(a.begin() + 1, a.end());
	dft(a);
	a.resize(l);
	return a;
}
vi mult(vi a, vi b) {
	int dv = (a.size() / 2);
	vi fn(a.size() + b.size() - 1);
	vi u[2][2];
	vi t[2] = {a, b};
	for (int j = 0; j < 2; j++) {
		for (int k = 0; k < 2; k++) {
			if (k == 0) {
				u[j][k].resize(dv);
				for (int s = 0; s < dv; s++)
					u[j][k][s] = t[j][s];
			}
			else {
				u[j][k].resize(t[j].size() - dv);
				for (int s = dv; s < t[j].size(); s++)
					u[j][k][s - dv] = t[j][s];
			}
		}
	}
	for (int j = 0; j < 2; j++)
		for (int k = 0; k < 2; k++) {
			vi f1 = mul1(u[0][j], u[1][k]);
			for (int m = 0; m < f1.size(); m++)	{
				int id = m + (j + k) * dv;
				fn[id] = add(fn[id], f1[m]);
			}
		}
	return fn;
}
void otp(vi a) {
	for (int i = 0; i < a.size(); i++)
		printf("%d ", a[i]);
	printf("\n");
}
ll jc[maxn], bjc[maxn];
int b[maxn];
int a[maxn];
int main() {
	int t;
	cin >> t;
	jc[0] = bjc[0] = 1;
	for (int i = 1; i < maxn; i++)	
		jc[i] = jc[i - 1] * i % mod, 
		bjc[i] = ksm(jc[i], mod - 2);
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		for (int j = n - 1; j >= 0; j--) {
			scanf("%d", &b[j]);
			b[j] %= mod;
			if (b[j] < 0) b[j] += mod;
		}
		m %= mod;
		if (!m) 
			for (int j = 0; j < n; j++) a[j] = b[j];
		else {
			if (m < 0) m += mod;
			m = mod - m;
			ll bk = ksm(m, mod - 2);
			vi g(n), h(n);
			for (int j = 0; j < n; j++)
				h[j] = bjc[j], 
				g[j] = mul(mul(b[j], bjc[j]), ksm(bk, j));
			vi fn;
			if (n <= 20000) fn = mul1(g, h);
			else fn = mult(g, h);
			for (int j = 0; j < n; j++)
				a[j] = mul(mul(fn[j], ksm(m, j)), jc[j]);
		}
		for (int j = 0; j < n; j++) {
			printf("%d", a[j]);
			if (j != n - 1) printf(" ");
			else printf("\n");
		} 
	}
	return 0;
}
/*
10 
3 1 1 2 3
1 1 1 
*/

