#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<utility>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vec;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define stop char nyaa;cin>>nyaa;

struct BIT {
private:
	vector<int> node; int n;
public:
	BIT(int n_) {
		n = n_; node.resize(n, 0);
	}
	void add(int a, int w) {
		for (int i = a; i < n; i |= i + 1)node[i] += w;
	}
	int sum(int a) {
		int ret = 0;
		for (int i = a - 1; i >= 0; i = (i&(i + 1)) - 1)ret += node[i];
		return ret;
	}
	int sum(int a, int b) {
		return sum(b) - sum(a);
	}
};

void solve() {
	int n;
	string s; cin >> s; n = s.length();
	vector<int> alf(26, 0);
	rep(i, n) {
		alf[s[i] - 'a']++;
	}
	vector<int> h(26, 0);
	rep(i, 26) {
		if (alf[i] % 2) {
			cout << -1 << endl; return;
		}
		h[i] = alf[i] / 2;
	}
	vector<int> a, b;
	vector<int> cnt(26, 0);
	ll ans = 0;
	int x = 0;
	rep(i, n) {
		int id = s[i] - 'a';
		if (cnt[id] < h[id]) {
			a.push_back(id);
			cnt[id]++;
			ans += x;
		}
		else {
			b.push_back(id);
			x++;
		}
	}
	reverse(b.begin(), b.end());
	vector<vector<int>> loc(26);
	rep(i, n / 2) {
		loc[a[i]].push_back(i);
	}
	vector<int> cur(26, 0);
	vector<int> trueloc(n / 2);
	rep(i, n / 2) {
		trueloc[i] = loc[b[i]][cur[b[i]]];
		cur[b[i]]++;
	}
	BIT bi(n/2);
	rep(i, n / 2) {
		int x = trueloc[i];
		ans += bi.sum(x,n/2);
		bi.add(x, 1);
	}
	cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
		return 0;
}

