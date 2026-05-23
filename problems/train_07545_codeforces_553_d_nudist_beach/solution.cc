#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MOD = 1000000007;
const double EPS = 1e-9;
vector<int> g[MAXN];
int tot[MAXN], good[MAXN];
int p[MAXN], q[MAXN];
set<int> bad;
bool vis[MAXN];
vector<int> res;
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; ++i) {
    int val;
    scanf("%d", &val);
    --val;
    bad.insert(val);
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 0; i < n; ++i) {
    good[i] = tot[i] = (int)g[i].size();
  }
  for (int u : bad) {
    for (int v : g[u]) {
      --good[v];
    }
  }
  double low = 0, high = 1;
  for (int i = 0; i < 50; ++i) {
    double mid = 0.5 * (low + high);
    queue<int> Q;
    for (int j = 0; j < n; ++j) {
      p[j] = tot[j];
      q[j] = good[j];
      vis[j] = false;
    }
    for (int j = 0; j < n; ++j) {
      if (!bad.count(j)) {
        double val = 1.0 * q[j] / p[j];
        if (val <= mid - EPS) {
          Q.push(j);
          vis[j] = true;
        }
      }
    }
    int cur = n - k;
    while (!Q.empty()) {
      --cur;
      int u = Q.front();
      Q.pop();
      for (int v : g[u]) {
        if (!bad.count(v)) {
          --q[v];
          double val = 1.0 * q[v] / p[v];
          if ((val <= mid - EPS) && !vis[v]) {
            Q.push(v);
            vis[v] = true;
          }
        }
      }
    }
    if (cur > 0) {
      low = mid;
      res.clear();
      for (int j = 0; j < n; ++j) {
        if (!vis[j] && !bad.count(j)) {
          res.push_back(j);
        }
      }
    } else {
      high = mid;
    }
  }
  printf("%d\n", (int)res.size());
  for (int i = 0; i + 1 < (int)res.size(); ++i) {
    printf("%d ", res[i] + 1);
  }
  printf("%d\n", res.back() + 1);
  return 0;
}
