#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast")
using namespace std;
const int maxn = 1510, mod = 998244353;
pair<int, int> e[maxn * maxn / 2];
vector<pair<int, int> > ed[maxn];
int p[maxn];
bool br[maxn * maxn / 2];
int add(int x, int y) {
  x += y;
  if (x >= mod) {
    x -= mod;
  }
  return x;
}
int mul(int x, int y) { return (long long)x * y % mod; }
int getp(int x) { return (p[x] == x ? x : p[x] = getp(p[x])); }
bool used[maxn][maxn];
vector<int> nv, nf;
int us[maxn];
int posit = 0;
void dfs(int v, int up) {
  if (us[v] == posit) {
    return;
  }
  us[v] = posit;
  nv.push_back(v);
  for (auto [u, w] : ed[v]) {
    if (w >= up) {
      continue;
    }
    nf.push_back(w);
    dfs(u, up);
  }
}
vector<int> solve(vector<int> vert, vector<int> f) {
  sort((f).begin(), (f).end());
  bool good = true;
  for (int x : vert) {
    for (int y : vert) {
      if (used[x][y]) {
        good = false;
        break;
      }
    }
    if (!good) {
      break;
    }
  }
  vector<int> ans(vert.size() + 1, 0);
  if (f.empty()) {
    ans.back() = 1;
    return ans;
  }
  vector<int> ids;
  while (!br[f.back()]) {
    int id = f.back();
    f.pop_back();
    if (good) {
      ans[1]++;
    }
    used[e[id].first][e[id].second] = true;
    good = false;
    ids.push_back(id);
  }
  int id = f.back();
  if (good) {
    ans[1]++;
  }
  ids.push_back(id);
  f.pop_back();
  used[e[id].first][e[id].second] = true;
  nv.clear();
  nf.clear();
  posit++;
  dfs(e[id].first, id);
  vector<int> a = solve(nv, nf);
  nv.clear();
  nf.clear();
  posit++;
  dfs(e[id].second, id);
  vector<int> b = solve(nv, nf);
  assert(ans.size() + 1 == a.size() + b.size());
  for (int i = 0; i < (int)a.size(); i++) {
    for (int j = 0; j < (int)b.size(); j++) {
      ans[i + j] = add(ans[i + j], mul(a[i], b[j]));
    }
  }
  for (int id : ids) {
    used[e[id].first][e[id].second] = false;
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x;
      scanf("%d", &x);
      x--;
      if (i < j) {
        e[x] = make_pair(i, j);
        ed[i].push_back(make_pair(j, x));
        ed[j].push_back(make_pair(i, x));
      }
    }
  }
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  int m = n * (n - 1) / 2;
  for (int i = 0; i < m; i++) {
    int x = e[i].first;
    int y = e[i].second;
    x = getp(x);
    y = getp(y);
    if (x != y) {
      br[i] = true;
      p[x] = y;
    }
  }
  vector<int> f;
  for (int i = 0; i < m; i++) {
    f.push_back(i);
  }
  vector<int> v;
  for (int i = 0; i < n; i++) {
    v.push_back(i);
  }
  auto ans = solve(v, f);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}
