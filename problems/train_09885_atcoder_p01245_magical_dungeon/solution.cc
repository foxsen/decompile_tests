#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ll mod = 1000000007;
//const ll mod = 998244353;
const int inf = 1e9 + 10;
const ll INF = 1e18;
const ld EPS = 1e-10;
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

struct Edge {
  int f, t, c;
};

int Case = 0;
int n, m;
vector<Edge> G;
int s, t, h;
int d[105];
bool isroop[105];

void init() {
  G.clear();
  memset(d, 0, sizeof(d));
  memset(isroop, 0, sizeof(isroop));
}

bool check(int res) {
  memset(d, 0, sizeof(d));
  rep(i, m) {
    int v = G[i].f, u = G[i].t, c = G[i].c;
    if (v != res) continue;
    chmax(d[u], min(h, h + c));
  }
  rep(i, n - 1) {
    rep(j, m) {
      int v = G[j].f, u = G[j].t, c = G[j].c;
      if (!d[v]) continue;
      chmax(d[u], min(h, d[v] + c));
    }
  }
  return d[res] == h;
}

void solve() {
  rep(i, n) isroop[i] = check(i);
  memset(d, 0, sizeof(d));
  d[s] = h;
  rep(i, n - 1) {
    rep(j, m) {
      int v = G[j].f, u = G[j].t, c = G[j].c;
      if (!d[v]) continue;
      chmax(d[u], min(h, d[v] + c));
    }
    rep(j, m) {
      int v = G[j].f, u = G[j].t, c = G[j].c;
      if (!d[v]) continue;
      if (d[u] != min(h, d[v]) && isroop[u]) d[u] = h;
    }
  }
  cout << "Case " << Case << ": ";
  if (d[t]) cout << d[t];
  else cout << "GAME OVER";
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(25);

  while (cin >> n >> m, n) {
    init();
    Case++;
    vector<Edge> tmp;
    rep(i, m) {
      int v, u, w;
      cin >> v >> u >> w;
      tmp.push_back({v, u, w});
    }
    cin >> s >> t >> h;
    for (Edge e: tmp) {
      if (e.f != t) G.push_back(e);
    }

    solve();
  }

  




  
  return 0;
}
