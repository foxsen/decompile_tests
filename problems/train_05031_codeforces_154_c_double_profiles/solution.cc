#include <bits/stdc++.h>
using namespace std;
long long p[1000005], h[1000005];
unordered_map<long long, long long> m1, m2;
int main() {
  long long ans = 0, n, m, B = 37, x, y;
  m1.reserve(1 << 12), m2.reserve(1 << 12);
  m1.max_load_factor(0.25), m2.max_load_factor(0.25);
  scanf("%lld%lld", &n, &m), p[0] = 1;
  for (long long i = 1; i < 1000005; i++) p[i] = p[i - 1] * B;
  while (m--) scanf("%lld%lld", &x, &y), h[x] += p[y], h[y] += p[x];
  for (long long i = 1; i <= n; i++) m1[h[i]]++, h[i] += p[i], m2[h[i]]++;
  for (auto i : m1) ans += (i.second * (i.second - 1)) / 2;
  for (auto i : m2) ans += (i.second * (i.second - 1)) / 2;
  cout << ans;
}
