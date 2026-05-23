#include <bits/stdc++.h>
using namespace std;
int n, m, N, a[200500], b[200500], arr[200500 + 200500], z[200500 + 200500],
    ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  if (n < m) {
    cout << 0;
    return 0;
  }
  if (m == 1) {
    cout << n;
    return 0;
  }
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> b[i];
  for (int i = 2; i <= m; i++) arr[N++] = b[i] - b[i - 1];
  arr[N++] = 1 << 30;
  for (int i = 2; i <= n; i++) arr[N++] = a[i] - a[i - 1];
  for (int i = 1, l = 0, r = 0; i < N; i++) {
    if (i <= r) z[i] = min(z[i - l], r - i + 1);
    while (z[i] + i < N && arr[z[i]] == arr[z[i] + i]) z[i]++;
    if (z[i] + i - 1 > r) l = i, r = z[i] + i - 1;
  }
  for (int i = m; i < N; i++) {
    if (z[i] == m - 1) ans++;
  }
  cout << ans;
  return 0;
}
