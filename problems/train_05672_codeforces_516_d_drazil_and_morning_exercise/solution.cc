#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int> > G[100006];
long long dis[100006], sid[100006];
int p, s, t;
void dfs(int u, int f, long long* d) {
  if (dis[u] > dis[p]) p = u;
  for (auto t : G[u])
    if (t.first != f) {
      int v = t.first;
      d[v] = d[u] + t.second;
      dfs(v, u, d);
    }
}
int L[100006], R[100006], clo;
void cfs(int u, int f) {
  L[u] = ++clo;
  for (auto d : G[u])
    if (d.first != f) {
      int v = d.first;
      cfs(v, u);
    }
  R[u] = clo;
}
struct que {
  int u;
  long long c;
  int idx;
} Q[100006 * 52];
int cnt = 0;
int as[55];
int T[100006], S;
long long f[100006];
void add(int x, int c) {
  while (x <= n + 2) T[x] += c, x += (x & -x);
}
int sum(int x) {
  int re = 0;
  while (x > 0) re += T[x], x -= (x & -x);
  return re;
}
void solve() {
  cin >> n;
  for (int i = (2), iend = (n); i <= iend; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    G[u].emplace_back(make_pair(v, w)), G[v].emplace_back(make_pair(u, w));
  }
  p = 1;
  dfs(1, 1, dis);
  s = p, p = s, dis[s] = 0;
  dfs(s, s, dis);
  t = p, p = t;
  dfs(t, t, sid);
  for (int i = (1), iend = (n); i <= iend; ++i) {
    f[i] = max(dis[i], sid[i]);
    if (!S || f[i] < f[S]) S = i;
  }
  cfs(S, S);
  for (int i = (1), iend = (n); i <= iend; ++i) Q[i] = (que){i, f[i], 0};
  cnt = n;
  int q;
  cin >> q;
  for (int i = (1), iend = (q); i <= iend; ++i) {
    long long l;
    scanf("%lld", &l);
    for (int u = (1), uend = (n); u <= uend; ++u)
      Q[++cnt] = (que){u, f[u] + l, i};
  }
  sort(Q + 1, Q + 1 + cnt,
       [](que& a, que& b) { return a.c == b.c ? a.idx < b.idx : a.c < b.c; });
  for (int i = (1), iend = (cnt); i <= iend; ++i) {
    int u = Q[i].u;
    if (!Q[i].idx)
      add(L[u], 1);
    else
      as[Q[i].idx] = max(as[Q[i].idx], sum(R[u]) - sum(L[u] - 1));
  }
  for (int i = (1), iend = (q); i <= iend; ++i) printf("%d\n", as[i]);
}
signed main() { solve(); }
