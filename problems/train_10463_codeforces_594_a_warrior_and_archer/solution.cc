#include <bits/stdc++.h>
using namespace std;
int n, i, ans, a[500100];
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  ans = 1000000000;
  for (i = 1; i + n / 2 <= n; i++) ans = min(ans, a[i + n / 2] - a[i]);
  cout << ans;
  return 0;
}
