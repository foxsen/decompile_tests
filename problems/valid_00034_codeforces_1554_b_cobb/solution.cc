#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 5, INF = 1e18, mod = 1e9 + 7;
long long n, k, a[N], ans;
void doWork() {
  ans = -INF;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (long long i = max(n - 2 * k, (long long)0); i < n; i++)
    for (long long j = i + 1; j < n; j++)
      ans = max(ans, (i + 1) * (j + 1) - k * (a[i] | a[j]));
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int test = 1;
  cin >> test;
  while (test--) doWork();
}
