#include <bits/stdc++.h>
using namespace std;
inline void debug() {}
template <typename _type, typename... type>
inline void debug(_type arg, const type&... next) {}
const int MaxN = 1000 * 1000 + 5;
int n, p[MaxN];
int res;
int sum[MaxN], full;
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> p[i], res ^= p[i];
  for (int i = 1; i <= n; ++i) {
    sum[i - 1] += n / i;
    ++sum[n % i];
  }
  for (int i = n; i >= 1; --i) {
    sum[i] += sum[i + 1];
    if (sum[i] % 2) res ^= i;
  }
  cout << res << '\n';
}
