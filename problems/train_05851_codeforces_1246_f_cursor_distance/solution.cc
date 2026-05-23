#include <bits/stdc++.h>
using namespace std;
template <typename T>
void debug_out(T t) {
  cerr << t;
}
template <typename A, typename B>
void debug_out(pair<A, B> u) {
  cerr << "(" << u.first << " " << u.second << ")";
}
template <typename T>
void debug_out(vector<T> t) {
  int sz = t.size();
  for (int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if (i != sz - 1) cerr << ", ";
  }
}
template <typename T>
void debug_out(vector<vector<T>> t) {
  int sz = t.size();
  for (int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if (i != sz - 1) cerr << endl;
  }
}
class tree {
 public:
  ;
  int n;
  vector<int> p;
  vector<int> c;
  vector<int> pos;
  vector<int> path;
  tree(vector<int> _p) : p(_p) {
    n = p.size();
    c.resize(n, -1);
    pos.resize(n, -1);
    vector<vector<int>> g(n);
    vector<int> sub(n, 1);
    vector<int> dep(n);
    for (int i = 0; i < n; i++) {
      if (i != p[i]) g[p[i]].push_back(i);
    }
    function<void(int)> dfs = [&](int v) {
      if (p[v] != v) dep[v] = dep[p[v]] + 1;
      for (int u : g[v]) {
        dfs(u);
        sub[v] += sub[u];
      }
    };
    for (int i = 0; i < n; i++)
      if (i == p[i]) dfs(i);
    function<void(int, int)> dfs2 = [&](int v, int t) {
      pos[v] = path.size();
      c[v] = pos[t];
      path.push_back(v);
      int mx = -1;
      for (int u : g[v])
        if (mx == -1 || sub[u] > sub[mx]) mx = u;
      if (mx != -1) dfs2(mx, t);
      for (int u : g[v])
        if (u != mx) dfs2(u, u);
    };
    for (int i = 0; i < n; i++)
      if (i == p[i]) dfs2(i, i);
  }
  int getp(int v, int d) {
    while (d > 0) {
      int l = c[v];
      int ps = pos[v];
      assert(ps >= l);
      if (d > ps - l) {
        if (p[path[l]] == path[l]) return path[l];
        v = p[path[l]];
        d -= ps - l + 1;
      } else {
        return path[ps - d];
      }
    }
    return v;
  }
};
string s;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  int n = s.length();
  const int N = 26;
  vector<vector<int>> a(n, vector<int>(N, n));
  vector<vector<int>> b(n, vector<int>(N, -1));
  for (int i = n - 1; i > -1; i--) {
    if (i < n - 1) a[i] = a[i + 1];
    a[i][s[i] - 'a'] = i;
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) b[i] = b[i - 1];
    b[i][s[i] - 'a'] = i;
  }
  int cnt = 0;
  int va, vb;
  vector<int> ta(n);
  vector<vector<int>> sa(n);
  for (int i = 0; i < n; i++) {
    ta[i] = cnt;
    sa[i] = a[i];
    sort(sa[i].begin(), sa[i].end());
    while (sa[i].back() == n) sa[i].pop_back();
    cnt += sa[i].size();
  }
  va = cnt;
  vector<int> pa(cnt);
  vector<int> wa(cnt);
  vector<int> ca(cnt);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int)sa[i].size(); j++) wa[ta[i] + j] = i;
    ca[ta[i]] = 1 << (s[sa[i][0]] - 'a');
    for (int j = 1; j < (int)sa[i].size(); j++)
      ca[ta[i] + j] = ca[ta[i] + j - 1] | (1 << (s[sa[i][j]] - 'a'));
    if (i == 0)
      for (int j = 0; j < (int)sa[i].size(); j++) pa[ta[i] + j] = ta[i] + j;
    else {
      for (int j = 0; j < (int)sa[i].size(); j++) {
        int x = i, y = sa[i][j];
        int z = x;
        for (int u = 0; u < N; u++) {
          if (b[y][u] < x) continue;
          z = min(z, b[x - 1][u]);
        }
        if (z == -1) z = 0;
        int pos =
            upper_bound(sa[z].begin(), sa[z].end(), y) - sa[z].begin() - 1;
        pa[ta[i] + j] = ta[z] + pos;
      }
    }
  }
  tree ast(pa);
  cnt = 0;
  vector<int> tb(n);
  vector<vector<int>> sb(n);
  for (int i = 0; i < n; i++) {
    tb[i] = cnt;
    sb[i] = b[i];
    sort(sb[i].begin(), sb[i].end(), greater<int>());
    while (sb[i].back() == -1) sb[i].pop_back();
    cnt += sb[i].size();
  }
  vb = cnt;
  vector<int> pb(cnt);
  vector<int> wb(cnt);
  vector<int> cb(cnt);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int)sb[i].size(); j++) wb[tb[i] + j] = n - 1 - i;
    cb[tb[i]] = 1 << (s[sb[i][0]] - 'a');
    for (int j = 1; j < (int)sb[i].size(); j++)
      cb[tb[i] + j] = cb[tb[i] + j - 1] | (1 << (s[sb[i][j]] - 'a'));
    if (i == n - 1)
      for (int j = 0; j < (int)sb[i].size(); j++) pb[tb[i] + j] = tb[i] + j;
    else {
      for (int j = 0; j < (int)sb[i].size(); j++) {
        int x = i, y = sb[i][j];
        int z = x;
        for (int u = 0; u < N; u++) {
          if (a[y][u] > x) continue;
          z = max(z, a[x + 1][u]);
        }
        if (z == n) z = n - 1;
        int pos = upper_bound(sb[z].begin(), sb[z].end(), y, greater<int>()) -
                  sb[z].begin() - 1;
        pb[tb[i] + j] = tb[z] + pos;
      }
    }
  }
  tree bst(pb);
  const int inf = 1e9;
  vector<int> da(va);
  vector<int> db(vb);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int)sa[i].size(); j++) {
      int v = ta[i] + j;
      if (i == 0) {
        da[v] = inf;
        continue;
      }
      if (ca[v] != ca[pa[v]])
        da[v] = 1;
      else
        da[v] = da[pa[v]] + 1;
    }
  }
  for (int i = n - 1; i > -1; i--) {
    for (int j = 0; j < (int)sb[i].size(); j++) {
      int v = tb[i] + j;
      if (i == n - 1) {
        db[v] = inf;
        continue;
      }
      if (cb[v] != cb[pb[v]])
        db[v] = 1;
      else
        db[v] = db[pb[v]] + 1;
    }
  }
  vector<long long> dwa(va);
  vector<long long> dwb(vb);
  for (int i = 0; i < va; i++) {
    dwa[i] = dwa[pa[i]] + wa[i];
  }
  for (int i = vb - 1; i > -1; i--) {
    dwb[i] = dwb[pb[i]] + wb[i];
  }
  auto getp = [&](int v, int dep, bool rev) {
    return (!rev ? ast.getp(v, dep) : bst.getp(v, dep));
  };
  auto solve = [&](int pos) {
    long long res = 0;
    int x = pos;
    int y = pos;
    while (x > 0 || y < n - 1) {
      int sx = upper_bound(sa[x].begin(), sa[x].end(), y) - sa[x].begin() - 1 +
               ta[x];
      int sy = upper_bound(sb[y].begin(), sb[y].end(), x, greater<int>()) -
               sb[y].begin() - 1 + tb[y];
      int dep = min(da[sx], db[sy]);
      dep = min(n, dep);
      int cx = getp(sx, dep, false);
      int cy = getp(sy, dep, true);
      res += dwa[sx] - dwa[cx] + dwb[sy] - dwb[cy];
      sx = cx;
      sy = cy;
      x = wa[sx];
      y = n - 1 - wb[sy];
    }
    return res;
  };
  long long res = 0;
  for (int i = 0; i < n; i++) res += solve(i);
  cout << res;
  return 0;
}
