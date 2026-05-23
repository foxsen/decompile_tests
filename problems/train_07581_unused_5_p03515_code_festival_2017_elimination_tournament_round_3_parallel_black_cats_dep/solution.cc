#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<functional>
#include<map>
#include<unordered_set>
using namespace std;
/*int p = 998244353;*/
int p = 1000000007;
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define rep(i,n) for(int i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define qin pair<int,pin>
#define V vector
#define Endl endl
#define veb vector<bool>
#define sq(a) (a)*(a)
#define rev(s) reverse(s.begin(),s.end())
#define end_pr(s) cout << s <<endl;return 0
#define itn int
int RE() {
	vel v(3, 2);
	return v.at(4);
}
int ru(int a, int r) {
	if (r == 0) { return 1; }
	int ans = ru(a, r / 2);
	ans *= ans; ans %= p;
	if (r % 2 == 1) { ans *= a; }
	return ans % p;
}
int inv(int a) {
	return ru(a,p - 2);
}
vel dis(int mid1, vvel &way) {
	int n = way.size();
	vel dist(n, -1); dist[mid1] = 0;
	queue<int> q;
	q.push(mid1);
	while (!q.empty()) {
		int st = q.front(); q.pop();
		rep(i, way[st].size()) {
			int to = way[st][i];
			if (dist[to] == -1) {
				dist[to] = dist[st] + 1;
				q.push(to);
			}
		}
	}
	return dist;
}
pin most_far(int now, int n, vvel &way) {
	vel dist1 = dis(now, way);
	pin ans = mkp(-1, 0);
	rep(i, n) {
		if (dist1[i] > ans.first) { ans = mkp(dist1[i], i); }
	}
	return ans;
}

template<typename T>
V<T> uni(V<T> &v) {
	if (v.size() == 0) { return v; }
	sor(v);
	V<T> ans(1, v[0]);
	for (int i = 1; i < v.size(); i++) {
		if (v[i] != v[i - 1]) { ans.push_back(v[i]); }
	}
	v = ans;
	return v;
}
int s_gcd(int a, int b) {
	if (b == 0) { return a; }
	return s_gcd(b, a%b);
}
int gcd(int a, int b) {
	if (a < b) { swap(a, b); }
	return s_gcd(a, b);
}
vel par;
vel dp;
vvel chi;
int top(int i) {
	if (par[i] < 0) { return i; }
	int ans = top(par[i]);
	par[i] = ans;
	return ans;
}
void merge(int x, int y) {
	par[y] += par[x];
	par[x] = y;
	chi[y].push_back(x);
}
void solve(int now_pot) {
	for (auto x : chi[now_pot]) {
		dp[x] += dp[now_pot];
		solve(x);
	}
}
signed main() {
	int n; cin >> n;
	V<qin> edge(n - 1);
	rep(i, n - 1) {
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		edge[i] = mkp(c, mkp(a, b));
	}
	par = vel(n, -1);
	dp = vel(n, 0);
	chi = vvel(n);
	vel ans(n,0);
	sor(edge); rev(edge);
	rep(i, n - 1) {
		int c = edge[i].first;
		pin ed = edge[i].second;
		int x = ed.first;
		int y = ed.second;
		x = top(x); y = top(y);
		if ((par[x] > par[y]) xor (chi[x].size()>chi[y].size())) { swap(x, y); }
		int szx = par[x] * -1;
		int szy = par[y] * -1;//par[x]=yにあとでする
		ans[y] += szx * c;
		for (auto st : chi[y]) {
			dp[st] += szx * c;
		}
		dp[x] += szy * c;
		merge(x, y);
	}
	solve(top(0));
	int ret = 0;
	rep(i, n) {
		cout << ans[i] + dp[i] << endl;
	}
}