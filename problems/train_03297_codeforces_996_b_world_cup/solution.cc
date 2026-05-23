#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  int ans;
  int m = INT_MAX;
  for (int i = 1; i <= n; i++) {
    int b;
    if (i > a[i])
      b = i;
    else {
      b = a[i] / n;
      b = b * n + i;
      if (b <= a[i]) b += n;
    }
    if (m > b) {
      m = b;
      ans = i;
    }
  }
  cout << ans << "\n";
  return 0;
}
