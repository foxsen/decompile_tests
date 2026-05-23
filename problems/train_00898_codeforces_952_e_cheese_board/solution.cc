#include <bits/stdc++.h>
int n, t, ans = 1;
std::string s;
int main() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> s >> s, t += s == "soft";
  for (; (ans * ans + 1) / 2 < std::max(t, n - t) || ans * ans < n; ans++)
    ;
  std::cout << ans;
  return 0;
}
