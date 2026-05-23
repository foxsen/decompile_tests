#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
const int mod = 1000000007;
int n, m;
vector<int> g[N];
int v[N];
int main() {
  cin >> n >> m;
  memset(v, 0, sizeof(v));
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
  }
  for (int i = 1; i < n + 1; ++i) {
    if (v[i]) continue;
    for (int u : g[i]) {
      if (u > i) v[u] = 1;
    }
  }
  int num = 0;
  for (int i = n; i > 0; --i) {
    if (v[i]) continue;
    for (int u : g[i]) {
      if (u < i) v[u] = 1;
    }
    ++num;
  }
  printf("%d\n", num);
  for (int i = 1; i < n + 1; ++i)
    if (!v[i]) printf("%d ", i);
  printf("\n");
}
