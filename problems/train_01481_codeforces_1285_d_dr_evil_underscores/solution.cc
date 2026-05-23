#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int cnt = 1, T[N * 31][2], n;
long long t, a[N * 31];
void insert(long long x) {
  int u = 0;
  for (int i = 30; i >= 0; i--) {
    int v = (x >> i) & 1;
    if (!T[u][v]) {
      memset(T[cnt], 0, sizeof(T[cnt]));
      a[cnt] = 0;
      T[u][v] = cnt++;
    }
    u = T[u][v];
  }
  a[u] = x;
}
long long dfs(int p, int k) {
  if (!T[p][0] && !T[p][1]) return 0;
  if (!T[p][0]) return dfs(T[p][1], k - 1);
  if (!T[p][1]) return dfs(T[p][0], k - 1);
  return (1LL << k) + min(dfs(T[p][0], k - 1), dfs(T[p][1], k - 1));
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &t);
    insert(t);
  }
  printf("%lld\n", dfs(0, 30));
  return 0;
}
