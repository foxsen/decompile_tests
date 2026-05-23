#include <bits/stdc++.h>
#pragma GCC optimize(2, 3, "Ofast")
using namespace std;
template <typename T1, typename T2>
void ckmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
int read() {
  int x = 0, f = 0;
  char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template <typename T>
void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template <typename T>
void print(T x, char let) {
  print(x), putchar(let);
}
const int N = 200005;
const int mod = 1e9 + 7;
const int inf = 1e9;
inline void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline void sub(int &x, int y) {
  x -= y;
  if (x < 0) x += mod;
}
vector<pair<int, int> > adj[N];
int a[N], n, LIM;
bool ban[N];
int sz[N], maxp[N], sumsz, rt;
void getrt(int u, int fa) {
  maxp[u] = 0, sz[u] = 1;
  for (auto v : adj[u]) {
    if (ban[v.first] || v.first == fa) continue;
    getrt(v.first, u);
    sz[u] += sz[v.first];
    ckmax(maxp[u], sz[v.first]);
  }
  ckmax(maxp[u], sumsz - sz[u]);
  if (maxp[u] < maxp[rt]) rt = u;
}
vector<pair<int, int> > tmp, tmq[2];
int ans;
void dfs1(int u, int fa, int lst, int turns, int sum) {
  sum = (sum + a[u]) % mod;
  tmp.push_back({turns, sum});
  for (auto v : adj[u]) {
    if (ban[v.first] || v.first == fa) continue;
    dfs1(v.first, u, v.second, turns + (lst != v.second), sum);
  }
}
int calc1(vector<pair<int, int> > x) {
  static int zz[N];
  int n = (int(x.size())), res = 0;
  for (int i = 0; i < n; i++) zz[i] = x[i].second;
  for (int i = 1; i < n; i++) add(x[i].second, x[i - 1].second);
  for (int i = 0; i < n; i++) {
    int t = upper_bound(x.begin(), x.end(), make_pair(LIM - x[i].first, mod)) -
            x.begin() - 1;
    ckmin(t, i - 1);
    if (t >= 0) add(res, (x[t].second + 1ll * (t + 1) * (zz[i] + a[rt])) % mod);
  }
  return res;
}
int calc2(vector<pair<int, int> > x, vector<pair<int, int> > y) {
  int n = (int(x.size())), m = (int(y.size())), res = 0;
  for (int i = 1; i < n; i++) add(x[i].second, x[i - 1].second);
  for (int i = 0; i < m; i++) {
    int t =
        upper_bound(x.begin(), x.end(), make_pair(LIM - y[i].first - 1, mod)) -
        x.begin() - 1;
    if (t >= 0)
      add(res, (x[t].second + 1ll * (t + 1) * (y[i].second + a[rt])) % mod);
  }
  return res;
}
void calc_in(int u) {
  sort(tmp.begin(), tmp.end());
  for (auto v : tmp)
    if (v.first <= LIM) add(ans, (v.second + a[u]) % mod);
  sub(ans, calc1(tmp));
}
void dfz(int u) {
  ban[u] = 1;
  tmq[0].clear(), tmq[1].clear();
  add(ans, a[u]);
  for (auto v : adj[u]) {
    if (!ban[v.first]) {
      tmp.clear();
      dfs1(v.first, u, v.second, 0, 0);
      for (auto it : tmp) tmq[v.second].push_back(it);
      calc_in(u);
    }
  }
  sort(tmq[0].begin(), tmq[0].end());
  sort(tmq[1].begin(), tmq[1].end());
  add(ans, calc1(tmq[0]));
  add(ans, calc1(tmq[1]));
  add(ans, calc2(tmq[0], tmq[1]));
  for (auto v : adj[u]) {
    if (!ban[v.first]) {
      rt = 0, sumsz = sz[v.first], getrt(v.first, 0);
      dfz(rt);
    }
  }
}
int main() {
  n = read(), LIM = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n - 1; i++) {
    int u = read(), v = read(), w = read();
    adj[u].push_back({v, w}), adj[v].push_back({u, w});
  }
  maxp[rt = 0] = n, sumsz = n, getrt(1, 0);
  dfz(rt);
  print(ans, '\n');
  return 0;
}
