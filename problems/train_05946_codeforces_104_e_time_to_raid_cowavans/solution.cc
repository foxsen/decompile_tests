#include <bits/stdc++.h>
using namespace std;
struct reqest {
  long long a, b, ind;
};
bool comp(reqest a, reqest b) {
  if (a.b == b.b) return a.a < b.a;
  return a.b < b.b;
}
int main() {
  long long n;
  scanf("%lld", &n);
  vector<long long> w(n);
  for (int i = 0; i < n; ++i) scanf("%lld", &w[i]);
  long long m;
  scanf("%lld", &m);
  vector<reqest> req(m);
  for (int i = 0; i < m; ++i) {
    scanf("%lld%lld", &req[i].a, &req[i].b);
    --req[i].a;
    req[i].ind = i;
  }
  sort(req.begin(), req.end(), comp);
  long long c = sqrt(n);
  vector<long long> ans(m);
  vector<long long> dp(n);
  for (int i = 0; i < req.size(); ++i) {
    if (req[i].b > c) {
      long long sum = 0;
      for (int j = req[i].a; j < n; j += req[i].b) {
        sum += w[j];
      }
      ans[req[i].ind] = sum;
    } else {
      long long res = 0;
      if (i != 0 && req[i - 1].b == req[i].b) {
        res = dp[req[i].a];
      } else {
        res = dp[req[i].a];
        dp.assign(n, 0);
        for (int j = n - 1; j >= 0; --j) {
          dp[j] = w[j];
          if (j + req[i].b < n) {
            dp[j] += dp[j + req[i].b];
          }
        }
        res = dp[req[i].a];
      }
      ans[req[i].ind] = res;
    }
  }
  for (int i = 0; i < ans.size(); ++i) printf("%lld\n", ans[i]);
  puts("");
  return 0;
}
