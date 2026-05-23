#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long arr[1000000];
int main() {
  long long n, m, a, t, time = 0;
  while (cin >> n >> m >> a >> t) {
    for (int i = 0; i < m; i++) cin >> arr[i];
    long long time = 0, ans = 0;
    long long k = t / a + 1;
    if (arr[0] < a)
      time = arr[0] + t;
    else
      time = a + t;
    ans++;
    for (int i = 0; i < m; i++) {
      if (arr[i] <= time) continue;
      long long l = time / a, r = arr[i] / a;
      r = min(r, n);
      if (l == r) {
        time = arr[i] + t;
        ans++;
      } else {
        long long t2;
        long long t1 = (r - l);
        if (t1 % k == 0)
          t2 = t1 / k;
        else
          t2 = t1 / k + 1;
        ans += t2;
        l += (t2 - 1) * k;
        if ((l + 1) * a + t >= arr[i])
          time = (l + 1) * a + t;
        else
          time = arr[i] + t, ans++;
      }
    }
    long long t1 = time / a;
    if (t1 < n) {
      long long t2 = (n - t1) / k;
      if ((n - t1) % k == 0)
        t2 = (n - t1) / k;
      else
        t2 = (n - t1) / k + 1;
      ans += t2;
    }
    cout << ans << endl;
  }
  return 0;
}
