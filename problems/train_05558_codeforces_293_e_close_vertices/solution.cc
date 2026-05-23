#include <bits/stdc++.h>
using namespace std;
mt19937 gen(time(NULL));
const long double eps = 1e-9;
const int inf = 1e9;
const int mod = 1e9 + 7;
const long long infinity = 2 * 1e18;
struct edge {
  int to, w;
};
vector<edge> g[100005];
int lv[100005];
vector<vector<int>> mx[100005];
int md[100005];
vector<vector<int>> t[100005];
long long ans = 0;
int w, l;
int dfs(int u, int s, int &center, int e = -1) {
  int sz = 1;
  for (auto v : g[u])
    if (v.to != e && lv[v.to] == -1) sz += dfs(v.to, s, center, u);
  if (center == -1 && (2 * sz >= s || e == -1)) center = u;
  return sz;
}
int pre_dfs(int u, int e) {
  int ml = 0;
  for (auto v : g[u])
    if (lv[v.to] == -1 && v.to != e) ml = max(ml, pre_dfs(v.to, u) + 1);
  return ml;
}
void calc(int u, int anc, int center, int len = 0, int carry = 0, int e = -1) {
  if (u != center) {
    mx[anc][len].push_back(carry);
    mx[center][len].push_back(carry);
  }
  for (auto v : g[u])
    if (lv[v.to] == -1 && v.to != e)
      calc(v.to, (u == center) ? v.to : anc, center, len + 1, carry + v.w, u);
}
void build(int center, int u, int l, int r) {
  if (l >= r) return;
  for (int i = l; i <= r - 1; i++)
    for (auto v : mx[center][i]) t[center][u].push_back(v);
  sort(t[center][u].begin(), t[center][u].end());
  if (l == r - 1) return;
  int m = (l + r) / 2;
  build(center, 2 * u + 1, l, m);
  build(center, 2 * u + 2, m, r);
}
int get(int center, int u, int l, int r, int L, int R, int w) {
  if (l >= r || L >= R) return 0;
  if (l == L && r == R) {
    auto &x = t[center][u];
    if (x.size() <= 1 || x.front() > w) return (x.size() && x.back() <= w);
    int lx = 0, rx = x.size();
    while (lx < rx - 1) {
      int mx = (lx + rx) / 2;
      if (x[mx] > w)
        rx = mx;
      else
        lx = mx;
    }
    return rx;
  }
  int m = (l + r) / 2, ans = 0;
  if (L < m) ans += get(center, 2 * u + 1, l, m, L, min(m, R), w);
  if (R > m) ans += get(center, 2 * u + 2, m, r, max(L, m), R, w);
  return ans;
}
void cdc(int u, int s, int level = 0, int e = -1) {
  int center = -1;
  dfs(u, s, center);
  int height = pre_dfs(center, -1) + 1;
  lv[center] = level;
  mx[center].resize(height);
  for (auto v : g[center])
    if (lv[v.to] == -1) mx[v.to].resize(height);
  calc(center, center, center);
  t[center].resize(4 * height);
  build(center, 0, 0, height);
  for (auto v : g[center])
    if (lv[v.to] == -1) t[v.to].resize(4 * height), build(v.to, 0, 0, height);
  long long loc = 0;
  for (auto v : g[center])
    if (lv[v.to] == -1)
      for (int i = 1; i <= height - 1; i++)
        for (auto a : mx[v.to][i]) {
          if (i <= l && a <= w) ans++;
          if (i < l && a < w) {
            loc += get(center, 0, 0, height, 0, min(height, l - i + 1), w - a);
            loc -= get(v.to, 0, 0, height, 0, min(height, l - i + 1), w - a);
          }
        }
  ans += loc / 2;
  t[center].clear();
  for (auto v : g[center])
    if (lv[v.to] == -1) t[v.to].clear();
  mx[center].clear();
  for (auto v : g[center])
    if (lv[v.to] == -1) mx[v.to].clear();
  for (auto v : g[center])
    if (lv[v.to] == -1) cdc(v.to, s / 2, level + 1, center);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, q;
  cin >> n >> l >> w;
  int u, v, ww;
  for (int i = 0; i < n - 1; i++) {
    cin >> u >> ww;
    g[u].push_back({i + 2, ww}), g[i + 2].push_back({u, ww});
  }
  fill_n(lv, 100005, -1);
  cdc(1, n);
  cout << ans << '\n';
}
