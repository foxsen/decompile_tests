#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1000000007;
const int INF = MOD + 1;
const ld EPS = 1e-12;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template<typename T> T inf() { assert(false); }
template<> constexpr int inf<int>() { return 1e9; }
template<> constexpr ll inf<ll>() { return 1e18; }
template<> constexpr ld inf<ld>() { return 1e30; }
/*--------------------template--------------------*/

template <typename Flow>
struct FEdge {
	int from, to;
	Flow cap; int rev;
	FEdge(int s, int t, Flow f, int r) : from(s), to(t), cap(f), rev(r) {}
};

template<typename Flow> using FGraph = vector<vector<FEdge<Flow>>>;

template <typename Flow>
void add_edge(FGraph<Flow> &g, int from, int to, Flow cap) {
	g[from].emplace_back(from, to, cap, (int)g[to].size());
	g[to].emplace_back(to, from, 0, (int)g[from].size() - 1);
}

template <typename Flow>
Flow augment(FGraph<Flow> &g, vector<Flow> &d, vector<int> &iter,
	int v, int t, const Flow &f) {
	if (v == t) return f;
	for (int &i = iter[v]; i < (int)g[v].size(); i++) {
		auto &e = g[v][i];
		if (e.cap > 0 && d[v] < d[e.to]) {
			Flow ff = augment(g, d, iter, e.to, t, min(f, e.cap));
			if (ff > 0) {
				e.cap -= ff;
				g[e.to][e.rev].cap += ff;
				return ff;
			}
		}
	}
	return 0;
}

template <typename Flow>
Flow max_flow(FGraph<Flow> &g, int s, int t, Flow zero = 0) {
	const int V = g.size();
	Flow flow = zero;
	for (;;) {
		vector<Flow> d(V, -1);
		queue<int> que;
		d[s] = zero;
		que.push(s);
		while (!que.empty()) {
			int v = que.front(); que.pop();
			for (const auto &e : g[v]) {
				if (e.cap <= zero || d[e.to] >= zero) continue;
				d[e.to] = d[v] + 1;
				que.push(e.to);
			}
		}
		if (d[t] < zero) return flow;
		vector<int> iter(V, 0);
		Flow f;
		while ((f = augment(g, d, iter, s, t, inf<Flow>())) > 0) flow += f;
	}
}

int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	int n, m, s, t;
	while (cin >> n >> m >> s >> t, n)
	{
		s--; t--;
		FGraph<int> g(n);
		map<pii, int> st;
		REP(i, m)
		{
			int a, b; cin >> a >> b;
			a--; b--;
			add_edge(g, a, b, 1);
			st[pii(a, b)]++;
		}
		int fl = max_flow(g, s, t);
		vi vis(n);
		vis[s] = 1;
		queue<int> que;
		que.push(s);
		while (!que.empty())
		{
			int t = que.front();
			que.pop();
			for (auto e : g[t])
			{
				if (e.cap == 0) continue;
				int nx = e.to;
				if (vis[nx]) continue;
				vis[nx] = 1;
				que.push(nx);
			}
		}
		while (!que.empty()) que.pop();
		vis[t] = -1;
		que.push(t);
		while (!que.empty())
		{
			int t = que.front();
			que.pop();
			for (auto e : g[t])
			{
				if (e.cap == 1) continue;
				int nx = e.to;
				if (vis[nx]) continue;
				vis[nx] = -1;
				que.push(nx);
			}
		}
		vi v1, v2;
		REP(i, n)
		{
			if (vis[i] == 1) v1.push_back(i);
			else if(vis[i] == -1) v2.push_back(i);
		}
		int add = 0;
		for (auto i : v1)for (auto j : v2)
		{
			add += st[pii(j, i)];
		}
		if (add) fl++;
		cout << fl << " " << add << endl;
	}
	return 0;
}