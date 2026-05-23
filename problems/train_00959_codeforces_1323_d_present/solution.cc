#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int a[N], t[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int k = 0; k <= 24; k++) {
    for (int i = 0; i < n; i++) t[i] = a[i] % (1 << (k + 1));
    sort(t, t + n);
    long long cnt = 0;
    for (int i = 0; i < n - 1; i++) {
      cnt += (lower_bound(t + i + 1, t + n, (1 << (k + 1)) - t[i]) -
              lower_bound(t + i + 1, t + n, (1 << k) - t[i]));
      cnt +=
          n -
          (lower_bound(t + i + 1, t + n, (1 << k) + (1 << (k + 1)) - t[i]) - t);
    }
    ans |= (1 << k) * (cnt % 2);
  }
  cout << ans << endl;
  return 0;
}
