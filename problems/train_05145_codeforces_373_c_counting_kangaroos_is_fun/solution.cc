#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j, a[500005] = {0}, low, high, ans = 0;
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  low = 1, high = (n / 2) + 1;
  for (i = 1; i <= n / 2; i++) {
    while (a[high] < 2 * a[i] && high < n) high++;
    if (a[high] >= 2 * a[i]) ans++, high++;
    if (high > n) break;
  }
  cout << n - ans;
  return 0;
}
