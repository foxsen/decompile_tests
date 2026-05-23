#include <bits/stdc++.h>
using namespace std;
const int MN = 2000111;
int lab[MN];
struct DSU {
  void init(int n) {
    for (int i = 0, _a = (n + 1); i < _a; ++i) lab[i] = -1;
  }
  int getRoot(int u) {
    if (lab[u] < 0) return u;
    return lab[u] = getRoot(lab[u]);
  }
  bool merge(int u, int v) {
    u = getRoot(u);
    v = getRoot(v);
    if (u == v) return false;
    if (lab[u] > lab[v]) swap(u, v);
    lab[u] += lab[v];
    lab[v] = u;
    return true;
  }
};
int m, n;
char a[1011][1011];
const int di[4] = {-1, 1, 0, 0};
const int dj[4] = {0, 0, -1, 1};
bool outside(int i, int j) { return i < 1 || i > m || j < 1 || j > n; }
int id(int i, int j) { return (i - 1) * n + j; }
int main() {
  while (scanf("%d%d\n", &m, &n) == 2) {
    for (int i = (1), _b = (m); i <= _b; ++i) scanf("%s\n", &a[i][1]);
    DSU dsu;
    dsu.init((m + 1) * (n + 1));
    for (int i = (1), _b = (m); i <= _b; ++i)
      for (int j = (1), _b = (n); j <= _b; ++j) {
        for (int dir = 0, _a = (4); dir < _a; ++dir) {
          int ii = i + di[dir], jj = j + dj[dir];
          if (outside(ii, jj)) continue;
          if (a[i][j] == '*' || a[ii][jj] == '*') continue;
          dsu.merge(id(i, j), id(ii, jj));
        }
      }
    for (int i = (1), _b = (m); i <= _b; ++i) {
      for (int j = (1), _b = (n); j <= _b; ++j) {
        if (a[i][j] == '.') {
          putchar('.');
        } else {
          int res = 1;
          set<int> all;
          for (int dir = 0, _a = (4); dir < _a; ++dir) {
            int ii = i + di[dir], jj = j + dj[dir];
            if (outside(ii, jj)) continue;
            if (a[ii][jj] == '*') continue;
            int t = dsu.getRoot(id(ii, jj));
            if (all.count(t)) continue;
            all.insert(t);
            res += -lab[dsu.getRoot(id(ii, jj))];
          }
          putchar((char)('0' + res % 10));
        }
      }
      puts("");
    }
  }
}
