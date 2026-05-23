#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, m;
  cin >> n >> m;
  long long a[n], i, j;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long time[101] = {0};
  long long sum = 0;
  for (i = 0; i < n; i++) {
    sum += a[i];
    long long ans = 0;
    if (sum <= m) {
      cout << ans << " ";
      time[a[i]]++;
      continue;
    }
    long long sum1 = sum;
    for (long long t = 100; t >= 1; t--) {
      if (sum1 - t * time[t] <= m) {
        if ((sum1 - m) % t == 0)
          ans += (sum1 - m) / t;
        else
          ans += (sum1 - m) / t + 1;
        break;
      }
      ans += time[t];
      sum1 -= t * time[t];
    }
    cout << ans << " ";
    time[a[i]]++;
  }
  return 0;
}
