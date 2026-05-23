#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define int ll

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e17 + 7;

map<int, V<pi>> m;

signed main()
{
	IO_OP;

	int n, x, d;
	cin >> n >> x >> d;
	if (d == 0) {
		if (x == 0) cout << 1 << endl;
		else cout << n + 1 << endl;
		return 0;
	}
	if (x == 0) {
		cout << 1 + n * (n - 1) / 2 << endl;
		return 0;
	}
	for(int take=0;take<=n;take++) {
		int mid = take * x;
		int l = take * (take - 1) / 2 + mid / d;
		int r = take * (2*n-take-1) / 2 + mid / d;
		m[mid % d].EB(l, r);
	}
	int ans = 0;
	for(auto& p:m) {
		V<pi> &v = p.S;
		sort(ALL(v));
		int mx = -INF;
		for(pi p:v) {
			int l = p.F, r = p.S;
			if(l > mx) ans += r - l + 1;
			else ans += max(0LL, r - mx);
			mx = max(mx, r);
		}
	}
	cout << ans << endl;
	
}



