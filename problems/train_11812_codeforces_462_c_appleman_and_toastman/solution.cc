#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 4;
int n, m;
long long int a[N];
long long ans = 0;
bool cmp(long long a, long long b) { return a > b; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%I64d", a + i);
  sort(a + 1, a + n + 1);
  if (n == 1) {
    cout << a[1];
    return 0;
  }
  if (n == 2) {
    cout << 2 * (a[1] + a[2]);
    return 0;
  }
  ans = 1LL * a[n] * n;
  for (int i = n - 1; i >= 1; --i) ans += 1LL * a[i] * (i + 1);
  cout << ans;
}
