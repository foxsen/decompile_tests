#include <bits/stdc++.h>
using namespace std;
long long n, k, tot, num, now, a[200001], f[200001];
int main() {
  cin.sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 0; i <= n; i++) cin >> a[i];
  now = -1;
  for (int i = 0; i <= n; i++) {
    f[i] += a[i];
    if (i != n) {
      f[i + 1] += f[i] / 2;
      f[i] %= 2;
    }
    if (now == -1 && f[i] != 0) now = i;
  }
  for (int i = n; i >= 0; i--) {
    tot *= 2;
    tot += f[i];
    if (tot > 2147483647 || tot < -2147483647) break;
    if (i <= now) {
      long long ans = tot - a[i];
      if (ans <= k && ans >= -k && !(i == n && ans == 0)) num++;
    }
  }
  cout << num << endl;
}
