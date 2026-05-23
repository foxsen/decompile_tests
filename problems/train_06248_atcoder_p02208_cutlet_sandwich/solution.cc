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
#include<random>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
#include<complex>
using namespace std;

//#define int long long
typedef long long ll;

typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = mod * mod;
typedef pair<int, int>P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef pair<ll, ll> LP;
typedef vector<ll> vec;
typedef long double ld;
typedef pair<ld, ld> LDP;
const ld eps = 1e-6;
const ld pi = acos(-1.0);
typedef vector<vector<ll>> mat;
typedef vector<ll> vec;

struct edge {
	int to, cost;
};
vector<edge> G[1 << 19];
int dist[1 << 19];
void solve() {
	int x, y, z, n, m, s, t;
	cin >> x >> y >> z >> n >> m >> s >> t;
	s = (s - 1) + x + y + z;
	t = (t - 1) + x + y + z + n;
	rep(i, n) {
		int a, b; cin >> a >> b; a--; b--;
		G[i + x + y + z].push_back({ a,1 });
		G[a].push_back({ i + x + y + z,0 });
		G[i + x + y + z].push_back({ b+x,1 });
		G[b+x].push_back({ i + x + y + z,0 });
	}
	rep(i, m) {
		int c, d; cin >> c >> d; c--; d--;
		int id = i + x + y + z + n;
		G[id].push_back({ c + x,1 });
		G[c + x].push_back({ id,0 });
		G[id].push_back({ d + x + y,1 });
		G[d + x + y].push_back({ id,0 });
	}
	rep(i, x + y + z + n + m)dist[i] = mod;
	priority_queue<P, vector<P>, greater<P>> q;
	q.push({ 0,s }); dist[s] = 0;
	while (!q.empty()) {
		P p = q.top(); q.pop();
		int id = p.second;
		if (dist[id] < p.first)continue;
		rep(j, G[id].size()) {
			int to = G[id][j].to;
			int nd = G[id][j].cost + p.first;
			if (nd < dist[to]) {
				dist[to] = nd;
				q.push({ nd,to });
			}
		}
	}
	if (dist[t] == mod)dist[t] = -1;
	cout << dist[t] << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(8);
	//init();
	solve();
	stop
		return 0;
}

