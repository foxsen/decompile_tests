#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  int m = unique(a, a + n) - a;
  int cont[k + 1];
  memset(cont, 0, sizeof cont);
  for (int i = 0; i < m; ++i) ++cont[a[i]];
  for (int i = 1; i + 1 < m; ++i)
    if (a[i - 1] == a[i + 1]) ++cont[a[i]];
  int best = n + 1, ans = -1;
  for (int i = 1; i <= k; ++i) {
    int aux = m - 1 - cont[i];
    if (aux < best) {
      best = aux;
      ans = i;
    }
  }
  cout << ans << endl;
  return 0;
}
