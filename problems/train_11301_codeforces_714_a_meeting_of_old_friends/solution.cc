#include <bits/stdc++.h>
using namespace std;
int main() {
  long long l1, r1, l2, r2, k;
  cin >> l1 >> r1 >> l2 >> r2 >> k;
  long long start = max(l1, l2);
  long long end = min(r1, r2);
  long long ans = end - start + 1;
  if (ans < 0)
    cout << 0;
  else {
    if (k >= start && k <= end) ans -= 1;
    cout << ans;
  }
  return 0;
}
