#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
using namespace std;

#define int int64_t

#define CHOOSE(a) CHOOSE2 a
#define CHOOSE2(a0,a1,a2,a3,x,...) x
#define REP1(i, s, cond, cal) for (signed i = signed(s); i cond; i cal)
#define REP2(i, s, n) REP1(i, s, < signed(n), ++)
#define REP3(i, n) REP2(i, 0, n)
#define rep(...) CHOOSE((__VA_ARGS__,REP1,REP2,REP3))(__VA_ARGS__)
#define rrep(i, s) rep(i, s, >= 0, --)

#define all(c) begin(c), end(c)
#define maxup(ans, x) (ans = (ans < x ? x : ans))
#define minup(ans, x) (ans = (ans > x ? x : ans))

#define breakif(cond) if(cond) break; else

using VV = vector<vector<int>>;
using V = vector<int>;
using P = pair<int, int>;
using IP = pair<int, P>;

template<typename T>
inline void input(vector<T>& v) { for (auto& x : v) cin >> x; }

void comb(int idx, int rem, int sum, V& data, V& v) {
	if (rem == 0) {
		v.push_back(sum);
		return;
	}
	if (idx == data.size()) return;
	comb(idx + 1, rem, sum, data, v);
	comb(idx + 1, rem - 1, sum + data[idx], data, v);
}

signed main() {
	int n, k, l, r; cin >> n >> k >> l >> r;
	V as(n); input(as);
	V x; x.insert(x.begin(), as.begin(), as.begin() + as.size() / 2);
	V y; y.insert(y.begin(), as.begin() + as.size() / 2, as.end());
	int ans = 0;
	rep(p, 0, k + 1) {
		int q = k - p;
		V ps, qs;
		comb(0, p, 0, x, ps);
		comb(0, q, 0, y, qs);
		sort(all(ps));
		sort(all(qs));
		for (int s : ps) {
			int t1 = upper_bound(all(qs), r - s) - qs.begin();
			int t2 = lower_bound(all(qs), r - s) - qs.begin();
			ans += upper_bound(all(qs), r - s) - lower_bound(all(qs), l - s);
		}
	}
	cout << ans << endl;
	//system("pause");
}