#include <bits/stdc++.h>
using namespace std;
int N;
int x, y, root = -1;
vector<int> g[200100];
int len[200100], viz[3][200100];
int dmax = 0, ind;
int stacky[200100], l = 0;
void dfs(int x) {
  viz[0][x] = 1;
  if (g[x].size() == 1) {
    len[x] = 1;
  } else {
    int okk = 1;
    int kiddo = -1, kiddo2 = -1;
    for (auto y : g[x]) {
      if (viz[0][y]) {
        continue;
      }
      dfs(y);
      if (x == root) {
        if (len[y] == 0) {
          okk = 0;
        } else if (kiddo == -1) {
          kiddo = len[y];
        } else if (kiddo != len[y] && kiddo2 == -1) {
          kiddo2 = len[y];
        } else if (kiddo2 != len[y] && kiddo != len[y]) {
          okk = 0;
        }
      } else {
        if (len[y] == 0) {
          okk = 0;
          continue;
        }
        if (kiddo == -1) {
          kiddo = len[y];
        } else if (kiddo != len[y]) {
          okk = 0;
        }
      }
    }
    if (okk) {
      if (x != root || kiddo2 == -1) {
        len[x] = kiddo + 1;
      } else {
        len[x] = kiddo + kiddo2 + 1;
      }
    }
  }
}
void dfss(int x, int t, int d) {
  stacky[++l] = x;
  viz[t][x] = 1;
  if (d > dmax) {
    ind = x;
    dmax = d;
    root = stacky[(l + 1) / 2];
  }
  for (auto y : g[x])
    if (!viz[t][y]) dfss(y, t, d + 1);
  --l;
}
int main() {
  cin.sync_with_stdio(false);
  cin >> N;
  if (N == 2) {
    cout << 1;
    return 0;
  }
  for (int i = 1; i < N; ++i) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfss(1, 1, 0);
  dmax = 0;
  dfss(ind, 2, 0);
  dfs(root);
  if (len[root]) {
    int ret = len[root] - 1;
    while (ret % 2 == 0) ret /= 2;
    cout << ret;
    return 0;
  } else {
    cout << -1;
    return 0;
  }
  return 0;
}
