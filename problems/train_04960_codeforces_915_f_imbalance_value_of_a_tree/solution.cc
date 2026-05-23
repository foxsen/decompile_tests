#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = (int)1e9 + 7;
const int MAXN = (int)1e6 + 5;
int n;
pair<int, int> a[MAXN];
vector<int> e[MAXN];
bool mark[MAXN];
ll solmax = 0, solmin = 0;
int sz[MAXN], p[MAXN];
int root(int u) {
  while (p[u] != u) u = p[p[u]];
  return u;
}
int sizee(int u) { return sz[root(u)]; }
void join(int u, int v) {
  int ur = root(u);
  int vr = root(v);
  if (sz[ur] < sz[vr]) {
    p[ur] = vr;
    sz[vr] += sz[ur];
  } else {
    p[vr] = ur;
    sz[ur] += sz[vr];
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  int u, v;
  for (int i = 0; i < n - 1; ++i) {
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  memset(mark, 0, sizeof(mark) * sizeof(bool));
  for (int i = 1; i <= n; ++i) {
    int v = a[i].second;
    p[v] = v;
    sz[v] = 1;
    ll s2 = 0, s = 0;
    for (int u : e[v]) {
      if (mark[u]) {
        int x = sizee(u);
        s += x;
        s2 += 1LL * x * x;
        join(v, u);
      }
    }
    solmax += ((s * s - s2) / 2 + s + 1) * a[i].first;
    mark[v] = 1;
  }
  memset(mark, 0, sizeof(mark) * sizeof(bool));
  for (int i = n; i >= 1; --i) {
    int v = a[i].second;
    p[v] = v;
    sz[v] = 1;
    ll s2 = 0, s = 0;
    for (int u : e[v]) {
      if (mark[u]) {
        int x = sizee(u);
        s += x;
        s2 += 1LL * x * x;
        join(v, u);
      }
    }
    solmin += ((s * s - s2) / 2 + s + 1) * a[i].first;
    mark[v] = 1;
  }
  cout << solmax - solmin;
  return 0;
}
