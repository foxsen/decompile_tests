#include <bits/stdc++.h>
using namespace std;
const int N = 605, INF = 1e9;
int w[N][N], a[N], b[N];
bool used[N];
vector<int> v[N], t[N];
int g = 0;
bool dfs(int node) {
  if (used[node]) return false;
  used[node] = 1;
  for (int to : t[node]) {
    if (b[to] == -1 || dfs(b[to])) {
      b[to] = node;
      a[node] = to;
      return true;
    }
  }
  return false;
}
int main() {
  int n, m, k, d;
  scanf("%d%d%d%d", &n, &m, &k, &d);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      w[i][j] = INF;
    }
    w[i][i] = 0;
  }
  for (int i = 0; i < k; i++) {
    int x;
    scanf("%d", &x);
    x--;
    v[x].push_back(g++);
  }
  for (int i = 0; i < m; i++) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    x--, y--;
    w[x][y] = min(w[x][y], z);
    w[y][x] = min(w[y][x], z);
  }
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      for (int z = 0; z < n; z++) {
        w[x][z] = min(w[x][z], w[x][y] + w[y][z]);
      }
    }
  }
  int l = -1, r = INF;
  while (r - l > 1) {
    int p = (l + r) >> 1;
    for (int i = 0; i < k; i++) {
      t[i].clear();
    }
    fill(a, a + k, -1);
    fill(b, b + n, -1);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (w[i][j] <= p) {
          for (int x : v[i]) {
            t[x].push_back(j);
          }
        }
      }
    }
    bool work = true;
    int ct = 0;
    while (work) {
      work = false;
      fill(used, used + k, 0);
      for (int i = 0; i < k; i++) {
        if (a[i] == -1 && dfs(i)) {
          work = true;
          ct++;
        }
      }
    }
    if (ct >= d)
      r = p;
    else
      l = p;
  }
  printf("%d", r == INF ? -1 : r);
  return 0;
}
