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
const int MOD = 1e9 + 7;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template<class T>
istream& operator >> (istream& is, vector<T>& v)
{
	for (auto &i : v) is >> i;
	return is;
}
template<class T>
ostream& operator<<(ostream& os, vector<T>& v)
{
	const string delimiter = "\n";
	REP(i, v.size())
	{
		os << v[i];
		if (i != v.size() - 1) os << delimiter;
	}
	return os;
}
/*--------------------template--------------------*/

struct UnionFind
{
	vector<int> par;
	UnionFind(int n) :par(n, -1) {}
	int find(int x) { return par[x] < 0 ? x : par[x] = find(par[x]); }
	void unite(int x, int y)
	{
		x = find(x); y = find(y);
		if (x == y) return;
		if (par[y] < par[x]) swap(x, y);
		if (par[x] == par[y]) par[x]--;
		par[y] = x;
		if (find(x) != find(y)) par[find(y)] = x;
	}
	int count()
	{
		int cnt = 0;
		REP(i, par.size()) if (par[i] < 0) cnt++;
		return cnt;
	}
	bool same(int x, int y)
	{
		return find(x) == find(y);
	}
};

typedef ld Weight;
struct Edge
{
	int from, to; Weight cost; char c;
	bool operator < (const Edge& e) const { return cost < e.cost; }
	bool operator > (const Edge& e) const { return cost > e.cost; }
};
typedef vector<Edge> Edges;

const ld INF = 1e9;
const ld EPS = 1e-9;

int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	int n, m, k;
	while (cin >> n >> m >> k, n)
	{
		Edges es;
		REP(i, m)
		{
			int a, b; ld c; char d;
			cin >> a >> b >> c >> d;
			a--; b--;
			es.emplace_back(Edge{ a, b, c, d });
		}
		int mn = INF, mx = -1;
		ld lb = -INF, ub = INF;
		REP(lp, 300)
		{
			ld mid = (ub + lb) / 2;
			Edges tmp;
			for (auto e : es)
			{
				if (e.c == 'A') e.cost += mid;
				tmp.push_back(e);
			}
			sort(ALL(tmp));
			UnionFind uf(n);
			ld cost = 0;
			int cnta = 0;
			for (auto e : tmp)
			{
				if (uf.same(e.from, e.to)) continue;
				if (e.c == 'A')
				{
					cnta++;
				}
				cost += e.cost;
				uf.unite(e.from, e.to);
			}

			chmax(mx, cnta);
			chmin(mn, cnta);
			if (lp == 299)
			{
				if (uf.count() != 1 || (mx < k || mn > k))
				{
					cout << -1 << endl;
				}
				else
				{
					cout << ll(cost - k * mid + EPS) << endl;
				}
			}
			else if (cnta > k)
			{
				lb = mid;
			}
			else
			{
				ub = mid;
			}
		}
	}
	return 0;
}
