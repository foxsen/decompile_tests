#include <bits/stdc++.h>

using namespace std;
#define int long long 
#define x first
#define y second

int e (pair<int, int> p[4]) {
	int ans = 0;
	ans += abs (p[0].x - p[1].x);
	ans += abs(p[3].x - p[2].x);
	ans += abs(p[0].y- p[2].y);
	ans += abs(p[1].y - p[3].y);
	int x1 = min (p[2].x , p[3].x) - max(p[1].x , p[0].x);
	int x2 = max (p[2].x,p[3].x) - min(p[1].x , p[0].x);
	int x3 = min (p[1].y ,p[3].y) - max(p[2].y ,p[0].y);
	int x4 = max (p[1].y,p[3].y) - max (p[2].y, p[0].y); 
	if(x1 > x4 || x3 > x2) ans += 2 * (max(x1,x3) - min (x2,x4));
	return ans;
}
void solve () {
	pair<int,int> a[4];
	for (int i = 0; i< 4; i++) {
		cin >> a[i].x >> a[i].y;
	}
	vector<int> m(4);
	iota(m.begin(), m.end(), 1);
	int ans = 1e18;
	do {
		pair <int,int> p[4];
		for (int i = 0; i < 4; i++) {
			p[i] = a[m[i] - 1];
		}
		ans = min (ans, e(p));
	}while (next_permutation(m.begin(), m.end()));
	cout << ans << endl;
}

signed main () {
	int t;
	cin >> t;
	while (t--) {
		solve();
	} 
}
