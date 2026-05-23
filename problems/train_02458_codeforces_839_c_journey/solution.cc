#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int N = 100100;
int cnt = 0;
long double Cnt[N];
long double SumCnt = 0;
long double H[N];
long double P[N];
vector<int> g[N];
long double dfs(int v, int p = -1) {
  if ((int)g[v].size() == 1 && v != 1) {
    return 0;
  }
  long double sum = 0.000;
  for (int i = 0; i < (int)g[v].size(); ++i) {
    int to = g[v][i];
    if (to == p) continue;
    sum += dfs(to, v);
  }
  sum /= ((int)g[v].size() - (p != -1));
  sum += 1.000;
  return sum;
}
signed main() {
  int n;
  scanf("%d", &n);
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  printf("%.15Lf\n", dfs(1));
  return 0;
}
