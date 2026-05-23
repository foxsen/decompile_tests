#include <bits/stdc++.h>
using namespace std;
long long a[2000005];
long long p[2000005];
long long n, t;
int main() {
  cin >> t;
  while (t--) {
    scanf("%lld", &n);
    for (int i = 0; i < n; i++) scanf("%lld", &a[i]);
    sort(a, a + n);
    int cnt = 0;
    p[cnt] = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] == a[i - 1])
        p[cnt]++;
      else {
        cnt++;
        p[cnt]++;
      }
    }
    sort(p, p + cnt + 1);
    int min1 = p[0] + 1;
    int ans = 0x3f3f3f3f;
    int num;
    bool flag;
    for (int i = 1; i <= min1; i++) {
      flag = false;
      num = 0;
      for (int j = 0; j <= cnt; j++) {
        int x = (p[j] - 1) / i + 1;
        if ((i - 1) * x > p[j] || p[j] > x * i) {
          flag = true;
          break;
        }
        num += x;
      }
      if (flag) continue;
      ans = min(ans, num);
    }
    printf("%d\n", ans);
    for (int i = 0; i <= cnt; i++) p[i] = 0;
  }
}
