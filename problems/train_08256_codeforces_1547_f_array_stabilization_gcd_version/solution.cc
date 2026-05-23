#include <bits/stdc++.h>
using namespace std;

constexpr size_t MAXN = 4e5 + 5;
int t;

#define mid ((x + y) >> 1)
#define lson (pos << 1)
#define rson (pos << 1 | 1)

int n, m;
int a[MAXN];

inline int GCD(int a, int b) { return !b ? a : GCD(b, a % b); }

struct SegmentTree {
	int g[MAXN << 2];

	inline void PushUp(int x, int y, int pos) { g[pos] = GCD(g[lson], g[rson]); }

	inline void Build(int x, int y, int pos, int* in) {
		if (x == y) g[pos] = in[x];
		else Build(x, mid, lson, in), Build(mid + 1, y, rson, in), PushUp(x, y, pos);
	}

	inline int Query(int l, int r, int x = 1, int y = m, int pos = 1) {
		if (y<l || x>r) return 0;
		if (l <= x && y <= r) return g[pos];
		return GCD(Query(l, r, x, mid, lson), Query(l, r, mid + 1, y, rson));
	}
}ST;

inline void Solve() {
	int n; cin >> n;
	m = n << 1;
	for (int i = 1; i <= n; i++) cin >> a[i], a[i + n] = a[i];
	int gsum = a[1];
	for (int i = 2; i <= n; i++) gsum = GCD(gsum, a[i]);
	for (int i = 1; i <= m; i++) a[i] /= gsum;
	ST.Build(1, m, 1, a);
	int l = 1, r = 1, ans = 0;
	while (l <= n) {
		int g = ST.Query(l, r);
		if (g == 1) l++, r++;
		else r++;
		ans = max(ans, r - l + 1 - 1);
	}
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) Solve();
}