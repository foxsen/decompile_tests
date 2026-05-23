#include <bits/stdc++.h>
using namespace std;
long long n, a[1001], cnt = 0;
long long s;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> s;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 2; i <= n; i++) {
    cnt += a[i] - a[1];
  }
  if (cnt >= s)
    cout << a[1];
  else if (a[1] >= (s - cnt) / n + ((s - cnt) % n == 0 ? 0 : 1))
    cout << a[1] - (s - cnt) / n - ((s - cnt) % n == 0 ? 0 : 1);
  else
    cout << -1;
}
