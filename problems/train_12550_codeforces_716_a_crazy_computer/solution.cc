#include <bits/stdc++.h>
const long long MOD = 1000000007;
int main() {
  long long n, c;
  std::cin >> n >> c;
  std::vector<long long> t(n, 0);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> t[i];
    ++ans;
    if (i > 0) {
      if (t[i] > t[i - 1] + c) {
        ans = 0;
        ++ans;
      }
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
