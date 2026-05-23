#include <bits/stdc++.h>
constexpr int ABC = 20;
int mask_length(int mask) {
  int res = 0;
  while (mask) {
    mask &= mask - 1;
    ++res;
  }
  return res;
}
int main() {
  std::string s;
  std::cin >> s;
  int n = s.length();
  std::vector<bool> seen(1 << ABC);
  seen[0] = true;
  std::vector<int> dp(1 << ABC);
  for (int L = 1; L <= std::min(ABC, n); ++L) {
    std::vector<int> last_idx(ABC, -1);
    int mask = 0, len = 0;
    for (int i = 0; i < L; ++i) {
      last_idx[s[i] - 'a'] = i;
      if (!(mask & (1 << (s[i] - 'a')))) {
        mask |= (1 << (s[i] - 'a'));
        ++len;
      }
    }
    if (len == L) {
      seen[mask] = true;
      dp[mask] = L;
    }
    for (int i = L; i < n; ++i) {
      if (last_idx[s[i - L] - 'a'] == i - L) {
        mask ^= (1 << (s[i - L] - 'a'));
        --len;
      }
      if (last_idx[s[i] - 'a'] <= i - L) {
        mask |= (1 << (s[i] - 'a'));
        ++len;
      }
      last_idx[s[i] - 'a'] = i;
      if (len == L) {
        seen[mask] = true;
        dp[mask] = L;
      }
    }
  }
  for (int mask = 0; mask < (1 << ABC); ++mask) {
    for (int i = 0; i < ABC; ++i) {
      if (mask & (1 << i)) {
        dp[mask] = std::max(dp[mask ^ (1 << i)], dp[mask]);
      }
    }
  }
  int ans = 0;
  for (int mask = 0; mask < (1 << ABC); ++mask) {
    if (seen[mask]) {
      ans = std::max(ans, dp[mask] + dp[mask ^ ((1 << ABC) - 1)]);
    }
  }
  std::cout << ans << '\n';
  return 0;
}
