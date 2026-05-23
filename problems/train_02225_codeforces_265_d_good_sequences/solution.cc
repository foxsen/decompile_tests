#include <bits/stdc++.h>
using namespace std;
const int N = 100002;
int a[N];
int d[N];
int main() {
  int n, m, i, j;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  int ans = 0;
  for (i = 1; i <= n; i++) {
    int cnt = 0;
    for (j = 2; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        cnt = max(cnt, d[j]);
        cnt = max(cnt, d[a[i] / j]);
      }
    }
    for (j = 2; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        d[j] = max(d[j], cnt + 1);
        d[a[i] / j] = max(d[a[i] / j], cnt + 1);
      }
    }
    d[a[i]] = max(d[a[i]], cnt + 1);
    ans = max(cnt + 1, ans);
  }
  cout << ans;
}
