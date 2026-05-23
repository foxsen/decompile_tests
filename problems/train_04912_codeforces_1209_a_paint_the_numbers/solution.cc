#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
const int MAXN = (int)1e5 + 10;
const int mo = (int)1e9 + 7;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int a[110];
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  int v[110] = {0};
  int tot = 0, ans = 0;
  while (tot != n) {
    int base;
    ans++;
    for (int i = 1; i <= n; i++)
      if (!v[i]) {
        v[i] = 1;
        tot++;
        base = a[i];
        break;
      }
    for (int i = 1; i <= n; i++) {
      if (!v[i] && (a[i] % base == 0)) {
        v[i] = 1;
        tot++;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
