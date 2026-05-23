#include <bits/stdc++.h>
using namespace std;
int a[3005], b[3005];
long long f[3005][3005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], a[i] -= i, b[i] = a[i];
  sort(b + 1, b + n + 1);
  int tot = unique(b + 1, b + n + 1) - b - 1;
  for (int i = 1; i <= n; ++i) {
    long long mn = 0x3f3f3f3f3f3f3f3f;
    for (int j = 1; j <= tot; ++j) {
      mn = min(f[i - 1][j], mn);
      f[i][j] = mn + abs(a[i] - b[j]);
    }
  }
  long long ans = 0x3f3f3f3f3f3f3f3f;
  for (int i = 1; i <= tot; ++i) ans = min(ans, f[n][i]);
  cout << ans;
  return 0;
}
