#include <bits/stdc++.h>
using namespace std;
namespace ufs {
int fa[100005];
void makeset(int n) {
  for (int i = 1; i <= n; i++) fa[i] = i;
}
int findset(int u) {
  if (fa[u] == u) return fa[u];
  return fa[u] = findset(fa[u]);
}
void unionset(int a, int b) {
  int u = findset(a);
  int v = findset(b);
  fa[u] = v;
}
}  // namespace ufs
using namespace ufs;
int n, m, tot;
int x = 1, y = 0;
int tot_white, tot_black;
int col[100005], id[100005], d[100005];
bool used[100005];
vector<int> w, b;
vector<int> g[100005], v[100005];
map<int, int> t[100005];
void pr() {
  cout << "YES\n";
  for (int i = 1; i <= n; i++) cout << id[i] << ' ';
  exit(0);
}
void makenext(int &x, int &y) {
  y++;
  x += y / 3;
  y %= 3;
}
void dfs(int u) {
  if (col[u] == 1)
    tot_white++;
  else
    tot_black++;
  for (int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (col[v] != col[u] * -1) {
      col[v] = col[u] * -1;
      dfs(v);
    }
  }
}
void prepare() {
  for (int i = 1; i <= n; i++)
    if (col[i] == 0) {
      col[i] = 1;
      dfs(i);
    }
  if (tot_white % 3 == 2) {
    swap(tot_white, tot_black);
    for (int i = 1; i <= n; i++) col[i] *= -1;
  }
}
void filp() {
  for (int i = 1; i <= n; i++)
    if (v[i].size() >= 1) {
      for (int j = 0; j < v[i].size(); j++) col[v[i][j]] *= -1;
      break;
    }
  tot_white = tot_black = 0;
  for (int i = 1; i <= n; i++)
    if (col[i] == 1)
      tot_white++;
    else
      tot_black++;
  if (tot_white % 3 == 2) {
    swap(tot_white, tot_black);
    for (int i = 1; i <= n; i++) col[i] *= -1;
  }
}
void make12(int &x, int &y) {
  int _ind;
  for (int i = 0; i < w.size(); i++)
    if (id[w[i]] == 0) {
      _ind = w[i];
      break;
    }
  id[_ind] = x;
  makenext(x, y);
  for (int i = 0; i < b.size(); i++) {
    if (id[b[i]] == 0 && t[_ind][b[i]] == 0) {
      id[b[i]] = x;
      makenext(x, y);
    }
    if (x != id[_ind]) break;
  }
}
void makeall(int &x, int &y) {
  for (int i = 1; i <= n; i++)
    if (col[i] == 1 && id[i] == 0) {
      id[i] = x;
      makenext(x, y);
    }
  for (int i = 1; i <= n; i++)
    if (col[i] == -1 && id[i] == 0) {
      id[i] = x;
      makenext(x, y);
    }
}
void check() {
  w.clear();
  b.clear();
  for (int i = 1; i <= n; i++)
    if (col[i] == 1)
      w.push_back(i);
    else
      b.push_back(i);
  bool f = 0;
  for (int i = 0; i < w.size(); i++)
    if (d[w[i]] <= tot_black - 2) {
      swap(w[0], w[i]);
      f = 1;
      break;
    }
  if (f) {
    make12(x, y);
    makeall(x, y);
    pr();
  }
  if (tot_white >= 4) {
    int tot = 0;
    for (int i = 0; i < b.size(); i++)
      if (d[b[i]] <= tot_white - 2 && tot <= 1) {
        swap(b[tot], b[i]);
        tot++;
      }
    if (tot == 2) {
      swap(tot_black, tot_white);
      swap(w, b);
      for (int i = 1; i <= n; i++) col[i] *= -1;
      make12(x, y);
      make12(x, y);
      makeall(x, y);
      pr();
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  makeset(n);
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    d[u]++;
    d[v]++;
    t[u][v] = t[v][u] = 1;
    unionset(u, v);
  }
  for (int i = 1; i <= n; i++) {
    if (used[findset(i)] == 0) {
      used[findset(i)] = 1;
      tot++;
    }
    v[findset(i)].push_back(i);
  }
  prepare();
  if (tot_white % 3 == 0 && tot_black % 3 == 0) {
    makeall(x, y);
    pr();
  }
  if (tot == 2) {
    check();
  } else
    check();
  cout << "NO";
  return 0;
}
