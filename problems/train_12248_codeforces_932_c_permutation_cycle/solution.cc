#include <bits/stdc++.h>
#pragma GCC Optimize("Ofast")
using namespace std;
const long long maxn = 2e5 + 7;
const long long mod = 1e9 + 7;
const long long INF = 3e18 + 315;
long long n, A, B, u, v;
template <typename... Args>
void input(Args&... args) {
  ((cin >> args), ...);
}
template <typename... Args>
void output(Args&... args) {
  ((cout << args), ...);
}
void no();
void yes();
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  input(n, A, B);
  for (long long k = 0; k <= n; ++k) {
    if (n < k * A) break;
    if (!((n - k * A) % B)) {
      u = k;
      v = (n - k * A) / B;
      break;
    }
  }
  if (u == 0 && v == 0) return output("-1\n"), 0;
  for (long long i = 1; i <= u; ++i)
    for (long long j = 1; j <= A; ++j) {
      long long ans = ((i - 1) * A + j % A + 1);
      output(ans, " ");
    }
  for (long long i = 1; i <= v; ++i)
    for (long long j = 1; j <= B; ++j) {
      long long ans = u * A + (i - 1) * B + j % B + 1;
      output(ans, " ");
    }
  return 0;
}
void no() { cout << "NO" << endl; }
void yes() { cout << "YES" << endl; }
