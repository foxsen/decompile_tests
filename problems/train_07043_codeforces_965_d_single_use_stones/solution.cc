#include <bits/stdc++.h>
using namespace std;
int res = 1e9, n, k;
int a[1000005];
int main() {
  cin >> n >> k;
  for (int i = 1; i < n; ++i) {
    cin >> a[i];
    a[i] += a[i - 1];
    if (i >= k) res = min(res, a[i] - a[i - k]);
  }
  cout << res;
  return 0;
}
