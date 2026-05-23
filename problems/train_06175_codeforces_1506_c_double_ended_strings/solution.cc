#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <bitset>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()


const int maxn = 2e6 + 13;
const int INF = 2e9;
const int MOD = 1e9 + 7;


void solve() {
	string a, b;
	cin >> a >> b;
	int ans = a.size() + b.size();
	int n = a.size();
	int m = b.size();
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int cnt = 0;
			int u = i, v = j;
			while (u < n && v < m && a[u] == b[v])cnt++, ++u, ++v;
			ans = min(ans, n + m - 2 * cnt);
		}
	}
	cout << ans << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> q;
	while (q--)solve();

	return 0;
}