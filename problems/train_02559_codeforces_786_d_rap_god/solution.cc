#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
const int N = 40100;
int T, p[N], c[N], dep[N], ch[N], vis[N], st[N], q, ret[N], cp[N];
int n, u, v;
char s[10];
vector<pair<int, int> > e[N], Q[N];
void dfs(int u, int f) {
  for (auto v : e[u])
    if (v.first != f) {
      dfs(v.first, u);
      p[v.first] = u;
      c[v.first] = v.second;
    }
}
int gao(int u, int v) {
  T++;
  int r = v, tot = 0;
  dep[v] = n;
  int ret = -1;
  while (r != u) {
    ch[dep[r]] = c[r];
    vis[r] = T;
    cp[r] = 1;
    dep[p[r]] = dep[r] - 1;
    r = p[r];
    ret++;
  }
  vis[u] = T;
  cp[u] = 1;
  for (int j = 1; j < n + 1; j++)
    if (vis[j] != T) {
      int top = 0, r = j;
      while (vis[r] != T) st[top++] = r, r = p[r];
      for (int i = top - 1; i >= 0; i--) {
        int r = st[i];
        dep[r] = dep[p[r]] + 1;
        vis[r] = T;
        if (cp[p[r]] != 1)
          cp[r] = cp[p[r]];
        else if (ch[dep[r]] > c[r])
          cp[r] = 0;
        else if (ch[dep[r]] == c[r])
          cp[r] = 1;
        else
          cp[r] = 2;
        ret += (cp[r] == 0) || (cp[r] == 1 && dep[r] < dep[v]);
      }
    }
  return ret;
}
void solve(int u, int f) {
  for (auto v : Q[u]) ret[v.second] = gao(u, v.first);
  int pr = c[u];
  for (auto v : e[u])
    if (v.first != f) {
      p[u] = v.first;
      c[u] = v.second;
      solve(v.first, u);
    }
  c[u] = pr;
  p[u] = f;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i < n; i++) {
    scanf("%d%d%s", &u, &v, s);
    e[u].push_back(make_pair(v, s[0]));
    e[v].push_back(make_pair(u, s[0]));
  }
  dfs(1, 0);
  for (int i = 0; i < q; i++) {
    scanf("%d%d", &u, &v);
    Q[u].push_back(make_pair(v, i));
  }
  solve(1, 0);
  for (int i = 0; i < q; i++) printf("%d\n", ret[i]);
}
