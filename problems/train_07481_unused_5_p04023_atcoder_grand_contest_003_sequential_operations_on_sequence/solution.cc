#include <bits/stdc++.h>

using namespace std;

#define N 100000
#define ll long long

int n, m, q;
ll a[N + 5], ans[N + 5], coef[N + 5];

void f(ll l, ll v) {
	if (!l) return ;
	int p = upper_bound(a + 1, a + m + 1, l) - a - 1;
	if (!p)
		ans[1] += v, ans[l + 1] -= v;
	else {
		coef[p] += v * (l / a[p]);
		f(l % a[p], v);
	}
}

int main() {
	scanf("%d%d", &n, &q);
	a[++m] = n;
	for (int i = 1; i <= q; ++i) {
		ll x;
		scanf("%lld", &x);
		while(m && x <= a[m])
			m--;
		a[++m] = x;
	}
	coef[m] = 1;
	for (int i = m; i >= 2; --i) {
		coef[i - 1] += coef[i] * (a[i] / a[i - 1]);
		f(a[i] % a[i - 1], coef[i]);
	}
	ans[1] += coef[1], ans[a[1] + 1] -= coef[1];
	for (int i = 2; i <= n; ++i)
		ans[i] += ans[i - 1];
	for (int i = 1; i <= n; ++i)
		printf("%lld\n", ans[i]);
	return 0;
}