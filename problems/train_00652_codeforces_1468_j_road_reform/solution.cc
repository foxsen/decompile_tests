#include <bits/stdc++.h>
#define startt ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long  ll;
using namespace std;
#define vint vector<int>
#define all(v) v.begin(), v.end()
#define MOD 1000000007
#define MOD2 998244353
#define MX 1000000000
#define MXL 1000000000000000000
#define PI 3.14159265
#define pb push_back
#define sc second
#define fr first
#define int ll
#define endl '\n'
#define ld long double
																															int ceildiv(int one, int two) {if (one % two == 0) {return one / two;}else {return one / two + 1;}} int power(int n, int pow, int m) {if (pow == 0) return 1;if (pow % 2 == 0) {ll x = power(n, pow / 2, m);return (x * x) % m;}else return (power(n, pow - 1, m) * n) % m;} int gcd(int a, int b) { if (!b)return a; return gcd(b, a % b);} int factorial(int n, int mod) {if (n > 1)return (n * factorial(n - 1, mod)) % mod; else return 1;} int lcm(int a, int b) {return (a * b) / gcd(a, b);} vector<int> read(int n) {vector<int> a; for (int i = 0; i < n; i++) { int x; cin >> x; a.pb(x);} return a;}vector<vector<int>> adj;void init(int n) {for (int i = 0; i <= n; i++) { vector<int> a; adj.pb(a);}}
const int MAXARR = 200005;
int id[MAXARR], edges;
pair <long long, pair<int, int> > p[MAXARR];

void initialize(int n)
{
	for(int i = 0;i <= n;++i)
	id[i] = i;
}

int root(int x)
{
	while(id[x] != x)
	{
		id[x] = id[id[x]];
		x = id[x];
	}
	return x;
}

void union1(int x, int y)
{
	int p = root(x);
	int q = root(y);
	id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
	int x, y;
	long long cost, minimumCost = 0;
	for(int i = 0;i < edges;++i)
	{
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;
		if(root(x) != root(y))
		{
			minimumCost += cost;
			union1(x, y);
		}
	}
	return minimumCost;
}

void solve()
{
	int n, m, k;
	cin >> n >> m >> k;
	initialize(n);
	edges = m;
	int best = MXL;
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		best = min(best, abs(w-k));
		p[i] = make_pair(max(0LL, w-k), make_pair(u, v));
	}
	sort(p, p+m);
	int minimumcost = kruskal(p);
	if(minimumcost == 0)
	{
		cout << best << endl;
	}
	else
	{
		cout << minimumcost << endl;
	}
}
 
int32_t main(){
	startt;
	int t = 1;
	cin >> t;
	while(t--)
	{
		solve();
	}
}


/*
 3 3 18
 3 1 60
 3 2 72
 1 2 84
 */
