#include <bits/stdc++.h>
int n, k, s, t, a[200010], b[200010], c[200010];
using namespace std;
int f(int x) {
  int i, ans = 0;
  for (i = 1; i <= k + 1; i++) {
    int len = c[i] - c[i - 1];
    if (len > x) return 0;
    if (x > 2 * len)
      ans += len;
    else
      ans += (x - len) + 2 * (len - (x - len));
  }
  if (t < ans)
    return 0;
  else
    return 1;
}
int main() {
  ios_base::sync_with_stdio(0);
  int ans = 1000000006, i;
  cin >> n >> k >> s >> t;
  for (i = 1; i <= n; i++) cin >> a[i] >> b[i];
  for (i = 1; i <= k; i++) cin >> c[i], c[i] = min(s, c[i]);
  c[k + 1] = s;
  sort(c + 1, c + 2 + k);
  int l = 1, r = 1000000001;
  while (l < r) {
    if (f((l + r) / 2))
      r = (l + r) / 2;
    else
      l = (l + r) / 2 + 1;
  }
  for (i = 1; i <= n; i++)
    if (b[i] >= l) ans = min(ans, a[i]);
  if (ans != 1000000006)
    cout << ans;
  else
    cout << -1;
}
