#include <bits/stdc++.h>
using namespace std;
signed main() {
  setlocale(LC_ALL, "rus");
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<long long> dp(n);
  stack<pair<int, int>> st;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      while (!st.empty() && st.top().first < a[i]) {
        ans += st.top().first;
        if (st.top().second > 0) {
          ans += dp[st.top().second - 1];
        }
        a[i] -= st.top().first;
        st.pop();
      }
      if (!st.empty()) {
        ans += a[i];
        dp[i] = 1;
        if (a[i] == st.top().first) {
          if (st.top().second > 0) {
            ans += dp[st.top().second - 1];
            dp[i] += dp[st.top().second - 1];
          }
          st.pop();
        } else {
          st.top().first -= a[i];
        }
        a[i] = 0;
      }
    } else {
      st.emplace(a[i], i);
    }
  }
  cout << ans;
}
