#include <bits/stdc++.h>
using namespace std;
struct node {
  long long w, d;
  node() {}
  node(long long w, long long d) : w(w), d(d) {}
  bool operator<(const node &x) const {
    if (x.w == w) {
      return d > x.d;
    }
    return w > x.w;
  }
};
long long n, m, k, dp[100010][202];
vector<node> in[100010], out[100010];
void checkmin(long long &x, long long y) {
  if (x > y) {
    x = y;
  }
}
int main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  for (int i = 1; i <= k; i++) {
    long long s, t, d, w;
    scanf("%lld%lld%lld%lld", &s, &t, &d, &w);
    in[s].push_back(node(w, d));
    out[t].push_back(node(w, d));
  }
  multiset<node> st;
  for (int i = 0; i < 100010; i++) {
    for (int j = 0; j <= 200; j++) {
      dp[i][j] = (long long)5e18;
    }
  }
  dp[1][0] = 0;
  for (int i = 1; i <= n + 1; i++) {
    for (int j = 0; j < (int)in[i].size(); j++) {
      st.insert(in[i][j]);
    }
    for (int j = 0; j <= m; j++) {
      checkmin(dp[i + 1][j + 1], dp[i][j]);
      if (st.empty()) {
        checkmin(dp[i + 1][j], dp[i][j]);
      } else {
        node x = *st.begin();
        checkmin(dp[x.d + 1][j], dp[i][j] + x.w);
      }
    }
    for (int j = 0; j < (int)out[i].size(); j++) {
      st.erase(st.lower_bound(out[i][j]));
    }
  }
  long long ans = (long long)5e18;
  for (int i = 0; i <= m; i++) {
    ans = min(ans, dp[n + 1][i]);
  }
  cout << ans << endl;
  return 0;
}
