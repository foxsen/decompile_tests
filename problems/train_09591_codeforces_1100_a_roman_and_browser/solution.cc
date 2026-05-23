#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i, j, l, e, s, b;
  cin >> n >> k;
  int a[n + 1];
  int ans = 0, count1 = 0, count2 = 0;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] == 1)
      count1++;
    else
      count2++;
  }
  for (b = 1; b <= n; b++) {
    j = 0;
    l = 0;
    for (i = b; i >= 1; i -= k) {
      if (a[i] == 1)
        j++;
      else
        l++;
    }
    for (i = b + k; i <= n; i += k) {
      if (a[i] == 1)
        j++;
      else
        l++;
    }
    e = count1 - j;
    s = count2 - l;
    ans = max(ans, abs(e - s));
  }
  cout << ans;
}
