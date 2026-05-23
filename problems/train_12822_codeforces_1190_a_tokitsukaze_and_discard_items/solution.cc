#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
using namespace std;
template <typename T>
void uin(T &a, T b) {
  if (b < a) {
    a = b;
  }
}
template <typename T>
void uax(T &a, T b) {
  if (b > a) {
    a = b;
  }
}
const long long N = 100 * 1000 + 228;
long long p[N];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  for (long long i = 1; i <= m; ++i) cin >> p[i];
  long long mod = 0;
  long long i = 1;
  long long moves = 0;
  while (i <= m) {
    long long page = (p[i] - mod + k - 1) / k;
    long long cnt = 0;
    while (i <= n && (p[i] - mod + k - 1) / k == page) {
      ++i;
      ++cnt;
    }
    mod += cnt;
    ++moves;
  }
  cout << moves << '\n';
  return 0;
}
