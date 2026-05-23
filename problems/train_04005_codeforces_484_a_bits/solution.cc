#include <bits/stdc++.h>
using namespace std;
int builtin_popcount(long long x) {
  int ret = 0;
  for (int i = 0; i <= 60; i++)
    if (x & (1LL << i)) ret++;
  return ret;
}
int main() {
  int n;
  cin >> n;
  while (n--) {
    long long l, r;
    cin >> l >> r;
    for (int i = 60, j = 0; i >= 0; i--) {
      if ((l & (1LL << i)) != (r & (1LL << i))) {
        if (builtin_popcount(r) > i + j)
          cout << r << endl;
        else {
          long long ans = 0;
          for (int k = 60; k >= i; k--) ans += (r & (1LL << k));
          cout << ans - 1 << endl;
        }
        break;
      }
      if (r & (1LL << i)) j++;
      if (i == 0) cout << l << endl;
    }
  }
}
