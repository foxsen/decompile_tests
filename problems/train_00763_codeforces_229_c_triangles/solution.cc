#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void chkmax(T& x, U y) {
  if (x < y) x = y;
}
template <typename T, typename U>
inline void chkmin(T& x, U y) {
  if (y < x) x = y;
}
int deg[1111111];
int main() {
  int n, m;
  cin >> n >> m;
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    deg[u]++, deg[v]++;
  }
  long long ans = 1LL * n * (n - 1) * (n - 2) / 3;
  for (int i = 1; i <= n; i++) ans -= 1LL * deg[i] * (n - 1 - deg[i]);
  cout << ans / 2 << endl;
  return 0;
}
