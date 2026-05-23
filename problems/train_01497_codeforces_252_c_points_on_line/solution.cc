#include <bits/stdc++.h>
using namespace std;
long long a[100005];
int main() {
  long long n, d;
  cin >> n >> d;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long l = 1, r = 2;
  long long ans = 0;
  while (l <= n || r <= n) {
    if (l >= r) {
      r = l + 1;
      continue;
    }
    if (r > n) {
      ans += max(0ll, (r - l - 1) * (r - l - 2) / 2), r--, l++;
      continue;
    }
    if (a[r] - a[l] <= d)
      r++;
    else {
      ans += max(0ll, (r - l - 1) * (r - l - 2) / 2);
      r--;
      l++;
    }
  }
  cout << ans << endl;
}
