#include <bits/stdc++.h>
long long memo[(1 << 21)];
long long modexp(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n & 1) res = ((res % 1000000007) * (a % 1000000007)) % 1000000007;
    a = ((a % 1000000007) * (a % 1000000007)) % 1000000007;
    n >>= 1;
  }
  return res;
}
int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    int t;
    std::cin >> t;
    memo[t]++;
  }
  for (int p = 0; p < 21; p++) {
    for (int mask = ((1 << 21) - 1); mask >= 0; mask--) {
      if (!(mask & (1 << p))) memo[mask] += memo[mask ^ (1 << p)];
    }
  }
  long long ans = 0;
  for (int mask = 0; mask < (1 << 21); mask++) {
    int z = __builtin_popcount(mask);
    if (z & 1)
      ans = ((ans % 1000000007) - (modexp(2, memo[mask]) % 1000000007) +
             1000000007) %
            1000000007;
    else
      ans = ((ans % 1000000007) + (modexp(2, memo[mask]) % 1000000007)) %
            1000000007;
  }
  std::cout << ans << "\n";
  return 0;
}
