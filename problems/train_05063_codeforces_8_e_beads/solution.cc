#include <bits/stdc++.h>
using namespace std;
long long f[55][2][2], K, d;
int a[55], n;
long long C(int l, int r, int x, int y) {
  if (l > r) return 1;
  long long& F = f[l][x][y];
  if (~F) return F;
  F = 0;
  for (int i = 0; i <= 1; ++i)
    for (int j = 0; j <= 1; ++j)
      if (a[l] - !i && a[r] - !j && (l < r || i == j) && (x || i <= j) &&
          (y || i <= (!j)))
        F += C(l + 1, r - 1, x || (i < j), y || (i < !j));
  return F;
}
int main() {
  cin >> n >> K;
  memset(a, -1, sizeof a);
  memset(f, -1, sizeof f);
  if (C(1, n, a[1] = 0, 0) < ++K) return cout << -1, 0;
  for (int i = 2; i <= n; ++i) {
    memset(f, -1, sizeof f);
    d = C(1, n, a[i] = 0, 0);
    K -= (a[i] = (d < K)) * d;
  }
  for (int i = 1; i <= n; ++i) cout << a[i];
}
